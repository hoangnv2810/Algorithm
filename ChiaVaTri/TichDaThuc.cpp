#include<iostream>
#include<vector>
using namespace std;
struct X{
    int hs, mu;
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int m, n;
        cin >> m >> n;
        X* a = new X[m];
        X* b = new X[n];
        for(int i = 0; i < m; i++){
            cin >> a[i].hs;
            a[i].mu = i;
        }
        for(int i = 0; i < n; i++){
            cin >> b[i].hs;
            b[i].mu = i;
        }
        vector< vector<X> > res;
        for(int i = 0; i < m; i++){
            vector<X> temp;
            for(int j = 0; j < n; j++){
                temp.push_back({a[i].hs * b[j].hs, a[i].mu + b[j].mu});
            }
            res.push_back(temp);
        }
        int mu = 0;
        while(mu < m+n-1){
            int hs = 0;
            for(int i = 0; i < res.size(); i++){
                for(int j = 0; j < res[i].size(); j++){
                    if(res[i][j].mu == mu) hs += res[i][j].hs; 
                }
            }
            cout << hs << " ";
            mu++;
        }
        cout << endl;
    }
}