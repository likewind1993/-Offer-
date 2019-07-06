class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix)
    {
        vector<int> ans;
        if (matrix.empty()) return ans;
        int l = 0, r = matrix[0].size() - 1, u = 0, d = matrix.size() - 1;
        while (l <= r && u <= d)
        {
            for (int i = l; i <= r; ++i) ans.push_back(matrix[u][i]);
            if(++u>d) break;

            for (int i = u; i <= d; ++i) ans.push_back(matrix[i][r]);
            if(--r<l) break;

            for (int i = r; i >= l; --i) ans.push_back(matrix[d][i]);
            if(--d<u) break;

            for (int i = d; i >= u; --i) ans.push_back(matrix[i][l]);
            ++l;
        }
        return ans;
    }
};