class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> count;

        for(char c: chars){
            count[c]++;
        }

        int res = 0;
        for(const string& word:words){
            unordered_map<char,int> curWord;
            for(char c : word) {
                curWord[c]++;
            }
            bool is_good = true;
            for(const auto& p : curWord){
                if(p.second > count[p.first]) {
                    is_good = false;
                    break;
                }
            }
            if(is_good) {
                res += word.size();
            }
        }
        return res;
    }
};