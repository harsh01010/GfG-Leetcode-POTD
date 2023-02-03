/*
Given a binary matrix of dimensions  with R rows and C columns. Start from cell(0, 0), moving in the right direction. Perform the following operations:

If the value of matrix[i][j] is 0, then traverse in the same direction and check the next value.
If the value of matrix[i][j] is 1, then update matrix[i][j] to 0 and change the current direction clockwise. ie - up, right, down, or left directions change to right, down, left, and up respectively.
Find the index of the cell where you will be forced to exit the matrix while performing the given traversal.

matrix[][] = {{0,1},
              {1,0}}
R=2
C=2

Output: (1,1)
*/
// c++ solution:
class Solution
{
public:
    pair<int, int> endPoints(vector<vector<int>> arr, int R, int C)
    {
        // code here
        pair<int, int> ans;
        ans.first = 0, ans.second = 0;
        int i = 0, j = 0;
        int dirt = 1;

        // up,(4)      -> right(1)
        // right,(1)  -> down(2)
        // down,(2)  -> left(3)
        // or left(3)  -> up(4)

        while (i >= 0 && j >= 0 && i < R && j < C)
        {
            ans.first = i, ans.second = j;
            if (dirt == 1)
            {
                if (arr[i][j] == 0)
                {
                    j++;
                }
                else
                {
                    arr[i][j] = 0;
                    dirt = 2;
                    i++;
                }
            }
            else if (dirt == 2)
            {
                if (arr[i][j] == 0)
                {
                    i++;
                }
                else
                {
                    arr[i][j] = 0;
                    dirt = 3;
                    j--;
                }
            }
            else if (dirt == 3)
            {
                if (arr[i][j] == 0)
                {
                    j--;
                }
                else
                {
                    arr[i][j] = 0;
                    dirt = 4;
                    i--;
                }
            }

            else
            {
                if (arr[i][j] == 0)
                {
                    i--;
                }
                else
                {
                    arr[i][j] = 0;
                    dirt = 1;
                    j++;
                }
            }
        }

        return ans;
    }
};