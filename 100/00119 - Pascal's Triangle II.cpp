class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v(1, 1);
        
        for(int i = 1; i <= rowIndex; i++)
        {
            vector<int> t(1, 1);
            for(int j = 1; j < i; j++)
            {
                t.push_back(v[j-1]+v[j]);
            }
            t.push_back(1);
            v.swap(t);
        }
        
        return v;
    }
};