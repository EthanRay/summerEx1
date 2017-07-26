#include"stdfx.h"

void quickSort(int *list, int m, int n){
	int i, j, k, t;
	i = m; j = n; k = list[m];
	if (m < n){
		while (i < j){
			for (i = i + 1; i < n; ++i){
				if (list[i] >= k)
					break;
			}
			for (j; j > m; --j)
				if (list[j] <= k)
					break;

			if (i < j){
				t = list[i]; list[i] = list[j]; list[j] = t;
			}
		}
		t = list[m]; list[m] = list[j]; list[j] = t; 
		quickSort(list, m, j - 1);
		quickSort(list, i, n);
	}
}

void maopao(int *list, int n){
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j<n - i;++j)
		{
			if (list[j]>list[j + 1])
				swap(list[j], list[j + 1]);
		}
}

void dfs1(vector<int> &nums, vector<int>&path, vector<vector<int>> &result,
	int gap, int start){
	if (gap == 0){
		result.push_back(path);
		return;
	}

	for (int i = start; i < nums.size(); ++i){
		if (gap<nums[i])return;
		path.push_back(nums[i]);
		dfs1(nums, path, result, gap - nums[i], i);
		path.pop_back();
	}
}
vector<vector<int>>comSum(vector<int>&nums, int target){
	vector<vector<int>>result;
	vector<int>path;
	sort(nums.begin(), nums.end());
	dfs1(nums, path, result, target, 0);
	return result;
}

bool canJump(const vector<int>&nums){
	int reach = 1;
	for (int i = 0; i < reach&&reach < nums.size(); ++i){
		reach = max(reach, i + 1 + nums[i]);
	}
	return reach > nums.size();
}

int MinJump(const vector<int>&nums){
	int step = 0;
	int left = 0;
	int right = 0;
	if (nums.size() == 1)return 0;

	while (left <= right){
		++step;
		const int oldRight = right;
		for (int i = left; i <= oldRight; ++i){
			int newRight = i + nums[i];
			if (newRight >= nums.size() - 1)
				return step;
			if (newRight > right)
				right = newRight;
		}
		left = oldRight+1;
	}
	
	return 0;
}

int maxProfit(vector<int>&prices){
	if (prices.size() < 2){
		return 0;
	}
	int profit = 0;
	int curMin = prices[0];

	for (int i = 0; i < prices.size(); ++i){
		profit = max(profit, prices[i] - curMin);
		curMin = min(prices[i], curMin);
	}
	return profit;
}

int lengthOfLongestSubstring(string s){
	const int ASCII = 255;
	int last[ASCII];
	int start = 0;
	
	fill(last, last + ASCII, -1);
	int maxLen = 0;
	for (int i = 0; i < s.size(); ++i){
		if (last[s[i]] >= start){
			maxLen = max(i - start, maxLen);
			start = last[s[i]] + 1;
		}
		last[i]=i;
	}
	return max((int)s.size() - start, maxLen);
}

int maxAreaMu(vector<int> &height){
	int start = 0;
	int end = height.size() - 1;
	int result = INT_MIN;

	while (start < end){
		int area = min(height[start], height[end])*(end - start);
		result = max(result, area);
		if (height[start] < height[end]){
			start++;
		}
		else{
			end--;
		}
	}
	return result;
}
