#include<bits/stdc++.h>
using namespace std;

void print(int a[], int n){
	cout << "[";
	for(int i = 0; i < n-1; i++){
		cout << a[i] << " ";
	}
	cout << a[n-1] << "]" << endl;
}

void Try(int a[], int n){
	if(n == 1) return; 
	else {
		int temp[n-1];
		for(int i = 0; i < n-1; i++){
			temp[i] = a[i]+a[i+1];
		}
		print(temp, n-1);
		Try(temp, n-1);
	
		
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, *a;
		cin >> n;
		a = new int[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		print(a, n);
		Try(a, n);
	}
}
