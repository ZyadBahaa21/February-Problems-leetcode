class Solution {
public:
	bool isAlienSorted(vector<string>& words, string order) {
		map<char, int> mp;
		for (int i = 0; i < order.size(); i++)
			mp[order[i]] = i;
		vector<int> testWord, udateWord;
		for (int i = 0; i < words.size(); i++)
		{
			testWord.clear();
			for (int j = 0; j < words[i].size(); j++)
			{
				testWord.push_back(mp[words[i][j]]);
			}
			if (testWord < udateWord)
				return false;
			udateWord = testWord;
		}
		return true;
	}
};