class Solution {
    bool isBST(vector<int>& sequence, int left, int right){
        if(left == right) return true;
        
        int root = sequence[right], i = 0, j = 0;
        for(i = left; i<right; ++i)
            if(sequence[i] > root) break;
        
        for(j=i; j<right; ++j)
            if(sequence[j] < root) return false;
        bool is_left_bst = true, is_right_bst = true;
        if(left<=i-1)
            is_left_bst = isBST(sequence, left, i-1);
        if(i <= right -1)
            is_right_bst = isBST(sequence, i, right - 1);
        
        return is_left_bst && is_right_bst;
    }
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty()) return false;
        return isBST(sequence, 0, sequence.size() - 1);
    }
};