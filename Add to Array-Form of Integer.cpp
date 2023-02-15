class Solution {
public:
	vector<int> addToArrayForm(vector<int>& num, int k) {
		vector<int>ans;
		int i = num.size() - 1, carry = 0, sumK;
		while (k > 0 || i >= 0)
		{
			sumK = carry;
			if (i >= 0)sumK += num[i--];
			sumK += (k % 10);
			carry = sumK / 10;
			k /= 10;
			ans.push_back(sumK % 10);
		}
		if (carry)ans.push_back(carry);
		reverse(ans.begin(), ans.end());
		return ans;
	}
};