#include<bits/stdc++.h>
using namespace std;

// Chuyen danh sach canh sang danh sach ke
int main(){
	int t;
	cin >> t;
	while(t--){
		int v, e;
		cin >> v >> e;
		vector<int> ke[v+1];
		for(int i = 0; i < e; i++){
			int start, end;
			cin >> start >> end;
			ke[start].push_back(end);
			ke[end].push_back(start);
		}
		for(int i = 1; i <= v; i++){
			cout << i << ": ";
			for(int j = 0; j < ke[i].size(); j++){
				cout << ke[i][j] << " ";
			}
			cout << endl;
		}
	}
}

// Chuyen danh sach ke sang danh sach canh
int main(){
	int n;
	cin >> n;
	vector<int> ke[n+5];
	cin.ignore();
	for(int i = 1; i <= n; i++){
		string s;
		getline(cin, s);
		s += " "; // cong them phan tu cuoi cung
		int j = 0, num = 0;
		while(j < s.size()){
			if(s[j] >= '0' && s[j] <= '9'){
				num = num*10 + (s[j]-'0');
			} else if(num > 0){
				ke[i].push_back(num);
				num = 0;
			}
			j++;
		}
	}
	int flag[n+1][n+1];
	memset(flag, 0, sizeof(flag));
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < ke[i].size(); j++){
			if(!flag[i][ke[i][j]] && !flag[ke[i][j]][i]){
				cout << i << " " << ke[i][j] << endl;;
				flag[i][ke[i][j]] = flag[ke[i][j]][i] = 1;
			}
		}
	}
}

// Bieu dien do thi co huong
int main(){
	int t;
	cin >> t;
	while(t--){
		int v, e;
		cin >> v >> e;
		vector<int> ke[v+1];
		for(int i = 0; i < e; i++){
			int start, end;
			cin >> start >> end;
			ke[start].push_back(end);
		}
		for(int i = 1; i <= v; i++){
			cout << i << ": ";
			for(int j = 0; j < ke[i].size(); j++){
				cout << ke[i][j] << " ";
			}
			cout << endl;
		}
	}
}

// Dfs tren do thi vo huong
// wa
//void Dfs(int u){
//	stack<int> st;
//	st.push(u);
//	while(!st.empty()){
//		u = st.top();
//		st.pop();
//		vs[u] = 1;
//		cout << u << " ";
//		for(int i = 0; i < ke[u].size(); i++){
//			if(!vs[ke[u][i]]){
//				st.push(ke[u][i]);
//				break;
//			}
//		}
//	}
//}

