#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int s, d;
		cin >> s >> d;
		int res[d];
		if(s == 0 && d == 1){
			cout << 0;
			continue;
		}
		if(s > d*9){
			cout << -1 << endl;
			continue;
		}
		s -= 1;
		for(int i = d-1; i > 0; i--){
			if(s > 9) {
				res[i] = 9;
				s -= 9;
			} else {
				res[i] = s;
				s = 0;
			}
		}
		res[0] = s+1;
		for(int i = 0; i < d; i++){
			cout << res[i];
		}
		cout << endl;
	}
}





