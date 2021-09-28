#include<bits/stdc++.h>
using namespace std;
int a[100], n, k;
void Try(int i){
	for(int j = a[i-1]+1; j <= n-k+i; j++){
		a[i] = j;
		if(i == k){
			for(int l = 1; l <= k; l++){
				cout << (char)(a[l]+64);
			}
			cout << endl;
		} else {
			Try(i+1);
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		Try(1);
	}
}

