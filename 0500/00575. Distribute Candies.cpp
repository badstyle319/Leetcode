class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> s;
        for(auto &type:candyType)
            s.insert(type);
        
        return min(s.size(), candyType.size() / 2);
    }
};