#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		string val;
		vector<string> a;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> val;
			a.push_back(val);
		}

		map<char, int> mp;
		for (int i = 0; i < a.size(); i++) {
			for (auto x : a[i]) {
				mp[x]++;
			}
		}

		for (auto x : mp) {
			cout << x.first << " ";
		}
		
		cout << endl;
		
	}
}
