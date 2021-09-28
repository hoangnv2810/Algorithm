#include<bits/stdc++.h>
using namespace std;
const long long mod = 123456789;

long long solution(long long n){
	if(n == 0) return 1;
	if(n == 1) return 2;
	if(n % 2 == 0) {
		return (solution(n/2) * solution(n/2))%mod;
	}
	else {
		return 2 * (solution(n/2)*solution(n/2)%mod)%mod;
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		long long n;
		cin >> n;
		cout << solution(n-1) << endl;
	}
}

