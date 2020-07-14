#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int len = (int)arr.size();
        // for(int i = 0; i < len; i++)
        // {
        //     if(arr[i] == 0)
        //     {
        //         i++;
        //         arr.insert(arr.begin() + i, 1, 0);
        //     }
        // }
        // arr.resize(len);
        
        vector<int> t(arr);
        
        for(int i = 0, j = 0; i < len && j < len; i++)
        {
            arr[j++] = t[i];
            if(!t[i] && j < len)
            {
                arr[j++] = 0;
            }
        }
    }
};

int main()
{
    Solution s;
    
    vector<int> v{8,4,5,0,0,0,0,7};
    
    s.duplicateZeros(v);
    for(auto val:v)
        cout << val << " ";
    cout << endl;
    
    return 0; 
}