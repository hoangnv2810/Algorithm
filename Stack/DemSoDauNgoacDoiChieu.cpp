#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string exp;
		cin >> exp;
		stack<char> s;
		for (auto x : exp) {
			if (x == ')') {
				if (!s.empty() && s.top() == '('){
					s.pop();
					continue;
				}
			}
			s.push(x);
		}

		int res = 0;
		while (!s.empty()) {
			auto s1 = s.top();
			s.pop();
			auto s2 = s.top();
			s.pop();
			if (s1 != s2) res++;
			res++;
		}
		cout << res << endl;
	}
}


