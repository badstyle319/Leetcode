class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int left=0, right=numbers.size()-1, sum;
        while(left<right){
            sum = numbers[left]+numbers[right];
            if(sum==target){
                ans.push_back(left+1);
                ans.push_back(right+1);
                break;
            }else if(sum>target)
                right--;
            else
                left++;
        }
        return ans;
    }
};