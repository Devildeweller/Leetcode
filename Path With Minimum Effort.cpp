class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> dirs = {{-1,0},{0,-1},{0,1},{1, 0}};
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();
        
        
        auto isSafe = [&](int x, int y) {
            return x>=0 && x<r && y>=0 && y<c;
        };
        
        vector<vector<int>> result(r, vector<int>(c, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        
        result[0][0]=0;
        pq.push({0, {0, 0}});

        while(!pq.empty()) {
            int diff  = pq.top().first;

            int x = pq.top().second.first;
            int y = pq.top().second.second;

            pq.pop();
            
            for(auto dir : dirs) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(isSafe(x_, y_)) {
                    int newDiff = max(diff, abs(heights[x][y] - heights[x_][y_]));
                    if(result[x_][y_] > newDiff) {
                    result[x_][y_] = newDiff;
                    pq.push({result[x_][y_], {x_, y_}});
                    }
                }
            }
            
        }

        return result[r-1][c-1];

    }
};
