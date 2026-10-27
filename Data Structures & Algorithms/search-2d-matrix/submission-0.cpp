class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size()==0 || matrix[0].size()==0) return false;
        int lowRow=0;
        int highRow =matrix.size()-1;

        while (highRow-lowRow > 1)
        {
            int midRow = lowRow + (highRow-lowRow)/2;

            if (target == matrix[midRow][0]) return true;
            else if (target <matrix[midRow][0]) highRow = midRow;
            else if (target >matrix[midRow][0]) lowRow = midRow;
        }
        int targetRow;
        if (target<matrix[highRow][0]) targetRow = lowRow;
        else targetRow = highRow;

        int low = 0 ;
        int high =matrix[targetRow].size() -1 ;

        while(low<=high)
        {
            int mid = high - (high-low)/2;
            if (target == matrix[targetRow][mid]) return true;
            else if (target <matrix[targetRow][mid]) high = mid-1;
            else if (target >matrix[targetRow][mid]) low = mid+1;

        }

        return false;

        
    }
};
