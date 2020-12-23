class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k %= len;
        nums.insert(nums.end(), nums.begin(), nums.begin() + len - k);
        nums.erase(nums.begin(), nums.begin() + len - k);
    }
};