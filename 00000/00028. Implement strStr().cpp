class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "")
            return 0;
        
        int len = (int)needle.length();
        int j = 0;
        for(int i = 0; i < (int)haystack.size(); i++)
        {
            
            for(j = 0; (i + len) <= haystack.size() && haystack[i + j] == needle[j] && j < len; j++);
            if(j == len)
                return i;
        }
        return -1;
    }
};