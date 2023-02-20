class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int n = nums.size();
		int l = 0, r = n - 1, mid, idx = -1;
		while (l <= r)
		{
			mid = (l + r) / 2;
			if (nums[mid] >= target)
			{
				r = mid - 1;
				idx = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		return idx == -1 ? n : idx;
	}
};