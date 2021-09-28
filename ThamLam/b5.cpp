#include<bits/stdc++.h>
using namespace std;
int a[20];
void Try(int i, int k, int n){
	for(int j = 0; j <= 1; j++){
		a[i] = j;
		if(i == n){
			int dem = 0;
			for(int i = 1; i <= n; i++){
				if(a[i]) dem++;
			}
			if(dem == k){
				for(int i = 1; i <= n; i++){
					cout << a[i];
				}
				cout << endl;
			}
		} else {
			Try(i+1, k, n);
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		Try(1, k, n);
	}
}

