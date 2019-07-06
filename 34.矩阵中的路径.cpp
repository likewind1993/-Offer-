class Solution {
private:
    vector<vector<int>>move = { { -1, 0 },{ 1, 0 },{ 0, 1 },{ 0, -1 } };
    int getIndex(int rows, int cols, int r, int c)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            return -1;
        return r * cols + c;
    }
    vector<int> getRowAndCol(int rows, int cols, int index)
    {
        int r = index / cols, c = index % cols;
        return vector<int>{r, c};
    }
    void findPath(char * matrix, bool * visited, int rows, int cols, int index, char * str, int & s_i, bool & ans, int str_len)
    {
        if (ans)
            return;
        if (s_i == str_len)
        {
            ans = true;
            return;
        }
        vector<int> r_and_c = getRowAndCol(rows, cols, index);
        int r = r_and_c[0], c = r_and_c[1];
        for (int i = 0; i < 4; ++i)
        {
            int new_index = getIndex(rows, cols, r + move[i][0], c + move[i][1]);
            if (new_index == -1)
                continue;
            if (visited[new_index] == false && matrix[new_index] == str[s_i])
            {
                ++s_i;
                visited[new_index] = true;
                findPath(matrix, visited, rows, cols, new_index, str, s_i, ans, str_len);
                visited[new_index] = false;
                --s_i;
            }
        }
    }
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if (str == NULL) return true;
        int length = rows * cols, s_i = 1, str_len = strlen(str);
        bool * visited = new bool[length], ans = false;
        for (int i = 0; i < length; ++i) visited[i] = false;
        for (int i = 0; i < length; ++i)
        {
            if (matrix[i] == str[0])
            {
                visited[i] = true;
                findPath(matrix, visited, rows, cols, i, str, s_i, ans, str_len);
                visited[i] = false;
            }
        }
        delete [] visited;
        return ans;
    }
};