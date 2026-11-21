class Solution {
vector<int>last;
vector<vector<int>>adj;
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
            
            int n = s.length();
        
            last.resize(26 , -1);

            adj.resize(n + 1);

            for(int i = 0; i < n; i++){

                  if(parent[i] >= 0){

                      adj[parent[i]].push_back(i);
                  }
            }

            dfs1(-1, 0, s, parent);

            for(int i = 0; i < n; i++){

                adj[i].clear();
            }

            for(int i = 0; i < n; i++){

                  if(parent[i] >= 0){

                      adj[parent[i]].push_back(i);
                  }
            }

            vector<int>ans(n, 0);

            dfs2(-1, 0, ans);

            return ans;

    }

    private:

    void dfs1(int par, int node, string &s, vector<int>&parent){

           int idx = last[s[node] - 'a'];

           parent[node] = idx >= 0 ? idx : parent[node];

           last[s[node] - 'a'] = node;

           for(int next : adj[node]){

                 if(par != next){

                     dfs1(node, next, s, parent);
                 }
           }

           last[s[node] - 'a'] = idx;
    }

    int dfs2(int par, int node, vector<int>&ans){

          int cnt = 1;

          for(int next : adj[node]){

               if(par != next){

                   cnt += dfs2(node, next, ans);
               }
          }

          return ans[node] = cnt;
    }


};