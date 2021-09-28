#include<iostream>
#include<conio.h>
using namespace std;
#define MAX 11 
int a[MAX][MAX];
int vs[MAX], x[MAX];
int n;
void Result() {
	cout << "Chu trinh Hamilton: ";
	for (int i = 0; i <= n; i++)
		cout << x[i] << " ";
	cout << endl;
}

void Hamilton(int k) {
	for (int i = 1; i <= n; i++) {
		if (a[x[k - 1]][i] == 1 && vs[i] == 0) {
			x[k] = i; vs[i] = 1;
			if (k < n) Hamilton(k + 1);
			else if (x[k] == x[0]) Result();
			vs[i] = 0;
		}
	}
}

int main() {
	x[0] = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	Hamilton(1);
}
