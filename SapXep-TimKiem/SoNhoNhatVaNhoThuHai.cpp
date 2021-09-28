#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, val;
		vector<int> a;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> val;
			a.push_back(val);
		}

		map<int, int> mp;
		for (auto x : a) {
			mp[x]++;
		}
			
		if (mp.size() == 1) {
			cout << -1;
		}
		else {
			map<int, int>::iterator it = mp.begin();
			cout << it->first << " ";
			cout << (++it)->first;
		}

		cout << endl;
		
	}
}
