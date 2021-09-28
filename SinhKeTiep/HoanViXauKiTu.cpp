#include<bits/stdc++.h>
using namespace std;
int a[100], used[100], n;
void Result(){
	for(int i = 1; i <= n; i++){
		cout << (char)(a[i]+64);
	}
	cout <<  " ";
}

void Try(int i){
	for(int j = 1; j <= n; j++){
		if(used[j] == 0){
			a[i] = j;
			used[j] = 1;
			if(i == n){
				Result();
			} else {
				Try(i+1);
			}
			used[j] = 0;
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		n = s.length();
		Try(1);
		cout << endl;
	}
}

