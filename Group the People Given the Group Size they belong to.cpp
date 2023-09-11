class Solution {
public:
    //you can get the code from my github link given below

    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        //here we have declared the map and our ans
        unordered_map<int, vector<int>> groups;
        vector<vector<int>> ans;


        for (int i = 0; i < groupSizes.size(); i++) {
            //now we are putting index in their groups
            int size = groupSizes[i];
            groups[size].push_back(i);
            //here when the group size is full we push it to ans
            // clear the vector in map
            if (groups[size].size() == size) {
                ans.push_back(groups[size]);
                groups[size].clear();
            }
        }
        //here we are pushing the remaining groups
        for (auto& kv : groups) {
            if (!kv.second.empty()) {
                ans.push_back(kv.second);
            }
        }

        return ans;
    }
};



















