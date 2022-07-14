class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), 
             [](vector<int> &v1, vector<int> &v2)
             {
                 if(v1[1] == v2[1])
                     return v1[0] < v2[0];
                 return v1[1] < v2[1];
             });
        
        priority_queue<int> pq;
        int total = 0;
        for(auto &course:courses)
        {
            total += course[0];
            pq.push(course[0]);
            if(total > course[1])
            {
                total -= pq.top();
                pq.pop();
            }
        }
        
        return pq.size();
    }
};