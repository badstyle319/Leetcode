class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        
        vector<string> temp(numRows);
        int idx = 0;
        bool downDir = false;
        string rv;

        for(int i=0;i<s.length();i++){
            temp[idx] += s[i];
            if(idx == 0 || idx == numRows-1)
                downDir = !downDir;
            idx += downDir ? 1 : -1;
        }
        
        for(int i=0;i<numRows;i++)
            rv += temp[i];
        
        return rv;
    }
};