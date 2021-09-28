#include<iostream>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		stack<string> st;
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
				string s1 = st.top();
				st.pop();
				string s2 = st.top();
				st.pop();
				auto temp = '(' + s1 + s[i] + s2 + ')';
				st.push(temp);
			}
			else {
				st.push(string(1, s[i]));
			}
		}
		while (!st.empty()) {
			cout << st.top();
			st.pop();
		}
		cout << endl;
	}
}

