#include<bits/stdc++.h>
using namespace std;

// Cau truc du lieu hang doi 1
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		queue<int> q;
		while(n--){
			int key;
			cin >> key;
			if(key == 1){
				cout << q.size();
				cout << endl;
			} else if(key == 2){
				if(q.empty()) cout << "YES";
				else cout << "NO";
				cout << endl;
			} else if(key == 3){
				int val;
				cin >> val;
				q.push(val);
			} else if(key == 4){
				if(!q.empty()) q.pop();
			} else if(key == 5){
				if(q.empty()) cout << -1;
				else cout << q.front();
				cout << endl;
			} else {
				if(q.empty()) cout << -1;
				else cout << q.back();
				cout << endl;
			}
		}
		cout << endl;
	}
}


// Cau truc du lieu hang doi 2
int main(){
	int t;
	cin >> t;
	queue<int> q;
	cin.ignore();
	while(t--){
		string s;
		cin >> s;
		if(s == "PUSH"){
			int val;
			cin >> val;
			q.push(val);
		} else if(s == "PRINTFRONT"){
			if(q.empty()){
				cout << "NONE" << endl;
			} else {
				cout << q.front() << endl;
			}
		} else {
			if(!q.empty()) q.pop();
		}
	}
}


// Hang doi hai dau
int main(){
	int t;
	cin >> t;
	deque<int> dq;
	while(t--){
		string s;
		cin >> s;
		if(s == "PUSHBACK"){
			int val;
			cin >> val;
			dq.push_back(val);
		} else if(s == "PUSHFRONT"){
			int val;
			cin >> val;
			dq.push_front(val);
		} else if(s == "PRINTBACK"){
			if(!dq.empty()) cout << dq.back() << endl;
			else cout << "NONE" << endl;
		} else if(s == "PRINTFRONT"){
			if(!dq.empty()) cout << dq.front() << endl;
			else cout << "NONE" << endl;
		} else if(s == "POPFRONT"){
			if(!dq.empty()) dq.pop_front();
		} else {
			if(!dq.empty()) dq.pop_back();
		}
	}
}


// So nhi phan tu 1 den n
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		queue<string> q;
		q.push("1");
		while(n--){
			string a = q.front();
			cout << a << " " << endl;
			q.pop();
			q.push(a + "0");
			q.push(a + "1");
		}
	}
}

// So 0 va so 9
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		queue<string> q;
		q.push("9");
		string s;
		while(1){
			s = q.front();
			q.pop();
			int base = 0, tmp = 0;
			for(int i = 0; i < s.size(); i++){
				tmp = tmp*10 + (s[i]-'0');
			}
			if(tmp % n == 0) break;
			q.push(s+"0");
			q.push(s+"9");
		}
		cout << s << endl;
	}
}

// So BDN 1
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int index = s.size();
		for(int i = 0; i < s.size(); i++){
			if(s[i] >= '2'){
				index = i;
				break;
			}
		}
		for(int i = index; i < s.size(); i++){
			s[i] = '1';
		}
		
		int base = 1, res = 0;
		for(int i = s.size()-1; i >= 0; i--){
			res += (s[i]-'0')*base;
			base *= 2;
		}
		cout << res << endl;
	}
}

// So BDN 2;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		queue<string> q;
		q.push("1");
		string s;
		while(!q.empty()){
			s = q.front();
			q.pop();
			int tmp = 0;
			for(int i = 0; i < s.size(); i++){
				tmp = tmp*10 + (s[i]-'0');
			}
			if(tmp % n == 0) break;
			q.push(s+"0");
			q.push(s+"1");
		}
		cout << s << endl;
	}
}

// So loc phat 1
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		queue<string> q;
		q.push("6");
		q.push("8");
		vector<string> v;
		while(!q.empty()){
			string s1 = q.front();
			q.pop();
			string s2 = q.front();
			q.pop();
			if(s1.length() <= n) v.push_back(s1);
			if(s2.length() <= n) v.push_back(s2);
			if(s1.length() > n|| s2.length() > n) break;
			q.push(s1+"6");
			q.push(s1+"8");
			q.push(s2+"6");
			q.push(s2+"8");
		}
		reverse(v.begin(), v.end());
		for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
		cout << endl;
	}
}


