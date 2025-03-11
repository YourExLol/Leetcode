139. Word Break

__________________________________________________________________

#######################Simple Recursion

class Solution {
public:
    bool fn(string &s,int start,int end,unordered_set<string> &us){
        if(us.find(s.substr(start,end-start+1))!=us.end()) return true;
        if(start==end) return false;

        for(int cut=start;cut<end;cut++){
            if(fn(s,start,cut,us) && fn(s,cut+1,end,us))
                return true;
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us(wordDict.begin(),wordDict.end());
        int end=s.size()-1;
        return fn(s,0,end,us);
    }
};

//__________________________________________________________________

####################### Memoization #####################

bool fn(string &s,int start,int end,unordered_set<string> &us, vector<vector<int>> &memo){
        if(memo[start][end]!=-1) return memo[start][end];

        if(us.find(s.substr(start,end-start+1))!=us.end()) return true;
        if(start==end) return false;

        for(int cut=start;cut<end;cut++){
            if(fn(s,start,cut,us,memo) && fn(s,cut+1,end,us,memo))
                {   memo[start][end]=1;
                    return true;}
        }
        memo[start][end]=0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us(wordDict.begin(),wordDict.end());
        int size=s.size();
        vector<vector<int>> memo(size,vector<int>(size,-1));

        return fn(s,0,size-1,us,memo);


      //__________________________________________________________________

####################### Tabulation #####################

      
    }
