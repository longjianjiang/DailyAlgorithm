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

// 给定n，要求返回由完全平方数字和等于n的最小个数。
// 首先确定不大于n的完全平方，之后就是尝试依次添加各个完全平方，直到等于n；
class Solution {
public:
	int numSquares(int n) {
		int res = 1;
		queue<int> q;
		unordered_set<int> us;
		vector<int> v;
		for (int i = 1; i*i <= n; ++i) {
			int num = i*i;
			if (num == n) { return res; }
			v.push_back(num);
			q.push(num);
			us.insert(num);
		}
		while (!q.empty()) {
			++res;
			int qsize = q.size();
			for (int i = 0; i < qsize; ++i) {
				int num1 = q.front();
				for (int j = 0; j < v.size(); ++j) {
					int sum = num1+v[j];
					if (sum == n) { return res; }
					if (sum < n && us.find(sum) == us.end()) {
						q.push(sum);
						us.insert(sum);
					}
				}
				q.pop();
			}
		}
		return -1;
	}
};
