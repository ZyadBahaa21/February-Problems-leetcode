class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		map<char, int>mp, mp2;
		for (char it : s1)mp[it]++;
		for (int i = 0; i < s2.size(); i++)
		{
			mp2[s2[i]]++;
			if (i >= s1.size()) {
				if (mp[s2[i - s1.size()]] <= 0)mp[s2[i - s1.size()]] = 0;
				mp2[s2[i - s1.size()]]--;
			}
			if (mp == mp2)
				return true;
		}
		return false;
	}
};