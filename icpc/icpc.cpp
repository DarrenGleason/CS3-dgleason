/*
    Darren Gleason
    9/29/2019
    --- This program evaluates a specified algorithm by outputing if the algorithm passes in a certain time frame, or if it does not.
*/
#include <iostream>
#include <cassert>
#include <cmath>
#include <string>

using namespace std;

bool test(int m, int n, int exp, string ans)
{
    int product = n;
    for(int i = 1; i < exp; ++i)
    {
        product *= n;
        if(product > m)
        {
            cout << "TLE" << endl;
            ans = "TLE";
            return true;
        }
    }
    return false;
}

string figure(int m, int n, int t, int facto, string ans)
{
    switch(t)
    {
        case 1:
            for(int i = n; i > 0; --i)
            {
                if(facto > m)
                {
                    cout << "TLE" << endl;
                    ans = "TLE";
                    return 0;
                }
                facto *= i;
            }
        break;
        case 2:
            if(test(m, 2, n, ans)) return 0;
        break;
        case 3:
            if(test(m, n, 4, ans)) return 0;
        break;
        case 4:
            if(test(m, n, 3, ans)) return 0;
        break;
        case 5:
            if(test(m, n, 2, ans)) return 0;
        break;
        case 6:
            if((n*log2(n)) > m) 
            {
                cout << "TLE" << endl;
                ans = "TLE";
                return 0;
            }
        break;
        case 7:
            if(n > m) 
            {
                cout << "TLE" << endl;
                ans = "TLE";
                return 0;
            }
        break;
    }
    cout << "AC" << endl;
    ans = "AC";
    return ans;
}

void caseOne(int m, int n, int t, int facto, string ans)
{
    assert(figure(m, n, t, facto, ans) == "AC");
}

void caseTwo(int m, int n, int t, int facto, string ans)
{
    assert(figure(m, n, t, facto, ans) == "TLE");
}

void caseThree(int m, int n, int t, int facto, string ans)
{
    assert(figure(m, n, t, facto, ans) == "AC");
}

int main(void)
{
    int m, n, t;
    cin >> m >> n >> t;
    int facto = 1;
    string ans;

    if ((m == 100000000) && (n == 2) && (t == 3))
    {
        caseOne(m, n, t, facto, ans);
    }

    else if((m == 22222222) && (n == 3333333) && (t == 6))
    {
        caseTwo(m, n, t, facto, ans);
    }

    else if((m == 1000999) && (n == 1000) && (t == 7))
    {
        caseThree(m, n, t, facto, ans);
    }

    else
    {
        figure(m, n, t, facto, ans);
    }
}