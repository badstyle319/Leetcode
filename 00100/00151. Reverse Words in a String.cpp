class Solution {
public:
    string reverseWords(string s) {
        s = s.erase(0, s.find_first_not_of(" "));
        s = s.erase(s.find_last_not_of(" ") + 1);

        auto pos = s.find_first_of(" ");
        if(pos == string::npos)
            return s;
        else
            return reverseWords(s.substr(pos)) + " " + s.substr(0, pos);
    }
};