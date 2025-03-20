#include<iostream>
using namespace std;

int upperBound(int *arr, int N, int t) {
    int low = 0, high = N-1, mid, res = -1;
    while(low<=high) {
        mid = (low+high)/2;
        if(arr[mid] >= t) {
            res = arr[mid];
            cout<<res;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    return res;
}
int lowerBound(int *arr, int N, int t) {
    int low = 0, high = N-1, mid, res = -1;
    while(low<=high) {
        mid = (low+high)/2;
        if(arr[mid] <= t) {
            res = arr[mid];
            cout<<res<<endl;
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return res;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int target = 7;
    int N = sizeof(arr)/sizeof(arr[0]);
    int uB = upperBound(arr, N, target);
    cout<<endl<<endl;
    int lB = lowerBound(arr, N, target);
    cout<<uB<<endl<<lB<<endl;
}