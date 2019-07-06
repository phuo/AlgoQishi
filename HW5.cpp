
/*
1. Leetcode 4. Median of Two Sorted Arrays
https://leetcode.com/problems/median-of-two-sorted-arrays
*/
class Solution {
public:
    int findKth(vector<int>& nums1, vector<int>& nums2, int i,  int j, int k) {
        if (i >= nums1.size()) return nums2[j + k - 1];
        if (j >= nums2.size()) return nums1[i + k - 1];
        if (k == 1) return min(nums1[i], nums2[j]);
        int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
        int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
        if (midVal1 < midVal2) {
            return findKth(nums1, nums2, i + k / 2, j, k - k / 2);
        } else {
            return findKth(nums1, nums2, i, j + k / 2, k - k / 2);
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int left = (m + n + 1) / 2;
        int right = (m + n + 2) / 2;
        return (findKth(nums1, nums2, 0, 0, left) + findKth(nums1, nums2,0,  0, right)) / 2.0;
    }
};

/*
2. Leetcode 973. K Closest Points to Origin
https://leetcode.com/problems/k-closest-points-to-origin/
*/
class Solution {
public:

    int dis(vector<int> point){
        return point[0]*point[0] + point[1]*point[1];
    }

    int partition(vector<vector<int>>& nums, int left, int right) {
        int pivot = dis(nums[left]), l = left + 1, r = right;
        while (l <= r) {
            if (dis(nums[l]) > pivot && dis(nums[r]) < pivot) {
                swap(nums[l++], nums[r--]);
            }
            if (dis(nums[l]) <= pivot) {
                l++;
            }
            if (dis(nums[r]) >= pivot) {
                r--;
            }
        }
        swap(nums[left], nums[r]);
        return r;
    }


    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //based on quick select
    vector<vector<int>> result(k);
      if(points.size()==0) return  result;
     int left = 0, right = points.size() - 1;
        while (true) {
            int idx = partition(points, left, right);
            if (idx == k - 1) {
                break;
            }
            if (idx < k - 1) {
                left = idx + 1;
            } else {
                right = idx - 1;
            }
        }
         std::copy( points.begin(), points.begin()+k, result.begin() );
        return result;

    }
};
/*
3. Leetcode 53. Maximum Subarray
https://leetcode.com/problems/maximum-subarray/
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        max_ending_here = max_ending_here + nums[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
    }
};


/*
4. Leetcode 215. Kth Largest Element in an Array
https://leetcode.com/problems/kth-largest-element-in-an-array/
*/
class Solution {
public:

        int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1, kth;
        while (true) {
            int idx = partition(nums, left, right);
            if (idx == k - 1) {
                kth = nums[idx];
                break;
            }
            if (idx < k - 1) {
                left = idx + 1;
            } else {
                right = idx - 1;
            }
        }
        return kth;
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot) {
                l++;
            }
            if (nums[r] <= pivot) {
                r--;
            }
        }
        swap(nums[left], nums[r]);
        return r;
    }
};
