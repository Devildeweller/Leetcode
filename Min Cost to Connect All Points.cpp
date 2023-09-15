class Solution {
public:
    int distance(vector<int>&point1,vector<int>&point2){
        return abs(point1[0]-point2[0])+ abs(point1[1]-point2[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<int> visited(n,0);
        vector<int> minCost(n,INT_MAX);

        int cp=0;
        int ans=0;

        while(cp>=0){
            visited[cp]=1;
            int np=-1;

            int mind=INT_MAX;
            for(int p=0;p<n;p++){
                if(visited[p] || cp==p){
                    continue;
                }
                minCost[p]=min(distance(points[cp],points[p]),minCost[p]);
                if(minCost[p]<mind)
                {
                    mind=minCost[p];
                    np=p;
                }
            }

            if(mind==INT_MAX){
                ans+=0;
            }
            else{
                ans+=mind;
            }
            
            cp=np;
            
        }
        return ans;
        
    }
};
