#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	cin.ignore();
	while(t--){
		string s;
		int stt;
		cin >> stt >> s;
		int i = s.length()-1;
		while(i >= 0 && s[i-1] >= s[i]) i--;
		if(i-1 < 0){
			cout << stt << " BIGGEST" << endl;
		} else {
			int j;
			for(j = s.length()-1; j >= i-1; j--){
				if(s[j] > s[i-1]){
					break;
				}
			}
			swap(s[i-1], s[j]);
			sort(s.begin()+i, s.end());
			cout << stt << " " ;
			for(int i = 0; i < s.length(); i++) cout << s[i];
			cout << endl;
		}
	}
}

