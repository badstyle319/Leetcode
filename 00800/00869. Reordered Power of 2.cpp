class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string target = to_string(N);
        set<string> s;
        
        sort(target.begin(), target.end());
        for(int i = 0; i < 32; i++)
        {
            string temp = to_string(1<<i);
            if(temp.size() == target.size())
            {
                sort(temp.begin(), temp.end());
                s.insert(temp);
            }
            if(temp.length() > target.length())
                break;
        }
        return s.count(target);
    }
};