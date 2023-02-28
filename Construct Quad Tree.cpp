/*
// Definition for a QuadTree node.
class Node {
public:
	bool val;
	bool isLeaf;
	Node* topLeft;
	Node* topRight;
	Node* bottomLeft;
	Node* bottomRight;

	Node() {
		val = false;
		isLeaf = false;
		topLeft = NULL;
		topRight = NULL;
		bottomLeft = NULL;
		bottomRight = NULL;
	}

	Node(bool _val, bool _isLeaf) {
		val = _val;
		isLeaf = _isLeaf;
		topLeft = NULL;
		topRight = NULL;
		bottomLeft = NULL;
		bottomRight = NULL;
	}

	Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
		val = _val;
		isLeaf = _isLeaf;
		topLeft = _topLeft;
		topRight = _topRight;
		bottomLeft = _bottomLeft;
		bottomRight = _bottomRight;
	}
};
*/

class Solution {
public:
	Node* check(int x, int y, int n, vector<vector<int>> &grid)
	{
		bool flag = true;
		int value = grid[x][y];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[x + i][y + j] != value)
				{
					flag = false;
					break;
				}
			}
			if (!flag)break;
		}
		if (flag)
		{
			Node* root = new Node();
			root->val = value;
			root->isLeaf = true;
			return root;
		}
		Node* root = new Node();
		root->isLeaf = false;
		root->topLeft = check(x, y, n / 2, grid);
		root->topRight = check(x, y + n / 2, n / 2, grid);
		root->bottomLeft = check(x + n / 2, y, n / 2, grid);
		root->bottomRight = check(x + n / 2, y + n / 2, n / 2, grid);
		return root;
	}
	Node* construct(vector<vector<int>>& grid)
	{
		return check(0, 0, grid.size(), grid);
	}
};