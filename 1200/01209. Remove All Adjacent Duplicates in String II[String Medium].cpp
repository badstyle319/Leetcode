class Solution {
public:
    string removeDuplicates(string s, int k) {
        deque<pair<char,int>> dq;
        
        for(auto &ch:s)
        {
            if(dq.empty())
            {
                dq.push_back(make_pair(ch, 1));
            }
            else
            {
                if(dq.back().first == ch)
                {
                    if(dq.back().second == k - 1)
                    {
                        dq.pop_back();
                    }
                    else
                    {
                        dq.back().second++;
                    }
                }
                else
                {
                    dq.push_back(make_pair(ch, 1));
                }
            }
        }
        
        string ans;
        
        while(!dq.empty())
        {
            //cout << dq.front().first << "," << dq.front().second << endl;
            ans += string(dq.front().second, dq.front().first);
            dq.pop_front();
        }
        
        return ans;
    }
};