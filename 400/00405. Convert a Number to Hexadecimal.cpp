class Solution {
public:
    string toHex(int num) {
        string ans;
        string hex = "0123456789abcdef";
        
        if(num>=0){
            do{
                ans.insert(0, 1, hex[num%16]);
                num/=16;
            }while(num);
        }else{
            ans = toHex(-num-1);
            if(ans.length()<8)
                ans.insert(0, 8-ans.size(), '0');
            for(int i=0;i<8;i++){
                ans[i] = isalpha(ans[i])?hex[5-ans[i]+'a']:hex[15-ans[i]+'0'];
            }
        }
        return ans;
    }
};