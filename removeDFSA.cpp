#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int removeDuplicates(vector<int> &nums);

int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(2);
    int ans = removeDuplicates(v1);
    cout << ans << endl;
    return 0;
}

int removeDuplicates(vector<int> &nums)
{
    int k = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[k] = nums[i];
            k += 1;
        }
    }
    return k;
}