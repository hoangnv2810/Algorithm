#include<bits/stdc++.h>
using namespace std;
// Thuat toan sinh nhi phan ke tiep
void NpKe(int a[], int n){
	for(int i = 1; i <= n; i++) a[i] = 0;
	while(1){
		for(int i = 1; i <= n; i++) cout << a[i];
		cout << endl;
		int i = n;
		while(i > 0 && a[i] == 1){
			a[i] = 0;
			i--;
		}
		if(i == 0) return;
		else{
			a[i] = 1;
		}
	}
}

int main(){
	int a[100];
	NpKe(a, 3);
}

