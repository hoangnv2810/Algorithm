#include<iostream>
#include<queue>
#include<vector>
using namespace std;


void solution(priority_queue<long long, vector<long long>, greater<long long>> q) {
	long long res = 0;
	while (q.size() > 1) {
		long long a = q.top();
		q.pop();
		long long b = q.top();
		q.pop();
		q.push(a + b);
		res += a + b;
	}
	cout << res << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		long long value;
		priority_queue<long long, vector<long long>, greater<long long>> q;
		
		for (int i = 0; i < n; i++) {
			cin >> value;
			q.push(value);
		}
		solution(q);
	}
}
