#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <time.h>

using namespace std;

void five()
{
    srand(time(NULL));
    int value = 0;
    ofstream myfile;
    myfile.open("five.txt", ofstream::out | ofstream::trunc);
    if(myfile.is_open()){
        for (int i = 5000; i--;){
            value = rand() % 5000 + 1;
            myfile << value << " ";
        }
        myfile.close();
    }
    else{
        cout << "Unable to open file" << endl;
    }
}

void readinfive(int temp[])
{
    ifstream infile;
    int number, i;
    infile.open("five.txt");
    infile.clear();
    infile >> number;
    int temp[number];

}

void bubbleSort(int s[], int n)
{
      bool swapp = true;
      while(swapp){
        swapp = false;
        for (int i = 0; i < n; i++) {
            if (s[i]>s[i+1] ){
                s[i] += s[i+1];
                s[i+1] = s[i] - s[i+1];
                s[i] -= s[i+1];
                swapp = true;
            }
        }
    }
}

void timeBubbleSort(int sort[], vector<float>& sortWriter, ofstream& outfile, int n)
{
    clock_t time;
    time = clock();
    bubbleSort(sort, n);
    time = clock() - time;
    float timer = (float)time/CLOCKS_PER_SEC;
    sortWriter.push_back(timer);
    outfile << "    It took " << timer << " second(s) to bubble sort the vector.\n";
}

int main() 
{
    srand(time(NULL));
    ofstream outfile;
    outfile.open("timeComplexity2.txt");
    vector<float> averageOH, averageFH, averageOM;

    five();
    
    int c = 5;

    int vecfive[c];

    readinfive(vecfive);

    int n = sizeof(vecfive)/sizeof(vecfive[0]);

    timeBubbleSort(vecfive, averageOH, outfile, n);

    for(int i = 0; i < 5000; i++) {
        cout << vecfive[i] << " ";
    }

    return 0;
}