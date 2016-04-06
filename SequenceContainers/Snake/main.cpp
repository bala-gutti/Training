#include <iostream>
#include <vector>
#include <deque>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int kMaxFood = 20;

const char kEmptyTile = ' ';
const char kWallTile = '#';
const char kFoodTile ='$';
const char kSnakeTile = '*';

struct pointT{
    int x;
    int y;
};

struct gameT{
    vector<string> world;
    int numRows, numCols;

    deque<pointT> snake;
    int dx, dy;

    int numEaten;
};

pointT MakePoint(int row, int col){
    pointT result;
    result.x = row;
    result.y = col;
    return result;
}

void LoadWorld(gameT& game, ifstream& input){
    input >> game.numRows >> game.numCols;
    game.world.resize(game.numRows);

    input >> game.dx >> game.dy;

    string dummy;
    getline(input,dummy);
    for(int row = 0; row < game.numRows; ++row){
        getline(input,game.world[row]);
        int col = game.world[row].find(kSnakeTile);
        if (col != string::npos){
            game.snake.push_back(MakePoint(row,col));
        }
    }
    game.numEaten = 0;
}

void InitializeGame(gameT& game)
{

    srand(static_cast<unsigned>(time(NULL)));

    ifstream inputFile("/home/bala/Desktop/Git/Training/SequenceContainers/Snake/level.txt");
    //inputFile.open();
    if(!inputFile.is_open())
    {
        cerr << "Unalbe to locate/find the file"  << endl;

    }
    else
    {
        LoadWorld(game,inputFile);
    }
}

const double kWaitTime = 0.1;
void Pause(){
    clock_t startTime = clock();
    while(static_cast<double>(clock()-startTime)/CLOCKS_PER_SEC < kWaitTime){
    }
}

const string kClearCommand = "clear";

void PrintWorld(gameT& game){
    system(kClearCommand.c_str());
    for(int row = 0; row < game.numRows; ++row)
        cout << game.world[row] << endl;
    cout << "Good eaten: " << game.numEaten << endl;
}

void DisplayResult(gameT& game){
    PrintWorld(game);
    if(game.numEaten == kMaxFood)
        cout << "the snake ate enough food and wins!" << endl;
    else
        cout << "Oh no! the snake crashed!" << endl;
}

const double kTurnRate = 0.2;

pointT GetNextPosition(gameT& game, int dx, int dy){
    pointT result = game.snake.front();
    result.x += dy;
    result.y += dx;
    return result;
}

bool InWorld(pointT& pt, gameT& game){
    return pt.y >= 0 && pt.x >=0 && pt.y < game.numCols && pt.x < game.numRows;
}

bool Crashed(pointT headPos, gameT& game){
    return !InWorld(headPos,game) || game.world[headPos.x][headPos.y] == kSnakeTile || game.world[headPos.x][headPos.y] == kWallTile;
}

bool RandomChance(double probability){
    return (rand()/(RAND_MAX + 1.0)) < probability;
}

void PerformAI(gameT& game){
    pointT nextHead = GetNextPosition(game,game.dx,game.dy);
    if(Crashed(nextHead,game) || RandomChance(kTurnRate)){
        int leftDx = -game.dy;
        int leftDy = game.dx;
        int rightDx = game.dy;
        int rightDy = -game.dx;
        /* Check if turning left or right will cause us to crash. */
        bool canLeft = !Crashed(GetNextPosition(game, leftDx, leftDy),game);
        bool canRight = !Crashed(GetNextPosition(game, rightDx, rightDy),game);

        bool willTurnLeft = false;
        if(!canLeft && !canRight)
            return; // If we can't turn, don't turn.
        else if(canLeft && !canRight)
            willTurnLeft = true; // If we must turn left, do so.
        else if(!canLeft && canRight)
            willTurnLeft = false; // If we must turn right, do so.
        else
            willTurnLeft = RandomChance(0.5); // Else pick randomly

        game.dx = willTurnLeft? leftDx : rightDx;
        game.dy = willTurnLeft? leftDy : rightDy;
    }
}

void PlaceFood(gameT& game) {
    while(true) {
        int row = rand() % game.numRows;
        int col = rand() % game.numCols;

        /* If the specified position is empty, place the food there. */
        if(game.world[row][col] == kEmptyTile) {
            game.world[row][col] = kFoodTile;
            return;
        }
    }
}

bool MoveSnake(gameT& game) {
    pointT nextHead = GetNextPosition(game, game.dx, game.dy);
    if(Crashed(nextHead, game))
        return false;
    bool isFood = (game.world[nextHead.x][nextHead.y] == kFoodTile);
    game.world[nextHead.x][nextHead.y] = kSnakeTile;
    game.snake.push_front(nextHead);
    if(!isFood) {
        game.world[game.snake.back().x][game.snake.back().y] = kEmptyTile;
    game.snake.pop_back();
    } else {
        ++game.numEaten;
    PlaceFood(game);
    }
    return true;
}
void RunSimulation(gameT& game){

    while(game.numEaten < kMaxFood){
        PrintWorld(game);
        PerformAI(game);
        if(!MoveSnake(game)){
            break;
        }
        Pause();
    }
    DisplayResult(game);
}

int main()
{
    gameT game;
    InitializeGame(game);
    RunSimulation(game);

    return 0;
}














