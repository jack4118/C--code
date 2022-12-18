//https://leetcode.com/problems/find-pivot-index/?envType=study-plan&id=level-1
// 724. Find Pivot Index

#include <iostream> // for std::cout
#include <vector> // for std::vector
#include <numeric> // for std::accumulate

using namespace std;

// Time Complexity : O(n)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // Initialize rightSum to store the sum of all the numbers strictly to the index's right...
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        // Initialize leftSum to store the sum of all the numbers strictly to the index's left...
        int leftSum = 0;
        // Traverse all elements through the loop...
        for (int idx = 0; idx < nums.size(); idx++) {
            // subtract current elements with from rightSum...
            rightSum -= nums[idx];
            // If the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right...
            if (leftSum == rightSum)
                return idx;     // Return the pivot index...
            // add current elements with leftSum...
            leftSum += nums[idx];
        }
        return -1;      // If there is no index that satisfies the conditions in the problem statement...
    }
};

int main()
{
    vector<int> Array = {1,7,3,6,5,6};

    Solution Obj;
    int Final;
    Final = Obj.pivotIndex(Array);

    cout<<Final << " ";

    //accumulate 用法：累加求和
    // vector<int> vec = {1,2,3,4}
    // int sum = accumulate(vec.begin(),vec.end(),42)
    // -> (1 + 2 + 3 + 4) + 42 前两个start(), end() 是范围， 42 是 初始数值
    return 0;
}