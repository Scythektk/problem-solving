#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    map<char, char> stringMap;
    map<char, char> stringMapInverse;
    // map['c']=1;
    for (int i = 0; i < s.length(); i++)
    {
        if (stringMap.find(s[i]) != stringMap.end())
        {
            if (stringMap[s[i]] != t[i])
            {
                return false;
            }
        }

        else
        {
            if (stringMapInverse.find(t[i]) != stringMapInverse.end())
            {
                return false;
            }

            stringMap[s[i]] = t[i];
            stringMapInverse[t[i]] = s[i];
        }
    }
    return true;
}

int main()
{
    bool ans = isIsomorphic("paper", "vivet");
    cout << ans << endl;
    return 0;
}