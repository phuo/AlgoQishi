

// 783. Minimum Distance Between BST Nodes
//https://leetcode.com/problems/minimum-distance-between-bst-nodes/
class Solution {
public:

    int dfs( TreeNode* root, TreeNode* & prev  ){
     //inorder
       if(root==NULL) return INT_MAX;

        auto left = dfs(root->left, prev);
        auto diff = INT_MAX;
        if(prev){
            diff = abs(prev->val - root->val);
        }
        prev=root;

        auto right = dfs(root->right, prev);
        return min(min(left,right),diff);
    }

    int minDiffInBST(TreeNode* root) {
        //dfs + inorder
        TreeNode* prev=NULL;
        return dfs(root, prev);
    }
};

//247.  Strobogrammatic Number II
//https://www.lintcode.com/problem/strobogrammatic-number-ii/description
class Solution {
public:
   vector<string> helper(int n, int length){
       vector<string> a;
        if(n==1){
            a =  {"0","1","8"};
        }else if(n==0){
            a= {""};
        }else{
            auto strs = helper(n-2, length);
            for(auto str : strs){
                if(n!=length) a.push_back(  '0'+str+'0' );
                 a.push_back( '1'+str+'1' );
                 a.push_back( '6'+str+'9' );
                 a.push_back( '9'+str+'6' );
                 a.push_back( '8'+str+'8' );
            }//end
        }
        return a;
   }

    vector<string> findStrobogrammatic(int n) {
        // write your code here
        vector<string> myVector = helper( n , n);
        return myVector;
    }
};

//544.  Output Contest Matches
//https://www.lintcode.com/problem/output-contest-matches/
class Solution {
public:
     string helper( int n,  vector<string> vec){
        if(n==1) return vec[0];
        int len = vec.size();

        vector<string> vec1;
         for(int i=0; i<n/2; i++){
            string s = "(" + vec[i] +"," +vec[len-i-1] +")";
            vec1.push_back(s);
         }
       return helper(n/2, vec1);
     }
    string findContestMatch(int n) {

        vector<string> vec;
        for(int i=1; i<=n; i++){
             vec.push_back(to_string(i));
        }
        string res = helper(n, vec);
        return res;

    }
};


//698. Partition to K Equal Sum Subsets
//https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

class Solution {
public:

    bool helper( vector<int>& nums, int avg, int k, int start,  int cursum, vector<bool>& visited  ){

        if(k==1) return true;

        if(cursum==avg) return helper(nums,avg,  k-1, 0, 0, visited);

        for(int i=start; i<nums.size(); i++){
            if( visited[i] ) continue;
            visited[i] = true;
            if( helper( nums,  avg, k, i+1,  cursum+nums[i], visited )) return true;
            visited[i] = false;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for( int i=0; i<nums.size(); i++){
            sum += nums[i];
        }

        if(sum%k >0 ) return false;
        vector<bool> visited(nums.size(), false);

        return helper( nums, sum/k, k, 0, 0, visited );
    }
};
