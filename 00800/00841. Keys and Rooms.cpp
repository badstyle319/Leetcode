class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> visited{{0}};
        queue<int> q{{0}};
        
        while(!q.empty())
        {
            int room = q.front(); q.pop();
            for(auto key:rooms[room])
            {
                if(visited.count(key))
                    continue;
                visited.insert(key);
                if(visited.size() == rooms.size())
                    return true;
                q.push(key);
            }
        }
        
        return visited.size() == rooms.size();
    }
};