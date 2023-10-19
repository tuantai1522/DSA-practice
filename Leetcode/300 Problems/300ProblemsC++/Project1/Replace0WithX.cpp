
//https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=replace-os-with-xs
#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
#include <queue>
using namespace std;
void dfs(vector<vector<char>>& mat, int x, int y, int rows, int columns) {
    if (x < 0 || x >= rows || y < 0 || y >= columns || mat[x][y] != 'O') {
        return;
    }

    //to mark this 'O' cell as - at boundary 
    mat[x][y] = '-';

    dfs(mat, x - 1, y, rows, columns);
    dfs(mat, x + 1, y, rows, columns);
    dfs(mat, x, y - 1, rows, columns);
    dfs(mat, x, y + 1, rows, columns);
}
vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{

    // //to loop boundary of matrix

    //TOP and BOTTOM
    for (int i = 0; i < m; ++i) {
        //TOP
        if (mat[0][i] == 'O') {
            dfs(mat, 0, i, n, m);
        }

        //BOTTOM
        if (mat[n - 1][i] == 'O') {
            dfs(mat, n - 1, i, n, m);
        }
    }

    //LEFT and RIGHT
    for (int i = 0; i < n; ++i) {
        //LEFT
        if (mat[i][0] == 'O') {
            dfs(mat, i, 0, n, m);
        }

        //RIGHT
        if (mat[i][m - 1] == 'O') {
            dfs(mat, i, m - 1, n, m);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == 'O') {
                mat[i][j] = 'X';
            }
            else if (mat[i][j] == '-') {
                mat[i][j] = 'O';
            }
        }
    }


    return mat;
    // code here
}