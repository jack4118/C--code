//https://leetcode.com/problems/running-sum-of-1d-array/solutions/?envType=study-plan&id=level-1
// 1480.Running Sum of 1d

#include <vector> // for std::vector
#include <iostream> // for std::cout
#include <algorithm> // for std::sort
#include <numeric>      // std::partial_sum

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        partial_sum(nums.begin(), nums.end(), nums.begin());
        return nums;
    }
};

int main()
{
    vector<int> Array = {1,2,3,4};

    Solution Obj;
    vector<int> Final;
    Final = Obj.runningSum(Array);
    
    for (int i = 0; i < Final.size(); i++)
    {
        cout<<Final[i] << " ";
    }

    return 0;
}