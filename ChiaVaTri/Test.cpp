#include<iostream>
#include<cstring>
using namespace std; 

int main(){ 
	int t;
	cin >> t; 
	while(t--){
		string s; 
		cin >> s; 
		int n = s.length(); 
//		for(int i = 1; i <= n; i++){ 
//			for(int j = 0, x = i; x < n; x++, j++){ 
//				cout << "i: " << i << " "<< "j: " << j << " x: " << x << endl;
//			} 
//		} 
		for(int k = 1; k < n; k++){
			for(int i = 1; i <= n-k; i++){
				int j = i+k;
				cout << "k: " << k << " i: " << i << " j: " << j << endl; 
			}
		}
	}
	return 0; 
}
