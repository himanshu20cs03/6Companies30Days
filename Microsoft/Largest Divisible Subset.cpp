/* 5. Largest Divisible Subset. 

 Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

Example 1:
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.

Example 2:
Input: nums = [1,2,4,8]
Output: [1,2,4,8]

Constraints:
1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 10^9
All the integers in nums are unique.

*/


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),a=0;
        vector<int> DP[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(nums[i]%nums[j]==0)
                {
                    if(DP[i].size()<=DP[j].size())
                    {
                        DP[i]=DP[j];
                    }
                }
            }
            DP[i].push_back(nums[i]);
            if(DP[i].size()>=DP[a].size())
            {
                a=i;
            }
        }
        return DP[a];
    }
};
