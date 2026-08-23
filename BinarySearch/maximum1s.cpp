#include <iostream>
#include <vector>
using namespace std;

// find the maximum one's in 2D array
int minimumOnes(vector<vector<int>> &matrix,int col,int row) {
    int cnt = -1;
    int idx = -1;
    int maxcnt = -1;
    for(int i = 0;i < col;i++) {
        int low = 0;
        int high = row-1;
        int mid = -1;
        while(low <= high) {
            mid = (low + high) / 2;

            if(matrix[i][mid] == 1) {
                high = mid - 1;
                idx = mid;
            } else{
                low = mid + 1;
            }
        }
        cnt = row - (idx+1);
        if(maxcnt < cnt) {
            maxcnt = cnt;
            idx = i;
        }
    }
    return idx;
}

int main() {
    int col = 3;
    int row = 3;
    vector<vector<int>> matrix = {{1,1,1},{0,0,1},{1,1,1}};
    cout<<minimumOnes(matrix,col,row)<<endl;
}