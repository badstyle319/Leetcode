class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int len = A.size();
        
        // for(int i = 0, j = len - 1; i < j && i < len && j >= 0; )
        // {
            // while(i < len && (A[i] % 2 == 0))
                // i++;
            // while(j >= 0 && A[j] % 2)
                // j--;
            
            // if(i < j && i < len && j >= 0)
                // swap(A[i++], A[j--]);
        // }
        for(int i = 0, j = len - 1; i < j; )
        {
            if(A[i] % 2 > A[j] % 2)
                swap(A[i], A[j]);

            if(A[i] % 2 == 0)
                i++;
            if(A[j] % 2 == 1)
                j--;
        }
        
        return A;
    }
};