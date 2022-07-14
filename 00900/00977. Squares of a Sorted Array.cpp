class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int len = (int)A.size();
        
        // for(int i = 0; i < len; i++)
            // A[i] = A[i] * A[i];
        
        // sort(A.begin(), A.end());
        
        // return A;
        
        vector<int> ans;
        
        int i = 0, j;
        for(; i < len; i++)
        {
            if(A[i] >= 0)
                break;
        }

        for(j = i - 1; j >= 0 && i < len;)
        {
            if(abs(A[j]) <= abs(A[i]))
            {
                ans.push_back(A[j] * A[j]);
                j--;
            }
            else
            {
                ans.push_back(A[i] * A[i]);
                i++;
            }
        }
        for(; j >= 0; j--)
            ans.push_back(A[j] * A[j]);
        for(; i < len; i++)
            ans.push_back(A[i] * A[i]);
        
        return ans;
    }
};