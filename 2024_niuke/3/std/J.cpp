// bo b大局，每大局bo a小局
#include<bits/stdc++.h>
using namespace std;

const int N=100007;
int n,a,b;
string s;
int nxt[20][N];
pair<int,int> res[20][N];

void solve(int u){
    for (int i=1;i<20;++i) {
        for (int j=0;j<n;++j) 
        nxt[i][j]=nxt[i-1][nxt[i-1][j]], res[i][j].first=res[i-1][j].first+res[i-1][nxt[i-1][j]].first, res[i][j].second=res[i-1][j].second+res[i-1][nxt[i-1][j]].second;
    }
    int nnxt[N], nres[N];
    memset(nnxt,0,sizeof(nnxt));
    memset(nres,0,sizeof(nres));
    for (int j=0;j<n;++j){
        int now=j,L=0,R=0;
        for (int i=19;i>-1;--i){
            if (L+res[i][now].first<u&&R+res[i][now].second<u) L+=res[i][now].first, R+=res[i][now].second, now=nxt[i][now];
        }
        nres[j]=res[0][now].second, nnxt[j]=nxt[0][now];
    }
    for (int j=0;j<n;++j) res[0][j]=(nres[j]?make_pair(0,1):make_pair(1,0)), nxt[0][j]=nnxt[j];
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>a>>b>>s;
    for (int i=0;i<n;++i) nxt[0][i]=(i+1)%n;
    for (int i=0;i<n;++i) res[0][i]=(s[i]=='1'?make_pair(0,1):make_pair(1,0));
    solve(a); solve(b);
    for (int i=0;i<n;++i) cout<<res[0][i].second;
}
