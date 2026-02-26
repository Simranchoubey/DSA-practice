/*410. Split Array Largest Sum
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
Return the minimized largest sum of the split.
A subarray is a contiguous part of the array.
Example 1:
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:
Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.*/

class Solution {
private:
    
    int countPartitions(vector<int> &a, int maxSum) {
        int n = a.size();
        int partitions = 1;
        long long subarraySum = 0;

        for (int i = 0; i < n; i++) {
            if (subarraySum + a[i] <= maxSum) {
                
                subarraySum += a[i];
            } else {
                
                partitions++;
                subarraySum = a[i];
            }
        }

        return partitions;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end()); 
        int high = accumulate(nums.begin(), nums.end(), 0);

        
        while (low <= high) {
            int mid = (low + high) / 2;
            int partitions = countPartitions(nums, mid);

            if (partitions > k) {
               
                low = mid + 1;
            } 
            else {
                
                high = mid - 1;
            }
        }
        return low;
    }
};
