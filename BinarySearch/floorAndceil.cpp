#include <iostream>
#include <vector>
using namespace std;

// smallest index arr[i] >= x (lower bound)
int ceilBs(vector<int> &arr,int x) {
    int low = 0;
    int high = arr.size()-1;
    int ans = arr.size();

    while(low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else{
            low = mid + 1;
        }
    }

    return ans;
}

// largest index arr[i] <= x
int floorBs(vector<int> &arr,int x) {
    int low = 0;
    int high = arr.size()-1;
    int ans = arr.size();

    while (low <= high) {
        int mid = ( low + high ) / 2;
        if(arr[mid] <= x) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {

    vector<int> arr = {1,2,4,6,6,8,9};
    cout<<ceilBs(arr,6)<<endl;
    cout<<floorBs(arr,6)<<endl;

}