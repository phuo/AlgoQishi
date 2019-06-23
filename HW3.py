Group B:

#Leetcode 934 Shortest Bridge:
#https://leetcode.com/problems/shortest-bridge/
class Solution:
    def shortestBridge(self, A: List[List[int]]) -> int:

        n, steps, Q = len(A), 0, collections.deque()

        def dfs(x,y):
            #find all grid belong to a island and push to queue
            if 0<=x<n and 0<=y<n and A[x][y]==1:
                Q.append( (x,y) )
                A[x][y] = -1
                for i,j in ((x+1,y), (x-1,y), (x,y+1), (x,y-1)):
                    dfs(i,j)

        #find first island
        def firstIsland():
            for i in range(n):
                for j in range(n):
                    if A[i][j]:
                        return i, j

        dfs( *firstIsland() )
        #BFS to find second island
        while Q:
            newQ = collections.deque()
            for x,y in Q:
                for i,j in ((x+1,y), (x-1,y), (x,y+1), (x,y-1)):
                    #inside scope of the grid
                    if 0<=i<n and 0<=j<n:
                        if  A[i][j] == 1:
                            return steps
                        elif not A[i][j]:
                            A[i][j] = -1
                            newQ.append( (i,j) )
            Q = newQ
            steps += 1
        return steps



#Leetcode 542 01 Matrix:
#https://leetcode.com/problems/01-matrix/
class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        n, m, Q = len(matrix), len(matrix[0]), collections.deque()

        #find all zeros
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    Q.append( (i,j) )
                else:
                    matrix[i][j] = sys.maxsize
        #bfs
        step = 1
        while Q:
            newQ = collections.deque()
            for x,y in Q:
                for i,j in ((x+1,y), (x-1,y), (x,y+1), (x,y-1)):
                     #in scope and not visited
                    if 0<=i<n and 0<=j<m and matrix[i][j]==sys.maxsize:
                        matrix[i][j] = step
                        newQ.append( (i,j) )
            step+=1
            Q = newQ

        return matrix


#Leetcode 513 Find Bottom Left Tree Value:
#https://leetcode.com/problems/find-bottom-left-tree-value/
class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        #standard BFS + iteratively update the left most element
        Q =collections.deque()
        Q.append(root)
        leftMost = root.val

        while Q:
            newQ = collections.deque()
            for cnt, node  in enumerate(Q):
                if cnt==0:
                    leftMost = node.val
                if node.left:
                    newQ.append(node.left)
                if node.right:
                    newQ.append(node.right)
            Q = newQ

        return leftMost



#Leetcode 200 Number of Islands:
#https://leetcode.com/problems/number-of-islands/
class Solution:
    def numIslands(self, A: List[List[str]]) -> int:
        #dfs
        if len(A)==0:
            return 0

        n, m, count = len(A), len(A[0]), 0

        def dfs(x,y):
            #find all grid belong to a island and push to queue
            if 0<=x<n and 0<=y<m and A[x][y]=='1':
                A[x][y] = '0'
                for i,j in ((x+1,y), (x-1,y), (x,y+1), (x,y-1)):
                    dfs(i,j)

        for i in range(n):
            for j in range(m):
                if A[i][j]=='1':
                    dfs(i,j)
                    count += 1

        return count


#Optional:

#Leetcode 129 Sum Root to Leaf Numbers:
#https://leetcode.com/problems/sum-root-to-leaf-numbers/
class Solution:

    def sumNumbers(self, root: TreeNode) -> int:
        self.res = 0
        self.dfs(root, 0)
        return self.res

    def dfs(self, root, value):
        if root:

            self.dfs(root.left, value*10+root.val)
            self.dfs(root.right, value*10+root.val)
            #at leaf
            if not root.left and not root.right:
                self.res += value*10 + root.val

#Leetcode 127 Word Ladder:
#https://leetcode.com/problems/word-ladder/
from collections import defaultdict
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList or not endWord or not beginWord or not wordList:
            return 0

        # Since all words are of same length.
        L = len(beginWord)

        # Dictionary to hold combination of words that can be formed,
        # from any given word. By changing one letter at a time.
        all_combo_dict = defaultdict(list)
        for word in wordList:
            for i in range(L):
                # Key is the generic word
                # Value is a list of words which have the same intermediate generic word.
                all_combo_dict[word[:i] + "*" + word[i+1:]].append(word)

        # Queue for BFS
        queue = [(beginWord, 1)]
        # Visited to make sure we don't repeat processing same word.
        visited = {beginWord: True}
        while queue:
            current_word, level = queue.pop(0)
            for i in range(L):
                # Intermediate words for current word
                intermediate_word = current_word[:i] + "*" + current_word[i+1:]

                # Next states are all the words which share the same intermediate state.
                for word in all_combo_dict[intermediate_word]:
                    # If at any point if we find what we are looking for
                    # i.e. the end word - we can return with the answer.
                    if word == endWord:
                        return level + 1
                    # Otherwise, add it to the BFS Queue. Also mark it visited
                    if word not in visited:
                        visited[word] = True
                        queue.append((word, level + 1))
                all_combo_dict[intermediate_word] = []
        return 0
