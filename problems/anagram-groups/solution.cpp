class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mappp;
        for(int i = 0; i<strs.size(); i++) {
            string st = strs[i];
            sort(st.begin(), st.end());
            mappp[st].push_back(strs[i]);  
        }
        vector<vector<string>> solulu;
        for(auto pair: mappp) {
            solulu.push_back(pair.second);

        }
        return solulu;
    }
};
