class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int x=0;
        int y=0;
        vector<vector<int>> r;
        while(x<nums1.size()&& y<nums2.size()){
            if(nums1[x][0]==nums2[y][0]){
                r.push_back({nums1[x][0],nums1[x][1]+nums2[y][1]});
                x++;
                y++;
            }
            
            else if(nums1[x][0]< nums2[y][0]){
                r.push_back(nums1[x]);
                x++;
            }
            else {
                r.push_back(nums2[y]);
                y++;
            }
        }
        while(x<nums1.size())
            r.push_back(nums1[x++]);
        while(y<nums2.size())
            r.push_back(nums2[y++]);
        return r;
    }
};