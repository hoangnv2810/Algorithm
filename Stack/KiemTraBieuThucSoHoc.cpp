#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		string str;
		getline(cin, str);
		stack<char> s;
		int flag;
		for (auto x : str) {
			if (x != ')') {
				s.push(x);
			}
			else {
				char top = s.top();
				s.pop();
				flag = 1;
				while (!s.empty() && top != '(') {
					if (top == '+' || top == '-' || top == '*' || top == '/') {
						flag = 0;
					}
					top = s.top();
					s.pop();
				}
				if (flag) {
					break;
				}
			}
		}
		if (!flag) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
}
