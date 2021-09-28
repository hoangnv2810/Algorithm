#include<iostream>
#include<conio.h>
using namespace std;
#define TRUE 1 
#define FALSE  0 
#define MAX  10000 
int a[100][100];//ma tr?n tr?ng s? c?a d? th?.
int n;//s? d?nh c?a d? th?
int m;//s? c?nh c?a d? th?.
int sc;//s? c?nh c?a c�y khung nh? nh?t.
int w;//�? d�i c?a c�y khung nh? nh?t.
int chuaxet[100];//m?ng d�nh d?u danh s�ch d?nh d� th�m v�o c�y khung nh? nh?t.
int cck[100][3];//danh s�ch c?nh c?a c�y khung nh? nh?t.
void nhap(void){
 int i, j, k;
 freopen("in.txt", "r",stdin);
 cin>>n>>m;
 cout<<"So dinh: "<<n<<endl;
 cout<<"So canh: "<<m<<endl;
 //kh?i t?o ma tr?n tr?ng s? c?a d? th? a[i][j] = MAX.
 for (i = 1; i <= n; i++){
  chuaxet[i] = TRUE;//G�n nh�n cho c�c d?nh.
  for (j = 1; j <= n; j++)
   a[i][j] = MAX;
 }

 //nh?p danh s�ch c?nh.
 for (int p = 1; p <= m; p++){
  cin>>i>>j>>k;
  a[i][j] = k;
  a[j][i] = k;
 }
}
void PRIM(void){
 int k, top, min, l, t, u;
 int s[100];//m?ng ch?a c�c d?nh c?a c�y khung nh? nh?t.
 sc = 0; w = 0; u = 1;
 top = 1;
 s[top] = u;// th�m d?nh u b?t k? v�o m?ng s[]
 chuaxet[u] = FALSE;
 while (sc<n - 1) {
  min = MAX;
  //t�m c?nh c� d? d�i nh? nh?t v?i c�c d?nh trong m?ng s[].
  for (int i = 1; i <= top; i++){
   t = s[i];
   for (int j = 1; j <= n; j++){
    if (chuaxet[j] && min>a[t][j]){
     min = a[t][j];
     k = t;
     l = j;
    }
   }
  }
  sc++;
  w = w + min;
  //th�m v�o danh s�ch c?nh c?a c�y khung.
  cck[sc][1] = k;
  cck[sc][2] = l;
  chuaxet[l] = FALSE; 
  top++;
  s[top] = l;
 }
}
void Result(void){
 cout<<"Do dai ngan nhat:"<< w<<endl;
 cout<<"Cac canh cua cay khung nho nhat"<<endl;
 for (int i = 1; i <= sc; i++)
  cout<< cck[i][1]<<" "<< cck[i][2]<<endl;
}
int main(void){
 nhap(); 
 PRIM();
 Result();
 getch();
}
