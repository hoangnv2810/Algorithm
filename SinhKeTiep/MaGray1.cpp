#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<string> s;
		s.push_back("0");
		s.push_back("1");
		if (n > 0) {
			for (int i = 2; i < pow(2, n); i *= 2) {
				for (int j = i - 1; j >= 0; j--) {
					s.push_back(s[j]);
				}
				for (int j = 0; j < i; j++) {
					s[j] = "0" + s[j];
				}
				for (int j = i; j < 2 * i; j++) {
					s[j] = "1" + s[j];
				}
			}
			for(auto x : s){
				cout << x << " ";
			}
			cout << endl;
		}
	}
}

