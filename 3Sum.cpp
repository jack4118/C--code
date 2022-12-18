//https://leetcode.com/problems/3sum/solutions/
// 15. 3Sum

#include <vector> // for std::vector
#include <iostream> // for std::cout
#include <algorithm> // for std::sort

using namespace std;
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort the vector
        sort(nums.begin(), nums.end());

        if(nums.size() <3 ) //Base case 1
        {
            return {};
        }
        if(nums[0]>0) // Base case 2
        {
            return {};
        }
        vector<vector<int>>answer;
        for (int i = 0; i < nums.size(); ++i) //Traversing the array to fix the number.
        {
            if(nums[i] > 0) //If number fixed is +ve, stop three because we can't make it zero by searching after it.
            {
                break;
            }
            if(i > 0 && nums[i] == nums[i - 1]) // If number is getting repeated, ignore the lower loop and continue.
            {
                continue;
            }
            int low = i + 1, high = nums.size() - 1; //Make two pointers high and low and initialize sum as 0.
            int sum = 0;
            while (low < high) //Search between two pointers, just similar to binary search
            {
                sum = nums[i] + nums[low] + nums[high];
                if(sum > 0) //If sum is +ve, means, we need more -ve numbers to make it 0, decrement high (high--).
                {
                    high--;
                }
                else if(sum < 0) //If sum is -ve, means, we need more +ve numbers to make it 0, increment low (low++).
                {
                    low++;
                }
                else
                {
                    answer.push_back({nums[i], nums[low], nums[high]}); // We have found the required triplet, push it in answer vector.
                    int last_low_occurence = nums[low], last_high_occurence = nums[high]; //Now again, to avoid duplicate triplets, we have to navigate to last ovvurences of num[low] and num[high] respectively.
                    while(low < high && nums[low] == last_low_occurence) //Update the low and high with last occurences of low and high.
                    {
                        low++;
                    }
                    while(low < high && nums[high] == last_high_occurence)
                    {
                        high--;
                    }
                }
            }
        }
        return answer; //Return the answer vector
    }
};

int main()
{
    vector<int> v = {{-1, 0, 1, 2, -1, -4}};
    // vector<int> v = {{0,1,1}};
    // vector<int> v = {{0,0,0}};

    int response = 0;

    Solution Obj;
    vector<vector<int>> Final;
    int Temp[6];
    int count = 0;
    Final = Obj.threeSum(v);

    for (int i = 0; i < Final.size(); i++)
    {
        for (int j = 0; j < Final[i].size(); j++)
        {
            cout<<Final[i][j] << " ";
            // cout << "\n i = "<< i << " j = "<< j << "\n ";
            Temp[count] = Final[i][j];
            count++;
        }
        cout<<endl;
        if(i == 0)
        {
            cout<<"The only possible triplet sums up to 0.";
            response ++;
        }
    }

    return 0;
}