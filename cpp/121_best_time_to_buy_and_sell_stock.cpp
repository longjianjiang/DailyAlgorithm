#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// Input: [7,1,5,3,6,4]
// Output: 5
// 给定数组表示每一天的股票的价格，只允许交易一次，返回收益最大的交易。
// 1> dp的方式； dp[i] 表示第i天的收益最大。 dp[i][0] 表示卖出，dp[i][1] 表示买进。
// 2> 滑动窗口；
class Solution {
public:

    int maxProfit_dp(vector<int>& prices) {
		int nsize = prices.size();
		if (nsize < 2) { return 0; }

		int res = 0;
		vector<vector<int>> dp(nsize, vector<int>(2, 0));
		dp[0][0] = 0; dp[0][1] = -prices[0];

		for (int i = 1; i < nsize; ++i) {
			dp[i][0] = max(dp[i-1][0], prices[i]+dp[i-1][1]);
			dp[i][1] = max(dp[i-1][1], -prices[i]);
			res = max(res, dp[i][0]);
		}

		return res;
    }

	int maxProfit_sw(vector<int>& prices) {
		int nsize = prices.size();
		if (nsize < 2) { return 0; }

		int res = 0;
		int l = 0, r = 1;
		while (r < nsize) {
			if (prices[r] > prices[l]) {
				res = max(res, prices[r] - prices[l]);
			} else {
				l = r;
			}
			++r;
		}

		return res;
	}
};
