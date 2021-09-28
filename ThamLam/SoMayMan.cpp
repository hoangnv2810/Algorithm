#include<iostream>
#include<cstring>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int sum;
		cin >> sum;
		int check = 0;
		for (int i = 0; i * 4 <= sum; i++) {
			int temp = sum - i * 4;
			if (temp % 7 == 0) {
				check = 1;
				for (int j = 0; j < i; j++) cout << 4;
				for (int j = 0; j < temp / 7; j++) cout << 7;
				break;
			}
		}
		if (!check) cout << -1;
		cout << endl;
	}
}





