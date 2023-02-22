class Solution {
public:
	int shipWithinDays(vector<int>& weights, int days) {
		int low = *max_element(weights.begin(), weights.end()), high = 0, ans = -1;
		for (auto i : weights)
			high += i;
		while (low <= high)
		{
			int mid = low + (high - low) / 2;
			int cnt = 1, sum = 0;
			for (int i = 0; i < weights.size(); i++)
			{
				sum += weights[i];
				if (sum > mid)
				{
					cnt++;
					sum = weights[i];
				}
			}
			if (cnt <= days)
			{
				ans = mid;
				high = mid - 1;
			}
			else
				low = mid + 1;
		}
		return ans;
	}
};