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
        for (int i = 0; i < 5000; i++){
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
        for (int i = 0; i < 100000; i++){
            value = rand() % 100 + 1;
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
        for (int i = 0; i < 500000; i++){
            value = rand() % 100 + 1;
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
        for (int i = 0; i < 1000000; i++){
            value = rand() % 100 + 1;
            myfile << value << " ";
        }
        myfile.close();
    }
    else{
        cout << "Unable to open file" << endl;
    }
}

vector<int> readinfive()
{
    ifstream infile;
    vector<int> temp;
    int number, i;
    infile.open("five.txt");
    infile.clear();
    while(infile >> number){
        temp.push_back(number);
    }
    return temp;
}

vector<int> readinonehund()
{
    ifstream infile;
    vector<int> temp;
    int number, i;
    infile.open("onehund.txt");
    infile.clear();
    while(infile >> number){
        temp.push_back(number);
    }
    return temp;
}

vector<int> readinfivehund()
{
    ifstream infile;
    vector<int> temp;
    int number, i;
    infile.open("fivehund.txt");
    infile.clear();
    while(infile >> number){
        temp.push_back(number);
    }
    return temp;
}

vector<int> readinonemil()
{
    ifstream infile;
    vector<int> temp;
    int number, i;
    infile.open("onemil.txt");
    infile.clear();
    while(infile >> number){
        temp.push_back(number);
    }
    return temp;
}

void bubbleSort(vector<int>& s)
{
      bool swapp = true;
      while(swapp){
        swapp = false;
        for (int i = 0; i < s.size()-1; i++) {
            if (s[i]>s[i+1] ){
                s[i] += s[i+1];
                s[i+1] = s[i] - s[i+1];
                s[i] -= s[i+1];
                swapp = true;
            }
        }
    }
}

void selectionSort(vector<int>& s)
{
    for (int i = 0; i < s.size(); i++){  
        int min = i;  
        for (int j = i+1; j < s.size(); j++){
            if (s.at(j) < s.at(min)) {
                min = j;  
            }
        }
        swap(s.at(min), s.at(i));  
    }
}

void insertionSort(vector<int>& s)
{
    for (auto i = s.begin(); i != s.end(); i++) 
    {         
        auto const insertion_point =  
                upper_bound(s.begin(), i, *i); 
          
        rotate(insertion_point, i, i+1);         
    } 
}

void shellSort(vector<int>& s)
{
    for (int gap = s.size()/2; gap > 0; gap /= 2) 
    { 
        for (int i = gap; i < s.size(); i += 1) 
        { 
            int temp = s.at(i); 
            int j;             
            for (j = i; j >= gap && s.at(j - gap) > temp; j -= gap){
                s.at(j) = s.at(j - gap); 
            }
            s.at(j) = temp; 
        } 
    } 
}

int partition(vector<int> &values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    int pivotValue = values[pivotIndex];
    int i = left, j = right;
    int temp;
    while(i <= j) {
        while(values[i] < pivotValue) {
            i++;
        }
        while(values[j] > pivotValue) {
            j--;
        }
        if(i <= j) {
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}

void quickSort(vector<int> &values, int left, int right) {
    if(left < right) {
        int pivotIndex = partition(values, left, right);
        quickSort(values, left, pivotIndex - 1);
        quickSort(values, pivotIndex, right);
    }
}

void merge(std::vector<int> &arr, int start, int middle, int end) {

    std::vector<int> leftArray(middle - start + 1);
    std::vector<int> rightArray(end - middle);

    for (int i = 0; i < leftArray.size(); ++i)
        leftArray[i] = arr[start + i];

    for (int i = 0; i < rightArray.size(); ++i)
        rightArray[i] = arr[middle + 1 + i];

    int leftIndex = 0, rightIndex = 0;
    int currentIndex = start;
    while (leftIndex < leftArray.size() && rightIndex < rightArray.size()) {
        if (leftArray[leftIndex] <= rightArray[rightIndex]) {
            arr[currentIndex] = leftArray[leftIndex];
            leftIndex++;
        } else {
            arr[currentIndex] = rightArray[rightIndex];
            rightIndex++;
        }
        currentIndex++;
    }

    while (leftIndex < leftArray.size()) arr[currentIndex++] = leftArray[leftIndex++];

    while (rightIndex < rightArray.size()) arr[currentIndex++] = rightArray[rightIndex++];
}

void mergeSort(std::vector<int> &arr, int start, int end) {
    if (start < end) {
        int middle = (start + end) / 2;

        mergeSort(arr, start, middle);
        mergeSort(arr, middle + 1, end);
        merge(arr, start, middle, end);
    }
}

void heapify(std::vector<int> &s, int size, int i) {
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && s[left] > s[max])
        max = left;

    if (right < size && s[right] > s[max])
        max = right;

    if (max != i) {
        int temp = s[i];
        s[i] = s[max];
        s[max] = temp;

        heapify(s, size, max);
    }
}

void heapSort(vector<int> &s) {
    int size = s.size();

    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(s, size, i);
    }

    for (int i = size - 1; i >= 0; i--) {
        int temp = s[0];
        s[0] = s[i];
        s[i] = temp;

        heapify(s, i, 0);
    }
}

void printVector(vector<int> a)
{
    for(int i = 0; i < a.size(); i++){
        cout << a.at(i) << " ";
    }
}

int sequentialSearch(const vector<int> & v, int key) {
    int index = 0;
    while (index < v.size()) {
        if (v[index] == key)
            return index;
        else
            index ++;
    }
    return -1;
}

int binarySearch(const vector<int> &v, int key) {
    int low = 0;
    int high = v.size()-1;
    while (low <= high) { 
        int mid = (low+high)/2;
        if (v[mid] == key) 
            return mid;
        else if (v[mid] > key) 
            high = mid - 1;
        else 
            low = mid + 1;
    }
    return -1;
}

Node<int> *binarySearchTree(BST<int> &tree, int key, Node<int> *n)
{
    n = tree.find(key);
    return n;
}

void timeBubbleSort(vector<int> sort, vector<float>& sortWriter, ofstream& outfile)
{
    clock_t time;
    time = clock();
    bubbleSort(sort);
    time = clock() - time;
    float timer = (float)time/CLOCKS_PER_SEC;
    sortWriter.push_back(timer);
    outfile << "    It took " << timer << " second(s) to bubble sort the vector.\n";
}

void timeSelectionSort(vector<int> sort, vector<float>& sortWriter, ofstream& outfile)
{
    clock_t time;
    time = clock();
    selectionSort(sort);
    time = clock() - time;
    float timer = (float)time/CLOCKS_PER_SEC;
    sortWriter.push_back(timer);
    outfile << "    It took " << timer << " second(s) to selection sort the vector.\n";
}

void timeInsertionSort(vector<int> sort, vector<float>& sortWriter, ofstream& outfile)
{
    clock_t time;
    time = clock();
    insertionSort(sort);
    time = clock() - time;
    float timer = (float)time/CLOCKS_PER_SEC;
    sortWriter.push_back(timer);
    outfile << "    It took " << timer << " second(s) to insertion sort the vector.\n";
}

void timeShellSort(vector<int> sort, vector<float>& sortWriter, ofstream& outfile)
{
    clock_t time;
    time = clock();
    shellSort(sort);
    time = clock() - time;
    float timer = (float)time/CLOCKS_PER_SEC;
    sortWriter.push_back(timer);
    outfile << "    It took " << timer << " second(s) to shell sort the vector.\n";
}

void timeQuickSort(vector<int> sort, vector<float>& sortWriter, ofstream& outfile)
{
    int low = 0;
    int high = sort.size() - 1;
    clock_t time;
    time = clock();
    quickSort(sort, low, high);
    time = clock() - time;
    float timer = (float)time/CLOCKS_PER_SEC;
    sortWriter.push_back(timer);
    outfile << "    It took " << timer << " second(s) to quick sort the vector.\n";
}

void timeMergeSort(vector<int> sort, vector<float>& sortWriter, ofstream& outfile)
{
    int low = 0;
    int high = sort.size() - 1;
    clock_t time;
    time = clock();
    mergeSort(sort, low, high);
    time = clock() - time;
    float timer = (float)time/CLOCKS_PER_SEC;
    sortWriter.push_back(timer);
    outfile << "    It took " << timer << " second(s) to merge sort the vector.\n";
}

void timeHeapSort(vector<int> sort, vector<float>& sortWriter, ofstream& outfile)
{
    clock_t time;
    time = clock();
    heapSort(sort);
    time = clock() - time;
    float timer = (float)time/CLOCKS_PER_SEC;
    sortWriter.push_back(timer);
    outfile << "    It took " << timer << " second(s) to heap sort the vector.\n";
}
void timeSort(vector<int> mysort, vector<float>& sortWriter, ofstream& outfile)
{
    clock_t time;
    time = clock();
    sort(mysort.begin(), mysort.end());
    time = clock() - time;
    float timer = (float)time/CLOCKS_PER_SEC;
    sortWriter.push_back(timer);
    outfile << "    It took " << timer << " second(s) to algorithm sort the vector.\n";
}

void timeStableSort(vector<int> mysort, vector<float>& sortWriter, ofstream& outfile)
{
    clock_t time;
    time = clock();
    stable_sort(mysort.begin(), mysort.end());
    time = clock() - time;
    float timer = (float)time/CLOCKS_PER_SEC;
    sortWriter.push_back(timer);
    outfile << "    It took " << timer << " second(s) to algorithm stable sort the vector.\n";
}

void timeSequentialSearch(vector<int>& sort, int key, vector<float>& searchWriter, ofstream& outfile)
{
    clock_t sec;
    if(key == 0) {
        key = 1;
    }
    sec = clock();
    int searchIndex = sequentialSearch(sort, key);
    sec = clock() - sec;
    float timer = (float)sec/CLOCKS_PER_SEC;
    searchWriter.push_back(timer);
    outfile << "    It took " << timer << " second(s) to sequential search for the key.\n";
}

void timeBinarySearch(vector<int>& mysort, int key, vector<float>& searchWriter, ofstream& outfile)
{
    clock_t sec;
    if(key == 0) {
        key = 1;
    }
    sort(mysort.begin(), mysort.end());
    sec = clock();
    int searchIndex = binarySearch(mysort, key);
    sec = clock() - sec;
    float timer = (float)sec/CLOCKS_PER_SEC;
    searchWriter.push_back(timer);
    outfile << "    It took " << timer << " second(s) to binary search for the key.\n";
}

void timeBinarySearchTree(vector<int>& mysort, int key, vector<float>& searchWriter, ofstream& outfile)
{
    sort(mysort.begin(), mysort.end());
    BST<int> tree;
    for(int i=0; i < mysort.size(); i++) {
        tree.insert(mysort.at(i));
    }
    Node<int> *n;
    clock_t sec;
    if(key == 0) {
        key = 1;
    }
    sort(mysort.begin(), mysort.end());
    sec = clock();
    Node<int> *searchIndex = binarySearchTree(tree, key, n);
    sec = clock() - sec;
    float timer = (float)sec/CLOCKS_PER_SEC;
    searchWriter.push_back(timer);
    outfile << "    It took " << timer << " second(s) to binary tree search for the key.\n";
}

int main()
{
    ios::sync_with_stdio(false);
    srand(time(NULL));
    ofstream outfile;
    outfile.open("timeComplexity.txt");
    outfile.clear();
    //vector<float> averageOH, averageFH, averageOM;


    // vector<float> searchWriter, searchWriter, searchWriter;
    // vector<float> sortWriter, sortWriter, sortWriter;
    // float averageSortOH, averageSortFH, averageSortOM, addSortOH, addSortFH, addSortOM, averageSearchOH, averageSearchFH, averageSearchOM, addSearchOH, addSearchFH, addSearchOM;

    for(int j = 0; j < 3; j++) {
        vector<float> searchWriter, sortWriter;
        vector<int> vec;
        int key;
        outfile << j << endl;
        if(j != 1 && j != 2) {
            outfile << "100000 Values:" <<  endl;
            for(int i = 0; i < 10; i++) {
                outfile << "    Run number " << i + 1 << ":" << endl;
                onehund();
                vec = readinonehund();
                key = rand()%100 + 1;
                timeBubbleSort(vec, sortWriter, outfile);
                timeSelectionSort(vec, sortWriter, outfile);
                timeInsertionSort(vec, sortWriter, outfile);
                timeShellSort(vec, sortWriter, outfile);
                timeQuickSort(vec, sortWriter, outfile);
                timeMergeSort(vec, sortWriter, outfile);
                timeHeapSort(vec, sortWriter, outfile);
                timeSort(vec, sortWriter, outfile);
                timeStableSort(vec, sortWriter, outfile);
                timeSequentialSearch(vec, key, searchWriter, outfile);
                timeBinarySearch(vec, key, searchWriter, outfile);
                timeBinarySearchTree(vec, key, searchWriter, outfile);
            }
        }
        else if(j != 0 && j != 2) {
            outfile << "500000 Values:" << endl;
            for(int i = 0; i < 10; i++) {
                outfile << "    Run number " << i + 1 << ":" << endl;
                fivehund();
                vec = readinfivehund();
                key = rand()%100 + 1;
                timeBubbleSort(vec, sortWriter, outfile);
                timeSelectionSort(vec, sortWriter, outfile);
                timeInsertionSort(vec, sortWriter, outfile);
                timeShellSort(vec, sortWriter, outfile);
                timeQuickSort(vec, sortWriter, outfile);
                timeMergeSort(vec, sortWriter, outfile);
                timeHeapSort(vec, sortWriter, outfile);
                timeSort(vec, sortWriter, outfile);
                timeStableSort(vec, sortWriter, outfile);
                timeSequentialSearch(vec, key, searchWriter, outfile);
                timeBinarySearch(vec, key, searchWriter, outfile);
                timeBinarySearchTree(vec, key, searchWriter, outfile);

            }
        }
        else if(j != 0 && j != 1) {
            outfile << "1000000 Values:" << endl;
            for(int i = 0; i < 10; i++) {
                outfile << "    Run number " << i + 1 << ":" << endl;
                onemil();
                vec = readinonemil();
                key = rand()%100 + 1;
                timeBubbleSort(vec, sortWriter, outfile);
                timeSelectionSort(vec, sortWriter, outfile);
                timeInsertionSort(vec, sortWriter, outfile);
                timeShellSort(vec, sortWriter, outfile);
                timeQuickSort(vec, sortWriter, outfile);
                timeMergeSort(vec, sortWriter, outfile);
                timeHeapSort(vec, sortWriter, outfile);
                timeSort(vec, sortWriter, outfile);
                timeStableSort(vec, sortWriter, outfile);
                timeSequentialSearch(vec, key, searchWriter, outfile);
                timeBinarySearch(vec, key, searchWriter, outfile);
                timeBinarySearchTree(vec, key, searchWriter, outfile);

            }
        }
        
    }

    // addSortOH = sortWriter.at(0) + sortWriter.at(1) + sortWriter.at(2) + sortWriter.at(3) + sortWriter.at(4) + sortWriter.at(5) + sortWriter.at(6) + sortWriter.at(7) + sortWriter.at(8);
    // averageSortOH = addSortOH/9;

    // addSearchOH = searchWriter.at(0) + searchWriter.at(1) + searchWriter.at(2);
    // averageSearchOH = addSearchOH/3;

    // averageOH.push_back(averageSortOH);

    // outfile << "    The average of the sorting algorithms is " << averageSortOH << ".\n";
    // outfile << "    The average of the searching algorithms is " << averageSearchOH << ".\n";

    // sort(averageOH.begin(), averageOH.end());
    // sort(averageFH.begin(), averageFH.end());
    // sort(averageOM.begin(), averageOM.end());

    // for(int p = 0; p < averageOH.size(); p++) {
    //     cout << averageOH.at(p) << endl;;
    // }
    outfile.close();
    return 0;
}
