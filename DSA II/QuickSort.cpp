/*  
    l = left index of the array
    r = right index of the array

    QuickSort Function:
        1. if l < r, then
            a. p = Partition(arr, l, r)
            b. QuickSort(arr, l, p-1)
            c. QuickSort(arr, p+1, r)
    
    Partition Function:
        1. pivot = arr[r]
        2. i = l-1
        3. for j = l to r-1
            a. if arr[j] < pivot, then
                i++
                swap arr[i] and arr[j]
        4. swap arr[i+1] and arr[r]
        5. return i+1
*/
#include<iostream>
using namespace std;

int partition(int A[], int p, int r) {
    int x = A[r];
    int i = p-1;
    for(int j = p; j < r; j++) {
        if(A[j] <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i+1;
}

void quickSort(int A[], int p, int r) {
    if(p < r) {
        int q = partition(A,p,r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

int main() {
    int A[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(A) / sizeof(A[0]);
    quickSort(A, 0, n - 1);
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}