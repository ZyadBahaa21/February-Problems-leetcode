class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		map<char, int>mp, mp2;
		for (char it : p)mp[it]++;
		vector<int>ans;
		for (int i = 0; i < s.size(); i++)
		{
			mp2[s[i]]++;
			if (i >= p.size()) {
				if (mp[s[i - p.size()]] <= 0)mp[s[i - p.size()]] = 0;
				mp2[s[i - p.size()]]--;
			}
			if (mp == mp2)
			{
				if (i - p.size() < 0)ans.push_back(i + 1);
				else ans.push_back(i - p.size() + 1);
			}
		}
		return ans;
	}
};