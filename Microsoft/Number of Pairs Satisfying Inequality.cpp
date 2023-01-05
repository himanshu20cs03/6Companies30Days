/* 9. Number of Pairs satisfying Inequality.

Problem name :- Number of Pairs Satisfying Inequality

You are given two 0-indexed integer arrays nums1 and nums2, each of size n, and an integer diff. Find the number of pairs (i, j) such that:
0 <= i < j <= n - 1 and
nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff.
Return the number of pairs that satisfy the conditions.

Example 1:
Input: nums1 = [3,2,5], nums2 = [2,2,1], diff = 1
Output: 3
Explanation:
There are 3 pairs that satisfy the conditions:
1. i = 0, j = 1: 3 - 2 <= 2 - 2 + 1. Since i < j and 1 <= 1, this pair satisfies the conditions.
2. i = 0, j = 2: 3 - 5 <= 2 - 1 + 1. Since i < j and -2 <= 2, this pair satisfies the conditions.
3. i = 1, j = 2: 2 - 5 <= 2 - 1 + 1. Since i < j and -3 <= 2, this pair satisfies the conditions.
Therefore, we return 3.

Example 2:
Input: nums1 = [3,-1], nums2 = [-2,2], diff = -1
Output: 0
Explanation:
Since there does not exist any pair that satisfies the conditions, we return 0.
 
Constraints:
n == nums1.length == nums2.length
2 <= n <= 10^5
-10^4 <= nums1[i], nums2[i] <= 10^4
-10^4 <= diff <= 10^4

*/

class Solution {
public:

    long long a = 40000 + 7;
    long long b[100007];
    int n = 1e5;
    void UP(int i, long long v){
        int x = i;
        while(x < n){
            b[x] += v;
            x += (x&-x);
        }
    }
    long long sum(int i){
        long long s = 0;
        while(i>0){
            s = s + b[i];
            i -= (i&-i);
        }
        return s;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        UP(nums1[0] - nums2[0] + a, 1);
        long long ans = 0;
        for(int i=1;i<n;i++){
            ans += sum(nums1[i] - nums2[i] + a + diff);
            UP(nums1[i] - nums2[i] + a, 1);
        }
        return ans;
    }
};
