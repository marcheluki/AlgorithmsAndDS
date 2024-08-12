#include <iostream>
#include <vector>
#include <fstream>
#include <limits>

using namespace std;

void merge(vector<double> &A, int p, int q, int r) {
    // Example: Suppose array A has 10 elements: [5, 12, 7, 9, 1, 14, 2, 8, 10, 3]
    // p is the starting index, q is the middle index, and r is the ending index.
    // Let's say p = 0, q = 4 (0+9/2), and r = 9.

    // Calculate the size of the left part of the array.
    // L (left array) starts from index p and ends at index q.
    // In our example, this would be: L = [5, 12, 7, 9, 1]
    const int n1 = q - p + 1; // n1 will be 5 (4-0+1)

    // Calculate the size of the right part of the array.
    // R (right array) starts from index q+1 and ends at index r.
    // In our example, this would be: R = [14, 2, 8, 10, 3]
    const int n2 = r - q; // n2 will be 5 (9-4)

    // Dynamically allocate memory for the left and right arrays.
    // Adding 1 extra element to each array for the sentinel value.
    double* L = new double[n1 + 1];
    double* R = new double[n2 + 1];

    // Copy the elements from the left half of A into L.
    for (int i = 0; i < n1; i++) { // In our example, L will be filled with: [5, 12, 7, 9, 1]
        L[i] = A[p + i]; // Filling L from A[0] to A[4]
    }
    // Copy the elements from the right half of A into R.
    for (int j = 0; j < n2; j++) { // In our example, R will be filled with: [14, 2, 8, 10, 3]
        R[j] = A[q + 1 + j];  // Filling R from A[5] to A[9]
    }

    // Add sentinel values at the end of L and R.
    // The sentinel value is a very small number, ensuring that
    // no valid element in L or R will be smaller when comparing.
    L[n1] = -std::numeric_limits<double>::infinity();
    R[n2] = -std::numeric_limits<double>::infinity();

    // Merge the L and R arrays back into the original array A.
    // i tracks the current index in L, j tracks the current index in R,
    // and k tracks the position in the original array A.
    int i = 0, j = 0;
    for (int k = p; k <= r; k++) {
        // Compare elements in L and R and place the larger one into A[k].
        if (L[i] >= R[j]) {
            A[k] = L[i]; // Take the element from L if it's larger
            i++; // Move to the next element in L
        } else {
            A[k] = R[j]; // Otherwise, take the element from R
            j++; // Move to the next element in R
        }
    }

    delete[] L; // Deallocate memory for L
    delete[] R; // Deallocate memory for R
}

void mergeSort(vector<double> &A, int p, int r) {
    if (p >= r) { // if the first index is greater than or equal to the last index
        return; // we return because the array is already sorted
    }
    // Calculate the middle index of the array.
    // This divides the array into two halves.
    // Example: For an array of 10 elements, q would be (0 + 9) / 2 = 4.
    int q = (p + r) / 2;
    mergeSort(A, p, q); // Recursively apply mergeSort to the left half (from p to q).
    mergeSort(A, q + 1, r); // Recursively apply mergeSort to the right half (from q+1 to r).
    merge(A, p, q, r); // Merge the two halves together into a sorted array
}

int main() {
    ifstream infile("four.txt");  // Abrir el archivo de entrada
    int N;
    infile >> N;  // Lee el primer número que es N, el tamaño del vector

    vector<double> test_merge(N);  // Crear un vector de tamaño N

    for (int i = 0; i < N; i++) {
        infile >> test_merge[i];  // Leer los números y almacenarlos en el vector
    }

    infile.close();

    mergeSort(test_merge, 0, N - 1);

    cout << "Merge Sort: ";
    for (int i = 0; i < N; i++) {
        cout << test_merge[i] << " ";
    }

    return 0;
}
