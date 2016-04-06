#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <deque>


using namespace std;
const string EMPTYSTRING = "";
const string FILE_PATH ="/home/bala/Desktop/Git/Training/SequenceContainers/Assignments/";

vector<string> LinesFromFile(const string& fileName){

    ifstream inputFile;
    stringstream fName;
    vector<string> fileContents;

    fName << FILE_PATH << fileName;
    string temp = fName.str();
    inputFile.open(temp.c_str());
    size_t i=0;
    if(inputFile.is_open()){

        string temp;
        while(getline(inputFile,temp)){
            fileContents.push_back(temp);
            cout << fileContents[i] << endl;
            ++i;
        }
    }
    else
        cerr << "Unable to open the file " << endl;

    cout << i <<  fileContents.size()<< endl;
    return fileContents;
}

string GetLine(){
    string val;
    cin >> val;
    return val;
}

void PrintBuffer(const deque<int>& cirBuff){
    for(size_t i = 0; i < cirBuff.size(); ++i)
        cout << cirBuff[i] << " ";
    cout << endl;
}

void PopulateBuffer(deque<int>& cirBuff)
{
    ifstream inputFile("/home/bala/Desktop/Git/Training/SequenceContainers/Assignments/circluarbuffer.txt");
    if(inputFile.is_open()){
        string tempVal;
        getline(inputFile,tempVal);
        cout << tempVal << endl;
        int item;
        istringstream ss(tempVal);
        while(ss >> item){
            cirBuff.push_back(item);
        }
    }
    else
        cerr << "Unable to open the file " << endl;
    PrintBuffer(cirBuff);
}
int main()
{
    //Problem 5.
/*
   cout << "Enter the name of the file : " << endl;
   string fileName = GetLine();
   vector<string> lines = LinesFromFile(fileName);
*/
    //Problem 6;
    deque<int> circularBuffer;
    PopulateBuffer(circularBuffer);

   return 0;
}

