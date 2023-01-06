#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};

    /*
        step 1, make a transpose
        step 2, reverse the rows like strings
    */

    // 1.Transpose

    for (int i = 0; i < matrix.size(); i++)
    {
        // Start second loop from i
        for (int j = i; j < matrix[i].size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // 2. Swap the rows

    for (int i = 0; i < matrix.size(); i++)
    {
        int left = 0, right = matrix[i].size() - 1;

        while (left <= right)
        {
            swap(matrix[i][left], matrix[i][right]);
            left++;
            right--;
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}