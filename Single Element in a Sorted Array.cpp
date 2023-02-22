class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		map<int, int>mp;
		for (auto it : nums)mp[it]++;
		for (auto it : nums) {
			if (mp[it] == 1)return it;
		}
		return 0;
	}
};