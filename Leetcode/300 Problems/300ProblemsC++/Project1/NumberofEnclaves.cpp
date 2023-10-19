//https://practice.geeksforgeeks.org/problems/number-of-enclaves/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-enclaves
#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
#include <queue>
using namespace std;
void dfs(vector<vector<int>>& mat, int x, int y, int rows, int columns) {
    if (x < 0 || x >= rows || y < 0 || y >= columns || mat[x][y] != 1) {
        return;
    }

    //to mark this 'O' cell as - at boundary 
    mat[x][y] = 2;

    dfs(mat, x - 1, y, rows, columns);
    dfs(mat, x + 1, y, rows, columns);
    dfs(mat, x, y - 1, rows, columns);
    dfs(mat, x, y + 1, rows, columns);
}
int numberOfEnclaves(vector<vector<int>>& mat) {

    int n = mat.size();
    int m = mat[0].size();
    // //to loop boundary of matrix

    //TOP and BOTTOM
    for (int i = 0; i < m; ++i) {
        //TOP
        if (mat[0][i] == 1) {
            dfs(mat, 0, i, n, m);
        }

        //BOTTOM
        if (mat[n - 1][i] == 1) {
            dfs(mat, n - 1, i, n, m);
        }
    }

    //LEFT and RIGHT
    for (int i = 0; i < n; ++i) {
        //LEFT
        if (mat[i][0] == 1) {
            dfs(mat, i, 0, n, m);
        }

        //RIGHT
        if (mat[i][m - 1] == 1) {
            dfs(mat, i, m - 1, n, m);
        }
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == 1) {
                ++count;
            }
        }
    }


    return count;
    // code here
}
