class Solution {
    void print(vector<int> &v)
    {
        for(auto val:v)
            cout << val << " ";
        cout << endl;
    }
public:
    int numSquares(int n) {
        vector<int> v(n+1, 0);
        
        for(int i = 0; i <= n; i++)
            v[i] = i;
        // print(v);
        
        for(int i = 1; i <= n; i++)
        {
            // cout << "i=" << i << endl;
            for(int j = 1; j * j <= i; j++)
            {
                v[i] = min(v[i], v[i-j*j]+1);
            }
            // print(v);
        }
        
        return v[n];
    }
};