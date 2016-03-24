#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

const int NUM_LINES = 4;
const int NUM_COLUMNS = 3;
const int COLUMN_WIDTH = 20;

void fileStreams();
int stringManipuators();
int getLineManipulators();
void stringStreamManipulators();
int GetInteger();

int main()
{
    GetInteger();
    return 0;
}

int GetInteger(){

    while(true){
        string tempVal;
        stringstream converter;

        cout << "Enter an integer" << endl;
        getline(cin,tempVal);
        converter << tempVal;
        int number;
        if(converter >> number){

            cout << number << endl;
            string remaining;
            if(getline(converter,remaining)){
                cout << "Not an integer. erroneous chars present." << endl;
            }
            else
                return number;

        }
        else{
            cout << "Input is not an integer." << endl;
        }
    }

}

void stringStreamManipulators(){
    stringstream myStream;
    myStream << "chandu" << 1986 << endl;
    cout << myStream.str();

}

int getLineManipulators(){


    ifstream myStream("/home/bala/Desktop/Training/Streams-Train/capitals.txt");
    if(!myStream.is_open()){
        cerr << "unable to open the file" << endl;
       return 0;
    }
    string capital,country;
    while(getline(myStream,capital) && getline(myStream,country)){

        cout << capital << " is the capital of " << country << endl;
    }
    return 1;
}

int stringManipuators(){

    for(int k = 0; k < NUM_COLUMNS - 1 ; k++){
        cout << setfill('-') << setw(COLUMN_WIDTH) << "" << setfill(' ') << "+";
    }

    cout << setw(COLUMN_WIDTH) << "" << setfill(' ') << endl;

    ifstream mystream("/home/bala/Desktop/Training/Streams-Train/table-data.txt");
    if(!mystream.is_open()){ //can also use mystream.fail()
        cerr << "unable to open the file" << endl;
        return 0;
    }

    for(int k = 0; k < NUM_LINES; k++){
        int intVal;
        double doubleValue;
        mystream >> intVal >> doubleValue;
        cout << setw(COLUMN_WIDTH) << intVal << "|" << setw(COLUMN_WIDTH) << doubleValue << endl;
    }
    return 1;
}

void fileStreams(){
    int tempVal1,tempVal2;

    ifstream myStream;
    ofstream outStream;
    myStream.open("/home/bala/Desktop/Training/Streams-Train/inputFile.txt");
    if(!myStream.is_open()){
        cerr << "unable to open the file" <<endl;
    }

    myStream >> tempVal1 >> tempVal2;
    cout << tempVal1 << endl <<tempVal2 <<endl;
    outStream.open("outputFile.txt");
    outStream << tempVal1 << " asdf" << tempVal2;

    myStream.close();
    outStream.close();
}

void stdStreams(){
    cout << "enter an integer" << endl;
    int tempVar;
    string tempString;
    cin >> tempVar >> tempString;
    //if(cin.)
    cout <<tempVar << tempString <<endl;
}
