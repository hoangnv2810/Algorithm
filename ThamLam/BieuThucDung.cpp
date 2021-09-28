#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		stack<char> st;
		int res = 0;
		for (int i = 0; i < s.length(); i++) {
			if (st.empty()) {
				st.push(s[i]);
			} 
			else if (st.top() == '[' && s[i] == ']') {
				st.pop();
			}
			else if (st.top() == ']' && s[i] == '[') {
				res += st.size();
				st.pop();
			}
			else st.push(s[i]);
		}
		cout << res << endl;
	}
}
