#include <iostream>
#include <vector>
using namespace std;

// using dutch national flag algorithm
void sortColors(vector<int> &nums) {
    // 0 -> i , 1 -> j , 2 -> k
    int i = 0;
    int j = 0;
    int k = nums.size() - 1;

    while(j <= k) {
        if(nums[j] == 1) {
            j++;
        }

        else if(nums[j] == 0) {
            swap(nums[i],nums[j]);
            i++;
            j++;
        }

        else{
            swap(nums[j],nums[k]);
            k--;
        }
    }
}

int main() {
    vector<int> nums = {2,1,2,0,1,0,2};
    sortColors(nums);

    for(auto i : nums) {
        cout<<i<< " ";
    }
    cout<<endl;
}