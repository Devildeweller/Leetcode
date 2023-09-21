class Solution {
public:
    double getMedian(vector<int>ar1, vector<int> ar2, int n, int m)
        {
            int i = 0; 
            int j = 0; 
            int count;
            int m1 = -1, m2 = -1;
            for (count = 0; count <= (m + n) / 2; count++) {
                m2 = m1;
                if (i != n && j != m) {
                    m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
                }
                else if (i < n) {
                    m1 = ar1[i++];
                }
                else {
                    m1 = ar2[j++];
                }
            }
            if ((m + n) % 2 == 1) {
                return m1;
            }
            else {
                return (m1 + m2) / (2*1.0);
            }
        }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return getMedian(nums1,nums2,nums1.size(),nums2.size());
    }
};
