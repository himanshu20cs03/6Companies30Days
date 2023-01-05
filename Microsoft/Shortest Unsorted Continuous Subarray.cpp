/* 10. Shortest Unsorted Continuous Subarray

Problem name :- Shortest Unsorted Continuous Subarray

Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.
Return the shortest such subarray and output its length.

Example 1:
Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Example 2:
Input: nums = [1,2,3,4]
Output: 0

Example 3:
Input: nums = [1]
Output: 0
 

Constraints:
1 <= nums.length <= 10^4
-10^5 <= nums[i] <= 10^5
 
Follow up: Can you solve it in O(n) time complexity?

*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> Vectr;
        int a=-1,b=-1;
        for(int c:nums)
        {
            Vectr.push_back(c);
        }
        sort(Vectr.begin(),Vectr.end());
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=Vectr[i])
            {
                a=i;
                break;
            }
        }
        for(int j=n-1;j>=0;j--)
        {
            if(Vectr[j]!=nums[j])
            {
                b=j;
                break;
            }
        }
        if(a==-1 or b==-1)
        {
            return 0;
        }
        return b-a+1;
    }
};
