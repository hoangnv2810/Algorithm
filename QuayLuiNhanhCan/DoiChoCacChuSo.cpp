#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		for(int i = 0; i < s.length(); i++){
			char max = s[s.length()-1];
			int index = s.length()-1;
			if(n > 0){
				for(int j = s.length()-2; j > i; j--){
					if(max < s[j]){
						max = s[j];
						index = j;
					}
				}
				if(max > s[i]){
					n--;
					swap(s[i], s[index]);
				}
			}
		}
		for(int i = 0; i < s.length(); i++){
			cout << s[i];
		}
		cout << endl;
	}
}

