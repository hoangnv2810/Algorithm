#include<iostream>
#include<stack>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string exp;
		cin >> exp;
		stack<int> s;
		s.push(-1);
		int res = 0;
		for (int i = 0; i < exp.length(); i++) {
			if (exp[i] == '(') {
				s.push(i);
			}
			else {
				s.pop();
				if (!s.empty()) res = max(res, i - s.top());
				else {
					s.push(i);
				}
			}
		}
		cout << res << endl;
	}
}