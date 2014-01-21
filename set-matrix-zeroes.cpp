
/**
 * set-matrix-zeroes
 * http://oj.leetcode.com/problems/set-matrix-zeroes
 * Prob:
 *  
 * Solution:
 *      set the first column and first row as flag rows. record the status of firstCol and firstRow at the beginning
 */
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.size() == 0)
            return;
        bool firstCol0 = false;
        bool firstRow0 = false;
        int row = matrix.size();
        int col = matrix[0].size();
        for (int i = 0; i < row; i++)
            if (matrix[i][0] == 0)
                firstCol0 = true;
        for (int j = 0; j < col; j++)
            if (matrix[0][j] == 0)
                firstRow0 = true;
        for (int i = 1; i < row; i++)
            for (int j = 1; j < col; j++)
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
        for (int i = 1; i < row; i++)
            if (matrix[i][0] == 0)
                for (int j = 1; j < col; j++)
                    matrix[i][j] = 0;
        for (int j = 1; j < col; j++)
            if (matrix[0][j] == 0)
                for (int i = 1; i < row; i++)
                    matrix[i][j] = 0;
        if (firstRow0)
            for (int j = 0; j < col; j++)
                matrix[0][j] = 0;
        if (firstCol0)
            for (int i = 0; i < row; i++)
                matrix[i][0] = 0;

    }
};