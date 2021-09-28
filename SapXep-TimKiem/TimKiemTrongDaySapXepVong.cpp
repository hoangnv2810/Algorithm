#include<iostream>
#include<algorithm>
using namespace std;

int binary_search(int a[], int l, int r, int x) {
	if (l <= r) {
		int mid = (r-l) / 2 + l;
		if (a[mid] == x) return mid+1;
		if (a[mid] > x) return binary_search(a, l, mid - 1, x);
		else return binary_search(a, mid + 1, r, x);

	}
	return 0;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, * a, x;
		cin >> n >> x;
		a = new int[n];
		for (int i = 0; i < n; i++) cin >> a[i];
		int max, index = 0;
		max = a[index];
		for (int i = 1; i < n; i++) {
			if(max < a[i]){
				max = a[i];
				index = i;
			}
		}
		
		if(binary_search(a, 0, index, x) || binary_search(a, index+1, n-1, x)){
			if(binary_search(a, 0, index, x))
				cout << binary_search(a, 0, index, x);
			if(binary_search(a, index+1, n-1, x))
				cout << binary_search(a, index+1, n-1, x);
		} 
		else {
			cout << -1;
		}
		cout << endl;
	}
}

