#include<bits/stdc++.h>
using namespace std;
int a[100][100], n, T[100][100]; 
bool chuaxet[100];
void PRIM(int a[100][100], int u){
	int k, top, min, l, t;
	int s[100];
	int sc = 0, w = 0;
	u = 1;
	top = 1;
	s[top] = u;
	chuaxet[u] = false;
	while(sc < n-1){
		min = INT_MAX;
		for(int i = 1; i <= top; i++){
			t = s[i];
			for(int j = 1; j <= n; j++){
				if(chuaxet[j] && min > a[t][j]){
					min = a[t][j];
					k = t;
					l = j;
				}
			}
		}
		sc++;
		w = w + min;
		T[sc][1] = k;
		T[sc][2] = l;
		chuaxet[l] = false;
		top++;
		s[top] = l;
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){

	}
}

