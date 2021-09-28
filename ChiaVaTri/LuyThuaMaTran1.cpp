#include<iostream>
using namespace std;
const long long mod = 1e9 + 7;
int n;
long long a[10][10], b[10][10];
void Mul(long long x[10][10], long long y[10][10]) {
	long long temp[10][10];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			long long res = 0;
			for (int k = 0; k < n; k++) {
				res += (x[i][k] * y[k][j]) % mod;
				res %= mod;
			}
			temp[i][j] = res;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = temp[i][j];
		}
	}
}

void Pow(int n) {
	if (n <= 1) return;
	Pow(n / 2);
	Mul(a, a);
	if (n % 2 != 0) Mul(a, b);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				b[i][j] = a[i][j];
			}
		}
		Pow(k);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}
}