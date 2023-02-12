class Solution {
public:
	long long dfs(vector<vector<int>>& x, vector<int>& vis, int node, int& seats, long long& ans) {
		if (vis[node]) return 0;
		vis[node] = 1;
		long long bran = 0, eachN = 0;
		for (int i = 0; i < x[node].size(); i++) {
			eachN = dfs(x, vis, x[node][i], seats, ans);
			ans += (eachN + seats - 1) / seats;
			bran += eachN;
		}
		return bran + 1;
	}
	long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
		int n = roads.size();
		vector<vector<int>> graph(n + 1, vector<int>());
		for (int i = 0; i < n; i++) {
			graph[roads[i][0]].push_back(roads[i][1]);
			graph[roads[i][1]].push_back(roads[i][0]);
		}
		vector<int> vis(n + 1, 0);
		long long ans = 0;
		dfs(graph, vis, 0, seats, ans);
		return ans;
	}
};