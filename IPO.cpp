class Solution {
public:
	int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital)
	{
		vector<pair<int, int>> projects(profits.size());
		for (int i = 0; i < profits.size(); i++) {
			projects[i] = make_pair(capital[i], profits[i]);
		}
		sort(projects.begin(), projects.end());
		int i = 0;
		priority_queue<int> maximize;
		while (k--) {
			while (i < profits.size() && projects[i].first <= w)
			{
				maximize.push(projects[i].second);
				i++;
			}
			if (maximize.empty())
				break;
			w += maximize.top();
			maximize.pop();
		}
		return w;
	}
};