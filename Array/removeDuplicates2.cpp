#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{   
    int k=0;
    for(int x : nums) {
        if(k < 2 || nums[k-2] != x) {
            nums[k] = x;
            k++;
        }
    }
    return k;
}

int main() {
    vector<int> arr = {1,1,1,2,2,2,3,3};
    int idx = removeDuplicates(arr);
    for(int i=0;i<idx;i++) {
        cout<<arr[i]<<" ";
    }
}