class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>> m;
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            string org=strs[i];
            sort(strs[i].begin(),strs[i].end());
            m[strs[i]].push_back(org);
        }
       for(pair<string,vector<string>> v:m){
        ans.push_back(v.second);
       }
        return ans;
    }
};
