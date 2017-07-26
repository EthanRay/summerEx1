#include"stdfx.h"

bool isUniqueChars(char*str)
{
	if (strlen(str) > 256)return false;
	bool *charSet = new bool[256];

	for (int i = 0; i < strlen(str); ++i)
	{
		int val = str[i];
		if (charSet[val])
		{
			return false;
		}
		charSet[val] = true;
	}
	return true;
}

void reverse(char *str)
{
	char *end = str;
	char tmp;
	while (str)
	{
		while (*end)
		{
			++end;
		}
		--end;
		
		while (str < end)
		{
			tmp = *str;
			*str = *end;
			*end = tmp;
			++str; --end;
		}
	}
}

bool permutation(string s,string t)
{
	if (s.length() != t.length())
		return false;

	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	return  s.compare(t);
}

void replaceSpace(char* str, int length)
{
	int spaceCount = 0, newLength, i;
	for (i = 0; i < length; ++i)
	{
		if (str[i] == ' ')
			++spaceCount;
	}
	newLength = length + spaceCount * 2;
	str[newLength] = '\0';
	for (i = length - 1; i >= 0; --i)
	{
		if (str[i] == ' ')
		{
			str[newLength - 1] = '0';
			str[newLength - 2] = '2';
			str[newLength - 3] = '%';
			newLength-=3;
		}
		else
		{
			str[newLength--] = str[i];
		}
	}
}

/*数据流中位数*/
vector<int> medianII(vector<int> &nums)
{
	multiset<int, less<int>>minBst;
	multiset<int, greater<int>>maxBst;

	vector<int>ans;
	for (auto num : nums){
		if (maxBst.empty() || num > *maxBst.cbegin()){
			minBst.emplace(num);
			if (minBst.size() > maxBst.size() + 1){
				maxBst.emplace(*minBst.cbegin());
				minBst.erase(minBst.cbegin());
			}
		}
		else{
			maxBst.emplace(num);
			if (maxBst.size() > minBst.size()){
				minBst.emplace(*maxBst.cbegin());
				maxBst.erase(maxBst.cbegin());
			}
		}
		ans.emplace_back(minBst.size() == maxBst.size() ?
			*maxBst.cbegin() : *minBst.cbegin());
	}
	return ans;
}

struct Node
{
	int frequence;
	string str;
	Node(string s, int f){
		frequence = f;
		str = s;
	}
};

/*树先序遍历*/
vector<int> postorderTraversal(TreeNode *root)
{
	vector<int>result;
	stack<const TreeNode*>s;
	if (root != nullptr)s.push(root);
	
	while (!s.empty())
	{
		const TreeNode *p = s.top();
		s.pop();
		result.push_back(p->data);

		if (p->right != nullptr){
			s.push(p->right);
		}
		if (p->left != nullptr){
			s.push(p->left);
		}
	}
	
	return result;
}

vector<int> inorderTraversal(TreeNode *root)
{
	vector<int>result;
	stack<const TreeNode*>s;
	const TreeNode*p = root;

	while (!s.empty()||p!=nullptr)
	{
		if (p != nullptr)
		{
			s.push(p);
			p = p->left;
		}
		else{
			p = s.top();
			s.pop();
			result.push_back(p->data);
			p = p->right;
		}
	}
	return result;
}

void merge1(vector<int>&A, vector<int>&B)
{
	int m = A.size(), n = B.size();
	int ia = m - 1, ib = n - 1, icur = m + n - 1;

	while (ia >= 0 && ib >= 0)
	{
		A[icur--] = A[ia] >= B[ib] ? A[ia--] : B[ib--];
	}
	while (ib >= 0){
		A[icur--] = B[ib--];
	}
	while (ia >= 0){
		A[icur--] = A[ia--];
	}
}
ListNode *merge2(ListNode *l1, ListNode *l2){
	if (l1 == nullptr)return l2;
	if (l2 == nullptr)return l1;
	ListNode dummy(-1);
	ListNode *p = &dummy;

	for (; l1 != nullptr&&l2 != nullptr; p = p->next)
	{
		if (l1->val > l2->val)
		{
			p->next = l2; l2 = l2->next;
		}
		else{
			p->next = l1; l1 = l1->next;
		}
		p->next = l1 != nullptr ? l1 : l2;
		return dummy.next;
	}
}

ListNode *findInsertPos(ListNode *head, int x){
	ListNode *pre = nullptr;
	for (ListNode*cur = head; cur != nullptr&&cur->val <= x;
		pre = cur, cur = cur->next);
		return pre;
}
ListNode *merge3(ListNode*head){
	
	ListNode dummy(0);
	

	for (ListNode *cur = head; cur != nullptr;){
		auto pos = findInsertPos(&dummy, cur->val);
		ListNode *tmp = cur->next;
		cur->next = pos->next;
		pos->next = cur;
		cur = tmp;
	}
	return dummy.next;
}

vector<int>searchRange(vector<int>& nums, int target)
{
	const int L = distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
	const int U = distance(nums.begin(), prev(upper_bound(nums.begin(), nums.end(), target)));
	if (nums[L] != target){
		return vector < int > {-1, -1};
	}
	else{
		return vector < int > {L, U};
	}
}

template<typename ForX,typename T>
ForX lowBound(ForX first, ForX last, T value)
{
	while (first != last){
		auto mid = next(first, distance(first, last) / 2);
		if (value > *mid)first = ++mid;
		else last = mid;
	}
	return first;
}

template<typename ForX,typename T>
ForX lowerBound2(ForX first, ForX last, T value)
{
	while (first != last){
		auto mid = next(first, distance(first, last) / 2);
		if (value > *mid)first = ++mid;
		else last = mid;
	}
	return first;
}

bool searchMat(const vector<vector<int>>&matrix, int target)
{
	if (matrix.empty())
		return false;
	
	const size_t m = matrix.size();
	const size_t n = matrix.front().size();

	int first = 0;
	int last = m*n;

	while (first < last)
	{
		int mid = first + (last - first) / 2;
		int value = matrix[mid / n][mid%n];
		if (value == target)
			return true;
		else if (value < target)
			first = mid + 1;
		else
			last = mid;
	}
	return false;
}
