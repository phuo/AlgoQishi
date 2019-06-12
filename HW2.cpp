


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
