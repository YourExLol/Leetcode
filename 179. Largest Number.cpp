## Problem Statement ##
## 179. Largest Number
## https://leetcode.com/problems/largest-number/

############################################### Code begins here ##############################################################

bool cmp(string a, string b) {
    return a+b>b+a;
}

class Solution {
public:

    string largestNumber(vector<int>& nums) {

        vector<string> v;
        for(auto x:nums) v.push_back(to_string(x));

        sort(v.begin(),v.end(),cmp);

        if(v[0]=="0") return "0";

        string ans="";
        for(auto x:v) ans+=x;
        return ans;
    }
};
