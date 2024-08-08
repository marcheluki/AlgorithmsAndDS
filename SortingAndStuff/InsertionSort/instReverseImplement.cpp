#include <iostream>
using namespace std;

void InsertionSortDecrease(int arr[], int n){ // This function sorts the array in decreasing order
    for(int i=1;i<n;i++){ //  it starts from the second element of the array because the first element is already sorted
        
        int key= arr[i]; // key is the element that is to be compared with the elements before it
        int j=i-1; // j is the index of the element before the key element
        while(j>=0 && arr[j]<key){ // this loop compares the key element with the elements before it
            arr[j+1]=arr[j]; // if the key element is smaller than the element before it, the element before it is shifted to the right
            j = j-1; // the index is decremented to compare the key element with the element before the previous element
        }
        arr[j+1]=key; // the key element is placed in the correct position
    }
}



void printArr(int arr[], int n){
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
};
int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    printArr(arr, n);
    InsertionSortDecrease(arr, n);
    cout << "Sorted array: ";
    printArr(arr, n);
    return 0;
}