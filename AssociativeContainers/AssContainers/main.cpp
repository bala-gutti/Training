#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;

const size_t KNUMITERATIONS = 1000;
int DieRoll(){
    return (rand()%365) + 1;
}

size_t RunProcess(){
    set<int> generated;
    while(true){
        int nextValue = DieRoll();
        if(generated.count(nextValue))
            return generated.size() + 1;
        generated.insert(nextValue);
    }

    /*vector<int> generated;
    while(true)
    {
        int nextValue = DieRoll();
        for(size_t i = 0; i < generated.size(); ++i){
            if(generated[i] == nextValue)
                return generated.size() + 1;
        }
        generated.push_back(nextValue);
    }
    */
}

int main()
{
    srand(static_cast<unsigned>(time(NULL)));
    size_t total = 0;
    for(size_t k = 0; k < KNUMITERATIONS; ++k)
    {
        total += RunProcess();
    }

    cout << "Average number of steps: " << double(total)/KNUMITERATIONS << endl;
    return 0;
}