int vs[1001];
vector<int> ke[1001];
void Dfs(int u){
	vs[u] = 1;
	cout << u << " ";
	for(int i = 0; i < ke[u].size(); i++){
		if(!vs[ke[u][i]]){
			Dfs(ke[u][i]);
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int v, e, u;
		cin >> v >> e >> u;
		memset(vs, 0, sizeof(vs));
		for(int i = 1; i <= v; i++){
			ke[i].clear();
		}
		for(int i = 0; i < e; i++){
			int start, end;
			cin >> start >> end;
			ke[start].push_back(end);
			ke[end].push_back(start);
		}
		Dfs(u);
		cout << endl;
	}
}

// bfs tren do thi vo huong
int vs[1001];
vector<int> ke[1001];
void Bfs(int u){
	queue<int> q;
	q.push(u);
	vs[u]= 1;
	while(!q.empty()){
		u = q.front();
		q.pop();
		cout << u << " ";
		for(int i = 0; i < ke[u].size(); i++){
			if(!vs[ke[u][i]]){
				vs[ke[u][i]] = 1;
				q.push(ke[u][i]);
			}
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int v, e, u;
		cin >> v >> e >> u;
		memset(vs, 0, sizeof(vs));
		for(int i = 1; i <= v; i++){
			ke[i].clear();
		}
		for(int i = 0; i < e; i++){
			int start, end;
			cin >> start >> end;
			ke[start].push_back(end);
			ke[end].push_back(start);
		}
		Bfs(u);
		cout << endl;
	}
}

// Liet ke canh cau
class edge{
	public:
		int dau, cuoi;
		edge(){
			
		}
		edge(int dau, int cuoi){
			this->dau = dau;
			this->cuoi = cuoi;
		}
};


int vs[1001];
vector<int> ke[1001];
void Bfs(int u){
	queue<int> q;
	q.push(u);
	vs[u]= 1;
	while(!q.empty()){
		u = q.front();
		q.pop();
		for(int i = 0; i < ke[u].size(); i++){
			if(!vs[ke[u][i]]){
				vs[ke[u][i]] = 1;
				q.push(ke[u][i]);
			}
		}
	}
}

int tplt(int v){
	int k = 0;
	for(int i = 1; i <= v; i++){
		if(!vs[i]){
			k++;
			Bfs(i);
		}
	}
	return k;
}
vector<edge> res;
void canhCau(int canh, int k, int v, int e, vector<edge> temp){
	memset(vs, 0, sizeof(vs));
	for(int i = 1; i <= v; i++){
		ke[i].clear();
	}
	for(int i = 0; i < e; i++){
		if(i != canh){
			ke[temp[i].dau].push_back(temp[i].cuoi);
			ke[temp[i].cuoi].push_back(temp[i].dau);
		}
	}
	
	int count = tplt(v);
	if(count > k){
		edge eg;
		if(temp[canh].dau > temp[canh].cuoi){
			eg.dau = temp[canh].cuoi;
			eg.cuoi = temp[canh].dau;
			res.push_back(eg);
		} else {
			eg.dau = temp[canh].dau;
			eg.cuoi = temp[canh].cuoi;
			res.push_back(eg);
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int v, e;
		cin >> v >> e;
		memset(vs, 0, sizeof(vs));
		for(int i = 1; i <= v; i++){
			ke[i].clear();
		}
		vector<edge> temp;
		for(int i = 0; i < e; i++){
			int start, end;
			cin >> start >> end;
			temp.push_back(edge(start, end));
			ke[start].push_back(end);
			ke[end].push_back(start);
		}
		int k = tplt(v);
		for(int i = 0; i < e; i++){
			canhCau(i, k, v, e, temp);
		}
		for(int i = 0; i < res.size(); i++){
			cout << res[i].dau << " " << res[i].cuoi << " ";
		}
		res.clear();
		cout << endl;
	}
}

// Duong di va chu trinh euler voi do thi vo huong
int check(int v, vector<int> ke[1001]){
	int deg = 0;
	for(int i = 1; i <= v; i++){
		if(ke[i].size()%2 == 1){
			deg++;
		}
	}
	if(deg == 0) return 2;
	else if(deg == 2) return 1;
	else return 0;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int v, e;
		cin >> v >> e;
		vector<int> ke[v+1];
		for(int i = 0; i < e; i++){
			int start, end;
			cin >> start >> end;
			ke[start].push_back(end);
			ke[end].push_back(start);
		}
		
		cout << check(v, ke) << endl; 
	}
}

// Duong di va chu trinh euler voi do thi co huong

int check(int v, int deg[1001][2]){
	for(int i = 1; i <= v; i++){
		if(deg[i][0] != deg[i][1]) return 0;
	}
	return 1;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int v, e;
		cin >> v >> e;
		int deg[v+1][2];
		memset(deg, 0, sizeof(deg));
		for(int i = 0; i < e; i++){
			int start, end;
			cin >> start >> end;
			deg[start][0]++;
			deg[end][1]++;
		}
		
		cout << check(v, deg) << endl; 
	}
}

// Chuyen ma tran ke sang danh sach ke
int main(){
	int n;
	cin >> n;
	int a[n+1][n+1];
	vector<int> ke[n+1];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			if(a[i][j]) ke[i].push_back(j+1);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < ke[i].size(); j++){
			cout << ke[i][j] << " ";
		}
		cout << endl;
	}
}

// Chuyen danh sach ke sang ma tran ke

