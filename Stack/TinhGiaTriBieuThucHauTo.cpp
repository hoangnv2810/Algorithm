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
		stack<int> st;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
				int a = st.top();
				st.pop();
				int b = st.top();
				st.pop();
				int temp;
				if (s[i] == '+') temp = a + b;
				else if (s[i] == '-') temp = b - a;
				else if (s[i] == '*') temp = a * b;
				else temp = b / a;
				st.push(temp);
			}
			else {
				st.push((s[i]-'0'));
			}
		}
		cout << st.top() << endl;
	}
}

