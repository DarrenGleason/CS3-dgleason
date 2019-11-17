#include <random>
#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

void five()
{
    srand(time(NULL));
    int value = 0;
    ofstream myfile;
    myfile.open("five.txt", ofstream::out | ofstream::trunc);
    if(myfile.is_open()){
        for (int i = 0; i < 5000; i++){
            value = rand() % 100 + 1;
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
    // One by one move boundary of unsorted subarray  
    for (int i = 0; i < s.size(); i++){  
        // Find the minimum element in unsorted array  
        int min = i;  
        for (int j = i+1; j < s.size(); j++){
            if (s.at(j) < s.at(min)) {
                min = j;  
            }
        }
        // Swap the found minimum element with the first element  
        swap(s.at(min), s.at(i));  
    }
}

void insertionSort(vector<int>& s)
{
    for (auto i = s.begin(); i != s.end(); i++) 
    {         
        // Searching the upper bound, i.e., first  
        // element greater than *it from beginning 
        auto const insertion_point =  
                upper_bound(s.begin(), i, *i); 
          
        // Shifting the unsorted part 
        rotate(insertion_point, i, i+1);         
    } 
}

void shellSort(vector<int>& s)
{
    for (int gap = s.size()/2; gap > 0; gap /= 2) 
    { 
        // Do a gapped insertion sort for this gap size. 
        // The first gap elements a[0..gap-1] are already in gapped order 
        // keep adding one more element until the entire array is 
        // gap sorted  
        for (int i = gap; i < s.size(); i += 1) 
        { 
            // add a[i] to the elements that have been gap sorted 
            // save a[i] in temp and make a hole at position i 
            int temp = s.at(i); 
  
            // shift earlier gap-sorted elements up until the correct  
            // location for a[i] is found 
            int j;             
            for (j = i; j >= gap && s.at(j - gap) > temp; j -= gap){
                s.at(j) = s.at(j - gap); 
            }
            //  put temp (the original a[i]) in its correct location 
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

    // fill in left array
    for (int i = 0; i < leftArray.size(); ++i)
        leftArray[i] = arr[start + i];

    // fill in right array
    for (int i = 0; i < rightArray.size(); ++i)
        rightArray[i] = arr[middle + 1 + i];

    /* Merge the temp arrays */

    // initial indexes of first and second subarrays
    int leftIndex = 0, rightIndex = 0;

    // the index we will start at when adding the subarrays back into the main array
    int currentIndex = start;

    // compare each index of the subarrays adding the lowest value to the currentIndex
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

    // copy remaining elements of leftArray[] if any
    while (leftIndex < leftArray.size()) arr[currentIndex++] = leftArray[leftIndex++];

    // copy remaining elements of rightArray[] if any
    while (rightIndex < rightArray.size()) arr[currentIndex++] = rightArray[rightIndex++];
}

void mergeSort(std::vector<int> &arr, int start, int end) {
    // base case
    if (start < end) {
        // find the middle point
        int middle = (start + end) / 2;

        mergeSort(arr, start, middle); // sort first half
        mergeSort(arr, middle + 1, end);  // sort second half

        // merge the sorted halves
        merge(arr, start, middle, end);
    }
}

void heapify(vector<int> s, int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && s.at(l) > s.at(largest)) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && s.at(r) > s.at(largest)) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) { 
        swap(s.at(i), s.at(largest)); 
  
        // Recursively heapify the affected sub-tree 
        heapify(s, n, largest); 
    } 
} 

void heapSort(vector<int> s, int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n/2-1; i >= 0; i--) 
        heapify(s, n, i); 
  
    // One by one extract an element from heap 
    for (int i = n - 1; i >= 0; i--) { 
        // Move current root to end 
        swap(s.at(0), s.at(i)); 
  
        // call max heapify on the reduced heap 
        heapify(s, i, 0); 
    } 
} 

void printVector(vector<int> a)
{
    for(int i = 0; i < a.size(); i++){
        cout << a.at(i) << " ";
    }
}

void timeBubbleSort(vector<int> sort)
{
    clock_t time;
    time = clock();
    bubbleSort(sort);
    time = clock() - time;
    cout << "\nIt took " << (float)time/CLOCKS_PER_SEC << " second(s) to bubble sort the vector." << endl;
}

void timeSelectionSort(vector<int> sort)
{
    clock_t time;
    time = clock();
    selectionSort(sort);
    time = clock() - time;
    cout << "\nIt took " << (float)time/CLOCKS_PER_SEC << " second(s) to selection sort the vector." << endl;
}

void timeInsertionSort(vector<int> sort)
{
    clock_t time;
    time = clock();
    insertionSort(sort);
    time = clock() - time;
    cout << "\nIt took " << (float)time/CLOCKS_PER_SEC << " second(s) to insertion sort the vector." << endl;
}

void timeShellSort(vector<int> sort)
{
    clock_t time;
    time = clock();
    shellSort(sort);
    time = clock() - time;
    cout << "\nIt took " << (float)time/CLOCKS_PER_SEC << " second(s) to shellsort the vector." << endl;
}

void timeQuickSort(vector<int> sort)
{
    int low = 0;
    int high = sort.size() - 1;
    clock_t time;
    time = clock();
    quickSort(sort, low, high);
    time = clock() - time;
    cout << "\nIt took " << (float)time/CLOCKS_PER_SEC << " second(s) to quicksort the vector." << endl;
}

void timeMergeSort(vector<int> sort)
{
    int low = 0;
    int high = sort.size() - 1;
    clock_t time;
    time = clock();
    mergeSort(sort, low, high);
    time = clock() - time;
    cout << "\nIt took " << (float)time/CLOCKS_PER_SEC << " second(s) to merge sort the vector." << endl;
}

void timeHeapSort(vector<int> sort)
{
    clock_t time;
    int n = sizeof(sort)/sizeof(sort.at(0));
    cout << sizeof(sort) << " " << sizeof(sort.at(0)) << " " << sizeof(sort)/sizeof(sort.at(0)) << " Yeah" << endl;
    time = clock();
    heapSort(sort, n);
    time = clock() - time;
    cout << "\nIt took " << (float)time/CLOCKS_PEeR_SEC << " second(s) to heap sort the vector." << endl;
    printVector(sort);
}

int main()
{
    // reading random numbers into a file
    five();
    onehund();
    fivehund();
    onemil();
    // reading the file into a vector
    vector<int> vecfive = readinfive(); // test vector, so i can see a representation of time...
    vector<int> vecOM = readinonemil();
    vector<int> vecFH = readinfivehund();
    vector<int> vecOH = readinonehund();

    timeBubbleSort(vecfive);
    timeSelectionSort(vecfive);
    timeInsertionSort(vecfive);
    timeShellSort(vecfive);
    timeQuickSort(vecfive);
    timeMergeSort(vecfive);
    timeHeapSort(vecfive);
    return 0;
}
