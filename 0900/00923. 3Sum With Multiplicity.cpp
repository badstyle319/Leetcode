class Solution {
    const int MOD = 1e9 + 7;
public:
    int threeSumMulti(vector<int>& arr, int target) {
        long long ans = 0;
        map<int, long long> mp;
        
        sort(arr.begin(), arr.end());
        for(auto &num:arr)
        {
            mp[num]++;
        }
        
        auto it = unique(arr.begin(), arr.end());
        arr.resize(distance(arr.begin(), it));
        
        //x == y == z
        if(target % 3 == 0 && mp.count(target/3) && mp[target/3] >= 3)
        {
            ans += mp[target/3] * (mp[target/3] - 1) * (mp[target/3] - 2) / 6;
            ans %= MOD;
        }
        
        // x == y != z
        for(int i = 0; i < arr.size() && (arr[i] << 1) <= target; i++)
        {
            if(mp[arr[i]] >= 2)
            {
                int z = target - (arr[i] << 1);
                if(mp.count(z) && z != arr[i])
                {
                    ans += mp[arr[i]] * (mp[arr[i]] - 1) / 2 * mp[z];
                    ans %= MOD;
                }
            }
        }

        // x != y != z
        if(arr.size() < 3)
            return ans;
        for(int i = 0; i < arr.size() - 2 && arr[i] < target; i++)
        {
            for(int j = i + 1; j < arr.size() - 1 && arr[i] + arr[j] < target; j++)
            {
                int z = target - arr[i] - arr[j];
                cout << arr[i] << " " << arr[j] << " " << z << endl;
                if(mp.count(z) && z > arr[j])
                {
                    ans += mp[arr[i]] * mp[arr[j]] * mp[z];
                    ans %= MOD;
                }
            }
        }
        
        return (int)ans;
    }
};