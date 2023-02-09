class Solution {
public:
	long long distinctNames(vector<string>& ideas) {
		vector<set<string>>st(26);
		long long ans = 0, count = 0, count2 = 0;
		for (auto s : ideas)
			st[s[0] - 'a'].insert(s.substr(1));
		for (int i = 0; i < 26; i++) {
			for (int j = i + 1; j < 26; j++) {
				count = 0, count2 = 0;
				for (auto x : st[i])count += (!st[j].count(x));
				for (auto x : st[j])count2 += (!st[i].count(x));
				ans += (count*count2);
			}
		}
		return ans *= 2;
	}
};