## Problem Statement ##
## 2914. Minimum Number of Changes to Make Binary String Beautiful
## https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/

############################################### Code begins here ##############################################################

//it optimal to divide the string into substrng of 2 then 4,6,8.... For ex 11001100.
//so we check in how many cases odd-even index value are not same

class Solution {
public:
    int minChanges(string s) {
        int ans=0;
        for(int i=0;i<s.size()-1;i=i+2){
            if(s[i]!=s[i+1]) ans++;
        }
        return ans;

        } //f ends here
};
