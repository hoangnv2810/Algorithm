#include<iostream>
#include<cstring>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		string s;
		cin >> s;
		map<char, int> mp;
		for (int i = 0; i < s.length(); i++) {
			mp[s[i]]++;
		}
		priority_queue<int> q;
		for (auto x : mp) {
			q.push(x.second);
		}
		while (k > 0 && !q.empty()) {
			int a = q.top();
			q.pop();
			a -= 1;
			q.push(a);
			k--;
		}
		long long res = 0;
		while (!q.empty()) {
			res += q.top() * q.top();
			q.pop();
		}

		cout << res << endl;
	}
}





