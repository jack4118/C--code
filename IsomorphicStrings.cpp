//https://leetcode.com/problems/isomorphic-strings/solutions/?envType=study-plan&id=level-1
// 205. Isomorphic Strings

#include <iostream>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char f2s[128] = {0};
        char s2f[128] = {0};
        int k = 0;

        for ( k = 0; s[k] != 0 && t[k] != 0; k++)
        {
            char symbol_first = s[k];
            char symbol_second = t[k];
            if (f2s[symbol_first] == 0)
            {
                if (s2f[symbol_second] == 0)
                {
                    f2s[symbol_first] = symbol_second;
                    s2f[symbol_second] = symbol_first;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (f2s[symbol_first] != symbol_second)
                {
                    return false;
                }
            }
        }
        if (s [k] == 0 && t[k] == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution Obj;
    bool Final;
    Final = Obj.isIsomorphic("egg", "add");

    if (Final == 1)
    {
        cout<<"True"<<endl;
    }
    else 
    {
        cout<<"False"<<endl;
    }
    
    return 0;
}