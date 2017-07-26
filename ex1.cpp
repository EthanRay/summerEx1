#include"stdfx.h"

/*
A+B问题 给出两个整数a和b, 求他们的和, 
但不能使用 + 等数学运算符
*/
int apluse(int a, int b)
{
	int sum = a^b;//异或得到未进位和
	int ca = (a&b) << 1;//作与并向左移1位得到进位
	if (ca == 0)
	{
		return sum;
	}
	return apluse(sum,ca);
}

/*
尾部的零 设计一个算法，计算出n阶乘中尾部零的个数
*/
long trailingZeros(long n)
{
	long sum = 0;

	while (n!=0)
	{
		sum += n / 5;
		n /= 5;
	}

	return sum;
}

/*
统计数字 计算数字k在0到n中的
出现的次数，k可能是0~9的一个值
*/
int singleCount(int i, int k)
{
	if (i == 0 && k == 0)
	{
		return 1;
	}

	int cnt = 0;
	while (i>0)
	{
		if (i % 10 == k)
			++cnt;
		i = i / 10;
	}
	return cnt;
}
 int digitCounts(int k, int n)
{
	int cnt = 0;
	for (int i = k; i <= n; ++i)
	{
		cnt += singleCount(i, k);
	}
	return cnt;
}

 /*
 查找斐波纳契数列中第 N 个数。
 */
 int fib(int n)
 {
	 if (n <= 1)
		 return n;

	 int ni = 1, ni1 = 1, ni2 = 0;
	 for (int i = 2; i < n; ++i)
	 {
		 ni = ni1 + ni2;
		 ni2 = ni1;
		 ni1 = ni;
	 }
	 return ni;
 }

 /*x的平方根*/
 int sqrt(int x)
 {
	 int left = 1;
	 int right = x / 2;

	 while (left <= right)
	 {
		 int mid = left + (right - left) / 2;
		 if (mid > x / mid)
			 right = mid - 1;
		 else{
			 left = mid + 1;
		 }
	 }
	 return left - 1;
 }

 /*骰子求和*/
 vector<pair<int, double>>dicesSum(int n)
 {
	 vector<pair<int, double>>result;
	 vector<vector<double>>dp(2, vector<double>(6 * n + 1));

	 for (int i = 1; i <= 6; ++i)
	 {
		 dp[1][i] = 1.0 / 6;
	 }

	 for (int i = 2; i <= n; ++i)
	 {
		 for (int j = 1; j <= 6 * i; ++j)
		 {
			 dp[i % 2][j] = 0.0;
			 for (int k = 1; k <= 6; ++k){
				 if (j > k){
					 dp[i % 2][j] += dp[(i - 1) % 2][j - k];
				 }
			 }
			 dp[i % 2][j] /= 6.0;
		 }
	 }

	 for (int i = n; i <= 6 * n; ++i)
	 {
		 result.emplace_back(i, dp[n % 2][i]);
	 }
	 return result;
 }

 /*最多有多少个点在一条直线上*/
 struct Point
 {
	 int x;
	 int y;
	 Point() :x(0), y(0){}
	 Point(int a, int b) :x(a), y(b){}
 };
 int maxPoints(vector<Point>& points)
 {
	 int max_points = 0;
	 for (int i = 0; i < points.size(); ++i)
	 {
		 unordered_map<double, int>slope_count;
		 const auto& start = points[i];
		 int same = 1;

		 for (int j = i + 1; j < points.size(); ++j)
		 {
			 const auto& end = points[j];
			 if (start.x == end.x&&start.y == end.y)
			 {
				 ++same;
			 }
			 else{
				 auto slope = numeric_limits<double>::max();
				 if (start.x - end.x != 0){
					 slope = (start.y - end.y)*1.0 / (start.x - end.x);//斜率
				 }
				 ++slope_count[slope];
			 }
		 }

		 int current_max = same;
		 for (const auto& kvp : slope_count){
			 current_max = max(current_max, kvp.second + same);
		 }
		 max_points = max(max_points, current_max);
	 }
	 return max_points;
 }

 /*超级丑数*/
 int nthSuperUglyNumber(int n, vector<int>& primes)
 {
	 priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>heap;
	 vector<int> uglies(n), idx(primes.size()), ugly_by_last_prime(n);
	 uglies[0] = 1;

	 for (int i = 0; i < primes.size(); ++i)
	 {
		 heap.emplace(primes[i], i);
		 
	 }
	 for (int i = 1; i < n; ++i)
	 {
		 int k;
		 tie(uglies[i], k) = heap.top();
		 heap.pop();
		 ugly_by_last_prime[i] = k;
		 while (ugly_by_last_prime[++idx[k]] > k);
		 heap.emplace(uglies[idx[k]] * primes[k], k);
	 }
	 return uglies[n - 1];
 }



