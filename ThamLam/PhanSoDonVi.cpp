#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		long long tu, mau, res;
		cin >> tu >> mau;
		while (1) {
			if (mau % tu == 0) {
				cout << 1 << "/" << mau/tu << endl;
				break;
			}
			else {
				res = mau / tu + 1;
				cout << 1 << "/" << res << " + ";
				tu = res * tu - mau;
				mau = res * mau;
			}
		}
	}
}
