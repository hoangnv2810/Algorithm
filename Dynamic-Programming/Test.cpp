#include<bits/stdc++.h>
using namespace std;

// Xau Con Chung Dai Nhat
 int dp[1001][1001];
 int main(){
 	int t;
 	cin >> t;
 	while(t--){
 		string a, b;
 		cin >> a >> b;
 		for(int i = 0; i <= a.length(); i++){
 			for(int j = 0; j <= b.length(); j++){
 				if(j == 0 || i == 0) dp[i][j] = 0;
 				else if(a[i-1] == b[j-1]){
 					dp[i][j] = dp[i-1][j-1] + 1;
 				} else {
 					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
 				}
 			}
 		}
 		cout << dp[a.length()][b.length()] << endl;
 	}
 }

// Day Con Tang Dai Nhat
 int main(){
 	int t;
 	cin >> t;
 	while(t--){
 		int n, *a;
 		cin >> n;
 		a = new int[n];
 		for(int i = 0; i < n; i++){
 			cin >> a[i];
 		}
 		int dp[n+1];
 		memset(dp, 0, sizeof(dp));
 		dp[0] = 1;
 		int res = 0;
 		for(int i = 1; i < n; i++){
 			for(int j = 0; j < i; j++){
 				if(a[i] > a[j])
 					dp[i] = max(dp[i], dp[j]+1);
 			}
 			res = max(res, dp[i]);
 		}
 		cout << res << endl;
 	}
 }


//Day Con Co Tong Bang S
 int main(){
 	int t;
 	cin >> t;
 	while(t--){
 		int n, sum, *a;
 		cin >> n >> sum;
 		a = new int[n];
 		for(int i = 0; i < n; i++) cin >> a[i];
 		int dp[sum+1];
 		memset(dp, 0, sizeof(dp));
 		dp[0] = 1;
 		for(int i = 0; i < n; i++){
 			for(int j = sum; j >= a[i]; j--){
 				if(dp[j] == 0 && dp[j - a[i]] == 1){
 					dp[j] = 1;
 				}
 			}
 		}
 		if(dp[sum]){
 			cout << "YES" << endl;
 		} else cout << "NO" << endl;
 	}
 }

// To Hop C(k, n)
 int mod = 1e9+7;
 int main(){
     int t;
     cin >> t;
     while(t--){
         int n, k;
         cin >> n >> k;
         int dp[k+1];
         memset(dp, 0, sizeof(dp));
         dp[0] = 1;
         for(int i = 1; i <= n; i++){
             for(int j = min(i, k); j > 0; j--){
                 dp[j] = (dp[j]+dp[j-1])%mod;
             }
         }
         cout << dp[k]%mod << endl;
     }
 }

// Bac Thang
 int main(){
     int t;
     cin >> t;
     while(t--){
         int n, k;
         cin >> n >> k;
         int dp[n+1];
         memset(dp, 0, sizeof(dp));
         dp[0] = 1;
         for(int i = 1; i <= n; i++){
             int sum = 0;
             for(int j = 1; j <= k; j++){
                 if(i - j >= 0) sum += dp[i-j];
             } 
             dp[i] = sum;
         }
         cout << dp[n] << endl;
     }
 }

// Day Con Lap Lai Dai Nhat
 int main(){
     int t;
     cin >> t;
     while(t--){
         int n;
         cin >> n;
         string s;
         cin >> s;
         int dp[n+1][n+1];
         memset(dp, 0, sizeof(dp));
         for(int i = 1; i <= n; i++){
             for(int j = 1; j <= n; j++){
                 if(s[i-1] == s[j-1] && i != j) dp[i][j] = d[i-1][j-1]+1;
                 else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
             }
         }
         cout << dp[n][n] << endl;
     }
 }


// So Buoc It Nhat
 int main(){
     int t;
     cin >> t;
     while(t--){
         int n, *a;
         cin >> n;
         a = new int[n];
         for(int i = 0; i < n; i++){
             cin >> a[i];
         }
         int dp[n+1], res = 0;
         memset(dp, 0, sizeof(dp));
         dp[0] = 1;
         for(int i = 1; i < n; i++){
             for(int j = 0; j < i; j++){
                 if(a[i] > a[j]) dp[i] = max(dp[i], dp[j]+1);
             }
             res = max(dp[i], res);
         }
         cout << n-res << endl;
     }
 }

