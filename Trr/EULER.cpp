#include<bits/stdc++.h>
using namespace std;
int a[100][100], CE[100], u, n;
void EULER(int a[100][100]){
	stack<int> s;
	s.push(u);
	int t = 1;
	while(!s.empty()){
		int v = s.top();
		int x = 1;
		while(x <= n && a[v][x] == 0) x++;
		if(x <= n){
			s.push(x);
			a[v][x] = 0;
			a[x][v] = 0;
		} else {
			CE[t] = v;
			t++;
			s.pop();
		}
	}
	for(int i = t-1; i > 0; i--){
		cout << CE[i] << " ";
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
	
	}
}

