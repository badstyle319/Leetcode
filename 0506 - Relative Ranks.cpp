class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        map<int, int> mp;
        map<int, int>::reverse_iterator it;
        vector<string> result(nums.size(), "");
        int counter = 0;
        int len = nums.size();
        
        for(int i=0;i<len;i++){
            mp[nums[i]] = i;
        }
        
        for(it=mp.rbegin();it!=mp.rend();it++){
            switch(counter){
                case 0:
                    result[it->second] = "Gold Medal";
                    break;
                case 1:
                    result[it->second] = "Silver Medal";
                    break;
                case 2:
                    result[it->second] = "Bronze Medal";
                    break;
                default:
                    stringstream ss;
                    ss<<(counter+1);
                    result[it->second] = ss.str();
            }
            counter++;
        }
        
        return result;
    }
};