#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;
  
  int L[n1];
  int M[n2];
  
  for (int i = 0; i < n1; i++)  L[i] = arr[left + i];

  for (int j = 0; j < n2; j++)  M[j] = arr[mid + 1 + j];
    
  int i = 0, j = 0, k = left;
  
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
        arr[k] = L[i];
        i++;
    } else {
        arr[k] = M[j];
        j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  
  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}
void mergeSort(int arr[], int l, int right) {
  if (l < right) {
    int m = l + (right - l) / 2;
    
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, right);
    merge(arr, l, m, right);
  }
}

int main() {
    int arr[6] = {6,5,12,10,9,1};
    mergeSort(arr,0,5);
    for(int i = 0; i < 6; i++) cout<<arr[i]<<" ";
}