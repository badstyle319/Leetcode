class Solution {
    bool isVowel(char ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
            || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
public:
    bool halvesAreAlike(string s) {
        int half = s.size() / 2;
        int counter = 0;
        
        for(int i = 0; i < half; i++)
        {
            if(isVowel(s[i]))
                counter++;
        }
        for(int i = half; i < s.size(); i++)
        {
            if(isVowel(s[i]))
                counter--;
        }
        return counter == 0;
    }
};