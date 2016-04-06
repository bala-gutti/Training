#include <iostream>
#include <fstream>
#include <set>
#include <map>
using namespace std;


void openUserFile(const ifstream& fileStream){
    fileStream.open("/home/bala/Desktop/Git/Training/AssociativeContainers/KeyWordCounter/keywords.txt");
    if (fileStream.fail()){
        cerr << "unable to open the file.";
    }
}

set<string> GetFileContents(const ifstream& file){
    set<string> result;
    string line;
    while(getline(file,line)){
        result.insert(line);
    }
    return result;
}

map<string,size_t> GenerateKeywordReport(const set<string>& str){

}

int main()
{
    ifstream fileStream;
    openUserFile(fileStream);

    map<string,size_t> report = GenerateKeywordReport(GetFileContents(fileStream));

    for(map<string,size_t>::iterator itr = report.begin(); itr != report.end(); ++itr){
        cout << "Keyword " << itr->first << " occurred " << itr->second << " times." << endl;
    }
    return 0;
}

