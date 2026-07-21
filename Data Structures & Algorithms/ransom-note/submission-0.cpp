class Solution {
public:
    vector<int> freq;
    bool canConstruct(string ransomNote, string magazine) {
        freq = vector<int>(26,0);
        for(char c:magazine){
            freq[c - 'a']++;
        }

        for(char c:ransomNote){
            if(--freq[c-'a'] < 0){
                return false;
            }
        }
        return true;
    }
};