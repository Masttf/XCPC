#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
const int SZ=20;
char s[MAXN];
struct SAM{
public:
vector<int>e[MAXN];
int ch[MAXN][2];
int sum[MAXN],Max[MAXN],fa[MAXN],pos[MAXN],up[MAXN][SZ];
int posmin[MAXN];
int n_last,sz;
public:
void init(int n){
   n_last=sz=1;
   for (int i=0;i<=n;i++){
        sum[i]=Max[i]=fa[i]=ch[i][0]=ch[i][1]=pos[i]=0;
        memset(up[i],0,sizeof(up[i]));
        posmin[i]=0x3f3f3f3f;
        e[i].clear();
   }
}
void p(int i,int c){
   int p=n_last,np=++sz;
   n_last=sz; 
   sum[np]++; pos[i]=np;
   Max[np]=Max[p]+1;
   posmin[np]=min(posmin[np],i);
   for (;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
   if (!p) {fa[np]=1; return;}
   int q=ch[p][c]; 
   if (Max[q]==Max[p]+1) fa[np]=q;
   else {
   	int nq=++sz; Max[nq]=Max[p]+1;
   	fa[nq]=fa[q]; fa[np]=fa[q]=nq;
   	memcpy(ch[nq],ch[q],sizeof(ch[q]));
   	for (;ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
   }
}
void build_tree(){
    for (int i=2;i<=sz;i++) e[fa[i]].push_back(i);
}
void dfs(int now, int father){
    up[now][0]=father;
    for (int i=1;i<SZ;i++) up[now][i]=up[up[now][i-1]][i-1];
	for (int i=0;i<e[now].size();i++){
		int u=e[now][i];
		dfs(u,now);
		sum[now]+=sum[u];
        posmin[now]=min(posmin[now],posmin[u]);
	}
}
int solve(int id,int len){
    for (int i=SZ-1;i>=0;i--) if (up[id][i]!=0&&Max[up[id][i]]>=len) id=up[id][i];
    return Max[id];
}
int getmin(int id,int len){
    for (int i=SZ-1;i>=0;i--) if (up[id][i]!=0&&Max[up[id][i]]>=len) id=up[id][i];
    return posmin[id];
}}sam1,sam2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
	cin >> s;
	int n=strlen(s);
    sam1.init(n<<1);
    sam2.init(n<<1);
	for (int i=1;i<=n;i++){
        sam1.p(i,s[i-1]-'a');
	}
    for (int i=n;i>=1;i--){
        sam2.p(i,s[i-1]-'a');
    }
    sam1.build_tree();
    sam2.build_tree();
    sam1.dfs(1,0);
    sam2.dfs(1,0);
    vector<pair<int,int> >ext;
    vector<pair<int,int> >w(sam1.sz+1);
    for (int i=2;i<=sam1.sz;i++){
        int r=sam1.posmin[i];
        int lmin=r-sam1.Max[i]+1;
        int rmax=r-sam1.Max[i]+sam2.solve(sam2.pos[lmin],sam1.Max[i]);
        w[i]=make_pair(lmin,rmax);
        ext.push_back(w[i]);
    }
    sort(ext.begin(),ext.end());
    int len=unique(ext.begin(),ext.end())-ext.begin();
    ext.resize(len);
    vector<vector<long long> >ans(ext.size()),ans_sum(ext.size());
    vector<int>ext_rmin(ext.size(),n+1);
    for (int i=2;i<=sam1.sz;i++){
        int id=lower_bound(ext.begin(),ext.end(),w[i])-ext.begin();
        ans[id].push_back(sam1.posmin[i]-sam1.Max[sam1.up[i][0]]);
        ext_rmin[id]=min(ext_rmin[id],sam1.posmin[i]);
    }
    for (int i=0;i<ans.size();i++){
        sort(ans[i].begin(),ans[i].end());
        ans_sum[i]=ans[i];
        for (int j=1;j<ans[i].size();j++)
            ans_sum[i][j]+=ans_sum[i][j-1];
    }
    int q,op,l,r;
    cin >> q;
    long long lastans=0;
    for (int i=1;i<=q;i++){
        cin >> op >> l >> r;
        l=(l+lastans%n-1)%n+1;
        r=(r+lastans%n-1)%n+1;
	    int len=r-l;
        r=sam1.getmin(sam1.pos[r],r-l+1);
        l=r-len;
        int lmin=r-sam1.solve(sam1.pos[r],r-l+1)+1;
        int rmax=l+sam2.solve(sam2.pos[l],r-l+1)-1;
        if (op==1){
            lastans=1ll*(l-lmin+1)*(rmax-r+1);
        }else{
            int id=lower_bound(ext.begin(),ext.end(),make_pair(lmin,rmax))-ext.begin();
            r=r-ext_rmin[id];
            int r0=lower_bound(ans[id].begin(),ans[id].end(),l)-ans[id].begin();
            lastans=1ll*(ans_sum[id][r]-(r0?ans_sum[id][r0-1]:0ll))-1ll*(r-r0+1)*(l-1);
        }
        cout << lastans << endl;
    }}
    return 0;
}
