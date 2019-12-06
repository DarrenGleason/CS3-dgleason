#include <random>
#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <iterator>
#include <functional>
#include <cstdio>
#include <stdlib.h>
#include <stdio.h>
#include <array>

using namespace std;

template<class T>
struct Node {
    T data;
    Node<T>* lTree;
    Node<T>* rTree;
};

template<class T>
class BST
{
  private:
    Node<T> *root;
    int nodeCount;
    
    Node<T>* find(Node<T> *p, const T& K) const {
        if (p == nullptr) return nullptr;
        if (K == p->data)
            return p;
        else if (K < p->data)
            return find(p->lTree, K);
        else 
            return find(p->rTree, K);
    }
    
    void insert(Node<T>* &p, Node<T> *newNode) {
        if (p == nullptr) {
            p = newNode;
            this->nodeCount++;
        }
        else {
            if (newNode->data <= p->data)
                insert(p->lTree, newNode);
            else
                insert(p->rTree, newNode);
        }
    }
    
  public:
    BST() {
        this->root = nullptr;
        this->nodeCount = 0;
    }

    Node<T>* find(const T& key) {
        return find(this->root, key);
    }
    void insert(const T& key) {
        Node<T> *node = new Node<T>;
        node->data = key;
        node->lTree = nullptr;
        node->rTree = nullptr;
        insert(this->root, node);
    }
};

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

void onehund()
{
    srand(time(NULL));
    int value = 0;
    ofstream myfile;
    myfile.open("onehund.txt", ofstream::out | ofstream::trunc);
    if(myfile.is_open()){
        for (int i = 100000; i--;){
            value = rand() % 100000 + 1;
            myfile << value << " ";
        }
        myfile.close();
    }
    else{
        cout << "Unable to open file" << endl;
    }
}

void fivehund()
{
    srand(time(NULL));
    int value = 0;
    ofstream myfile;
    myfile.open("fivehund.txt", ofstream::out | ofstream::trunc);
    if(myfile.is_open()){
        for (int i = 500000; i--;){
            value = rand() % 500000 + 1;
            myfile << value << " ";
        }
        myfile.close();
    }
    else{
        cout << "Unable to open file" << endl;
    }
}

