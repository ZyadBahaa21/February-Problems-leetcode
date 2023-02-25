class Solution {
public:
	int minimumDeviation(vector<int>& nums) {
		priority_queue<int> pr;
		int mini = INT_MAX;
		for (auto it : nums)
		{
			if (it % 2 != 0) it *= 2;
			mini = min(mini, it);
			pr.push(it);
		}
		int ans = pr.top() - mini;
		while (pr.top() % 2 == 0)
		{
			int even = pr.top() / 2;
			pr.pop();
			mini = min(mini, even);
			pr.push(even);
			ans = min(ans, pr.top() - mini);
		}
		return ans;
	}
};