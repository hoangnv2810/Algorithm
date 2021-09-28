#include<bits/stdc++.h>
using namespace std;

void sum(string a, string b){
	int sum1 = 0, sum2 = 0;
	for(int i = 0; i < a.length(); i++){
		sum1 = sum1*10 + (a[i]-'0');
	}
	for(int i = 0; i < b.length(); i++){
		sum2 = sum2*10 + (b[i]-'0');
	}
	cout << sum1 + sum2 << " ";
}

int main(){

		string a, b;
		cin >> a >> b;
		for(int i = 0; i < a.length(); i++){
			if(a[i] == '6') a[i] = '5';
		}
		for(int i = 0; i < b.length(); i++){
			if(b[i] == '6') b[i] = '5';
		}
		sum(a, b);
		for(int i = 0; i < a.length(); i++){
			if(a[i] == '5') a[i] = '6';
		}
		for(int i = 0; i < b.length(); i++){
			if(b[i] == '5') b[i] = '6';
		}
		sum(a, b);
		
		cout << endl;
	
}
