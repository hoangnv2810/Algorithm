#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int *a = new int[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int k;
	cin >> k;
	for(int i = 0; i < n; i++){
		if(a[i] != k) cout << a[i] << " ";
	}
	cout << endl;
}

