class Solution {
public:
	void bfs(vector<vector<int>> &grid, queue<pair<int, int>> &lands, int &maxi) {
		while (!lands.empty()) {
			auto currentLand = lands.front();
			lands.pop();
			pair<int, int> directions[4] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
			for (auto dir : directions) {
				int nx = currentLand.first + dir.first;
				int ny = currentLand.second + dir.second;
				if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid.size() && grid[nx][ny] == 0) {
					lands.push({ nx, ny });
					grid[nx][ny] = grid[currentLand.first][currentLand.second] + 1;
					maxi = max(maxi, grid[nx][ny]);
				}
			}
		}
	}
	int maxDistance(vector<vector<int>>& grid) {
		int maxi = 0;
		queue<pair<int, int>> lands;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid.size(); j++) {
				if (grid[i][j] == 1) {
					lands.push({ i, j });
				}
			}
		}
		bfs(grid, lands, maxi);
		return maxi - 1;
	}
};