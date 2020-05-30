class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(target == arr)
            return true;
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        return target == arr;
    }
};