class Solution {
public:
	vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
		vector<vector<pair<int, int>>> graph(n);
		for (int i = 0; i < red_edges.size(); i++)
			graph[red_edges[i][0]].push_back({ red_edges[i][1], 0 });
		for (int i = 0; i < blue_edges.size(); i++)
			graph[blue_edges[i][0]].push_back({ blue_edges[i][1], 1 });
		vector<int> distance(n, -1);
		distance[0] = 0;
		queue <pair<int, pair<int, int>>> q;
		q.push({ 0,{-1,0} });
		while (!q.empty()) {
			auto p = q.front();
			q.pop();
			int node = p.first, prev_color = p.second.first;
			int dPlus = p.second.second;
			for (auto it = graph[node].begin(); it < graph[node].end(); it++) {
				int curr_colour = it->second;
				int curr_node = it->first;
				if (prev_color != curr_colour)
				{
					graph[node].erase(it);
					q.push({ curr_node,{curr_colour,dPlus + 1} });
					if (distance[curr_node] != -1) distance[curr_node] = min(dPlus + 1, distance[curr_node]);
					else distance[curr_node] = dPlus + 1;
					it--;
				}
			}
		}
		return distance;
	}
};