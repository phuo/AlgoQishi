/*
69. Sqrt(x)
https://leetcode.com/problems/sqrtx/
Runtime: 8 ms, faster than 51.97% of C++ online submissions for Sqrt(x).
Memory Usage: 8.4 MB, less than 45.24% of C++ online submissions for Sqrt(x).
*/
class Solution {
public:
    int mySqrt(int x) {
        if(x<=1) return x;
        int s =1, e =x;
        while(s+1<e){
            int  mid = s +(e-s)/2;
            if( x/mid == mid ){ //prevent overflow
                return mid;
            }else if(x/mid>mid){
                s = mid;
            }else if(mid>x/mid){
                e = mid;
            }
        }
        return s;
    }
};
/*
74. Search a 2D Matrix
https://leetcode.com/problems/search-a-2d-matrix/
Runtime: 12 ms, faster than 83.82% of C++ online submissions for Search a 2D Matrix.
Memory Usage: 10 MB, less than 46.10% of C++ online submissions for Search a 2D Matrix.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int T) {

        int nrow = matrix.size();
        int len = nrow;
        if(len<1) return false;
        int ncol = matrix[0].size();
        len *= ncol;
        if(len<1) return false;

        int s=0, e=len-1;
        while(s+1<e){
            int mid = s + (e-s)/2;

            int i = mid/ncol;
            int j = mid%ncol;

            if( matrix[i][j]<T ){
                s = mid;
            }else if( matrix[i][j]>T ){
                e = mid;
            }else{
                return true;
            }

        }

        if( matrix[(s)/ncol][(s) % ncol] == T ||  matrix[(e)/ncol][(e) % ncol] == T ){
            return true;
        }else{
            return false;
        }

    }
};
/*
33. Search in Rotated Sorted Array
https://leetcode.com/problems/search-in-rotated-sorted-array/
Runtime: 4 ms, faster than 93.93% of C++ online submissions for Search in Rotated Sorted Array.
Memory Usage: 8.7 MB, less than 82.86% of C++ online submissions for Search in Rotated Sorted Array.
*/
class Solution {
public:
    int search(vector<int>& nums, int T) {

        if(nums.size()==0) return -1;
        //general case
        int s = 0, e = nums.size()-1;

        //twisted version
        while( s+1 < e ){
            int mid = s + (e-s)/2;

            if(nums[mid] == T){
                return mid;
            }else if(nums[mid] >T){
                //blend, T right, mid L
                if( nums[s] > nums[e] && T<=nums[e] && nums[mid]>= nums[s]) s = mid;
                else e = mid;
            }else{
                //blend, T left, mid right
                 if( nums[s] > nums[e] && T>=nums[s] && nums[mid]<=nums[e]) e = mid;
                else s = mid;
            }

        }//end

        if( nums[s]==T) return s;
        if( nums[e]==T) return e;
        return -1;
    }
};
/*
278. First Bad Version
https://leetcode.com/problems/first-bad-version/submissions/
Runtime: 0 ms, faster than 100.00% of C++ online submissions for First Bad Version.
Memory Usage: 8.2 MB, less than 53.49% of C++ online submissions for First Bad Version.
*/
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s = 1, e = n;
        while( s+1 < e){

            int mid = s + (e-s)/2;
            if (isBadVersion(mid)) e = mid;
            else s = mid;
        }
        if (isBadVersion(s)) return s;
        else return e;
    }
};

/*
300. Longest Increasing Subsequence
https://leetcode.com/problems/longest-increasing-subsequence/
Runtime: 40 ms, faster than 49.06% of C++ online submissions for Longest Increasing Subsequence.
Memory Usage: 8.8 MB, less than 9.89% of C++ online submissions for Longest Increasing Subsequence.
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
     //DP
     int n = nums.size();
     if(n<1) return 0;

     vector<int> seqLen(n,1);
      for(int j=1; j<n; j++){

          for(int i=0; i<j; i++){
            if(nums[i] < nums[j] ){
                seqLen[j] = std::max( 1 + seqLen[i], seqLen[j]);
            }
          }//end
      }
    std::vector<int>::iterator result;
    result = std::max_element(seqLen.begin(), seqLen.end());
    return *result;
    }
};
