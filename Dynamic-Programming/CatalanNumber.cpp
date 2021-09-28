#include<iostream>
#include<vector>
#include<string>
using namespace std;

string add(string a, string b) {
	while (a.length() < b.length()) a = "0" + a;
	while (a.length() > b.length()) b = "0" + b;
	string res;
	int carry = 0;
	for (int i = a.length() - 1; i >= 0; i--) {
		int num = (a[i] - '0') + (b[i] - '0') + carry;
		res = char(num % 10 + '0') + res;
		carry = num / 10;
	}
	if (carry > 0) res = char(carry + '0') + res;
	return res;
}

string Mul(string a, string b) {
	int index = 0;
	vector< vector<int> > res(b.length());
	for (int i = b.length() - 1; i >= 0; i--) {
		int t = 0;
		while (t < index) {
			res[index].push_back(0);
			t++;
		}
		int carry = 0;
		for (int j = a.length() - 1; j >= 0; j--) {
			int num = (b[i] - '0') * (a[j] - '0') + carry;
			res[index].push_back(num % 10);
			carry = num / 10;
		}
		if (carry > 0) res[index].push_back(carry);
		while (res[index].size() < a.size() + b.size()) {
			res[index].push_back(0);
		}
		reverse(res[index].begin(), res[index].end());
		index++;
	}
	string ans;
	int carry = 0;
	for (int i = res[0].size() - 1; i >= 0; i--) {
		int num = carry;
		for (int j = 0; j < res.size(); j++) {
			num += res[j][i];
		}
		ans = (char)(num % 10 + '0') + ans;
		carry = num / 10;
	}
	if (carry > 0) ans = char(carry + '0') + ans;
	while (ans[0] == '0') ans.erase(ans.begin());
	return ans;
}

#include<iostream>
#include<vector>
#include<string>
using namespace std;

string add(string a, string b) {
	while (a.length() < b.length()) a = "0" + a;
	while (a.length() > b.length()) b = "0" + b;
	string res;
	int carry = 0;
	for (int i = a.length() - 1; i >= 0; i--) {
		int num = (a[i] - '0') + (b[i] - '0') + carry;
		res = char(num % 10 + '0') + res;
		carry = num / 10;
	}
	if (carry > 0) res = char(carry + '0') + res;
	return res;
}

string Mul(string a, string b) {
	int index = 0;
	vector< vector<int> > res(b.length());
	for (int i = b.length() - 1; i >= 0; i--) {
		int t = 0;
		while (t < index) {
			res[index].push_back(0);
			t++;
		}
		int carry = 0;
		for (int j = a.length() - 1; j >= 0; j--) {
			int num = (b[i] - '0') * (a[j] - '0') + carry;
			res[index].push_back(num % 10);
			carry = num / 10;
		}
		if (carry > 0) res[index].push_back(carry);
		while (res[index].size() < a.size() + b.size()) {
			res[index].push_back(0);
		}
		reverse(res[index].begin(), res[index].end());
		index++;
	}
	string ans;
	int carry = 0;
	for (int i = res[0].size() - 1; i >= 0; i--) {
		int num = carry;
		for (int j = 0; j < res.size(); j++) {
			num += res[j][i];
		}
		ans = (char)(num % 10 + '0') + ans;
		carry = num / 10;
	}
	if (carry > 0) ans = char(carry + '0') + ans;
	while (ans[0] == '0') ans.erase(ans.begin());
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string dp[1000];
		dp[0] = "1";
		dp[1] = "1";
		for (int i = 2; i <= n; i++) {
			string temp = "0";
			for (int j = 0; j < i; j++) {
				temp = add(temp, Mul(dp[j], dp[i - j - 1]));
			}
			dp[i] = temp;
		}
		cout << dp[n] << endl;
	}
}