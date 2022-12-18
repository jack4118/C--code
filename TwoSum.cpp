//https://leetcode.com/problems/two-sum/description/
// 1. Two Sum

#include <vector> // for std::vector
#include <iostream> // for std::cout
#include <algorithm> // for std::sort
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>visited;
        int len = nums.size();
        for(int i = 0; i < len; ++i)
        {
            int n = nums[i];
            int complement = target - n;
            if(visited.count(complement))
            {
                return{visited[complement],i};
            }
            visited[n] = i; // assume that each input would have exactly one solution
        }
        return{};
    }
};

int main()
{
    vector<int> Array = {3,3};
    int target = 6;

    Solution Obj;
    vector<int> Final;
    Final = Obj.twoSum(Array,target);

    for (int i = 0; i < Final.size(); i++)
    {
        cout<<Final[i] << " ";
    }

    return 0;
}