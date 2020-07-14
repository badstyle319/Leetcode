class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int L = 0, R = (int)s.size()-1; L < R; L++, R--)
            swap(s[L], s[R]);
    }
};