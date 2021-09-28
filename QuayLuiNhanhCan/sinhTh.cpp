#include<bits/stdc++.h>
using namespace std;
// Thuat toan sinh to hop ke tiep
void ThKe(int a[], int n, int k){
	for(int i = 1; i <= k; i++) a[i] = i;
	while(1){
		for(int i = 1; i <= k; i++) cout << a[i];
		cout << endl;
		int i = k;
		while(i > 0 && a[i] >= n-k+i) i--;
		if(i == 0) return;
		a[i] = a[i]+1;
		for(int j = i+1; j <= k; j++){
			a[j] = a[i] + j-i;
		}
	}
}
int main(){
	int a[100];
	ThKe(a, 5, 3);
}

