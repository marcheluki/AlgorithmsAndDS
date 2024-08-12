#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


void merge(vector<double> &A, int p, int q, int r){ 
 // we got p from the first index of the array, q from the middle index of the array and r from the last index of the array
    const int n1 = q-p+1; //size of left array calculated by subtracting the first index from the middle index
    // this is done because the left array starts from the first index and ends at the middle index
    const int n2 = r-q;  //size of right array calculated by subtracting the middle index from the last index

    double* L = new double[n1]; //the double* L is a pointer to the first element of the left array
    //the new double n1 is a pointer to the first element of the left array. we use new to allocate memory for the left array
    double* R = new double[n2]; //the double* R is a pointer to the first element of the right array
    // double R is a pointer to the first element of the right array and this is equal to new double n2 which is a pointer to the first element of the right array

    for (int i = 0;i<n1;i++){ //this loop is used to copy the elements of the left array to the left array
        L[i] = A[p+i]; //a[p+i] is the element of the left array and it is copied to the left array in the ith position
    }
    for (int j = 0;j<n2;j++){ //this loop is used to copy the elements of the right array to the right array
        R[j] = A[q+1+j];  //a[q+1+j] is the element of the right array and it is copied to the right array in the jth position
        // q+1 is the first element of the right array and j is the index of the element of the right array
        // so we do q+1+j to get the element of the right array
    }

    int i=0, j=0, k=p; // i is the index of the left array, j is the index of the right array and k is the index of the array

    while(i<n1 && j<n2){ //this loop is used to compare the elements of the left and right arrays
        if (L[i] <= R[j]){ //if the element of the left array is less than or equal to the element of the right array
            A[k] = L[i]; //the element of the left array is copied to the array
            i++; //the index of the left array is incremented
        }else{
            A[k] = R[j]; //if the element of the right array is less than the element of the left array, the element of the right array is copied to the array
            j++;//the index of the right array is incremented
        }
        k++;//the index of the array is incremented
    }

    while (i< n1){ //this loop is used to copy the remaining elements of the left array to the array
        A[k] = L[i]; //the element of the left array is copied to the array
        i++; //the index of the left array is incremented
        k++; //the index of the array is incremented
    }

    while(j<n2){ //this loop is used to copy the remaining elements of the right array to the array
        A[k] = R[j]; //the element of the right array is copied to the array
        j++; //the index of the right array is incremented
        k++; //the index of the array is incremented
    }

    delete[] L; //we use delete to deallocate the memory of the left array
    delete[] R; //we use delete to deallocate the memory of the right array

}

void mergeSort(vector<double> &A, int p, int r){ //this function is used to sort the array
    //we get p from the first index of the array and r from the last index of the array

    if (p>=r){ //if the first index is greater than or equal to the last index, we return
        return; //we return because the array is already sorted
    }
    int q = (p+r)/2; //we calculate the middle index of the array
    mergeSort(A, p, q); //we call the mergeSort function recursively with the left array
    mergeSort(A, q+1, r); //we call the mergeSort function recursively with the right array
    return merge(A, p, q, r); //we call the merge function to merge the left and right arrays

}



int main(){
    //comando para compilar: g++ main.cpp -o a.out
    //comando para ejecutar: ./a.out o ./a.out < in.txt

    //Merge sort
    //vector<int> test_merge = {37,-8,20,51,16,-4,9,-2,41,5,-12,33,18,7,-6,28,15,3,50,-9,22,11,13,26,35};

    ifstream infile("in.txt");  // Abrir el archivo de entrada

    // if (!infile) {
    //     cout << "Error al abrir el archivo." << endl;
    //     return 1;
    // }

    int N;
    infile >> N;  // Lee el primer numero que es N, el tamaño del vector
    cout << "N: " << N << endl;

    vector<double> test_merge(N);  // Crear un vector de tamaño N

    for (int i = 0; i < N; i++) {
        infile >> test_merge[i];  // Leer los numeros y almacenarlos en el vector
        cout << test_merge[i] << " ";
    }

    cout << endl;

    infile.close(); 
    
    mergeSort(test_merge, 0, N-1);
    
    cout << "Merge Sort: ";
    for (int i = 0; i< N; i++){
        cout << test_merge[i] <<" ";
    }

    return 0;
}
