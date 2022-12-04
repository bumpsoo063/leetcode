#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool chek(vector<vector<int>>& matrix, int x, int y, int xsize, int ysize) {
		while (++x <= xsize && ++y <= ysize) {
			if (matrix[y][x] != matrix[y - 1][x - 1]) {
				return false;
			}
		}
		return true;
	}
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		int x = 0, y = 0, xsize = matrix[0].size() - 1, ysize = matrix.size() - 1;
		while (x < xsize) {
			if (!chek(matrix, x, y, xsize, ysize)) {
				return false;
			};
			x++;
		}
		x = 0;
		while (y < ysize) {
			if (!chek(matrix, x, y, xsize, ysize)) {
				return false;
			};
			y++;
		}
		return true;
	}
};