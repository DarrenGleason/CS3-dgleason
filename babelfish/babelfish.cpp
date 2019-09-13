/*
    9/6/2019
    Darren Gleason
    Babelfish - Kattis Problem - Difficulty 2.1
    --- Takes a foreign dilect and translates it based on a known dictionary. There are up to 100,000 dictionary entries, all lowercase,
     no capitalization.
*/
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <cassert>

using namespace std;
void test1(unordered_map<string, string> map,string actual, string foreign){
    actual = map[foreign];
    assert(actual == "mean");
    cout << (actual == "" ? "eh" : actual) << endl;
}

void test2(unordered_map<string, string> map,string actual, string foreign){
    actual = map[foreign];
    assert(actual == "you");
    cout << (actual == "" ? "eh" : actual) << endl;
}

void test3(unordered_map<string, string> map,string actual, string foreign){
    actual = map[foreign];
    assert(actual == "what");
    cout << (actual == "" ? "eh" : actual) << endl;
}

int main(){
    unordered_map<string, string> map;
    string in, actual, foreign;

    while(getline(cin, in) && in != ""){
        stringstream s(in);
        s >> actual;
        s >> foreign;
        map[foreign] = actual;
    }

    cout << "Enter a word or phrase(select '$' to close the program)" << endl;

    while(cin >> foreign){
        //actual = map[foreign];
        if(foreign == "eanmay"){
            test1(map, actual, foreign);
        }
        else if(foreign == "ouyay"){
            test2(map, actual, foreign);
        }
        else if(foreign == "hatway"){
            test3(map, actual, foreign);
        }
        else{
            actual = map[foreign];
            cout << (actual == "" ? "eh" : actual) << endl;
        }
        if(foreign == "$") break;
    }
    return 0;
}