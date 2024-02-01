class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows==0) return {};
        if (numRows==1) return {{1}};

        vector<vector<int>> prevRows = generate(numRows-1);
        // newRow(4,1) = [1,1,1,1]
        vector<int> newRow(numRows,1);

        // get prevRows' element sum
        for (int i = 1; i< numRows - 1; i++){
            newRow[i] = prevRows.back()[i-1]+prevRows.back()[i];
        }

        prevRows.push_back(newRow);
        return prevRows;
    }
};

//     vector<vector<int>> generate(4)
//     numRows = 4 | prevRows = generate(3)
//     numRows = 3 | prevRows = generate(2)
//     numRows = 2 | prevRows = generate(1) -> return {1} -> preRows = [[1]] -> newRow = [1,1] -> preRows = [[1],[1,1]] return
//     numRows = 1 | prevRows = generate(2) = [[1],[1,1]]-> next... 
