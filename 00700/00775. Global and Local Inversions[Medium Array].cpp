class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int nMax = -1;
        
        for(int i = 0; i < (int)A.size() - 2; i++)
        {
            nMax = max(nMax, A[i]);
            if(nMax > A[i + 2])
                return false;
        }
        
        return true;
    }
};