int main(){
	int n;
	cin >> n;
	cin.ignore();
	string s;
	int a[n+1][n+1];
	memset(a, 0, sizeof(a));
	for(int i = 0; i < n; i++){
		getline(cin, s);
		s += " ";
		int j = 0, num = 0;
		while(j < s.size()){
			if(s[j] >= '0' && s[j] <= '9'){
				num = num*10 + (s[j]-'0');
			} else if(num > 0){
				a[i][num-1] = 1;
				a[num-1][i] = 1;
				num = 0; 
			}
			j++;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	
}

// Dfs tren do thi co huong
bool vs[1001];
vector<int> ke[1001];
void DFS(int u, int v){
	stack<int> s;
	s.push(u);
	cout << u << " ";
	vs[u] = true;
	while(!s.empty()){
		u = s.top();
		s.pop();
		for(int i = 0; i < ke[u].size(); i++){
			if(!vs[ke[u][i]]){
				cout << ke[u][i] << " ";
				vs[ke[u][i]] = true;
				s.push(u);
				s.push(ke[u][i]);
				break;
			}
		}
	}
}

void Dfs(int u){
	vs[u] = 1;
	cout << u << " ";
	for(int i = 0; i < ke[u].size(); i++){
		if(!vs[ke[u][i]]){
			Dfs(ke[u][i]);
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int v, e, u;
		cin >> v >> e >> u;
		memset(vs, false, sizeof(vs));
		for(int i = 1; i <= v; i++) ke[i].clear();
		int start, end;
		for(int i = 0; i < e; i++){
			cin >> start >> end;
			ke[start].push_back(end);
		}
		Dfs(u);
		cout << endl;
	}
}

// bfs tren do thi co huong
bool vs[1001];
vector<int> ke[1001];
bool vs[1001];
void BFS(int u, int v){
	queue<int> q;
	q.push(u);
	vs[u] = true;
	while(!q.empty()){
		u = q.front();
		q.pop();
		cout << u << " ";
		for(int i = 0; i < ke[u].size(); i++){
			if(!vs[ke[u][i]]){
				q.push(ke[u][i]);
				vs[ke[u][i]] = true;
			}
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int v, e, u;
		cin >> v >> e >> u;
		memset(vs, false, sizeof(vs));
		for(int i = 1; i <= v; i++) ke[i].clear();
		for(int i = 0; i < e; i++){
			int start, end;
			cin >> start >> end;
			ke[start].push_back(end);
		}
		
		BFS(u, v);
		cout << endl;
	}
}

// Duong di theo dfs voi do thi co huong
vector<int> ke[1001];
int truoc[1001], vs[1001];
void Dfs(int u){
	vs[u] = 1;
	for(int i = 0; i < ke[u].size(); i++){
		if(!vs[ke[u][i]]){
			truoc[ke[u][i]] = u;
			Dfs(ke[u][i]);
		}
	}
}
void result(int s, int t){
	vector<int> res;
	if(truoc[t] == 0){
		cout << -1;
	} else {
		res.push_back(t);
		while(t != s){
			t = truoc[t];
			res.push_back(t);
		}
		for(int i = res.size()-1; i >= 0; i--){
			cout << res[i] << " ";
		}
	}
	
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int v, e, u, t;
		cin >> v >> e >> u >> t;
		for(int i = 1; i <= v; i++) ke[i].clear();
		memset(vs, 0, sizeof(vs));
		for(int i = 0; i < e; i++){
			int start, end;
			cin >> start >> end;
			ke[start].push_back(end);
		}
		Dfs(u);
		result(u, t);
		cout << endl;
	}
}

// Duong di theo bfs voi do thi co huong
vector<int> ke[1001];
int truoc[1001], vs[1001];
void Bfs(int u){
	queue<int> q;
	q.push(u);
	vs[u] = 1;
	while(!q.empty()){
		u = q.front();
		q.pop();
		for(int i = 0; i < ke[u].size(); i++){
			if(!vs[ke[u][i]]){
				vs[ke[u][i]] = 1;
				truoc[ke[u][i]] = u;
				q.push(ke[u][i]);
			}
		}
	}
}

void result(int s, int t){
	vector<int> res;
	if(truoc[t] == 0){
		cout << -1;
	} else {
		res.push_back(t);
		while(t != s){
			t = truoc[t];
			res.push_back(t);
		}
		for(int i = res.size()-1; i >= 0; i--){
			cout << res[i] << " ";
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int v, e, u, t;
		cin >> v >> e >> u >> t;
		for(int i = 1; i <= v; i++) ke[i].clear();
		memset(vs, 0, sizeof(vs));
		for(int i = 0; i < e; i++){
			int start, end;
			cin >> start >> end;
			ke[start].push_back(end);
		}
		Bfs(u);
		result(u, t);
		cout << endl;
	}
}

// Kiem tra duong di
bool vs[1001];
bool BFS(int s, int t){
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		s = q.front();
		q.pop();
		vs[s] = true;
		if(s == t) return true;
		for(int i = 0; i < ke[s].size(); i++){
			if(!vs[ke[s][i]]){
				vs[ke[s][i]] = true;
				q.push(ke[s][i]);
			}
		}
	}
	return false;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int v, e;
		cin >> v >> e;
		for(int i = 0; i < v+1; i++){
			ke[i].clear();
		}
		
		for(int i = 0; i < e; i++){
			int start, end;
			cin >> start >> end;
			ke[start].push_back(end);
			ke[end].push_back(start);
		}
		int test, s, t;
		cin >> test;
		for(int i = 0; i < test; i++){
			memset(vs, false, sizeof(vs));
			cin >> s >> t;
			if(BFS(s, t)) cout << "YES";
			else cout << "NO";
			cout << endl;
		}
	}
}


// Duong di the dfs voi do thi vo huong
vector<int> ke[1001];
int truoc[1001], vs[1001];
void Dfs(int u){
	vs[u] = 1;
	for(int i = 0; i < ke[u].size(); i++){
		if(!vs[ke[u][i]]){
			truoc[ke[u][i]] = u;
			Dfs(ke[u][i]);
		}
	}
}
void result(int s, int t){
	vector<int> res;
	if(truoc[t] == 0){
		cout << -1;
	} else {
		res.push_back(t);
		while(t != s){
			t = truoc[t];
			res.push_back(t);
		}
		for(int i = res.size()-1; i >= 0; i--){
			cout << res[i] << " ";
		}
	}
	
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int v, e, u, t;
		cin >> v >> e >> u >> t;
		for(int i = 1; i <= v; i++) ke[i].clear();
		memset(vs, 0, sizeof(vs));
		for(int i = 0; i < e; i++){
			int start, end;
			cin >> start >> end;
			ke[start].push_back(end);
			ke[end].push_back(start);
		}
		Dfs(u);
		result(u, t);
		cout << endl;
	}
}

// Duong di theo bfs the do thi vo huong

// Dem so thanh phan lien thong

// Tim so thanh phan lien thong voi bfs

// Kiem tra tinh lien thong manh
vector<int> ke[1001];
bool vs[1001];
void BFS(int u){
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		u = q.front();
		q.pop();
		vs[u] = true;
		for(int i = 0; i < ke[u].size(); i++){
			if(!vs[ke[u][i]]){
				vs[ke[u][i]] = true;
				q.push(ke[u][i]);
			}
		}
	}
}

