class Solution {
public:
    int minDeletions(string s) {
        vector<int> vf(26, 0);

        for (auto c : s) {
            vf[c - 'a']++; 
        }
        sort(vf.begin(), vf.end());

        int ans = 0;

        for (int i = 24; i >= 0; i--) {
            if (vf[i] == 0) {
                break;
            }

            if (vf[i] >= vf[i + 1]) {
                int prev = vf[i];

                vf[i] = max(0, vf[i + 1] - 1);

                ans += prev - vf[i];
            }
        }

        return ans;
    }
};
