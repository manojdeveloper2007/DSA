#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix,int n,int m,int target) {
    int row = 0;
    int col = m-1;

    while(col >= 0 && row < n) {
        int ans = matrix[row][col];

        if(ans == target) {
            return true;
        }

        else if(ans < target) {
            row++;
        }

        else{
            col--;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int n = 5;
    int m = 5;
    cout<<searchMatrix(matrix,n,m,10)<<endl;
}