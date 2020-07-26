class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int len = (int)arr.size();
        int nMax = -1;
        
        for(int i = len - 1; i >= 0; i--)
        {
            int temp = arr[i];
            arr[i] = nMax;
            nMax = max(nMax, temp);
        }
        
        return arr;
    }
};