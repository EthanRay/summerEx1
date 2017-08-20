#include"stdfx.h"

int mininumTotal(vector<vector<int>>& tri){
	
	for (int i = tri.size() - 2; i >= 0; --i){
		for (int j = 0; j < i+1; ++j){
			tri[i][j] += min(tri[i + 1][j], tri[i + 1][j + 1]);
		}
	}
	return tri[0][0];
}

int maxSubArray(vector<int>& nums){
	int result = INT_MIN, f = 0;
	for (int i = 0; i < nums.size(); ++i){
		f = max(f + nums[i], nums[i]);
		result = max(result, f);
	}
	return result;
}

int minCut(const string&s){
	const int n = s.size();
	int *f=new int[n+1];
	bool p[10][10];

	for (int i = 0; i <= n; ++i){
		f[i] = n - 1 - i;
	}
	for (int i = n - 1; i >= 0; --i){
		for (int j = i; j < n; ++j){
			if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1])){
				p[i][j] = true;
				f[i] = min(f[i], f[j + 1] + 1);
			}
		}
	}
	return f[0];
}

int maxima(vector<vector<char>>&matrix){
	if (matrix.size() == 0){
		return -1;
	}
	int m = matrix.size();
	int n = matrix[0].size(),ret=0;
	vector<int>H(n, 0);
	vector<int>L(n, 0);
	vector<int>R(n, n);

	for (int i = 0; i < m; ++i){
		int left = 0, right = n;
		for (int j = 0; j < n; ++j){
			if (matrix[i][j] == '1'){
				++H[j];
				L[j] = max(L[j], left);
			}
			else{
				left = j + 1; L[j] = H[j] = 0;
			}
		}

		for (int j = n - 1; j >= 0; --j){
			if (matrix[i][j] == '1'){
				R[j] = min(R[j], right);
				ret = H[j] * (L[j] - R[j]);
			}
			else{
				right = j;
			}
		}
	}
	return ret;
}

int maxProfit3(vector<int>&prices){
	if (prices.size() <2)return 0;
	int v = 0, p = 0, n = prices.size();
	vector<int>f(n, 0);
	vector<int>g(n, 0);
	for (int i = 1, v = prices[0]; i < n; ++i){
		v = min(v, prices[i]);
		f[i] = max(f[i - 1], prices[i] - v);
	}
	for (int j = n - 2, p = prices[n - 1]; j >= 0; --j){
		p = max(p, prices[j]);
		g[j] = max(g[j], prices[j]);
	}
	int maxProfit = 0;
	for (int i = 0; i < n; ++i){
		maxProfit = max(maxProfit, f[i] + g[i]);
	}
	return maxProfit;
}

int minPathSum2(vector<vector<int>>&grid){
	const int m = grid.size();
	const int n = grid[0].size();

	int f[100][100];
	f[0][0] = grid[0][0];

	for (int i = 1; i < m; ++i){
		f[i][0] = f[i-1][0]+grid[0][i];
		f[i][0]=grid[0][1];
	}
	for (int j = 1; j < n; ++j){
		f[0][j] = f[0][j - 1] + grid[0][j];
	}

	for (int i = 1; i < n; ++i){
		for (int j = 1; j < m; ++j){
			f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
		}
	}
	return f[m - 1][n - 1];
}

int minDistance(const string &word1, const string &word2){
	const int n = word1.size();
	const int m = word2.size();

	vector<vector<int>>f;

	for (int i = 0; i <= n; ++i){
		f[i][0] = i;
	}
	for (int j = 0; j <= m; ++j){
		f[0][j] = j;
	}
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){
			if (word1[i - 1] == word2[j - 1])
				f[i][j] = f[i - 1][j - 1];
			else{
				int mn = min(f[i - 1][j], f[i][j - 1]);
				f[i][j] = 1 + min(f[i - 1][j - 1], mn);
			}
		}
	}
	return f[m][n];
}

int numDecodings(const string &s){
	if (s.empty() || s[0] == '0')
		return 0;
	int prev = 0;
	int cur = 1;

	for (int i = 0; i < s.size(); ++i){
		if (s[i] == '0')cur = 0;

		if (i < 1 || !(s[i - 1] == '1' || (s[i - 1] == '2'&&s[i] <= '6')))
			prev = 0;

		int tmp = cur;
		cur = prev + cur;
		prev = tmp;
	}
	return cur;
}

int numDistinct(const string &S, const string &T)
{
	vector<int> f(T.size() + 1);
	f[0] = 1;
	for (int i = 0; i < S.size(); ++i){
		for (int j = T.size() - 1; j >= 0; --j){
			f[j + 1] += S[i] == T[j] ? f[j] : 0;
		}
	}

	for (int i = 0; i<=T.size(); ++i){
		cout << f[i]<<" " ;
	}
	cout << endl;
	return f[T.size()];
}
