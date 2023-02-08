class Solution {
public:
	int jump(vector<int>& nums) {
		int i = 0, maxDist = 0, currDist = 0, ans = 0;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			maxDist = max(maxDist, i + nums[i]);
			if (i == currDist)
			{
				currDist = maxDist;
				ans++;
			}
		}
		return ans;
	}
};