#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>
#include<functional>
#include<set>
#include<hash_map>
#include<stack>
#include<unordered_set>


struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int data;

};

struct  ListNode
{
	ListNode *next;
	int val;
	ListNode(int x) :val(x){
		next = nullptr;
	}
};
using namespace std;