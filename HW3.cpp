
/*
Leetcode 934 Shortest Bridge:
https://leetcode.com/problems/shortest-bridge/
*/
class Solution {
public:
   //bfs + dfs

   void dfs(vector<vector<int>>& A, int i, int j, queue<pair<int,int>>& Q ){
       int m=A.size(), n = A[0].size();
       //outside matrix; visited
       if( i<0||i>=m || j<0 || j>=n || A[i][j] !=1 ) return;

       Q.push(pair<int, int>(i, j) );
       A[i][j]=-1;
    //   cout<<i<<" "<<j<<endl;
       dfs(A, i+1, j, Q);
       dfs(A, i-1, j, Q);
       dfs(A, i, j-1, Q);
       dfs(A, i, j+1, Q);
   }

   int shortestBridge(vector<vector<int>>& A) {

    int m=A.size();
    int n = m? A[0].size():0;
    if(m*n==0) return 0;

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int step=0;
     for(int i=0; i<m; i++){
         for(int j=0; j<n; j++){
             //find the 1st island,
             if( A[i][j] == 1 ){
                  //dfs push all adjacent islands
                  queue<pair<int,int>> Q;
                  dfs(A, i, j, Q);
                 //bfs
                  while(Q.size()>0){
                     int sz = Q.size();
                     for(int k=0; k<sz; k++){
                         auto ij = Q.front();
                         Q.pop();

                        for(int l=0; l<4; l++){
                           int ix=ij.first+dx[l], iy=ij.second+dy[l];
                           if( ix<0||ix>=m || iy<0 || iy>=n || A[ix][iy]<0 ) continue;
                           if( A[ix][iy]==1){
                               return step;
                           }else{
                               Q.push( pair<int,int>(ix, iy) );
                               A[ix][iy] = -1;
                           }
                        }
                     }
                     step++;
                 }//bfs
             }//dfs
         }
     }
   return 0;

   }
};


/*
Leetcode 542 01 Matrix:
https://leetcode.com/problems/01-matrix/
*/

class Solution {
public:

    bool inMatrix(int i, int j, int nrow, int ncol){
        if( i>=0 && i<nrow && j>=0 && j<ncol ){
            return true;
        }else{
            return false;
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int nrow = matrix.size();
         vector<vector<int>> nothing;
        if(nrow==0) return nothing;
        int ncol = matrix[0].size();
        if(ncol==0) return nothing;

        vector<int>row(ncol,-1);
        vector<vector<int>> out(nrow,row);

        queue<pair<int,int>> myQ;
        //find all zeros zero
        for(int i=0 ;i<nrow; i++){
            for(int j=0 ;j<ncol; j++){
                if( matrix[i][j]== 0){
                    myQ.push(pair<int,int>(i,j));
                    out[i][j]=0;
                }
            }
        }//

        int level=1;
        int dx[4] = {0,0,+1,-1};
        int dy[4] = {+1,-1,0,0};

        while( myQ.size()>0 ){

            int n = myQ.size();
            for(int t=0; t<n; t++){
                auto ij = myQ.front();
                int i=ij.first; int j=ij.second;
                myQ.pop();

                for(int k=0; k<4; k++){
                    //in Matrix && not visited
                    if( inMatrix(i+dx[k], j+dy[k], nrow, ncol) && out[i+dx[k]][j+dy[k]]==-1) {
                        myQ.push( pair<int,int>(i+dx[k], j+dy[k]) );
                        out[i+dx[k]][j+dy[k]] = level;
                    }
                }
            }

            level++;
        }
        return out;
    }
};

/*
Leetcode 513 Find Bottom Left Tree Value:
https://leetcode.com/problems/find-bottom-left-tree-value/
*/
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {

        queue<TreeNode*> Q;
        int bLeft = 0;
        if(root==NULL) return bLeft;

        Q.push(root);
        while( Q.size()>0 ){

            int n = Q.size();
            for(int i=0; i<n; i++){
                auto node = Q.front();

                if(i==0) bLeft=node->val;
                if( node->left !=NULL )  Q.push(node->left );
                if( node->right !=NULL ) Q.push(node->right );
                Q.pop();
            }

        }
        return bLeft;

    }
};
/*
Leetcode 200 Number of Islands:
https://leetcode.com/problems/number-of-islands/
*/

class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int nrow = grid.size();
        if(nrow==0) return cnt;
        int ncol = grid[0].size();
        if(ncol==0) return cnt;

        for(int i=0; i<nrow; i++){
            for(int j=0; j<ncol; j++){
                if( grid[i][j] =='1' ){
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }//i

        return cnt;
    }
private:
    void dfs( vector<vector<char>>& grid, int i, int j){

        //if(i<0 ||j<0 ||i>=nrow||j>=ncol|| grid[i][j]=='0' ) return;
       int m = grid.size(), n = grid[0].size();
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
            return;
        }
        grid[i][j]='0';
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
};
