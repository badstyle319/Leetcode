class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> result;
        for(int lowBound = ceil(sqrt(area));lowBound<=area;lowBound++){
            if(area%lowBound==0){
                result.push_back(lowBound);
                result.push_back(area/lowBound);
                break;
            }
        }
        return result;
    }
};