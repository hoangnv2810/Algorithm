#include<bits/stdc++.h>
using namespace std;

long long solution(int n, long long k){
	long long len = pow(2, n-1);
	if(k == len){
		return n;
	} 
	if(k > len){
		return solution(n-1, len-(k-len));
	}
	return solution(n-1, k);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		long long k;
		cin >> n >> k;
		cout << solution(n, k) << endl;
	}
}

