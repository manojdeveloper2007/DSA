#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> &nums) {
    // Moores voting algorthm (n/2 times greater)
    int freq = 0;
    int majority = -1;
    for(int i : nums) {
        if (freq == 0) {
            majority = i;
        }

        if(majority == i) {
            freq++;
        } else{
            freq--;
        }
    }
    return majority;
}

int main() {
    vector<int> arr = {3,1,3,6,3,3};
    cout<<majorityElement(arr)<<endl;
}