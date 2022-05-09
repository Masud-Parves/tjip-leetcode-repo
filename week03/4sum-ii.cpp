class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        unordered_map < int , int > seen;
        
        for(int a:nums1){
            for(int b:nums2){
                seen[a+b]++;
            }
        }
        int cnt = 0;
        for(int c: nums3){
            for(int d:nums4){
                auto it = seen.find(-(c+d));
                if(it!=seen.end()){
                    cnt += it->second;
                }
            }
        }
        return cnt;
    }
};