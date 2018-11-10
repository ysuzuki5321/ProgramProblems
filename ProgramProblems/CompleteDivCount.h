#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <deque>
using namespace std;
#pragma once
class CompleteDivCount
{
public:
	CompleteDivCount();
	~CompleteDivCount();
	void solve() {
		int n;
		cin >> n;
		queue<pair<vector<bool>, int>> q;
		for (size_t i = 1; i <= n; i++)
		{
			vector<bool> v(n + 1);
			v[i] = true;
			q.push(pair<vector<bool>, int>(v, i));
		}

		vector<int> res;
		while (!q.empty())
		{
			pair<vector<bool>, int> p = q.front(); q.pop();

			if (p.second >= pow(10, n - 1)) {
				res.push_back(p.second);
				continue;
			}

			int temp = p.second * 10;
			int digit = to_string(temp).size();

			for (size_t i = 1; i <= n; i++)
			{
				if (p.first[i]) continue;
				if ((temp + i) % digit == 0) {
					cout << (temp + i) << endl;

					vector<bool> a = p.first;
					a[i] = true;
					q.push(pair<vector<bool>, int>(a, temp + i));
				}
			}
		}

		for (size_t i = 0; i < res.size(); i++)
		{
			cout << res[i] << endl;
		}
	}

};

