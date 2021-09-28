#include<bits/stdc++.h>
using namespace std;
int b[100], a[100], used[100], n, k, res;
int result(){
	for(int i = 1; i < k; i++){
		if(a[b[i]] > a[b[i+1]]){
			return 0;
		}
	}
	return 1;
}

void Try(int i){
	for(int j = b[i-1]+1; j <= n-k+i; j++){
		b[i] = j;
		if(i == k){
			if(result()){
				res++;
			}
		} else {
			Try(i+1);
		}
	}
}

int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	Try(1);
	cout << res;
}

