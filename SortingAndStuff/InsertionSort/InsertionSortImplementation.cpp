#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n){ // This function sorts the array in increasing order
    for (int i=1; i<n; i++){ // it starts from the second element of the array because the first element is already sorted
        int key = arr[i]; //key is element to be compared with the elements before it
        int j = i-1; // j is the index of the element before the key element
        while (j>=0 && arr[j]>key){ // this loop compares the key element with the elements before it
            arr[j+1]=arr[j]; // if key is smaller than j, the element before it is shifted to the right by making 
                //the element at j+1 equal to the element at j, and j becomes j-1, so the value of j is decremented
            j=j-1; // the index is decremented to compare the key element with the element before the previous element
        }
        arr[j+1] = key; // the key element is placed in the correct position
    }
};

void printArr(int arr[], int n){
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
};

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    printArr(arr, n);
    InsertionSort(arr, n);
    cout << "Sorted array: ";
    printArr(arr, n);
    return 0;
}

// complexity of insertion sort is O(n^2) because there are two nested loops in the function.

// example:
// Original array: 64 34 25 12 22 11 90
// key = 34
// j = 0
// j >= 0 && arr[0] > 34
// arr[1] = 64
// arr= 64 64 25 12 22 11 90
// j = -1 -> loop ends
// arr[0] = 34
// arr= 34 64 25 12 22 11 90

// key = 25
// j = 1
// j >= 0 && arr[1] > 25
// arr[2] = 64
// arr= 34 64 64 12 22 11 90
// j = 0
// j >= 0 && arr[0] > 25
// arr[1] = 34
// arr= 34 34 64 12 22 11 90
// j = -1 -> loop ends
// arr[0] = 25
// arr= 25 34 64 12 22 11 90
// and so on ...

