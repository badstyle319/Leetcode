class Solution {
    vector<string> dic;
    void backtracking(const string& digits, int dimension, string &temp, vector<string>& ans)
    {
        if(dimension > digits.length())
            return;
        
        if(dimension == digits.length())
        {
            ans.push_back(temp);
            return;
        }
        
        for(auto ch: dic[digits[dimension] - '0'])
        {
            temp.push_back(ch);
            backtracking(digits, dimension + 1, temp, ans);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        
        dic.resize(10, "");
        dic[2] = "abc";
        dic[3] = "def";
        dic[4] = "ghi";
        dic[5] = "jkl";
        dic[6] = "mno";
        dic[7] = "pqrs";
        dic[8] = "tuv";
        dic[9] = "wxyz";
        
        string temp;
        vector<string> ans;
        backtracking(digits, 0, temp, ans);
        
        return ans;
    }
};