// Con Ech
 int main(){
     int t;
     cin >> t;
     while(t--){
         int n;
         cin >> n;
         long long dp[n+1];
         memset(dp, 0, sizeof(dp));
         dp[0] = 1;
         for(int i = 1; i <= n; i++){
             for(int j = 1; j <= 3; j++){
                 if(i-j >= 0) dp[i] += dp[i-j];
             }
         }
         cout << dp[n] << endl;
     }
 }

// Xem Phim
 int main(){
     int t = 1;
     while(t--){
         int c, n;
         cin >> c >> n;
         int w[n+1];
         for(int i = 1; i <= n; i++){
             cin >> w[i];
         }
         int dp[n+1][c+1];
         memset(dp, 0, sizeof(dp));
         for(int i = 1; i <= n; i++){
             for(int j = 1; j <= c; j++){
                 if(j < w[i]) dp[i][j] = dp[i-1][j];
                 else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + w[i]);
             }
         }
         cout << dp[n][c] << endl;
     }
 }

// Cai Tui
 struct data{
     int a, c;
 };

 int main(){
     int t;
     cin >> t;
     while(t--){
         int n, v;
         cin >> n >> v;
         data bag[n+1];
         for(int i = 1; i <= n; i++) cin >> bag[i].a;
         for(int i = 1; i <= n; i++) cin >> bag[i].c;
         int dp[n+1][v+1];
         memset(dp, 0, sizeof(dp));
         for(int i = 1; i <= n; i++){
             for(int j = 1; j <= v; j++){
                 if(j < bag[i].a) dp[i][j] = dp[i-1][j];
                 else dp[i][j] = max(dp[i-1][j], dp[i-1][j-bag[i].a] + bag[i].c);
             }
         }
         cout << dp[n][v] << endl;
               
     }
 }

// Giai Ma
 int main(){
     int t;
     cin >> t;
     while(t--){
         string s;
         cin >> s;
         int dp[s.length()+1];
         if(s[0] == '0') {
             cout << 0 << endl;
             continue;
         }

         dp[0] = dp[1] = 1;
         for(int i = 2; i <= s.length(); i++){
             if(s[i-1] > '0') dp[i] = dp[i-1];
             if(s[i-2] == '1' || s[i-2] == '2' && s[i-1] <= '6'){
                 dp[i] += dp[i-2];
             } 
         }
         cout << dp[s.length()] << endl;
     }
 }

//Xau Con Doi Xung Dai Nhat
 int main(){
     int t;
     cin >> t;
     while(t--){
         string s;
         cin >> s;
         int res = 1, u, v;
         for(int i = 0; i < s.length(); i++){
             u = i, v = i+1;
             while(u >= 0 && v < s.length()){
                 if(s[u] != s[v]) break;
                 else {
                     res = max(res, v-u+1);
                     u--;
                     v++;
                 }
             }
         }
         for(int i = 0; i < s.length(); i++){
             u = i, v = i;
             while(u >= 0 && v < s.length()){
                 if(s[u] != s[v]) break;
                 else {
                     res = max(res, v-u+1);
                     u--;
                     v++;
                 }
             }
         }
         cout << res << endl;
     }
 }

// Hinh Vuong Lon Nhat
 int main(){
     int t;
     cin >> t;
     while(t--){
         int m, n;
         cin >> m >> n;
         int dp[m][n], a[m][n];
         for(int i = 0; i < m; i++){
             for(int j = 0; j < n; j++){
                 cin >> a[i][j];
                 dp[i][j] = a[i][j];
             }
         }
         int res = 0;
         for(int i = 1; i < m; i++){
             for(int j = 1; j < n; j++){
                 if(a[i][j] == 0) continue;
                 else if(a[i][j] == a[i-1][j-1] && a[i][j] == a[i-1][j] && a[i][j] == a[i][j-1]){
                     dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                     res = max(res, dp[i][j]);
                 }
             }
         }
         cout << res << endl;
     }
 }

