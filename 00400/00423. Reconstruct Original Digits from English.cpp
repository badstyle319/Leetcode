class Solution {
public:
    string originalDigits(string s) {
        vector<int> arr(128, 0);
        string ans;
        int nums[10] = {};

        for(auto &ch:s)
        {
            arr[ch]++;
        }

        nums[0] = arr['z'];
        nums[2] = arr['w'];
        nums[4] = arr['u'];
        nums[6] = arr['x'];
        nums[8] = arr['g'];
        nums[1] = arr['o'] - nums[0] - nums[2] - nums[4];
        nums[3] = arr['t'] - nums[2] - nums[8];
        nums[5] = arr['f'] - nums[4];
        nums[7] = arr['s'] - nums[6];
        nums[9] = arr['i'] - nums[6] - nums[8] - nums[5];
        
        for(int i = 0; i < 10; i++)
        {
            ans.append(nums[i], i + '0');
        }
        
        return ans;
    }
};