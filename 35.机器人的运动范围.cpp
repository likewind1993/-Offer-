class Solution {
    vector<vector<int>> move = { { -1, 0 },{ 1, 0 },{ 0, -1 },{ 0, 1 } };
    int countDigit(int r, int c)
    {
        int sum = 0;
        while (r)
        {
            sum += r % 10;
            r /= 10;
        }
        while (c)
        {
            sum += c % 10;
            c /= 10;
        }
        return sum;
    }
    int movingGrid(vector<vector<int>>& matrix, int threshold, int rows, int cols, int r, int c)
    {
        if (r < 0 || r >= rows || c<0 || c >= cols || countDigit(r, c) > threshold || matrix[r][c] == 1)
            return 0;
        int count = 1;
        matrix[r][c] = 1;
        for (int i = 0; i < 4; ++i)
        {
            count += movingGrid(matrix, threshold, rows, cols, r + move[i][0], c + move[i][1]);
        }
        return count;
    }
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if (rows < 1 || cols < 1 || threshold < 0) return 0;
        vector<vector<int>> matrix(rows, vector<int>(cols, 0));
        return movingGrid(matrix, threshold, rows, cols, 0, 0);
    }
};