// Duong Di Nho Nhat
 int main(){
     int t;
     cin >> t;
     while(t--){
         int m, n;
         cin >> m >> n;
         int dp[m][n], a[m][n];
         for(int i = 0; i < m; i++){
             for(int j = 0; j < n; j++){
                 cin >> a[i][j];
             }
         }
         memset(dp, 0, sizeof(dp));
         for(int i = 0; i < m; i++){
             for(int j = 0; j < n; j++){
                 if(i == 0 && j == 0) dp[i][j] = a[i][j];
                 else if(i == 0) dp[i][j] = a[i][j] + dp[i][j-1];
                 else if(j == 0) dp[i][j] = a[i][j] + dp[i-1][j];
                 else {
                     dp[i][j] = a[i][j] + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                 }
             }
         }
         cout << dp[m-1][n-1] << endl;
     }
 }

//Catalan Number
 string Add(string a, string b) {
     while (a.length() < b.length()) a = "0" + a;
     while (a.length() > b.length()) b = "0" + b;
     int carry = 0;
     string res;
     for (int i = a.length() - 1; i >= 0; i--) {
         int num = (a[i] - '0') + (b[i] - '0') + carry;
         res = char(num % 10 + '0') + res;
         carry = num / 10;
     }
     if (carry > 0) res = char(carry + '0') + res;
     return res;
 }

 string Mul(string a, string b) {
     vector< vector<int> > res(b.length());
     int index = 0;
     for (int i = b.length() - 1; i >= 0; i--) {
         int t = 0;
         while (t < index) {
             res[index].push_back(0);
             t++; //note
         }
         int carry = 0;
         for (int j = a.length() - 1; j >= 0; j--) {
             int num = (b[i] - '0') * (a[j] - '0') + carry;
             res[index].push_back(num % 10);
             carry = num / 10;
         }
         if (carry > 0) res[index].push_back(carry);
         while (res[index].size() < a.length() + b.length()) {
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
         ans = char(num % 10 + '0') + ans;
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
         string dp[1001];
         dp[0] = "1";
         dp[1] = "1";
         for (int i = 2; i <= n; i++) {
             string temp = "0";
             for (int j = 0; j < i; j++) {
                 temp = Add(temp, Mul(dp[j], dp[i - j - 1]));
             }
             dp[i] = temp;
         }
         cout << dp[n] << endl;
     }
 }

//Tinh P(k, n)
 int mod = 1e9+7;
 int main(){
     int t;
     cin >> t;
     while(t--){
         int n, k;
         cin >> n >> k;
         long long res = 1;
         if(k > n) res = 0;
         for(int i = n-k+1; i <= n; i++){
             res = (res*i)%mod;
         }
         cout << res << endl;
     }
 }

// So Ugly
 int main(){
     int t;
     cin >> t;
     while(t--){
         int n;
         cin >> n;
         int dp[n+1];
         dp[0] = 1;
         int i2 = 0, i3 = 0, i5 = 0;
         for(int i = 1; i <= n; i++){
             dp[i] = min(dp[i2]*2, min(dp[i3]*3, dp[i5]*5));
             if(dp[i] == dp[i2]*2) i2++;
             if(dp[i] == dp[i3]*3) i3++;
             if(dp[i] == dp[i5]*5) i5++;
         }
         cout << dp[n-1] << endl;
     }
 }

// Day Con Chung Dai Nhat Cua Ba Xau
 int main(){
     int t;
     cin >> t;
     while(t--){
         int x, y, z;
         cin >> x >> y >> z;
         string a, b, c;
         cin >> a >> b >> c;
         int dp[x+1][y+1][z+1];
         memset(dp, 0, sizeof(dp));
         for(int i = 1; i <= a.length(); i++){
             for(int j = 1; j <= b.length(); j++){
                 for(int k = 1; k <= c.length(); k++){
                     if(a[i-1] == b[j-1] && a[i-1] == c[k-1]){
                         dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                     } else {
                         dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
                     }
                 }
             }
         }
         cout << dp[x][y][z] << endl;
     }
 }

// Tong Lon Nhat Cua Day Con Tang Dan
 int main(){
     int t;
     cin >> t;
     while(t--){
         int n;
         cin >> n;
         int a[n+1], dp[n+1];
         for(int i = 0; i < n; i++){
             cin >> a[i];
             dp[i] = a[i];
         }
         int res = 0;
         for(int i = 0; i < n; i++){
             for(int j = 0; j < i; j++){
                 if(a[i] > a[j]) dp[i] = max(dp[i], dp[j] + a[i]);
             }
             res = max(res, dp[i]);
         }

         cout << res << endl;
     }
 }

// Day So Bitonic 
 int main(){
     int t;
     cin >> t;
     while(t--){
         int n;
         cin >> n;
         int a[n+1], dp1[n], dp2[n];
         for(int i = 0; i < n; i++){
             cin >> a[i];
             dp1[i] = dp2[i] = a[i];
         }
         for(int i = 0; i < n; i++){
             for(int j = 0; j < i; j++){
                 if(a[i] > a[j]) dp1[i] = max(dp1[i], dp1[j] + a[i]);
             }
         }

         for(int i = n-1; i >= 0; i--){
             for(int j = n-1; j > i; j--){
                 if(a[i] > a[j]) dp2[i] = max(dp2[i], dp2[j] + a[i]);
             }
         }
         int res = 0;
         for(int i = 0; i < n; i++){
             res = max(res, dp1[i]+dp2[i]-a[i]);
         }
         cout << res << endl;
        
     }
 }

// Ky Tu Giong Nhau
 int main(){
     int t;
     cin >> t;
     while(t--){
         int n, insert, remove, copy;
         cin >> n >> insert >> remove >> copy;
         int dp[n+1];
         dp[0] = 0;
         dp[1] = insert;
         for(int i = 2; i <= n; i++){
             if(i%2 == 0){
                 dp[i] = min(dp[i/2] + copy, dp[i-1] + insert);
             } else {
                 dp[i] = min(dp[(i+1)/2] + copy + remove, dp[i-1] + insert);
             }
         }
         cout << dp[n] << endl;
     }
 }

// Tong Cac Xau Con
 int main(){
     int t;
     cin >> t;
     while(t--){
         string s;
         cin >> s;
         vector<int> a;
         for(int i = 0; i < s.length(); i++){
             a.push_back(s[i]-'0');
         }
         long long res = 0;
         for(int i = 0; i < a.size(); i++){
             long long temp = 0;
             for(int j = i; j < a.size(); j++){
                 temp = temp*10 + a[j];
                 res += temp;
             }
         }
         cout << res << endl;
     }
 }

//Tong Bang K
 int mod = 1e9+7;
 int main(){
     int t;
     cin >> t;
     while(t--){
         int n, k;
         cin >> n >> k;
         int a[n+1];
         for(int i = 0; i < n; i++){
             cin >> a[i];
         }

         int dp[k+1];
         memset(dp, 0, sizeof(dp));
         dp[0] = 1;
         for(int i = 1; i <= k; i++){
             for(int j = 0; j < n; j++){
                 if(i >= a[j]) dp[i] = (dp[i] + dp[i-a[j]])%mod;
             }
         }
         cout << dp[k] << endl; 
     }
 }

//Tong Lon Nhat Cua Day Con Khong Ke Nhau
 int main(){
     int t;
     cin >> t;
     while(t--){
         int n;
         cin >> n;
         int *a = new int[n];
         for(int i = 0; i < n; i++){
             cin >> a[i];
         }

         int dp[n+1], res = 0;
         memset(dp, 0, sizeof(dp));
         dp[0] = a[0];
         dp[1] = max(a[0], a[1]);
         for(int i = 2; i < n; i++){
             dp[i] = max(a[i] + dp[i-2], dp[i-1]);
             res = max(res, dp[i]);
         }
         cout << res << endl;
     }
 }

//Bien Doi Xau
 int main(){
     int t;
     cin >> t;
     while(t--){
         string a, b;
         cin >> a >> b;
         int m = a.length(), n = b.length();
         int dp[m+1][n+1];
         for(int i = 0; i <= m; i++){
             for(int j = 0; j <= n; j++){
                 if(i == 0) dp[i][j] = j;
                 else if(j == 0) dp[i][j] = i;
                 else if(a[i-1] == a[j-1]) dp[i][j] = dp[i-1][j-1];
                 else {
                     dp[i][j] = 1+min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                 }
             }
         }
         cout << dp[m][n] << endl;
     }
 }

//Tong Binh Phuong 
 int main(){
     int t;
     cin >> t;
     while(t--){
         int n;
         cin >> n;
         long long dp[n+1];
         for(int i = 0; i <= n; i++){
             dp[i] = i;
             for(int j = 1; j <= sqrt(i); j++){
                 dp[i] = min(dp[i], dp[i-j*j]+1);
             }
         }
         cout << dp[n] << endl;
     }
 }