int tplt(int v){
	int k = 0;
	for(int i = 1; i <= v; i++){
		if(!vs[i]){
			k++;
			BFS(i);
		}
	}
	return k;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int v, e;
		cin >> v >> e;
		memset(vs, false, sizeof(vs));
		for(int i = 1; i <= v; i++){
			ke[i].clear();
		}
		for(int i = 0; i < e; i++){
			int start, end;
			cin >> start >> end;
			ke[start].push_back(end);
		}
		
		if(tplt(v) == 1) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}

// Liet ke dinh tru
vector<int> ke[1001];
bool vs[1001];
void BFS(int u){
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		u = q.front();
		q.pop();
		vs[u] = true;
		for(int i = 0; i < ke[u].size(); i++){
			if(!vs[ke[u][i]]){
				vs[ke[u][i]] = true;
				q.push(ke[u][i]);
			}
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int v, e;
		cin >> v >> e;
		memset(vs, false, sizeof(vs));
		for(int i = 0; i <= v; i++){
			ke[i].clear();
		}
		for(int i = 0; i < e; i++){
			int start, end;
			cin >> start >> end;
			ke[start].push_back(end);
			ke[end].push_back(start);
		}
		
		int k = 0;
		for(int i = 1; i <= v; i++){
			if(!vs[i]){
				k++;
				BFS(i);
			}
		}
		
		for(int i = 1; i <= v; i++){
			memset(vs, false, sizeof(vs));
			vs[i] = true;
			int dem = 0;
			for(int j = 1; j <= v; j++){
				if(!vs[j]){
					dem++;
					BFS(j);
				}
			}
			if(dem > k) cout << i << " ";
		}	
		cout << endl;
	}
}

