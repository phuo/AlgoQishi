Group B:
/*
Leetcode 518 Coin Change 2:
https://leetcode.com/problems/coin-change-2/
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> row(amount+1, 0);
        vector<vector<int>> N(n+1,row);

        for(int i=0; i<n+1; i++) N[i][0] = 1;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=amount; j++){
                //end
                N[i][j] = N[i-1][j] + ( j>=coins[i-1] ? N[i][j-coins[i-1]] : 0 );
            }
        }
        return N[n][amount];
    }
};
/*
Leetcode 63 Unique Paths II:
https://leetcode.com/problems/unique-paths-ii/
*/
class Solution {
public:
   int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size() , n = obstacleGrid[0].size();
        vector<vector<long>> dp(m+1,vector<long>(n+1,0));
        dp[0][1] = 1;
        for(int i = 1 ; i <= m ; ++i)
            for(int j = 1 ; j <= n ; ++j)
                if(!obstacleGrid[i-1][j-1])
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
        return dp[m][n];
    }
};
/*
Leetcode 5 Longest Palindromic Substring:
https://leetcode.com/problems/longest-palindromic-substring/
*/
class Solution {
public:


    string longestPalindrome(string s) {
        int n = s.size();
        if (s.size() < 2) return s;

        vector<int> row(n, 0);
        vector<vector<int>> state(n, row);
        int max = 1;
        int start = 0;

        for(int i=0; i<n; i++) state[i][i] = 1;
        for(int i=0; i<n-1; i++){
        	if(s[i]==s[i+1]){
        		state[i][i+1] = 1;
        		max = 2;
        		start = i;
        	}
        }

        for(int len=3; len<=n; len++){
        	for(int i=0; i<n-len+1; i++){
        			if( s[i] == s[i+len-1] && state[i+1][i+len-1-1]==1 ){
        				max = len;
        				start = i;
        				state[i][i+len-1] = 1;
        			}
        	}
        }

        return s.substr(start, max);

    }
};
/*
Leetcode 64 Minimum Path Sum:
https://leetcode.com/problems/minimum-path-sum/
*/
class Solution {
public:
   int minPathSum(vector<vector<int>>& grid) {
        int nrow = grid.size();
        int ncol = grid[0].size();

        std::vector<vector<int>> steps;

        for(int i=0; i<nrow; i++){
        	auto vec = grid.at(i);
        	steps.push_back(vec);
        }

        //along axis = 0
        for(int i=1; i<ncol; i++) steps[0][i] += steps[0][i-1];
        for(int i=1; i<nrow; i++) steps[i][0] += steps[i-1][0];
        //along axis = 1

        for(int i=1; i<nrow; i++){
        	for(int j=1; j<ncol; j++){
        		steps[i][j] = grid[i][j] + min(steps[i][j-1], steps[i-1][j]);
        	}
        }
        return steps[nrow-1][ncol-1];
    }
};
