class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // 0,1,...,rowIndex
        vector<vector<int>> triangle (rowIndex+1);
        int column = 1;
        for(int r = 0; r<=rowIndex;r++){
            // update col num per iter
            vector<int> row(column,1);
            triangle[r] = row;
            for (int c = 1; c < column-1; c++){
                triangle[r][c] = triangle[r-1][c-1] + triangle[r-1][c];
            }
            column++;
        }
    return triangle[rowIndex];
    }
};
