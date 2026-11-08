class Solution {
public:
    int maxDepth(string s) {
        int maxi=0;
        int count=0;
        for(char x:s){
            if(x=='('){
                count++;
                maxi=max(maxi,count);
            }
            else if(x==')'){
                count--;
            }
        }
        return maxi;
    }
};