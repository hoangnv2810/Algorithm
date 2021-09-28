#include<bits/stdc++.h>
using namespace std;

struct Pair{
    int x, y;
};

int cmp(Pair a, Pair b){
    return a.x < b.x;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Pair a[n+1];
        int dp[n+1];
        for(int i = 1; i <= n; i++){
            cin >> a[i].x >> a[i].y;
            dp[i] = 1;
        }
        sort(a+1, a+1+n, cmp);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j < i; j++){
                if(a[j].y < a[i].x)
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }
        cout << dp[n] << endl;
    }
}