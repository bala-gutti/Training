#include <iostream>
#include <vector>
using namespace std;

struct point{
    int x;
    int y;
};


point p;
void SelectionSort(vector<int>& );
size_t GetSmallestIndex(const vector<int>&, size_t);

int main()
{
    cout << "Hello World!" << p.x << endl;
    vector<int> myVector;

    myVector.push_back(11);
    myVector.push_back(1);
    myVector.push_back(21);

    SelectionSort(myVector);

    for(size_t i = 0; i < myVector.size(); ++i)
        cout << myVector[i] << endl;
    return 0;
}

void SelectionSort(vector<int>& v){

    for(size_t i = 0; i < v.size(); ++i)
    {
        size_t smallestIndex = GetSmallestIndex(v,i);
        swap(v[i],v[smallestIndex]);

    }
}

size_t GetSmallestIndex(const vector<int>& v, size_t startIndex)
{
    size_t bestIndex = startIndex;
    for(size_t k = startIndex; k < v.size(); ++k)
    {
        if(v[k] < v[bestIndex])
            bestIndex = k;
    }
    return bestIndex;
}

//iterators
//v.insert(v.begin()+n,value); //0<= n < v.size()
//v.erase(v.begin()+n);
//v.clear();
