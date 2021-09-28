#include<bits/stdc++.h>
using namespace std;
int a[100], n;
void result(){
	if(a[1] == 1 && a[n] == 0){
		int flag = 0;
		for(int i = 1; i <= n-1; i++){
			if(a[i] == 1 && a[i+1] == 1){
				flag = 1;		
			}
		}
		if(!flag){
			for(int i = 1; i <= n; i++){
				if(a[i]==1) cout << (char)(a[i]+71);
				else cout << (char)(a[i]+65);
			}
		}
		cout << endl;
	}
	
}
void Try(int i){
	for(int j = 0; j <= 1; j++){
		a[i] = j;
		if(i == n){
			result();
		} else {
			Try(i+1);
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		Try(1);
	}
}

