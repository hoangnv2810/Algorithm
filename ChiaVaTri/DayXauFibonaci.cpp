#include<bits/stdc++.h>
using namespace std;

char solution(long long g[], int n, long long k){
	if(n == 1) return 'A';
	else if(n == 2) return 'B';
	if(k <= g[n-2]) return solution(g, n-2, k);
	return solution(g, n-1, k-g[n-2]);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		long long g[100], k;
		cin >> n >> k;
		g[1] = 1;
		g[2] = 1;
		for(int i = 3; i < 93; i++){
			g[i] = g[i-1] + g[i-2];
		}
		cout << g[92] << endl;
		cout << g[6] << endl;
		cout << solution(g, n, k) << endl;
	}
}

