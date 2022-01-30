class Solution {
public:
    //     int smallest(string a, string b) {
    //         for(int i=0; i<a.size(); i++) {
    //             if(a[i] < b[i]) return 0;
    //             else if(a[i] > b[i])  return 1;
    //         }
    //         return 0;
    //     }
    //     // brute force
    //     string kthLargestNumber(vector<string>& nums, int k) {
    //         // my approach would be to first short the array in ascending order then 
    //         // return kth element
    //         int n = nums.size();

    //         for(int i=0; i<n-1; i++) {
    //             for(int j = i+1; j<n; j++) {
    //                 if(nums[j].size() < nums[i].size()) {
    //                     // obviously a less length number will be smaller
    //                     swap(nums[i],  nums[j]);
    //                 } else if(nums[j].size() == nums[i].size()) {
    //                     // if length is same
    //                     if(smallest(nums[i], nums[j])) {
    //                         swap(nums[i],  nums[j]);
    //                     }
    //                 }
    //             }
    //         }

    //         return nums[n-k];
    //     }

        // using sort and custom comparator
    static bool comp(string& a, string& b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    }

    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), comp);
        return nums[nums.size() - k];
    }
};