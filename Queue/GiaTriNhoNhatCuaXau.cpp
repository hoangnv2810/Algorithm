#include<iostream>
#include<stack>
#include<map>
#include<queue>
#include<string>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		long long k;
		string s;
		cin >> k >> s;
		map<char, long long > mp;
		priority_queue<long long, vector<long long>> q;
		for (int i = 0; i < s.size(); i++) {
			mp[s[i]]++;
		}
		for (auto x : mp) {
			q.push(x.second);
		}
		while (!q.empty() && k > 0) {
			int top = q.top();
			q.pop();
			k--;
			q.push(--top);
		}
		long long res = 0;
		while (!q.empty()) {
			res += q.top() * q.top();
			q.pop();
		}
		cout << res << " ";
		cout << endl;
	}
}
