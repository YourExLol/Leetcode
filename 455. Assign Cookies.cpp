## Problem Statement ##
## 455. Assign Cookies
## https://leetcode.com/problems/assign-cookies/description/

############################################### Code begins here ##############################################################

//If the size of the cookie is sufficient for the child’s greed factor (s[cookieIdx] >= g[childIdx]), increment the count of content children (contentChildren) and move to the next child (childIdx++).
//Move to the next cookie (cookieIdx++) regardless of whether it was assigned to a child or not.

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int ans=0;
        int g_index=0; //child greed index
        int s_index=0; //cookies index

        while (g_index < g.size() && s_index < s.size()) {
            if (s[s_index] >= g[g_index]) {
                ans++;
                g_index++;
            }
            s_index++;
        }
        
        return ans;
    }
};
