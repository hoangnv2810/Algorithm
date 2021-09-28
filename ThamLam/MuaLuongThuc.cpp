#include<bits/stdc++.h>
using namespace std;

int solution(int n, int s, int m){
	if(s*m > n*(s-s/7)) return -1;
	else {
		for(int i = 1; i <= (s-s/7); i++){
			if(i*n >= s*m){
				return i;
			} 
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, s, m;
		cin >> n >> s >> m;
		cout << solution(n, s, m) << endl;
	}
}

