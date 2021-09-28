#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long oo = 1e9+7;

long long solution(long long n, long long k) {
	if (n == 0) return 0;
	if (k == 0) return 1;
	if (k % 2 == 0) {
		return (solution(n, k / 2) * solution(n, k/2))%oo;
	}
	else {
		return n*((solution(n, k/2) * solution(n, k/2))%oo)%oo;
	}
	
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		long long n, k;
		cin >> n >> k;
		cout << solution(n, k);

		cout << endl;
	}
}


//#include<iostream>
//#include<cmath>
//using namespace std;
//
//const long long mod = 1e9+7;
//int main(){
//	int t;
//	cin >> t;
//	while(t--){
//		long long x, y;
//		cin >> x >> y;
//		long long ans = 1;
//		while(y != 0){
//			if(y%2 != 0){
//				ans = (ans*x)%mod;
//			}
//			x = (x*x)%mod;
//			y /= 2;
//		}	
//		cout << ans << endl;
//	}
//}
