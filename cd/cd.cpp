/*
    9/8/2019
    Darren Gleason
    CD - Kattis Problem - Difficulty 4.3
    --- Takes an input and determines how many CDs to get rid of.
*/

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cassert>

using namespace std;

void testone(vector<int> jacky, vector<int> jilly, vector<int> solve);
void testtwo(vector<int> jacky, vector<int> jilly, vector<int> solve);
void testthree(vector<int> jacky, vector<int> jilly, vector<int> solve);

void answer(vector<int> jacky, vector<int>jilly, vector<int>solve)
{
    set_intersection(jacky.begin(), jacky.end(), jilly.begin(), jilly.end(), back_inserter(solve));
    cout << solve.size() << endl;
}

void input(int N, int M)
{
    while(cin >> N >> M && N != 0 && M != 0){
        vector<int> jacky, jilly, solve;

        int value;
        for(int i = 0; i < N; i++){
            cin >> value;
            jacky.push_back(value);
        }

        for(int i = 0; i < M; i++){
            cin >> value;
            jilly.push_back(value);
        }
        
        if((jacky.at(0) == 1) && (jacky.at(1) == 4) && (jacky.at(2) == 5) && (jilly.at(0) == 1) && (jilly.at(1) == 2) && (jilly.at(2) == 3))
        {
            testone(jacky, jilly, solve);
        }

        if((jacky.at(0) == 2) && (jacky.at(1) == 3) && (jacky.at(2) == 4) && (jacky.at(3) == 5) && (jilly.at(0) == 2) && (jilly.at(1) == 3) && (jilly.at(2) == 4) && jilly.at(3) == 5)
        {
            testtwo(jacky, jilly, solve);
        }

        if((jacky.at(0) == 6) && (jacky.at(1) == 8) && (jilly.at(0) == 5) && (jilly.at(1) == 9))
        {
            testthree(jacky, jilly, solve);
        }


        answer(jacky, jilly, solve);
    }
}

int main()
{
    int N, M;

    input(N, M);
    return 0;
}

void testone(vector<int> jacky, vector<int> jilly, vector<int> solve)
{
    answer(jacky, jilly, solve);
    assert(solve.size() == 1);
}

void testtwo(vector<int> jacky, vector<int> jilly, vector<int> solve)
{
    answer(jacky, jilly, solve);
    assert(solve.size() == 4);
}

void testthree(vector<int> jacky, vector<int> jilly, vector<int> solve)
{
    answer(jacky, jilly, solve);
    assert(solve.size() == 0);
}