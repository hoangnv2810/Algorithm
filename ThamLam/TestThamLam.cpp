#include<bits/stdc++.h>
using namespace std;

//Ðoi Tien
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[10] = { 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
		
		int i = 0, x[10] = {0}, res = 0;
		while(i < 10){
			if(n >= a[i]){
				n -= a[i];
				x[i]++;
			}
			if(n == 0) break;
			else {
				if(n < a[i]) i++;
			}
		}
		for(int i = 0; i < 10; i++){
			res += x[i];
		}
		cout << res << endl;
		
	}
}

//Chia mang thanh hai manng  con co tonglon nhat
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a+n);
		long long sum1 = 0, sum2 = 0, res = INT_MAX;
		for(int i = 0; i < n; i++){
			if(i < k) sum1 += a[i];
			else sum2 += a[i];
		}
		res = abs(sum2-sum1);
		sum1 = 0, sum2 = 0; // NOTE
		for(int i = 0; i < n; i++){
			if(i < n-k) sum1 += a[i];
			else sum2 += a[i];
		}
		res = max(res, abs(sum2-sum1));
		cout << res << endl;
	}
}

// Sap Xep Tham Lam
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n], b[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
			b[i] = a[i];
		}
		int check = 0;
		sort(b, b+n);
		for(int i = 0; i < n; i++){
			if(a[i] != b[i] && a[i] != b[n-i-1]){
				check = 1;
				break;
			}
		}
		if(check) cout << "No";
		else cout << "Yes";
		cout << endl;
	}
}

// Noi Day 1
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		long long value;
		priority_queue<long long, vector<long long>, greater<long long> > q;
		for(int i = 0; i < n; i++){
			cin >> value;
			q.push(value);
		}
		long res = 0;
		while(q.size() > 1){
			long long a = q.top();
			q.pop();
			long long b = q.top();
			q.pop();
			q.push(a+b);
			res += (a+b);
		}
		cout << res << endl;
	}
}

// Sap Dat Xau Ky Tu 1
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		map<char, int> mp;
		int max1 = INT_MIN;
		for(int i = 0; i < s.length(); i++){
			mp[s[i]]++;
			max1 = max(mp[s[i]], max1);
		}
		if(s.length()%2 == 0 && max1 <= s.length()-max1) cout << 1;
		else if(s.length()%2 != 0 && max1 <= s.length()/2 + 1) cout << 1;
		else cout << -1;
		cout << endl;
	}
}

// Sap Dat Xau Ky Tu 2
int main(){
	int t;
	cin >> t;
	while(t--){
		int d;
		cin >> d;
		string s;
		cin >> s;
		map<char, int> mp;
		int max = 0;
		for(int i = 0; i < s.length(); i++){
			mp[s[i]]++;
			if(mp[s[i]] > max) max = mp[s[i]];
		}
		if(s.length()-max >= (d-1)*(max-1)) cout << 1;
		else cout << -1;
		cout << endl;
		
	}
}

// Mua Luong Thuc
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, s, m;
		cin >> n >> s >> m;
		int res = 0;
		if(s*m > n*(s-s/7)) res = -1;
		else {
			for(int i = 1; i <= (s-s/7); i++){
				if(i*n >= s*m){
					res = i;
					break;
				}
			}
		}
		cout << res << endl;
	}
}

// Day Con Chung
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m, k;
		cin >> n >> m >> k;
		int a[n], b[m], c[k];
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < m; i++) cin >> b[i];
		for(int i = 0; i < k; i++) cin >> c[i];
		
		int i = 0, j = 0, l = 0, res = 0, check = 0;
		while(i < n && j < m && l < k){
			if(a[i] == b[j] && b[j] == c[l]){
				cout << a[i] << " ";
				check = 1;
				i++, j++, l++;
			}
			else if(a[i] < b[j]) i++;
			else if(b[j] < c[l]) j++;
			else l++;
		}
		if(!check) cout << "NO";
		cout << endl;
	}
}

// Tinch Lon Nhat
int main(){
	int t = 1;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a+n);
		int e = a[n-1]*a[n-2]*a[n-3];
		int b = a[n-1]*a[n-2];
		int c = a[0]*a[1];
		int d = a[0]*a[1]*a[n-1];
		int res = max(max(e,b), max(c, d));
		cout <<res << endl;
	}
}

// Gia Tri Nho Nhat Cua Bieu Thuc
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n], b[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int j = 0; j < n; j++) cin >> b[j];
		
		sort(a, a+n);
		sort(b, b+n, greater<int>());
		long long res = 0;
		for(int i = 0; i < n; i++){
			res += a[i]*b[i];
		}
		cout << res << endl;
	}
}

