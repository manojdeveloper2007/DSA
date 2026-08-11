#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr,int target) {
    // high and low
    int low = 0;
    int high = arr.size()-1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] == target) {
            return mid;
        }

        else if(target > arr[mid]) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    // sorted array
    vector<int> arr = {1,3,4,7,9,12,15};
    int target = 4;
    cout<<binarySearch(arr,target)<<endl;
}