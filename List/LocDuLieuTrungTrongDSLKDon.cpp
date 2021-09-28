#include<iostream>
#include<map>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
		int n;
	cin >> n;
	int* a = new int[n];
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	for (auto x : mp) {
		cout << x.first << " ";
	}
	cout << endl;
	}

}

