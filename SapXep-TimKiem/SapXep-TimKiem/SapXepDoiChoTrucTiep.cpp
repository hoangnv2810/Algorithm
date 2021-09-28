#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, * a;
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		bool flag = false;
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				flag = true;
				swap(a[i], a[j]);
			}
		}
		if (flag) {
			cout << "Buoc " << ++count << ": ";
			for (int k = 0; k < n; k++) cout << a[k] << " ";
			cout << endl;
			
		}
	}
}
