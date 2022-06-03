// Given a 2D matrix matrix, handle multiple queries of the following type:

// Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
// Implement the NumMatrix class:

// NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
// int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

#include <iostream>
#include <vector>
using namespace std;
// ROW CHACHING
class NumMatrix
{
    vector<vector<int>> mat, sums;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        mat = matrix;
        int m = matrix.size(), n = matrix[0].size();
        sums = vector<vector<int>>(m, vector<int>(n + 1));

        for (int i = 0; i < m; i++)
        {
            sums[i][0] = matrix[i][0];
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                sums[i][j] = sums[i][j - 1] + matrix[i][j - 1];
            }
        }
    }
    int sumRegin(int row1, int col1, int row2, int col2)
    {
        int sum = 0;
        for (int i = row1; i <= row2; i++)
        {
            sum += sums[i][col2 + 1] - sums[i][col1];
        }
        return sum;
    }
};