class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> freq(26, 0);
        int n = words.size();

        for(const string& word: words)
            for(char c : word)
                freq[c-'a']++;
        
        for(int f : freq) 
            if(f % n != 0) 
                return false;

        return true;
    }
};