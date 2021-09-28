void DFS(int u){
    vs[u] = 1;
    for(v ke(u)){
        if(vs[u] == 0){
            truoc[v] = u;
            DFS(v);
        }
    }
}

void BFS(int u){
    Đưa u vào queue;
    vs[u] = 1;
    while(q != rỗng){
        Lấy v ra khỏi queue
        for(i Ke v){
            if(vs[i] == 0){
                Đưa i vào queue;
                truoc[i] = v;
            }
        }
    }
}

//Duyệt tất cả các đỉnh
void DuyetDFS(){
    for(int v = 1; v <= n; v++){
        vs[v] = 0;
        e[v] = 0;
    }
    for(int v = 1; v <= n; v++){
        if(vs[v] == 0){
            DFS(v); // BFS(v);
        }
    }
}

// Đường đi từ u đến v
int a[100][100], n, u, v, e[100], vs[100];
void DuongDiDFS(int u, int v){
    DFS(u); // BFS(u) Sử dụng BFS là có đường đi ít cạnh nhất
    if(vs[v] == 1){
        int t = v;
        while(t > 0){
            cout << t << "<=";
            t = e[t];
        }
    } else {
        cout << "No";
    }
}

