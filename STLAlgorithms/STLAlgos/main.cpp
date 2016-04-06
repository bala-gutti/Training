#include <iostream>
#include <fstream>
#include <set>
#include <numeric>
using namespace std;

int main()
{

    ifstream fileStream("/home/bala/Desktop/Git/Training/STLAlgorithms/STLAlgos/input.txt");
    if(fileStream.is_open()){
        multiset<int> values;
        int currValue;
        while (fileStream >> currValue)
            values.insert(currValue);

        double total = 0.0;

        cout << accumulate(values.begin(), values.end(), 0.0) / values.size() << endl;

        for (multiset<int>::iterator itr = values.begin();itr != values.end(); ++itr)
            total += *itr;
        cout << "Average is: " << total / values.size() << endl;
    }
    else
        cerr << "unable to open the file " << endl;
    return 0;
}

