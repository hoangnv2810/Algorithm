#include<bits/stdc++.h>
using namespace std;
int a[100], b[100], n, used[100];
void result(){
	for(int i = 1; i <= n; i++){
		cout << (char)(a[i]+64);
	}
	for(int i = 1; i <= n; i++){
		cout << b[i];
	}
	cout << endl;
}

void TryNP(int i){
	for(int j = 0; j <= n-1; j++){
		b[i] = j+1;
		if(i == n){
			result();
		} else {
			TryNP(i+1);
		}
	}
}

void TryHV(int i){
	for(int j = 1; j <= n; j++){
		if(used[j] == 0){
			a[i] = j;
			used[j] = 1;
			if(i == n){
				TryNP(1);
			} else {
				TryHV(i+1);
			}
			used[j] = 0;
		}
	}
}

int main(){
	cin >> n;
	TryHV(1);
}

