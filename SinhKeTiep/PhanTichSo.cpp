#include<bits/stdc++.h>
using namespace std;
void print(int a[], int &k) {
	for (int i = 1; i <= k; i++) {
		if (i == 1) cout << "(";
		cout << a[i];
		if (i < k) cout << " ";
		else cout << ") ";
	}
}

void sinh(int a[], int& k, int& check) {
	int i = k;
	while (i > 0 && a[i] == 1) i--;
	if (i < 1) check = 0;
	else {
		int kc = k - i + 1;
		a[i]--;
		k = i + kc / a[i];
		for (int j = i + 1; j <= k; j++) {
			a[j] = a[i];
		}
		if(kc%a[i]){
			a[++k] = kc%a[i];
		}

	}

}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, a[100], k = 1, check = 1;
		cin >> n;
		a[k] = n;
		while(check){
			print(a, k);
			sinh(a, k, check);
		}
		cout << endl;
	}
}

