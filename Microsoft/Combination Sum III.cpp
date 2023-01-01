/* 2. Combination Sum with a twist. */

class Solution {
public:

    void combinationsum(int b,int k,int a,vector<vector<int>>&arr, vector<int>&an)
    {
        if(k==0)
        {
            if(a==0)
            {
                arr.push_back(an);
            }
            return ;
        }
        for(int i=b;i<10;i++)
        {
            if(i>b&&i==b||b>a)
            {
                return ;
            }
            an.push_back(i);
            combinationsum(i+1,k-1,a-i,arr,an);
            an.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> arr;
        vector<int> an;
        combinationsum(1,k,n,arr,an);
        return arr;
    }
};