// Kiem tra chu trinh tren do thi vo huong
int vs[1001], truoc[1001];
vector<int> ke[1001];

bool Bfs(int u){
	queue<int> q;
	q.push(u);
	vs[u] = 1;
	while(!q.empty()){
		u = q.front();
		q.pop();
		for(int i = 0; i < ke[u].size(); i++){
			if(!vs[ke[u][i]]){
				vs[ke[u][i]] = 1;
				truoc[ke[u][i]] = u;
				q.push(ke[u][i]);
			} else if(truoc[u] != ke[u][i]){
				return true;
			}
		}
	}
	return false;
}


int main(){
	int t;
	cin >> t;
	while(t--){
		int v, e;
		cin >> v >> e;
		memset(vs, false, sizeof(vs));
		memset(truoc, 0, sizeof(truoc));
		for(int i = 1; i <= v; i++){
			ke[i].clear();
		}
		for(int i = 0; i < e; i++){
			int start, end;
			cin >> start >> end;
			ke[start].push_back(end);
			ke[end].push_back(start);
		}
		
		int res = 0;
		for(int i = 1; i <= v; i++){
			memset(vs, false, sizeof(vs));
			if(!vs[i] && Bfs(i)){
				res = 1;
				break;
			}
		}
		if(res) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}

// Kiem tra chu trinh tren do thi co huong
vector<int> ke[1001];
bool cycleBFS(int v){
	vector<int> indegree(v+1, 0);
	for(int i = 1; i <= v; i++){
		for(int j = 0; j < ke[i].size(); i++){
			indegree[ke[i][j]]++;
		}
	}
	queue<int> q;
	for(int i = 1; i <= v; i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}
	int count = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 0; i < ke[u].size(); i++){
			if(--indegree[ke[u][i]] == 0){
				q.push(ke[u][i]);
			}
		}
		count++;
	}
	if(count == v) return false;
	else return true;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int v, e;
		cin >> v >> e;
		for(int i = 0; i <= v; i++){
			ke[i].clear();
		}
		for(int i = 0; i < e; i++){
			int start, end;
			cin >> start >> end;
			ke[start].push_back(end);
		}
		if(cycleBFS(v)) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}

// So luong hon dao 
int a[501][501], m, n, vs[501][501];
void Dfs(int row, int col){
	int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1};
	int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1};
	vs[row][col] = 1;
	for(int i = 0; i < 8; i++){
		row += dx[i];
		col += dy[i];
		if(row >= 1 && row <= m && col >= 1 && col <= n && a[row][col] && !vs[row][col]){
			Dfs(row, col);
		}
		row -= dx[i];
		col -= dy[i];
	}
}

int conut(int m, int n){
	memset(vs, 0, sizeof(vs));
	int k = 0;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(a[i][j] && !vs[i][j]){
				Dfs(i, j);
				k++;
			}
		}
	}
	return k;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> m >> n;
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= n; j++){
				cin >> a[i][j];
			}
		}
		cout << conut(m, n) << endl;
	}
}
