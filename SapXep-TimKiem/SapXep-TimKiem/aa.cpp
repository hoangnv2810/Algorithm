#include<bits/stdc++.h>
using namespace std;

int dem;
int solution(int n){
	if(n == 0) return dem;
	else if (n!= 0){
		dem++;
	}
	return solution(n/10);
	
}

int main(){
	int a = -1230;
	cout << solution(a) ;
}
