class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = (int)nums.size();
        
//         for(int i = 0; i < len; i++)
//         {
//             if(!nums[i])
//             {
//                 for(int j = i + 1; j < len; j++)
//                 {
//                     if(nums[j])
//                     {
//                         swap(nums[i], nums[j]);
//                         break;
//                     }
//                 }
//             }
//         }
        
        int idx = 0;
        for(int i = 0; i < len; i++)
        {
            if(nums[i])
            {
                nums[idx] = nums[i];
                idx++;
            }
        }
        for(int i = idx; i < len; i++)
            nums[i] = 0;
    }
};