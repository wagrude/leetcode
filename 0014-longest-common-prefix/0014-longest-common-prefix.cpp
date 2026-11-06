class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n=strs.size();
        string first=strs[0];
        string last=strs[n-1];
        for(int i=0;i<min(first.size(),last.size());i++){
            char ch = strs[0][i];
            for(int j = 1; j < n; j++) {
                if(strs[j][i] != ch) {
                    return ans;
                }
            }
            ans.push_back(ch);
        }
        return ans;
        
    }
};
