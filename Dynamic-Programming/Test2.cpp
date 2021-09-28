#include<bits/stdc++.h>
using namespace std;

// Xau Con Chung Dai Nhat
// int dp[1001][1001];
// int main(){
// 	int t;
// 	cin >> t;
// 	while(t--){
// 		string a, b;
// 		cin >> a >> b;
// 		for(int i = 0; i <= a.length(); i++){
// 			for(int j = 0; j <= b.length(); j++){
// 				if(j == 0 || i == 0) dp[i][j] = 0;
// 				else if(a[i-1] == b[j-1]){
// 					dp[i][j] = dp[i-1][j-1] + 1;
// 				} else {
// 					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
// 				}
// 			}
// 		}
// 		cout << dp[a.length()][b.length()] << endl;
// 	}
// }

// Day Con Tang Dai Nhat
//int main(){
//	int t;
//	cin >> t;
//	while(t--){
//		int n, *a;
//		cin >> n;
//		a = new int[n];
//		for(int i = 0; i < n; i++){
//			cin >> a[i];
//		}
//		int dp[n+1];
//		memset(dp, 0, sizeof(dp));
//		dp[0] = 1;
//		int res = 0;
//		for(int i = 1; i < n; i++){
//			for(int j = 0; j < i; j++){
//				dp[i] = max(dp[i], dp[j]+1);
//			}
//			res = max(res, dp[i]);
//		}
//		cout << res << endl;
//	}
//}

// Day Con Co Tong Bang S
//int main(){
//	int t;
//	cin >> t;
//	while(t--){
//		int n, sum, *a;
//		cin >> n >> sum;
//		a = new int[n];
//		for(int i = 0; i < n; i++) cin >> a[i];
//		int dp[sum+1];
//		memset(dp, 0, sizeof(dp));
//		dp[0] = 1;
//		for(int i = 0; i < n; i++){
//			for(int j = sum; j >= a[i]; j--){
//				if(dp[j] == 0 && dp[j - a[i]] == 1){
//					dp[j] = 1;
//				}
//			}
//		}
//		if(dp[sum]){
//			cout << "YES" << endl;
//		} else cout << "NO" << endl;
//	}
//}

string Add(string a, string b){
    while(a.length() < b.length()) a = "0" + a;
    while(a.length() > b.length()) b = "0" + b;
    int carry = 0;
    string res;
    for(int i = a.length()-1; i >= 0; i--){
        int num = (a[i]-'0') + (b[i]-'0') + carry;
        res = char(num%10 + '0') + res;
        carry = num/10;
    }
    if(carry > 0) res = char(carry+'0') + res;
    return res;
}

string Mul(string a, string b){
    vector< vector<int> > res(b.length());
    int index = 0;
    for(int i = b.length()-1; i >= 0; i--){
        int t = 0;
        while(t < index){
            res[index].push_back(0);
            t++; //note
        }
        int carry = 0;
        for(int j = a.length()-1; j >= 0; j--){
            int num = (b[i]-'0')*(a[j]-'0') + carry;
            res[index].push_back(num%10);
            carry = num/10;
        }
        if(carry > 0) res[index].push_back(carry);
        while(res[index].size() < a.length() + b.length()){
            res[index].push_back(0);
        }
        reverse(res[index].begin(), res[index].end());
        index++;
    }

    int carry = 0;
    string ans;
    for(int i = res[0].size()-1; i >= 0; i--){
        int num = carry;
        for(int j = 0; j < res.size(); j++){
            num += res[j][i];
        }
        ans = char(num%10+'0') + ans;
        carry = num/10;
    }
    if(carry > 0) ans = char(carry+'0') + ans;
    while(a[0] == '0') ans.erase(ans.begin());
    return ans; 
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string dp[n+1];
        dp[0] = "1";
        dp[1] = "1";
        for(int i = 2; i <= n; i++){
            string temp = "0";
            for(int j = 0; j < i; j++){
                temp = Add(temp, Mul(dp[j], dp[i-j-1]));
            }
            dp[i] = temp;
        }
        cout << dp[n] << endl;
    }
}
