#include<bits/stdc++.h>
using namespace std;

void sof(int n){
	bool a[n + 1];
    memset(a, true, sizeof(a));
	for(int p = 2; p*p <= n; p++){
		if(a[p] == true){
			for(int i = p*p; i <= n; i += p){
				a[i] = false;
			}
		}
	}
	bool flag = false;
	for(int i = 2; i <= n; i++){
		if(a[i] == true && a[n-i] == true && n-i >= 2) {
			flag = true;
			cout << i << " " << n-i;
			break;
		} 
	}
	if(flag == false) cout << -1;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		sof(n);
		cout << endl;
	}
}

