#include<bits/stdc++.h>
using namespace std;

int n, a[100], b[100], k, res = 0;
void Nhap(){
	for(int i = 1; i <= n; i++){
		cin >> b[i];
	}
}

void Result(){
	for(int i = 1; i <= n; i++){
		if(a[i]){
			cout << b[i] << " ";
		}
	}
	cout << endl;
}

void Try(int i){
	for(int j = 0; j <= 1; j++){
		a[i] = j;
		if(i == n){
			int sum = 0;
			for(int i = 1; i <= n; i++){
				if(a[i]) sum += b[i];
			}
			if(sum == k) {
				Result();
				res++;
			}
		} else {
			Try(i+1);
		}
	}
}

int main(){
	cin >> n >> k;
	Nhap();
	Try(1);
	cout << res << endl;
}

