/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == NULL)
			return res;
		TreeNode* temp;
		queue<TreeNode*> que;
		que.push(root);
		int odd_even = 0;
		while (!que.empty()) {
			vector<int> level;
			int cnt = que.size();
			for (int i = 0; i < cnt; i++)
			{
				temp = que.front();
				que.pop();
				level.push_back(temp->val);
				if (temp->left)  que.push(temp->left);
				if (temp->right) que.push(temp->right);
			}
			if (odd_even % 2 == 0)
			{
				res.push_back(level);
				odd_even++;
			}
			else
			{
				reverse(level.begin(), level.end());
				res.push_back(level);
				odd_even++;
			}
		}
		return res;
	}
};