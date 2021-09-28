#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, *a;
		cin >> n;
		a = new int [n];
		for(int i = 0; i < n; i++){
			a[i] = 0;
		}
		while(1){
			for(int i = 0; i < n; i++){
				cout << char(a[i]+65);
			}
			cout << " ";
			int i = n-1;
			while(i >= 0 && a[i] == 1){
				a[i] = 0;
				i--;
			}
			if(i < 0) break;
			else {
				a[i] = 1;
			}
		
			
		
		}
		cout << endl;
	}
}
