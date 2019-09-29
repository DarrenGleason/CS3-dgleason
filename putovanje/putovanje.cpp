/*
    9/29/2019
    Darren Gleason
    Putovanje - Kattis Problem - Difficulty 2.6
    --- Determines he max amount of fruits that whateverhisnameis can eat while walking throught he forest. This code was a little tricky mostly because of how it was worded, and not how difficult it actually was.
*/


#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;
int run(int stomach, int amntfood, vector<int> weight)
{
    int best = 0;

    for(int j = 0; j < amntfood; j++) {

        int sum = 0;
        int count = 0;
        int k = j;
        
        for(k; k < amntfood; k++) {
            if (sum + weight[k] <= stomach) {
                sum += weight[k];
                count++;
            }
        }
        best = max(best, count);
    }

    cout << best << endl;
    return best;
}

void testone(int stomach, int amntfood, vector<int> weight) 
{
    assert(run(stomach, amntfood, weight) == 12);
}

void testtwo(int stomach, int amntfood, vector<int> weight)
{
    assert(run(stomach, amntfood, weight) == 6);
}

void testthree(int stomach, int amntfood, vector<int> weight)
{
    assert(run(stomach, amntfood, weight) == 3);
}

void input()
{
    int stomach, amntfood;
    vector<int> weight;
    vector<int> test1{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    vector<int> test2{100, 100, 100, 100, 100, 500, 100, 100, 100, 100};
    vector<int> test3{1, 3, 5, 4, 2, 7};

    cout << "Input the amount of food followed by how much whatchamacallhim can eat:" << endl;
    cin >> amntfood >> stomach;

    cout << "Input the weight of each fruit:" << endl;
    for(int i = 0; i < amntfood; i++) {
        int temp;
        cin >> temp;
        weight.push_back(temp);
    }

    if((amntfood == 0) || (stomach == 0))
    {
        cout << "Value for amntfood and stomach must be greater than 0." << endl;
        input();
    }

    else if(amntfood >= 1000)
    {
        cout << "Value for amntfood has to be less than 1000" << endl;
        input();
    }

    else if(stomach >= 100000)
    {
        cout << "Value for stomach has to be less than 1000000" << endl;
        input();
    }

    else if ((amntfood == 15 && stomach == 12) && (test1 == weight))
    {
        testone(stomach, amntfood, weight);
    }

    else if((amntfood == 10 && stomach == 1000) && (test2 == weight))
    {
        testtwo(stomach, amntfood, weight);
    }

    else if((amntfood == 6 && stomach == 10) && (test3 == weight))
    {
        testthree(stomach, amntfood, weight);
    }

    else
    {
        run(stomach, amntfood, weight);
    }
}

int main()
{
    
    bool again = true;
    char gain;

    while(again == true)
    {
        cout << "Would you like to find out the greatest amount of fruits whateverhisnamewas can eat?(Y or N)" << endl;
        cin >> gain;
        if((gain == 'N') || (gain == 'n'))
        {
            again == false;
            break;
        }
        else if((gain == 'Y') || (gain == 'y'))
        {
            input();
        }
    }
    
    return 0;
}