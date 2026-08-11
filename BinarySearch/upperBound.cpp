#include <iostream>
#include <vector>
using namespace std;
// upper bound

// x = 7  lower bound of where nums[i] >= x
int upperbound(vector<int> &arr,int x) {
    int low = 0;
    int high = arr.size()-1;
    int ans = arr.size();

    while(low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else{
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {1,1,2,4,6,9,12,15,15};
    cout<<upperbound(arr,1);
}