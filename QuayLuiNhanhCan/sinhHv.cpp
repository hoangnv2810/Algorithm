#include<bits/stdc++.h>
using namespace std;
// Thuat toan sinh hoan vi ke tiep
void HvKe(int a[], int n){
	for(int i = 1; i <= n; i++) a[i] = i;
	while(1){
		for(int i = 1; i <= n; i++) cout << a[i];
		cout << endl;
		int i = n-1;
		while(i > 0 && a[i] > a[i+1]) i--;
		if(i == 0) return;
		int k = n;
		while(a[k] < a[i]) k--;
		int temp = a[k];
		a[k] = a[i];
		a[i] = temp;
		int l = i+1, r = n;
		while(l < r){
			swap(a[l], a[r]);
			l++, r--;
		}
	}
}


int main(){
	int a[100];
	HvKe(a, 9);
}

