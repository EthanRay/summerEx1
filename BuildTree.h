#include"stdfx.h"

class BuildTree{
public:
	TreeNode* buildTree(vector<int>&preorder, vector<int>&inorder){
		return buildTree(begin(preorder), end(preorder), begin(inorder), end(inorder));
	}
	template<typename Input>
	TreeNode* buildTree(Input pre_first, Input pre_last, Input in_first, Input in_last)
	{
		if (pre_first == pre_last)return nullptr;
		if (in_first == in_last)return nullptr;

		auto root = new TreeNode(*pre_first);
		auto inRootPost = find(in_first, in_last, *pre_first);
		auto leftSize = distance(in_first, inRootPost);

		root->left = buildTree(next(pre_first),next(pre_last,leftSize+1),
			in_first,next(in_first,leftSize));
		root->right = buildTree(next(pre_first, leftSize + 1), pre_last,
			next(inRootPost), in_last);
		return root;

	}
	


};