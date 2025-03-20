//Binary Search base code

#include<iostream>
using namespace std;

int binarySearch(int arr[], int x) {
    int low = 0, high = 5;
    while(low <= high) {
        int mid = (low + high)/2;
        if(x == arr[mid]) return mid;
        if(x > arr[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[6] = {1, 3, 5, 7, 11};
    int target = 7;
    int index = binarySearch(arr, target); 
    (index == -1) ? cout<<"Not Found!"<<endl : cout<<"Found at: "<<index<<endl;
}