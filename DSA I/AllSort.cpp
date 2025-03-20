#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int step = 0; step < n-1; step++) {
        for(int i = 0; i < n-step-1; i++) {
            if(arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
            }
        }
    }
}
void insertionSort(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        int min = arr[i];
        int minI = i;
        for(int j = i; j < n; j++) {
            if(arr[j]<min) {
                minI = j;
                min = arr[j];
            }
        }
        swap(arr[i], arr[minI]);
    }
}

int main() {
    int arr[4] = {6, 2, 4, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    //bubbleSort(arr, size);
    //insertionSort(arr,size);
    selectionSort(arr, size);
    for(int i = 0; i < size; i++) cout<<arr[i]<<" ";
}