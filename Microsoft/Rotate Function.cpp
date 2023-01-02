/* 4. You are given an integer array nums of length n. Return maximum length of Rotation Function.*/


class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int a=0,b=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            a=a+nums[i];
            b=b+i*nums[i];
        }
        int c=b;
        for(int i=n-1;i>0;i--)
        {
            c=max(c,b+a-(n*nums[i]));
            b=b+a-(n*nums[i]);
        }
        return c;
    }
};
