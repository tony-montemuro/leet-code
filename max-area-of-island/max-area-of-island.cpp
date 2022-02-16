class Solution {
public:
    int getArea(std::vector<std::vector<int>>& grid, std::vector<std::vector<bool>>& visited, int y, int x) {
        // Recursive algorithm: Area starts off as 1, the state of the block is set to visited, and
        // the area is calculated of each of the 4 adjacent land masses, and added to the area. Then,
        // the area is returned.
        int area = 1;
        visited[y][x] = true;
        if (y-1 >= 0 && grid[y-1][x] == 1 && !visited[y-1][x]) {
            area += getArea(grid, visited, y-1, x);
        }
        if (x-1 >= 0 && grid[y][x-1] == 1 && !visited[y][x-1]) {
            area += getArea(grid, visited, y, x-1);
        }
        if (y+1 < grid.size() && grid[y+1][x] == 1 && !visited[y+1][x]) {
            area += getArea(grid, visited, y+1, x);
        }
        if (x+1 < grid[y].size() && grid[y][x+1] == 1 && !visited[y][x+1]) {
            area += getArea(grid, visited, y, x+1);
        }
        return area;
    }
    
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        // Two variables: one that stores the max area, and a secondary grid that stores which
        // stores information about which land blocks have been visited.
        int maxArea = 0;
        std::vector<std::vector<bool>> visited;
        for (int i = 0; i < grid.size(); i++) {
            std::vector<bool> v(grid[i].size());
            visited.push_back(v);
        }
        
        // Now, go through each block. If the block belongs to an island that hasn't been visited,
        // compute the area of the island, and compare with maxArea. If greater, update maxArea.
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int area = getArea(grid, visited, i, j);
                    if (area > maxArea) maxArea = area;
                }
            }
        }
        return maxArea;
    }
};
