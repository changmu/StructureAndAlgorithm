class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		int m = matrix.size();
		if (m == 0) return;
		int n = matrix[0].size();		// m rows, n columns

		bool *wipeRow = new bool[m]();
		bool *wipeCol = new bool[n]();

		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (matrix[i][j] == 0)
					wipeRow[i] = wipeCol[j] = true;

		for (int i = 0; i < m; ++i)	
			if (wipeRow[i])				// wipe rows
				for (int j = 0; j < n; ++j)
					matrix[i][j] = 0;
		for (int i = 0; i < n; ++i)	
			if (wipeCol[i])				// wipe cols
				for (int j = 0; j < m; ++j)
					matrix[j][i] = 0;

		delete[] wipeCol;
		delete[] wipeRow;
	}
};
