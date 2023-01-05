/* 6. How to find a perfect Rectangle.

Problem name :- Perfect Rectangle

Given an array rectangles where rectangles[i] = [xi, yi, ai, bi] represents an axis-aligned rectangle. The bottom-left point of the rectangle is (xi, yi) and the top-right point of it is (ai, bi).
Return true if all the rectangles together form an exact cover of a rectangular region.

Example 1:
Input: rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
Output: true
Explanation: All 5 rectangles together form an exact cover of a rectangular region.

Example 2:
Input: rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
Output: false
Explanation: Because there is a gap between the two rectangular regions.

Example 3:
Input: rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
Output: false
Explanation: Because two of the rectangles overlap with each other.

Constraints:
1 <= rectangles.length <= 2 * 10^4
rectangles[i].length == 4
-10^5 <= xi, yi, ai, bi <= 10^5

*/


class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int n=rectangles.size();
        int m=rectangles[0].size();
        if(n==0||m==0)
        {
            return false;
        }
        int a = INT_MAX;
        int b = INT_MIN;
        int c = INT_MAX;
        int d = INT_MIN;
        unordered_set<string> B;
        long long ans = 0;
    
        for (auto A : rectangles)
        {
            a = min(A[0], a);
            c = min(A[1], c);
            b = max(A[2], b);
            d = max(A[3], d);
    
            ans += ((long long)(A[2] - A[0])) * ((long long)(A[3] - A[1]));
    
            string e = to_string(A[0]) + " " + to_string(A[1]);
            string f = to_string(A[0]) + " " + to_string(A[3]);
            string g = to_string(A[2]) + " " + to_string(A[3]);
            string h = to_string(A[2]) + " " + to_string(A[1]);
    
            if (B.find(e) != B.end())
            {
                B.erase(e);
            }
            else
            {
                B.insert(e);
            }
            if (B.find(f) != B.end())
            {
                B.erase(f);
            }
            else
            {
                B.insert(f);
            }
            if (B.find(g) != B.end())
            {
                B.erase(g);
            }
            else
            {
                B.insert(g);
            }
            if (B.find(h) != B.end())
            {
                B.erase(h);
            }
            else
            {
                B.insert(h);
            }
        }
    
        if (B.find(to_string(a) + " " + to_string(c)) == B.end() || B.find(to_string(a) + " " + to_string(d)) == B.end() || B.find(to_string(b) + " " + to_string(c)) == B.end() || B.find(to_string(b) + " " + to_string(d)) == B.end() || B.size() != 4)
        {
            return false;
        }
    
        return ans == ((long long)(b - a)) * ((long long)(d - c)); 
    }
};
