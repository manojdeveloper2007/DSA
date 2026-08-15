#include <iostream>
#include <vector>
using namespace std;

int minBloom(vector<int> &bloomDay)
{
    int minn = INT_MAX;

    for (int i : bloomDay)
    {
        if (minn > i)
        {
            minn = i;
        }
    }

    return minn;
}

int maxBloom(vector<int> &bloomDay)
{
    int maxx = INT_MIN;
    for (int i : bloomDay)
    {
        if (maxx < i)
        {
            maxx = i;
        }
    }
    return maxx;
}

int cntValid(vector<int> &bloomDay, int day, int k)
{
    int cnt = 0;
    int total = 0;
    for (int i : bloomDay)
    {
        if (i <= day)
        {
            cnt++;
            if(cnt == k) {
                total++;
                cnt=0;
            }
        }
        else
        {
            cnt = 0;
        }
    }
    return total;
}

int minDays(vector<int> &bloomDay, int m, int k)
{

    if((long)m * (long)k > bloomDay.size()){
        return -1;
    }

    int low = minBloom(bloomDay);
    int high = maxBloom(bloomDay);
    int minn = high;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int total = cntValid(bloomDay, mid, k);

        if (total >= m)
        {
            minn = min(minn, mid);
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return minn;
}

int main()
{
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;
    cout<<minDays(bloomDay,m,k)<<endl;
}