void onemil()
{
    srand(time(NULL));
    int value = 0;
    ofstream myfile;
    myfile.open("onemil.txt", ofstream::out | ofstream::trunc);
    if(myfile.is_open()){
        for (int i = 1000000; i--;){
            value = rand() % 1000000 + 1;
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
    while(infile >> number){
        for(int i = 0; i < 5000; i++) {
            temp[i] = number;
        }
    }
}

void readinonehund(int temp[])
{
    ifstream infile;
    int number, i;
    infile.open("onehund.txt");
    infile.clear();
    while(infile >> number){
        for(int i = 0; i < 100000; i++) {
            temp[i] = number;
        }
    }
}
void readinfivehund(int temp[])
{
    ifstream infile;
    int number, i;
    infile.open("fivehund.txt");
    infile.clear();
    while(infile >> number){
        for(int i = 0; i < 500000; i++) {
            temp[i] = number;
        }
    }
}

void readinonemil(int temp[])
{
    ifstream infile;
    int number, i;
    infile.open("onemil.txt");
    infile.clear();
    while(infile >> number){
        for(int i = 0; i < 1000000; i++) {
            temp[i] = number;
        }
    }
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

void selectionSort(int s[], int n)
{
    for (int i = 0; i < n; i++){  
        int min = i;  
        for (int j = i+1; j < n; j++){
            if (s[j] < s[min]) {
                min = j;  
            }
        }
        swap(s[min], s[i]);  
    }
}

void insertionSort(int s[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = s[i];  
        j = i - 1;  
        while (j >= 0 && s[j] > key) 
        {  
            s[j + 1] = s[j];  
            j = j - 1;  
        }  
        s[j + 1] = key;  
    }  
}  

int shellSort(int arr[], int n) 
{ 
    for (int gap = n/2; gap > 0; gap /= 2) 
    { 
        for (int i = gap; i < n; i += 1) 
        { 
            int temp = arr[i]; 
  
            int j;             
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                arr[j] = arr[j - gap]; 
              
            arr[j] = temp; 
        } 
    } 
    return 0; 
} 

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  

int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high];
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++)  
    {  
        if (arr[j] < pivot)  
        {  
            i++; 
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  

void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  

        int pi = partition(arr, low, high);  

        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  
  
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    const int n1 = m - l + 1; 
    const int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1];
    int R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 

void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 

void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
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

void timeSelectionSort(int sort[], vector<float> sortWriter, ofstream& outfile, int n)
{
    clock_t time;
    time = clock();
    selectionSort(sort, n);
    time = clock() - time;
    float timer = (float)time/CLOCKS_PER_SEC;
    sortWriter.push_back(timer);
    cout << "    It took " << timer << " second(s) to selection sort the vector.\n";
}

void timeInsertionSort(int sort[], vector<float>& sortWriter, ofstream& outfile, int n)
{
    clock_t time;
    time = clock();
    insertionSort(sort, n);
    time = clock() - time;
    float timer = (float)time/CLOCKS_PER_SEC;
    sortWriter.push_back(timer);
    outfile << "    It took " << timer << " second(s) to insertion sort the vector.\n";
}

void timeShellSort(int sort[], vector<float>& sortWriter, ofstream& outfile, int n)
{
    clock_t time;
    time = clock();
    shellSort(sort, n);
    time = clock() - time;
    float timer = (float)time/CLOCKS_PER_SEC;
    sortWriter.push_back(timer);
    outfile << "    It took " << timer << " second(s) to shell sort the vector.\n";
}

void timeQuickSort(int sort[], vector<float>& sortWriter, ofstream& outfile, int n)
{
    int low = 0;
    int high = n - 1;
    clock_t time;
    time = clock();
    quickSort(sort, low, high);
    time = clock() - time;
    float timer = (float)time/CLOCKS_PER_SEC;
    sortWriter.push_back(timer);
    outfile << "    It took " << timer << " second(s) to quick sort the vector.\n";
}

void timeMergeSort(int sort[], vector<float>& sortWriter, ofstream& outfile, int n)
{
    int low = 0;
    int high = n - 1;
    clock_t time;
    time = clock();
    mergeSort(sort, low, high);
    time = clock() - time;
    float timer = (float)time/CLOCKS_PER_SEC;
    sortWriter.push_back(timer);
    outfile << "    It took " << timer << " second(s) to merge sort the vector.\n";
}

void timeHeapSort(int sort[], vector<float>& sortWriter, ofstream& outfile, int n)
{
    clock_t time;
    time = clock();
    heapSort(sort, n);
    time = clock() - time;
    float timer = (float)time/CLOCKS_PER_SEC;
    sortWriter.push_back(timer);
    outfile << "    It took " << timer << " second(s) to heap sort the vector.\n";
}
void timeSort(int mysort[], vector<float>& sortWriter, ofstream& outfile, int n)
{
    clock_t time;
    time = clock();
    sort(mysort, mysort + n);
    time = clock() - time;
    float timer = (float)time/CLOCKS_PER_SEC;
    sortWriter.push_back(timer);
    outfile << "    It took " << timer << " second(s) to algorithm sort the vector.\n";
}

void timeStableSort(int mysort[], vector<float>& sortWriter, ofstream& outfile, int n)
{
    clock_t time;
    mysort[0] = 1;
    cout << mysort[0] << endl;
    time = clock();
    stable_sort(mysort, mysort + n);
    time = clock() - time;
    float timer = (float)time/CLOCKS_PER_SEC;
    sortWriter.push_back(timer);
    outfile << "    It took " << timer << " second(s) to algorithm stable sort the vector.\n";
}

// void timeSequentialSearch(int sort[], int key, vector<float>& searchWriter, ofstream& outfile)
// {
//     clock_t sec;
//     if(key == 0) {
//         key = 1;
//     }
//     sec = clock();
//     int searchIndex = sequentialSearch(sort, key);
//     sec = clock() - sec;
//     float timer = (float)sec/CLOCKS_PER_SEC;
//     searchWriter.push_back(timer);
//     outfile << "    It took " << timer << " second(s) to sequential search for the key.\n";
// }

// void timeBinarySearch(vector<int>& mysort, int key, vector<float>& searchWriter, ofstream& outfile)
// {
//     clock_t sec;
//     if(key == 0) {
//         key = 1;
//     }
//     sort(mysort.begin(), mysort.end());
//     sec = clock();
//     int searchIndex = binarySearch(mysort, key);
//     sec = clock() - sec;
//     float timer = (float)sec/CLOCKS_PER_SEC;
//     searchWriter.push_back(timer);
//     outfile << "    It took " << timer << " second(s) to binary search for the key.\n";
// }

// void timeBinarySearchTree(vector<int>& mysort, int key, vector<float>& searchWriter, ofstream& outfile)
// {
//     sort(mysort.begin(), mysort.end());
//     BST<int> tree;
//     for(int i=0; i < mysort.size(); i++) {
//         tree.insert(mysort.at(i));
//     }
//     Node<int> *n;
//     clock_t sec;
//     if(key == 0) {
//         key = 1;
//     }
//     sort(mysort.begin(), mysort.end());
//     sec = clock();
//     Node<int> *searchIndex = binarySearchTree(tree, key, n);
//     sec = clock() - sec;
//     float timer = (float)sec/CLOCKS_PER_SEC;
//     searchWriter.push_back(timer);
//     outfile << "    It took " << timer << " second(s) to binary tree search for the key.\n";
// }

int main()
{
    //ios::sync_with_stdio(false);
    srand(time(NULL));
    ofstream outfile;
    outfile.open("timeComplexity2.txt");
    vector<float> averageOH, averageFH, averageOM;


    // if(i <= 9) {
    //     cout << "Running." << endl;
    // }

    vector<float> searchWriterOH, searchWriterFH, searchWriterOM;
    vector<float> sortWriterOH, sortWriterFH, sortWriterOM;
    float averageSortOH, averageSortFH, averageSortOM, addSortOH, addSortFH, addSortOM, averageSearchOH, averageSearchFH, averageSearchOM, addSearchOH, addSearchFH, addSearchOM;
    // reading random numbers into a file
    // five();
    // onehund();
    // fivehund();
    // onemil();
    // reading the file into a vector

    // int vecfive[]; // test vector, so i can see a representation of time...
    //int vecOM[1000000];
    //int vecFH[500000];
    //int vecOH[100000];

     // test vector, so i can see a representation of time...
    int numOfNums;
    for(int j = 0; j < 3; j++) {
        outfile << j+ 1 << "." << endl;
        if(j = 0){
            numOfNums = 100000;
            onehund();
        }
        else if(j = 1) {
            numOfNums = 500000;
            fivehund();
        }
        else if(j = 2) {
            numOfNums = 1000000;
            onemil();
        }
        int vecfive[numOfNums]; 
        if(numOfNums = 100000) {
            readinonehund(vecfive);
        }
        else if(numOfNums = 500000) {
            readinfivehund(vecfive);
        }
        else if(numOfNums = 1000000)
        {
            readinonemil(vecfive);
        }
        for(int i = 0; i < 10; i++) {
            int n = sizeof(vecfive)/sizeof(vecfive[0]);
            // timeBubbleSort(vecfive, sortWriterOH, outfile, n);
            // timeSelectionSort(vecfive, sortWriterOH, outfile, n);
            // timeInsertionSort(vecfive, sortWriterOH, outfile, n);
            timeShellSort(vecfive, sortWriterOH, outfile, n);
            timeQuickSort(vecfive, sortWriterOH, outfile, n);
            timeMergeSort(vecfive, sortWriterOH, outfile, n);
            timeHeapSort(vecfive, sortWriterOH, outfile, n);
            timeSort(vecfive, sortWriterOH, outfile, n);
            timeStableSort(vecfive, sortWriterOH, outfile, n);
        }
    }
    // int keyfive = rand()%sizeof(vecfive);
    // int keyOneHund = rand()%sizeof(vecOH);
    // int keyFiveHund = rand()%sizeof(vecFH);
    // int keyOneMil = rand()%sizeof(vecOM);

    // int n = sizeof(vecfive)/sizeof(vecfive[0]);

    // timeBubbleSort(vecfive, sortWriterOH, outfile, n);
    // timeSelectionSort(vecfive, sortWriterOH, outfile, n);
    // timeInsertionSort(vecfive, sortWriterOH, outfile, n);
    // timeShellSort(vecfive, sortWriterOH, outfile, n);
    // timeQuickSort(vecfive, sortWriterOH, outfile, n);
    // timeMergeSort(vecfive, sortWriterOH, outfile, n);
    // timeHeapSort(vecfive, sortWriterOH, outfile, n);
    // timeSort(vecfive, sortWriterOH, outfile, n);
    // timeStableSort(vecfive, sortWriterOH, outfile, n);
    // timeSequentialSearch(vecfive, keyfive, searchWriterOH, outfile);
    // timeBinarySearch(vecfive, keyfive, searchWriterOH, outfile);
    // timeBinarySearchTree(vecfive, keyfive, searchWriterOH, outfile);

    // addSortOH = sortWriterOH.at(0) + sortWriterOH.at(1) + sortWriterOH.at(2) + sortWriterOH.at(3) + sortWriterOH.at(4) + sortWriterOH.at(5) + sortWriterOH.at(6) + sortWriterOH.at(7) + sortWriterOH.at(8);
    // averageSortOH = addSortOH/9;

    // addSearchOH = searchWriterOH.at(0) + searchWriterOH.at(1) + searchWriterOH.at(2);
    // averageSearchOH = addSearchOH/3;

    // averageOH.push_back(averageSortOH);

    // outfile << "    The average of the sorting algorithms is " << averageSortOH << ".\n";
    // outfile << "    The average of the searching algorithms is " << averageSearchOH << ".\n";

    // timeBubbleSort(vecOH, sortWriterOH, outfile);
    // timeSelectionSort(vecOH, sortWriterOH, outfile);
    // timeInsertionSort(vecOH, sortWriterOH, outfile);
    // timeShellSort(vecOH, sortWriterOH, outfile);
    // timeQuickSort(vecOH, sortWriterOH, outfile);
    // timeMergeSort(vecOH, sortWriterOH, outfile);
    // timeHeapSort(vecOH, sortWriterOH, outfile);
    // timeSort(vecOH, sortWriterOH, outfile);
    // timeStableSort(vecOH, sortWriterOH, outfile);
    // // timeSequentialSearch(vecOH, keyfive, searchWriterOH, outfile);
    // // timeBinarySearch(vecOH, keyfive, searchWriterOH, outfile);
    // // timeBinarySearchTree(vecOH, keyfive, searchWriterOH, outfile);

    // addSortOH = sortWriterOH.at(0) + sortWriterOH.at(1) + sortWriterOH.at(2) + sortWriterOH.at(3) + sortWriterOH.at(4) + sortWriterOH.at(5) + sortWriterOH.at(6) + sortWriterOH.at(7) + sortWriterOH.at(8);
    // averageSortOH = addSortOH/9;

    // addSearchOH = searchWriterOH.at(0) + searchWriterOH.at(1) + searchWriterOH.at(2);
    // averageSearchOH = addSearchOH/3;

    // outfile << "    The average of the sorting algorithms is " << averageSortOH << ".\n";
    // outfile << "    The average of the searching algorithms is " << averageSearchOH << ".\n";

    // timeBubbleSort(vecFH, sortWriterFH, outfile);
    // timeSelectionSort(vecFH, sortWriterFH, outfile);
    // timeInsertionSort(vecFH, sortWriterFH, outfile);
    // timeShellSort(vecFH, sortWriterFH, outfile);
    // timeQuickSort(vecFH, sortWriterFH, outfile);
    // timeMergeSort(vecFH, sortWriterFH, outfile);
    // timeHeapSort(vecFH, sortWriterFH, outfile);
    // timeSort(vecFH, sortWriterFH, outfile);
    // timeStableSort(vecFH, sortWriterFH, outfile);
    // timeSequentialSearch(vecFH, keyfive, searchWriterFH, outfile);
    // timeBinarySearch(vecFH, keyfive, searchWriterFH, outfile);
    // timeBinarySearchTree(vecFH, keyfive, searchWriterFH, outfile);

    // addSortFH = sortWriterFH.at(0) + sortWriterFH.at(1) + sortWriterFH.at(2) + sortWriterFH.at(3) + sortWriterFH.at(4) + sortWriterFH.at(5) + sortWriterFH.at(6) + sortWriterFH.at(7) + sortWriterFH.at(8);
    // averageSortFH = addSortFH/9;

    // addSearchFH = searchWriterFH.at(0) + searchWriterFH.at(1) + searchWriterFH.at(2);
    // averageSearchFH = addSearchFH/3;

    // outfile << "    The average of the sorting algorithms is " << averageSortFH << ".\n";
    // outfile << "    The average of the searching algorithms is " << averageSearchFH << ".\n";

    // timeBubbleSort(vecOM, sortWriterOM, outfile);
    // timeSelectionSort(vecOM, sortWriterOM, outfile);
    // timeInsertionSort(vecOM, sortWriterOM, outfile);
    // timeShellSort(vecOM, sortWriterOM, outfile);
    // timeQuickSort(vecOM, sortWriterOM, outfile);
    // timeMergeSort(vecOM, sortWriterOM, outfile);
    // timeHeapSort(vecOM, sortWriterOM, outfile);
    // timeSort(vecOM, sortWriterOM, outfile);
    // timeStableSort(vecOM, sortWriterOM, outfile);
    // timeSequentialSearch(vecOM, keyfive, searchWriterOM, outfile);
    // timeBinarySearch(vecOM, keyfive, searchWriterOM, outfile);
    // timeBinarySearchTree(vecOM, keyfive, searchWriterOM, outfile);

    // addSortOM = sortWriterOM.at(0) + sortWriterOM.at(1) + sortWriterOM.at(2) + sortWriterOM.at(3) + sortWriterOM.at(4) + sortWriterOM.at(5) + sortWriterOM.at(6) + sortWriterOM.at(7) + sortWriterOM.at(8);
    // averageSortOM = addSortOM/9;

    // addSearchOM = searchWriterOM.at(0) + searchWriterOM.at(1) + searchWriterOM.at(2);
    // averageSearchOM = addSearchOM/3;

    // outfile << "    The average of the sorting algorithms is " << averageSortOM << ".\n";
    // outfile << "    The average of the searching algorithms is " << averageSearchOM << ".\n";


    // sort(averageOH.begin(), averageOH.end());
    // sort(averageFH.begin(), averageFH.end());
    // sort(averageOM.begin(), averageOM.end());

    // for(int p = 0; p < averageOH.size(); p++) {
    //     cout << averageOH.at(p) << endl;;
    // }
    outfile.close();
    return 0;
}
