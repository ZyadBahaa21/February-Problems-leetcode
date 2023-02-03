class Solution {
public:
	string convert(string s, int numRows) {
		vector<vector<char>> matrix(numRows, vector<char>());
		string ans = "";
		if (numRows == 1) return s;
		matrix[0].push_back(s[0]);
		int i = 1, flag = 0;
		while (i < s.length()) {
			int moveR = (flag == 0 ? 1 : numRows - 2), r = numRows - 1;
			while (r-- and i < s.length()) {
				if (flag == 0) {
					matrix[moveR++].push_back(s[i++]);
				}
				else {
					matrix[moveR--].push_back(s[i++]);
				}
			}
			flag = flag == 0 ? 1 : 0;
		}
		for (int i = 0; i < numRows; i++) {
			for (auto it : matrix[i])
				ans += it;
		}
		return ans;
	}
};