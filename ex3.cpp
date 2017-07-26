#include"stdfx.h"

/*编辑距离*/
int minDistance(string word1, string word2)
{
	const size_t m = word1.size();
	const size_t n = word2.size();

	if (m < n){
		return minDistance(word2, word1);
	}
	vector<vector<int>>steps(m + 1, vector<int>(n + 1, 0));
	
	for (int j = 0; j < n + 1; ++j)
	{
		steps[0][j] = j;
	}
	
	for (int i = 1; i < m + 1; ++i){
		steps[i][0] = i;
		for (int j = 1; j < n + 1; ++j)
		{
			steps[i][j] = word1[i - 1] == word2[j - 1] ?
				steps[i - 1][j - 1] :
				1 + min(steps[i - 1][j - 1], min(steps[i - 1][j], steps[i][j - 1]));
		}
	}

	return steps[m][n];
}

/*动态规划-硬币*/
int DP_Coin()
{
	int a[3] = { 1, 3, 5 }, sum = 11, cent = 0, dp[12];
	dp[0] = 0;
	
	for (int i = 1; i <= sum; ++i)
		dp[i] = i;

	for (int i = 1; i <= sum; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (i >= a[j] && dp[i - a[j]] + 1 < dp[i])
			{
				dp[i] = dp[i - a[j]] + 1;
			}
		}
	}

	return dp[sum];
}

/*数塔*/
void number_pyramid()
{
	int a[200][200];
	int t, n, i, j;
	while (~scanf("%d",&n))
	{
		for (i = 0; i < n; ++i)
			for (j = 0; j <= i; ++j)
				scanf("%d", &a[i][j]);
	
		for (i = n - 1; i > 0; --i)
			for (j = 0; j < i; ++j)
				a[i - 1][j] += max(a[i][j], a[i][j + 1]);
		printf("%d\n", a[0][0]);
	}
	
}

/*??正则表达式匹配*/
bool isMatch(const char *s, const char *p)
{
	const int slen = strlen(s);
	const int plen = strlen(p);

	vector<vector<bool>>match(slen + 1,
		vector<bool>(plen + 1));

	match[0][0] = true;
	for (int i = 2; i <= plen; ++i){
		if (p[i - 1] == '*'){
			match[0 % 2][i] = match[0 % 2][i - 2];
		}
	}

	for (int i = 1; i <= slen; ++i)
	{
		match[i % 2][0] = false;
		for (int j = 1; j < plen; ++j){
			if (p[j - 1] != '*'){
				match[i % 2][j] = match[(i - 1) % 2][j - 1] &&
					(p[j - 1] == s[i - 1] || p[i - 1] == '.');
			}
			else{
				match[i % 2][j] = j >= 2 &&
					(match[i % 2][j - 2] || (match[(i - 1) % 2][j] 
					&& (p[j - 2] == s[i - 1] || p[j - 2] == '.')));
			}
		}
	}
	return match[slen % 2][plen];
}

bool isMatch2(const char*s, const char*p)
{
	bool star = false;
	const char*str, *ptr;
	for (str = s, ptr = p; *str != '\0'; str++, ptr++){
		switch (*ptr)
		{
		case '?':
			break;
		case'*':
			star = true;
			s = str, p = str;
			while (*p == '*')p++;
			if (*p == '\0')return true;
			str = s - 1;
			ptr = p - 1;
			break;
		default:
			if (*str != *ptr){
				if (!star)return false;
				s++;
				str = s - 1;
				ptr = p - 1;
			}
		}
	}
}

bool isMatch3(const char*s, const char*p){
	if (*p == '\0')return *s == '\0';

	if (*(p + 1) != '*')
	{
		if (*p == *s || (*p == '.'&&*s != '\0'))
			return isMatch3(s + 1, p + 1);
		else
			return false;
	}
	else{
		while (*p == *s || (*p == '.'&&*s != '\0')){
			if (isMatch3(s, p + 2))
				return true;
			s++;
		}
		return isMatch3(s, p + 2);
	}
}

/*交叉字符串*/
bool isInterleave(string s1, string s2, string s3)
{
	if (s1.size() + s2.size() != s3.size())
	{
		return false;
	}
	if (s1.size() < s2.size())
	{
		return isInterleave(s2, s1, s3);
	}

	vector<deque<bool>> T(2, deque<bool>(s2.size() + 1));
	T[0][0] = true;

	for (int j = 0; j < s2.size(); ++j){
		if (s2[j] == s3[j]){
			T[0][j + 1] = true;
		}
		else{
			break;
		}
	}

	for (int i = 0; i < s1.size(); ++i){
		T[(i + 1) % 2][0] = T[i % 2][0] && s1[i] == s3[i];

		for (int j = 0; j < s2.size(); ++j){
			bool b1 = T[i % 2][j + 1] && s1[i] == s3[i + j + 1];
			bool b2 = T[(i + 1) % 2][j] && s2[j] == s3[i + j + 1];
		}
	}
	return T[s1.size() % 2][s2.size()];
}

/*滑动窗口的中位数 */
vector<int> medianSlidingWindow(vector<int> &nums, int k)
{
	multiset<int, less<int>>minBst;
	multiset<int, greater<int>>maxBst;

	vector<int>ans;
	for (int i = 0; i < nums.size(); ++i){

		if (i >= k){
			if (maxBst.find(nums[i - k]) != maxBst.cend()){
				maxBst.erase(maxBst.find(nums[i - k]));
			}
			else{
				minBst.erase(minBst.find(nums[i - k]));
			}
		}

		if (maxBst.empty() || nums[i] > *maxBst.cbegin()){
			minBst.emplace(nums[i]);
			if (minBst.size() > maxBst.size() + 1){
				maxBst.emplace(*minBst.cbegin());
				minBst.erase(minBst.cbegin());
			}
		}
		else{
			maxBst.emplace(nums[i]);
			if (maxBst.size() > minBst.size()){
				minBst.emplace(*maxBst.cbegin());
				maxBst.erase(maxBst.cbegin());
			}
		}

		if (i >= k - 1){
			ans.emplace_back(minBst.size() == maxBst.size()?
				*maxBst.cbegin() : *minBst.cbegin());
		}
	}
	return ans;
}
