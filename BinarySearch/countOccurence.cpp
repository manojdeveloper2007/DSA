#include <iostream>
#include <vector>
using namespace std;

int countOccur(vector<int> &nums,int x) {
    int first = -1;
    int last = -1;

    int low = 0;
    int high = nums.size() - 1;

    while(low <= high) {
        int mid = (low + high) / 2;
        if(nums[mid] == x) {
            first = mid;
            high = mid - 1;
        } else if(nums[mid] < x) {
            low = mid + 1;
        } else{
            high = mid - 1;
        }
    }

    if (first == -1) {
        return -1;
    }

    low = 0;
    high = nums.size()-1;

    while(low <= high) {
        int mid = (low + high) / 2;
        if(nums[mid] == x) {
            last = mid;
            low = mid + 1;
        } else if(nums[mid] < x) {
            low = mid + 1;
        } else{
            high = mid - 1;
        }
    }

    int temp = last;

    return (last - first + 1);

}

int main() {
    vector<int> arr = {1,2,2,3,3,3,4,4,5,6};
    cout<<countOccur(arr,3)<<endl;
}