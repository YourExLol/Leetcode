## Problem Statement ##
## 20. Valid Parentheses
## https://leetcode.com/problems/valid-parentheses/description/

############################################### Code begins here ##############################################################

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        //push opening bracket in stack and compare closing bracket with stack top. and return stack.empty()
        for(auto x:s){
            if(x=='{' || x=='(' || x=='[') st.push(x);
            else{
                if(!st.empty() && ((st.top()=='(' && x==')' ) || (st.top()=='[' && x==']' ) || (st.top()=='{' && x=='}' )) ){
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
        return st.empty();
        
    }
};
