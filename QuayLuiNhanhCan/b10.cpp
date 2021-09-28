#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

long solution(int k, string s, map<char, int> mp) {
	priority_queue<int, vector<int>> q;
	long res = 0;
	for (auto x : s) {
		if (mp[x]) {
			q.push(mp[x]);
			mp[x] = 0;
		}
	}
	for (int i = k; i > 0 && !q.empty(); i--) {
		int temp = q.top();
		q.push(--temp);
		q.pop();
	}
	while (!q.empty()) {
		res += q.top() * q.top();
		q.pop();
	}
	return res;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int k;
		string s;
		cin >> k >> s;
		map<char, int> mp;
		for (auto x : s) {
			mp[x]++;
		}
		cout << solution(k, s, mp) << endl;
	}
}

