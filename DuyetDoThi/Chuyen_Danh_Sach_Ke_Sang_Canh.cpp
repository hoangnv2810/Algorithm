#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	cin.ignore();
	vector<int> ke[100];
	for(int i = 1; i <= n; i++){
		string s;
		getline(cin, s);
		s += " ";
		int j = 0, num = 0;
		while(j < s.size()){
			if(s[j] >= '0' && s[j] <= '9'){
				num = 10*num + (s[j]-'0');
			} else if(num > 0){
				ke[i].push_back(num);
				num = 0;	
			} 
			j++;
		}
	}
	int flag[100][100];
	memset(flag, 0, sizeof(flag));
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < ke[i].size(); j++){
			if(!flag[i][ke[i][j]] && !flag[ke[i][j]][i]){
				cout << i << " " << ke[i][j] << endl;				
				flag[i][ke[i][j]] = flag[ke[i][j]][i] = 1;
			}
		}
	}

}
	
