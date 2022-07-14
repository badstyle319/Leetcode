class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
		int cur = 0;
		int i = 0;
        int len = nums.size();
        while(cur < len - 1)
        {
            ans++;
            int pre = cur;
			for(; i <= pre; i++)
				cur = max(cur, i + nums[i]);
        }
        return ans;
    }
};