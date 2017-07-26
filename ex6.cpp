#include"stdfx.h"


bool queenIsValid(const vector<int>&C, int row, int col){
	for (int i = 0; i < row; ++i){
		if (C[i] == col)return false;
		if (abs(i - row) == abs(C[i] - col))return false;
	}
	return true;
}
void DFS4(vector<int>&C, vector<vector<string>>&result, int row){
	const int N = C.size();

	if (row == N){
		vector<string>solution;
		for (int i = 0; i < N; ++i){
			string s(N, '.');
			for (int j = 0; j < N; ++j){
				if (j == C[i])s[j] = 'Q';
			}
			solution.push_back(s);
		}
		result.push_back(solution);
		return;
	}

	for (int i = 0; i < N; ++i){
		const bool ok = queenIsValid(C, row, i);
		if (!ok)continue;

		C[row] = i;
		DFS4(C, result, row + 1);
	}
}
vector<vector<string>> solveNQueens1(int n){
	vector<vector<string>>result;
	vector<int>C(n, -1);
	DFS4(C, result, 0);
	return result;
}

vector<bool> columns;
vector<bool> mainDiag;
vector<bool> antiDiag;

void DFS5(vector<int>&C, vector<vector<string>>&result, int row){
	const int N = C.size();
	if (N == row){
		vector<string>solution;
		for (int i = 0; i < N; ++i){
			string s(N, '.');
			for (int j = 0; j < N; ++j){
				if (j == C[i])s[j] = 'Q';
			}
			solution.push_back(s);
		}
		result.push_back(solution);
		return;
	}

	for (int j = 0; j < N; ++j){
		const bool ok = !columns[j] && !mainDiag[row - j + N - 1] &&
			!antiDiag[row + j];
		if (!ok)continue;

		C[row] = j;
		columns[j] = mainDiag[row - j + N - 1] = antiDiag[row + j] = true;
		DFS5(C, result, row + 1);
		columns[j] = mainDiag[row - j + N - 1] = antiDiag[row + j] = false;
	}
}
vector<vector<string> > solveNQueens2(int n){
	columns = vector<bool>(n, false);
	mainDiag = vector<bool>(2 * n - 1, false);
	antiDiag = vector<bool>(2 * n - 1, false);

	vector<vector<string>>result;
	vector<int>C(n, -1);
	DFS5(C, result, 0);
	return result;
}

int counts=0;
bool queenIsVaild2(vector<int>&C, int row, int col){
	for (int i = 0; i < row; ++i){
		if (C[i] == col)return false;
		if (abs(C[i] - col)== abs(row - i))return false;
	}
	return true;
}
void DFS5(vector<int>&C, int row){
	int N = C.size();
	if (N == row){
		++counts;
		return;
	}

	for (int j = 0; j < N; ++j){
		bool ok = queenIsVaild2(C, row, j);
		if (!ok)continue;
		C[row] = j;
		DFS5(C, row + 1);
	}
}


