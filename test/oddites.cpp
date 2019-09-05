#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

string answer(int x){
    if(x%2 == 0)
        return " is even";
    else
        return " is odd";
}

void test() {
    assert(answer(0) == " is even");
    assert(answer(-0) == " is even");
    assert(answer(-1) == " is odd");
    assert(answer(10) == " is even");
}

void kattis() {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        cout << x << answer(x) << endl;
    }
}

int main(int argc, char* argv[])
{
    if (argc > 1 && strncmp(argv[1], "test", 4) == 0)
        test();
    else
        kattis();
    return 0;
}