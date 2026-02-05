class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>> m;
          vector<vector<string>> ans;
          for(int i=0;i<n;i++){
            string org=strs[i];
            vector<int> x(26,0);
            for(int i=0;i<org.size();i++){
                x[org[i]-'a']++;
            }
            string key="";
            for(int i=0;i<26;i++){
            key+='#'+to_string(x[i]);
            }
            m[key].push_back(org);
          }
          for(auto &z:m){
            ans.push_back(z.second);
          }
          return ans;
    }
};49. Group Anagrams
