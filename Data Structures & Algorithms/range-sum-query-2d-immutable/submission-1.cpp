class NumMatrix {
public:
vector<vector<int>> mx;
    NumMatrix(vector<vector<int>>& matrix) {
        int n =matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++)
        {
            vector<int> v;
            mx.push_back(v);
            for (int j =0; j<m;j++)
            {

                int sum = matrix[i][j];
                if(i) sum+=mx[i-1][j];
                if(j && !i) sum+= mx[i][j-1];
                if(j && i) sum+= ( mx[i][j-1] - mx[i-1][j-1]);
                mx[i].push_back(sum);
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int sum = mx[row2][col2];
        if(row1 && col1) sum+=mx[row1-1][col1-1];
        if(row1) sum-=mx[row1-1][col2];
        if(col1) sum-=mx[row2][col1-1];

        return sum;

        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */