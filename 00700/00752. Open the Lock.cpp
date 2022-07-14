class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        set<string> s(deadends.begin(), deadends.end());
        int ans = 0;
        
        q.push("0000");
        while(!q.empty())
        {
            ans++;
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                string org = q.front(); q.pop();
                if(!s.count(org))
                {
                    s.insert(org);
                    for(int j = 0; j < 4; j++)
                    {
                        static int rotate[] = {1, 9};
                        for(int k = 0; k < 2; k++)
                        {
                            string temp = org;
                            temp[j] = (temp[j] - '0' + rotate[k]) % 10 + '0';
                            if(temp == target)
                                return ans;
                            q.push(temp);
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};