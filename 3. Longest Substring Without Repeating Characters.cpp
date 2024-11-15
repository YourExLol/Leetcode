## Problem Statement ##
## 3. Longest Substring Without Repeating Characters
## https://leetcode.com/problems/longest-substring-without-repeating-characters/
## https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/

############################################### Code begins here ##############################################################

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        set<char> st; //to check which element have apperaed
        int g_ans=0;  //return ans

        //2 pointer algo
        int i=0; //left
        int j=0; //eight

        int size=s.size();

        while(j<size){
            if(st.count(s[j])==0){
                st.insert(s[j]);            // if not found Insert character into set
                g_ans = max(g_ans, j - i + 1); // Update the global max length
                 j++;  //expand the window on right side bu 1 unit
            }
            else {
                st.erase(s[i]);
                i++;
            }
        } //while ends here

        return g_ans;
    }
};