// Sap Xep Cong Viec 1
struct work{
	int first, second;
};

int cmp(work a, work b){
	return a.second < b.second;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		work a[n];
		for(int i = 0; i < n; i++) cin >> a[i].first;
		for(int j = 0; j < n; j++) cin >> a[j].second;
		
		sort(a, a+n, cmp);
		int i = 0, res = 1;
		for(int j = 1; j < n; j++){
			if(a[j].first > a[i].second){
				res++;
				i = j;
			}
		}
		cout << res << endl;
	}
}

//Sap Xep Cong Viec 2
struct Job{
	int jobId, deadline, profit;
};

int cmp(Job a, Job b){
	return a.profit > b.profit;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		Job a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i].jobId >> a[i].deadline >> a[i].profit; 
		}
		
		int res = 0, count = 0, check[n];
		memset(check, 0, sizeof(check));
		sort(a, a+n, cmp);
		for(int i = 0; i < n; i++){
			for(int j = min(n-1, a[i].deadline-1); j >= 0; j--){
				if(!check[j]){
					check[j] = 1;
					res += a[i].profit;
					count++;
					break;
				}
			}
		}
		cout << count << " " << res << endl;
	}
}

// Noi Day 2
int mod = 1e9+7;
int main(){
	int n;
	cin >> n;
	int value;
	
	priority_queue<long long, vector<long long>, greater<long long> > q;
	for(int i = 0; i < n; i++) {
		cin >> value;
		q.push(value);
	}
	long long res = 0;
	while(q.size() > 1){
		long long first = q.top();
		q.pop();
		long long second = q.top();
		q.pop();
		q.push((first+second)%mod);
		res += (first+second)%mod;
	}
	cout << res << endl;
}

// So Nho Nhat
int main(){
	int t;
	cin >> t;
	while(t--){
		int s, d;
		cin >> s >> d;
		int res[d];
		if(s == 0 && d == 1){
			cout << 0 << endl;
			continue;
		}
		
		if(s > 9*d){
			cout << -1 << endl;
			continue;
		}
		
		s -= 1;
		for(int i = d-1; i > 0; i--){
			if(s > 9){
				res[i] = 9;
				s -= 9;
			} else {
				res[i] = s;
				s = 0;
			}
		}
		res[0] = s+1;
		for(int i = 0; i < d; i++) cout << res[i];
		cout << endl;
	}
}

// Gia Tri Nho Nhat Cua Xau
int main(){
	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> k;
		string s;
		cin >> s;
		map<char, int> mp;
		for(int i = 0; i < s.size(); i++){
			mp[s[i]]++;
		}
		priority_queue<int> q;
		for(auto x: mp){
			q.push(x.second);
		}
		while(k > 0 && !q.empty()){
			int temp = q.top();
			q.pop();
			temp--;
			q.push(temp);
			k--;
		}
		long long res = 0;
		while(!q.empty()){
			int a = q.top();
			q.pop();
			res += a*a;
		}
		cout << res << endl;
	}
}

// So May Man
int main(){
	int t;
	cin >> t;
	while(t--){
		int sum;
		cin >> sum;
		int check = 0;
		for(int i = 0; i*4 <= sum; i++){
			int temp = sum-i*4;
			if(temp % 7 == 0){
				check = 1;
				for(int j = 0; j < i; j++) cout << 4;
				for(int j = 0; j < temp/7; j++) cout << 7;
				break;
			}
		}
		if(!check) cout << -1;
		cout << endl;
	}
}

// Phan So Don Vi
int main(){
	int t;
	cin >> t;
	while(t--){
		int tu, mau, res;
		cin >> tu >> mau;
		while(1){
			if(mau % tu == 0){
				cout << 1 << "/" << mau/tu << endl;
				break;
			} else {
				res = mau/tu + 1;
				cout << 1 << "/" << res  << " + ";
				tu = res*tu - mau;
				mau = res*mau;
			}
		}
	}
}

// Bieu Thuc Dung
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		stack<char> st;
		int res = 0;
		for(int i = 0; i < s.size(); i++){
			if(st.empty()){
				st.push(s[i]);
			}
			if(st.top() == '[' && s[i] == ']'){
				st.pop();
			}
			else if(st.top() == ']' && s[i] == '['){
				res += st.size();
				st.pop();
			} else st.push(s[i]);
		}
		cout << res << endl;
		
	}
}
