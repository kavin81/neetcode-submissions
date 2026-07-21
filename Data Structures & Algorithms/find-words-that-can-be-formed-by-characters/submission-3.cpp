class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26,0);
        for(char c : chars)
            freq[c - 'a']++;
        
        int res = 0;

        for(const string& word: words){
            vector<int> freq_tmp = freq;
            bool is_good = true;

            for(char c : word) {
                if(--freq_tmp[c - 'a'] < 0){
                    is_good = false;
                    break;
                }
            }
            if(is_good)
                res += word.size();
        }
        return res;
    }
};