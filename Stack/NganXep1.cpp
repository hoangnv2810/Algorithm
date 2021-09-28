#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int main() {
	stack<int> s;
	string input;
	while (cin >> input) {
		if (input == "push") {
			int val;
			cin >> val;
			s.push(val);
		}
		else if (input == "pop") {
			s.pop();
		}
		else {
			if (s.empty()) cout << "empty";
			else {
				vector<int> temp;
				while (!s.empty()) {
					temp.push_back(s.top());
					s.pop();
				}
				reverse(temp.begin(), temp.end());
				for (auto x : temp) {
					cout << x << " ";
					s.push(x);
				}
			}
			cout << endl;
		}

	}
}

