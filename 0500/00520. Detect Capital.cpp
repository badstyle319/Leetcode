class Solution {
public:
    bool detectCapitalUse(string word) {
        int capitalCnt = 0;
        int capitalFirst = 0;
        for(int i=0;i<word.size();i++){
            if(word[i]<='Z' && word[i]>='A'){
                capitalCnt++;
                if(!i)
                    capitalFirst = 1;
            }
                
        }
        return capitalCnt==word.size() || capitalCnt==0 || (capitalCnt==1 && capitalFirst);
    }
};