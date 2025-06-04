#include <stdio.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

_Bool checkTree(struct TreeNode *root) {
	return 1 * (root->right->val + root->left->val == root->val);
}

int main(int argc, char *argv[]) {
	const int input[3] = { 10, 4, 6 };

	struct TreeNode trree = { input[0] };
	for (size_t i = 1; i < 3; i += 2) {
		struct TreeNode *tree;
		tree = &trree;
		struct TreeNode left = { input[i] };
		struct TreeNode right = { input[i+1] };
		tree->left = &left;
		tree->right = &right;
	}
	// printf("%d", trree.left->val);
	// printf("%d", tree.val);
	int whatever = checkTree(&trree);


	return 0;
}
