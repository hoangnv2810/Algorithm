#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int main() {
	stack<int> s;
	int t;
	cin >> t;
	while (t--) {
		string input;
		cin >> input;
		if (input == "PUSH") {
			int val;
			cin >> val;
			s.push(val);
		}
		else if (input == "POP") {
			if (!s.empty()) s.pop();
		}
		else {
			if (s.empty()) cout << "NONE";
			else {
				cout << s.top();
			}
			cout << endl;
		}
	}
}

