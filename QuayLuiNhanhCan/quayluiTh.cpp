#include<bits/stdc++.h>
using namespace std;

int a[100], n = 5, k = 3;
void Result(){
	for(int i = 1; i <= k; i++){
		cout << a[i];
	}
	cout << endl;
}

void Try(int i){
	for(int j = a[i-1]+1; j <= n-k+i; j++){
		a[i] = j;
		if(i == k){
			Result();
		} else {
			Try(i + 1);
		}
	}	
}
int main(){
	Try(1);
}

