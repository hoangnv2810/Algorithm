// Cho mảng đã được sắp xếp A[] gồm N phần tử không có hai phần tử giống nhau và số X. Nhiệm vụ của bạn là tìm floor(X). Trong đó, K=floor(X) là phần tử lớn nhất trong mảng A[] nhỏ hơn hoặc bằng X.
#include<iostream>
using namespace std;

int solution(long long a[], long long x, int l, int r) {
	if (x >= a[r]) return r+1;
	int mid = (l + r) / 2;
	if (l <= r) {
		if (a[mid] == x) return mid + 1;
		if (a[mid - 1] <= x && x < a[mid]) return mid;
		if (a[mid] > x) return solution(a, x, l, mid - 1);
		return solution(a, x, mid + 1, r);
	}
	else {
		return -1;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		long long x, * a;
		cin >> n >> x;
		a = new long long[n];
		for (int i = 0; i < n; i++) cin >> a[i];
		cout << solution(a, x, 0, n - 1) << endl;
	}
}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		vector<long long> v;
//		long long x, val;
//		cin >> n >> x;
//		for (int i = 0; i < n; i++) {
//			cin >> val;
//			v.push_back(val);
//		}
//
//		vector<long long>::iterator it;
//		it = upper_bound(v.begin(), v.end(), x);
//		int res = it - v.begin();
//		if (res == 0) {
//			cout << -1 << endl;
//		} else cout << res << endl;
//
//	}
//}


