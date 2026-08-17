#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

bool canShip(vector<int> &weights, int days, int capacity)
{
    int currentWeight = 0;
    int usedDays = 1;

    for (int weight : weights)
    {

        if (currentWeight + weight <= capacity)
        {
            currentWeight += weight;
        }
        else
        {
            usedDays++;
            currentWeight = weight;
        }
    }

    return usedDays <= days;
}

int shipWithinDays(vector<int> &weights, int days)
{

    int low = *max_element(weights.begin(), weights.end());

    int high = accumulate(weights.begin(), weights.end(), 0);

    int answer = high;

    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        if (canShip(weights, days, mid))
        {
            answer = mid;

            // Try smaller capacity
            high = mid - 1;
        }
        else
        {
            // Capacity is too small
            low = mid + 1;
        }
    }

    return answer;
}

int main()
{
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    cout << shipWithinDays(weights, days) << endl;
}