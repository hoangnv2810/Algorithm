#include<bits/stdc++.h>
using namespace std;
int b[100], unused[100], a[100][100];
vector<int> v;
int n, k;

void Result(){
	for(int i = 1; i <= k; i++){
		cout << b[i] << "";
	}
	cout << endl;

}

void Try(int i){
	for(int j = 1; j <= n; j++){
		if(unused[j] == 0){
			b[i] = j;
			unused[j] = 1;
			if(i == n){
				Result();
			} else {
				Try(i+1);
			}
			unused[j] = 0;
		}
	}
}
int main(){
	cin >> n >> k;
	Try(1);
}

