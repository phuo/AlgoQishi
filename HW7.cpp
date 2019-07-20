/*
Leetcode 210
https://leetcode.com/problems/course-schedule-ii/
*/

#include <algorithm>
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        	vector<set<int>> graph(numCourses,set<int>{});
    	vector<int> inDegree(numCourses, 0);
    	for(auto pair : prerequisites){
    		graph[pair[0]].insert( pair[1] ); //construct graph
    		inDegree[pair[1]] +=1; //in-degree
    	}
    	//initialize the queue
    	queue<int> myQ;
    	std::vector<int> visited;
    	for(int i=0; i<numCourses; i++){
    		if(inDegree[i]==0){
    			myQ.push(i);
    			visited.push_back(i);
    		}
    	}
    	//topological sort
    	while( myQ.size()>0 ){
    		auto node = myQ.front(); myQ.pop();
    		for(auto subnode : graph[node]){
    			inDegree[subnode] -=1;
    			if(inDegree[subnode]==0){
    				myQ.push(subnode); visited.push_back(subnode);
    			}
    		}
    	}

        if(visited.size()==numCourses){
           return std::vector<int>(visited.rbegin(), visited.rend());
        }else{
            return std::vector<int>{};
        }

    }
};
/*
Leetcode 310
https://leetcode.com/problems/minimum-height-trees/
*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //bo yang cong

        vector<unordered_set<int>> graph(n,unordered_set<int>());
        std::vector<int> inDegree(n,0);

        for(auto edge : edges){
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);

            inDegree[edge[0]] ++;
            inDegree[edge[1]] ++;
        }//end

        set<int> mset;
        for(int i=0; i<n; i++) mset.insert(i);

        queue<int> Q;
        for(int i=0; i<n; i++){
            if(inDegree[i]==1) Q.push(i);
        }

        std::vector<int> out;
        while( Q.size()>0 &&(Q.size()!=mset.size()) ){
            //do level order tranverse
            int tt = Q.size();
            for(int k=0; k<tt; k++){
                int i = Q.front(); Q.pop();
                mset.erase(i);
                inDegree[i] = 0;//visited

                for(auto j : graph[i]){
                    graph[j].erase(i); inDegree[j] -=1;
                }
            }//end
           for(int j=0; j<n; j++) {
               if(inDegree[j] == 1) Q.push(j);
           }
        }

        for(auto y : mset) out.push_back(y);

        return out;
    }
};
