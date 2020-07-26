class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        
        int j = len - 1;
        for(int i = 0; i < len; i++)
        {
            int temp = target - numbers[i];
            for(; j > i && numbers[j] > temp; j--);
            if(numbers[j] == temp)
                return vector<int>{i+1, j+1};
        }
        return vector<int>();
    }
};