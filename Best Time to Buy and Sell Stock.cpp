class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int p = prices[0];
		int maxi = -1000000000;
		for (int i = 0; i < prices.size(); i++)
		{
			if (prices[i] >= p)maxi = max(maxi, prices[i] - p);
			else p = prices[i];
		}
		return maxi;
	}
};