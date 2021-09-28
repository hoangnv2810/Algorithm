#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		int* a = new int[n];
		int* b = new int[m];
		int* c = new int[k];
		
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		for (int i = 0; i < k; i++) {
			cin >> c[i];
		}
		
		int i = 0, j = 0, l = 0, check = 0;
		while(i < n && j < m && l < k){
			if (a[i] == b[j] && a[i] == c[l]) {
				cout << a[i] << " ";
				i++, j++, l++;
				check = 1;
			}
			else if (a[i] < b[j]) i++;
			else if (b[j] < c[l]) j++;
			else l++;
		}
		if (!check) cout << "-1";
		cout << endl;


	}
}