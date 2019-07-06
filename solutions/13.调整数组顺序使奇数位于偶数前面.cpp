class Solution {
    void exchangeVal(vector<int> & array, int i, int j)
    {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

public:
    void reOrderArray(vector<int> &array)
    {
        int n = array.size();
        if (n <= 1) return;
        int i = 0, j = 1;
        while ( i< j && j < n)
        {
            while (j <n && (array[j] & 1) == 0 ) ++j;
            while (i <n && (array[i] & 1) == 1 ) ++i;
            if (i < j && j<n)
            {
                exchangeVal(array, i, j);
                for (int k = j; k - 1 > i; --k)
                    exchangeVal(array, k, k - 1);
            }
        }
    }
};