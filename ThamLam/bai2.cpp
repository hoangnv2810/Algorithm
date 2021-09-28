#include<bits/stdc++.h>
using namespace std;

void solution(int n, int s, int m){
	int soNgayDuocMua = s-s/7;
	if(m*s > n*soNgayDuocMua) cout << -1;
	else {
		for(int i = 1; i <= soNgayDuocMua; i++){
			if(i*n >= s*m){
				cout << i;
				break;
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
		solution(n, s, m);
		cout << endl;
	}
}

