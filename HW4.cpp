/*
Leetcode 90:
https://leetcode.com/problems/subsets-ii/
*/
class Solution {
public:

    void dfs(vector<vector<int>>& res, vector<int>& out, vector<int>& nums, int pos ){
        //push for each one
        res.push_back(out);
        for(int i=pos; i<nums.size(); i++){

            if(i>pos &&nums[i]==nums[i-1]) continue;

            out.push_back(nums.at(i));
            dfs(res, out, nums, i+1);
            out.pop_back();
        }
    }//end

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out;
        // sort using a standard library compare function object
        std::sort(nums.begin(), nums.end());
        dfs(res, out, nums, 0);
        return res;
    }
};
/*
Leetcode 40:
https://leetcode.com/problems/combination-sum-ii/
*/
class Solution {
public:

    void dfs(vector<vector<int>>& res, vector<int>& out, vector<int>& candidates, int pos, int target){

        if( target==0 ){
            res.push_back(out);
            return;
        }

        for(int i=pos; i<candidates.size(); i++){
            if(i>pos && candidates[i]==candidates[i-1] ) continue;
            if(target-candidates[i] < 0 )  continue;
            out.push_back( candidates.at(i) );
            dfs(res, out, candidates, i+1,  target-candidates[i] );
            out.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int>>res;
        vector<int> out;
        dfs(res, out, candidates, 0,  target );
        return res;
    }
};

/*
Leetcode 216:
https://leetcode.com/problems/combination-sum-iii/
*/
class Solution {
public:

    void dfs( vector<vector<int>>& res,vector<int>& out,  int n, int k, int pos ){

        if(n==0 && k==0){
            res.push_back(out);
            return;
        }

        for(int i=pos; i<= std::min(n, 9) ; i++){
              out.push_back(i);
              dfs(res, out, n-i, k-1, i+1);
              out.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
            vector<vector<int>> res;
            vector<int> out;
            dfs(res, out, n, k, 1);
            return res;
    }
};
/*
Leetcode 47:
https://leetcode.com/problems/permutations-ii/
*/
class Solution {
public:
    //std permutation
    //in place is not good, do out-of-place
    void dfs(vector<vector<int>>& res, vector<int>& out,  vector<int>& nums, vector<bool>& used){
        if(out.size()==nums.size()){
            res.push_back(out);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(used[i]) continue;
            if(i>0 &&nums[i]==nums[i-1]  && !used[i-1] ) continue;

            out.push_back( nums[i] );
            used[i]=true;
            dfs(res, out,  nums, used);
            out.pop_back();
            used[i]=false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> out;
        vector<bool> used(nums.size(), false);
        dfs(res, out, nums, used);
        return res;
    }
};
/*
Leetcode 77:
https://leetcode.com/problems/combinations/
*/
class Solution {
public:
    
   void helper( vector<vector<int>>& out, vector<int>& nums, int pos,  int cnt, int n, int k){
        if(cnt==k){
            out.push_back( nums );
            return;
        }

        for(int j=pos; j<n; j++){
           nums.push_back(j+1);
            helper(out, nums, j+1, cnt+1,n, k );
           nums.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> out;
        vector<int> nums;
        helper(out, nums, 0, 0,n, k );
        return out;
    }
};
