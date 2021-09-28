#include<bits/stdc++.h>
using namespace std;

int n, a[100];
void Result(){
	for(int i = 1; i <= n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

void Try(int i){
	for(int j = 0; j <= 1; j++){
		a[i] = j;
		if(i == n){
			int flag = 0;
			if(n%2)
			for(int i = 1; i <= n/2+1; i++){
				if(a[i] == a[n-i+1]) flag++;
			}
			else
			for(int i = 1; i <= n/2; i++){
				if(a[i] == a[n-i+1]) flag++;
			}
			if(n%2 == 0 && flag == n/2 || n%2 == 1 && flag == n/2+1){
				Result();
			} 
		} else {
			Try(i+1);
		}
	}
}

int main(){
	cin >> n;
	Try(1);
}

