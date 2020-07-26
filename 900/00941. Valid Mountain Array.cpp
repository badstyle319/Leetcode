class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int len = A.size();
        
        if(len < 3 || A[0] >= A[1])
            return false;
        
        int accending = 1;
        for(int i = 1; i < len - 1; i++)
        {
            int temp = A[i + 1] - A[i];
            if(accending)
            {
                if(temp == 0)
                    return false;
                if(temp < 0)
                    accending = 0;
            }
            else
            {
                if(temp >= 0)
                    return false;
            }
        }
        return !accending;
    }
};