#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target);

int main()
{
    vector<int> v1(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    vector<int> ans = twoSum(v1, 5);
    cout << ans[1] << " " << ans[0] << endl;
    return 0;
}

vector<int> twoSum(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] == target - nums[i])
            {
                vector<int> a;
                a.push_back(i);
                a.push_back(j);
                return a;
            }
        }
    }
    return vector<int>();
}
