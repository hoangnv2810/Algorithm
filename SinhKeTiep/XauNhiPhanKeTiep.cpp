#include<iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int i = s.length() - 1;
		while (i >= 0 && s[i] == 1+'0') {
			s[i] = 0 + '0';
			i--;
		}
		s[i] = 1 + '0';

		for (int i = 0; i < s.length(); i++) cout << s[i];
		cout << endl;
	}
}
