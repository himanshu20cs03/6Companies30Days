/* You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    stack<int> Stack;
    for(string s:tokens) 
    {
        if(s.size()>1 || isdigit(s[0]))
        {
            Stack.push(stoi(s));
        } 
        else 
        {
            long long int a=Stack.top(); 
            Stack.pop();
            long long int b=Stack.top(); 
            Stack.pop();
            switch(s[0]) 
            {
                case '+': b=b+a; 
                break;
                case '-': b=b-a;
                break;
                case '*': b=b*a; 
                break;
                case '/': b=b/a;
                break;
                default : 
                break;
            }
            Stack.push(b);
        }
    }
    return Stack.top();
    }
};
