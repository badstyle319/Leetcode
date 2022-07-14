class Solution {
public:
    string intToRoman(int num) {
        string ans;
        int t;
        
        t = num /1000;
        ans.append(t, 'M');
        num %= 1000;

        t = num / 100;
        switch(t)
        {
            case 4:
                ans.append("CD");
                break;
            case 9:
                ans.append("CM");
                break;
            default:
                if(t >= 5)
                {
                    ans.append(1, 'D');
                    t -= 5;
                }
                ans.append(t, 'C');
                break;
        }
        num %= 100;

        t = num / 10;
        switch(t)
        {
            case 4:
                ans.append("XL");
                break;
            case 9:
                ans.append("XC");
                break;
            default:
                if(t >= 5)
                {
                    ans.append(1, 'L');
                    t -= 5;
                }
                ans.append(t, 'X');
                break;
        }
        num %= 10;

        t = num;
        switch(t)
        {
            case 4:
                ans.append("IV");
                break;
            case 9:
                ans.append("IX");
                break;
            default:
                if(t>=5)
                {
                    ans.append(1, 'V');
                    t -= 5;
                }
                ans.append(t, 'I');
                break;
        }
        return ans;
    }
};