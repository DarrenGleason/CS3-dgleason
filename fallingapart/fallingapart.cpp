/* 
    9/5/2019
    Darren Gleason
    Falling Apart - Kattis Problem - Difficulty 1.7
    --- Separates a list of integers, from a vector, to be put into two summations. ALways choosing the biggest number until no more numbers are gone. Ex: [4, 5, 6] a = 6, b = 5, a = 6 + 4; so on and so forth, determined by the size of the vector. This program also sorts the vector from largest to smallest, then takes the first integer in the sequence.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

void test1(int Alice, int Bob){
    assert(Alice == 3);
    assert(Bob == 1);
}

void test2(int Alice, int Bob){
    assert(Alice == 10);
    assert(Bob == 5);
}

void test3(int Alice, int Bob){
    assert(Alice == 2);
    assert(Bob == 1);
}

int main() {
    int iterative;
    cin >> iterative;
    vector<int> info(iterative);
    
    for (auto& i : info)
    {
        cin >> i;
    }
    
    sort(info.begin(), info.end());
    reverse(info.begin(), info.end());

    int Alice = 0;
    int Bob = 0;

    for(int i = 0; i < info.size(); i++)
    {   
        if(i % 2 == 0)
        {
            Alice += info[i];
        }
        else
        {
            Bob += info[i];
        }
    }

    if((info.at(0) == 2) && (info.at(1) == 1) && (info.at(2) == 1)){
        test1(Alice, Bob);
        cout << Alice << " " << Bob << endl;
    }
    else if((info.at(0) == 6) && (info.at(1) == 5) && (info.at(2) == 4)){
        test2(Alice, Bob);
        cout << Alice << " " << Bob << endl;
    }
    else if((info.at(0) == 1) && (info.at(1) == 1) && (info.at(2) == 1)){
        test3(Alice, Bob);
        cout << Alice << " " << Bob << endl;
    }
    else
    {
        cout << Alice << " " << Bob << endl;
    }
    return 0;
}

/*
    if info = 6 5 4, output = 10 5
    if info = 1 1 1, output = 2 1
    if info = 1 1 2, output = 3 1
*/