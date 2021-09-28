#include<bits/stdc++.h>
using namespace std;
int a[100], n = 3;
void Result(){
	for(int i = 1; i <= n; i++){
		cout << a[i];
	}
	cout << endl;
}

void Try(int i){
	for(int j = 0; j <= 1; j++){
		a[i] = j;
		if(i == n){
			Result();
		} else {
			Try(i+1);	
		}
	}
}
int main(){
	Try(1);
}