// So loc phat 2

// So loc phat 3

// Gia tri nho nhat cua xau
int main() {
	int t;
	cin >> t;
	while (t--) {
		long long k;
		string s;
		cin >> k >> s;
		map<char, long long > mp;
		priority_queue<long long, vector<long long>> q;
		for (int i = 0; i < s.size(); i++) {
			mp[s[i]]++;
		}
		for (auto x : mp) {
			q.push(x.second);
		}
		while (!q.empty() && k > 0) {
			int top = q.top();
			q.pop();
			k--;
			q.push(--top);
		}
		long long res = 0;
		while (!q.empty()) {
			res += q.top() * q.top();
			q.pop();
		}
		cout << res << " ";
		cout << endl;
	}
}

// Bien doi S-T
#define MAX 10000
class Node{
	public:
	int val, level;
	Node(int val, int level){
		this->val = val;
		this->level = level;
	}
};
int vs[MAX];
int BFS(int x, int y){
	queue<Node> q;
	q.push(Node(x, 0));
	while(q.front().val != y){
		Node nd = q.front();
		q.pop();
		vs[nd.val] = 1;
		if(nd.val*2 < MAX && nd.val*2 > 0 && vs[nd.val*2] == 0){
			q.push(Node(nd.val*2, nd.level+1));
		} 
		if(nd.val-1 < MAX && nd.val-1 > 0 && vs[nd.val-1] == 0){
			q.push(Node(nd.val-1, nd.level+1));
		}
	}
	return q.front().level;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int s, t;
		cin >> s >> t;
		memset(vs, 0, sizeof(vs));
		cout << BFS(s, t) << endl;
	}
}

// Quan ma
class Node{
	public:
	int x, y, level;
	Node(int x, int y, int level){
		this->x = x;
		this->y = y;
		this->level = level;
	}
};

int vs[9][9];
int BFS(int startX, int startY, int endX, int endY){
	int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2};
	int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1};
	queue<Node> q;
	q.push(Node(startX, startY, 0));
	vs[startX][startY] = 1;
	while(!q.empty()){
		Node nd = q.front();
		q.pop();
		if(nd.x == endX && nd.y == endY) return nd.level;
		for(int i = 0; i < 8; i++){
			int x = nd.x + dx[i];
			int y = nd.y + dy[i];
			if(x >= 1 && x <= 8 && y >= 1 && y <= 8 && !vs[x][y]){
				q.push(Node(x, y, nd.level+1));
				vs[x][y] = 1;
			}
		}
	}
}

int main(){
	int t;
	cin >> t;
	cin.ignore();
	while(t--){
		string a, b;
		cin >> a >> b;
		memset(vs, 0, sizeof(vs));
		int startX = (int)a[0] - 96;
		int startY = (a[1]-'0');
		int endX = (int)b[0] - 96;
		int endY = (b[1]-'0');
		cout << BFS(startX, startY, endX, endY) << endl; 
	}
}

// Bien doi so tu nhien
class Node{
	public:
		int val, level;
	Node(int val, int level){
		this->val = val;
		this->level = level;
	}
};

int BFS(int n){
	queue<Node> q;
	q.push(Node(n, 0));
	set<int> s;
	s.insert(n);
	while(!q.empty()){
		Node nd = q.front();
		q.pop();
		if(nd.val == 1) return nd.level;
		if(s.find(nd.val-1) == s.end()){
			q.push(Node(nd.val-1, nd.level+1));
			s.insert(nd.val-1);
		}
		for(int i = 2; i*i <= nd.val; i++){ // note nd.val
			if(nd.val%i == 0 && s.find(nd.val/i) == s.end()){
				q.push(Node(nd.val/i, nd.level+1));
				s.insert(nd.val/i);
			}
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n; 
		cin >> n;
		cout << BFS(n) << endl;
	}
}
