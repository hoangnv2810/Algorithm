#include<bits/stdc++.h>
using namespace std;

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
		
		int i = n-2;
		while(a[i] > a[i+1]) i--;
		if(i == -2) { 
			for(int i = n-1; i >=0; i--){
				cout << a[i] << " ";
			}
		} else {
			int j;
			for(j = n-1; j > i; j--){
				if(a[j] > a[i]) break;
			}
			
			swap(a[i], a[j]);
			sort(a+i+1, a+n);
			for(int i = 0; i < n; i++) cout << a[i] << " ";
		}
		
		cout << endl;
	}
}
