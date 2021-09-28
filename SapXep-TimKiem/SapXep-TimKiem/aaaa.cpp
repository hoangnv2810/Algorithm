#include<bits/stdc++.h>
using namespace std;

int solution(string s, int l, int r){
	if(l == r) return 1;
	if(s[l] != s[r]) return 0;
	if(r-l > 1) return solution(s, l+1, r-1);
}

int main(){
	string s;
	cin >> s;
	cout << solution(s, 0, s.length()-1);
}
