#include<iostream>
using namespace std;
const long long mod = 1e9 + 7;
long long dao(long long n) {
	long long k = 0;
	while (n != 0) {
		k = 10 * k + n % 10;
		n /= 10;
	}
	return k;
}

long long solution(long long n, long long k) {
	if (k == 0) return 1;
	if (n == 0) return 0;
	if (k % 2 == 0) return (solution(n, k / 2) * solution(n, k / 2)) % mod;
	return n * ((solution(n, k / 2) * solution(n, k / 2)) % mod) % mod;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		long long n, k;
		cin >> n;
		k = dao(n);
		cout << solution(n, k) << endl;
	}
}
