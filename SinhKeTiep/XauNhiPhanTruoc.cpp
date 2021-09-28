#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int nho = 0;
		for(int i = s.length()-1; i >= 0; i--){
			int temp;
			if(i == s.length()-1) temp = (s[i]-'0')-1-nho;
			else temp = (s[i]-'0')-nho;
			if(temp < 0){
				temp += 2;
				nho = 1;
			} else {
				nho = 0;
			}
			s[i] = (temp+'0');
		}
		for(int i = 0; i < s.length(); i++) cout << s[i];
		cout << endl;
	}
}

