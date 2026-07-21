class Solution {
public:
    unordered_map<char,int> pair;

    int maxLengthBetweenEqualCharacters(string s) {
        int res = -1;
        for(int i=0;i < s.size();i++){
            char c = s[i];

            if(pair.count(c)) 
                res = max(res,i-pair[c]-1);
            else
                pair[c] = i;
        }
        return res;
    }
};