/* 11. Number of Ways to Arrive at Destination

Problem name :- Number of Ways to Arrive at Destination

You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections.
The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.
You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. 
You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.
Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

Example 1:
Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output: 4
Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
The four ways to get there in 7 minutes are:
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6

Example 2:
Input: n = 2, roads = [[1,0,10]]
Output: 1
Explanation: There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.
 
Constraints:
1 <= n <= 200
n - 1 <= roads.length <= n * (n - 1) / 2
roads[i].length == 3
0 <= ui, vi <= n - 1
1 <= timei <= 10^9
ui != vi
There is at most one road connecting any two intersections.
You can reach any intersection from any other intersection.

*/


#define ll long long
const int mod = 1e9+7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> Dij(n);
        for(int i = 0; i < roads.size(); i++)
        {
            int a = roads[i][0];
            int b = roads[i][1];
            int c = roads[i][2];
            Dij[a].push_back({b,c});
            Dij[b].push_back({a,c});
        }
        vector<ll> time(n,LONG_MAX);
        time[0] = 0;
        vector<ll> A(n,0);
        A[0] = 1;
        priority_queue <pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>> > Q;
        Q.push({0,0});
        while(!Q.empty())
        {
            ll B = Q.top().first;
            int node = Q.top().second;
            Q.pop();
            for(auto j: Dij[node])
            {
                int DijNode = j.first;
                ll timeTotravel = j.second;
                
                if(B + timeTotravel < time[DijNode])
                {
                    time[DijNode] = B + timeTotravel;
                    Q.push({time[DijNode],DijNode});
                    A[DijNode] = A[node]%mod;
                }
                else if(B + timeTotravel == time[DijNode])
                    A[DijNode] = (A[DijNode]+A[node])%mod;
            }
        }
        return A[n-1];
    }
};
