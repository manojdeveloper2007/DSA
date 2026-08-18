#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum(vector<int> &books) {
    int total = 0;

    for(int i : books) {
        total += i;
    }
    return total;
}

int isValid(vector<int> &books,int maxpage,int k) {
    int student = 1;
    int total = 0;

    for(int i : books) {
        if((total + i) <= maxpage) {
            total += i;
        }
        else{
            total = i;
            student+=1;
        }
    }
    return student;
}

int minimumPage(vector<int> &books,int k) {

    if(k > books.size()) {
        return -1;
    }

    int low = *max_element(books.begin(),books.end());
    int high = sum(books);
    int ans = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        int valid = isValid(books,mid,k);

        if(valid > k) {
            low = mid + 1;
        } 
        else{
            high = mid - 1;
        }
    }
    return low;
}

int main() {
    vector<int> books = {15 ,10 ,19 ,10 ,5 ,18 ,7};
    int k = 4;
    cout<<minimumPage(books,k)<<endl;
}