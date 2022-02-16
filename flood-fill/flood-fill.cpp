class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Initialize currColor variable: stores color at image[sr][sc]
        int currColor = image[sr][sc];
        
        // Trivial Case: If the new color is same as current color, board is already filled. Simply
        // return image.
        if (newColor == currColor) return image;
        
        // Assign new color to current position, and traverse to pixels adjacent to current location.
        image[sr][sc] = newColor;
        if (sr-1 >= 0 && image[sr-1][sc] == currColor) {
            image = floodFill(image, sr-1, sc, newColor);
        }
        if (sc-1 >= 0 && image[sr][sc-1] == currColor) {
            image = floodFill(image, sr, sc-1, newColor);
        }
        if (sr+1 < image.size() && image[sr+1][sc] == currColor) {
            image = floodFill(image, sr+1, sc, newColor);
        }
        if (sc+1 < image[sr].size() && image[sr][sc+1] == currColor) {
            image = floodFill(image, sr, sc+1, newColor);
        }
        return image;
    }
};
