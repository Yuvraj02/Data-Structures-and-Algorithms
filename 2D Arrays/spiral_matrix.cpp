#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {5, 6, 7, 8},
                                  {9, 10, 11, 12}};

    int top = 0, bottom = matrix.size() - 1, right = matrix[0].size() - 1, left = 0;
    int dir = 0;

    /*
        dir=0, right
        dir=1, down
        dir=2, left
        dir=3, up
    */

    vector<int> spiralMatrix;

    while (left <= right && top <= bottom)
    {
        // Go right

        if (dir == 0)
        {
            for (int i = left; i <= right; i++)
            {
                // cout << matrix[top][i] << " ";
                spiralMatrix.push_back(matrix[top][i]);
            }
            top++;
            dir = 1;
        }

        // Go Down
        else if (dir == 1)
        {
            for (int i = top; i <= bottom; i++)
            {
                // cout<<matrix[i][right]<<" ";
                spiralMatrix.push_back(matrix[i][right]);
            }
            right--;
            dir = 2;
        }

        // Go Left
        else if (dir == 2)
        {
            for (int i = right; i >= left; i--)
            {
                // cout<<matrix[bottom][i]<<" ";
                spiralMatrix.push_back(matrix[bottom][i]);
            }
            bottom--;
            dir = 3;
        }

        // Go up
        else if (dir == 3)
        {
            for (int i = bottom; i >= top; i--)
            {
                // cout<<matrix[i][left]<<" ";
                spiralMatrix.push_back(matrix[i][left]);
            }
            left++;
            dir = 0;
        }
    }

    for (auto i : spiralMatrix)
    {
        cout << i << " ";
    }

    return 0;
}