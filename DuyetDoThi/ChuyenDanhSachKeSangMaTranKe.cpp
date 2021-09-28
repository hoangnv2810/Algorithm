#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	cin.ignore();
	string s;
	int a[n+1][n+1];
	memset(a, 0, sizeof(a));
	for(int i = 0; i < n; i++){
		getline(cin, s);
		s += " ";
		int j = 0, num = 0;
		while(j < s.size()){
			if(s[j] >= '0' && s[j] <= '9'){
				num = num*10 + (s[j]-'0');
			} else if(num > 0){
				a[i][num-1] = 1;
				a[num-1][i] = 1;
				num = 0; 
			}
			j++;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	
}

