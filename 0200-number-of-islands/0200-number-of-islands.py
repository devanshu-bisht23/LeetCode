from collections import deque

class Solution:

    def bfs(self, row, col, visited, grid):

        visited[row][col] = 1
        q = deque()

        n = len(grid)
        m = len(grid[0])

        q.append((row,col))

        drow = [-1,0,1,0]
        dcol = [0,1,0,-1]

        while q:

            temp = q[0]

            currRow = temp[0]
            currCol = temp[1]

            q.popleft()

            for i in range(4):
                nrow = currRow + drow[i]
                ncol = currCol + dcol[i]

                if (nrow>=0 and nrow<n and 
                    ncol>=0 and ncol < m and 
                    not visited[nrow][ncol] and 
                    grid[nrow][ncol] == "1"):

                    visited[nrow][ncol] = 1
                    q.append((nrow,ncol))




    def numIslands(self, grid: List[List[str]]) -> int:
        
        n = len(grid)
        m = len(grid[0])

        visited = []
        count = 0

        for i in range(n):
            row = []

            for j in range(m):
                row.append(0)

            visited.append(row)

        for row in range(n):
            for col in range(m):

                if(not visited[row][col] and grid[row][col] == '1'):
                    count+=1
                    self.bfs(row, col,visited, grid)

        return count