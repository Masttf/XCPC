#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&-(x))
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}

const int maxn = 5e5 + 5;
vector<int>t[maxn];
int siz[maxn],son[maxn],a[maxn],Son,n;
int pos[maxn];
unsigned long long cnt[maxn],val1[maxn],val2[maxn],ans[maxn];
unsigned long long Sum;
vector<int>p;
int get_index(int x){
	return lower_bound(p.begin(),p.end(),x)-p.begin()+1;
}
void add(int x,int val,int t){
	while(x<=n){
		if(t==1){
			cnt[x]++;
			val1[x]+=val;
			val2[x]+=val*val;
		}else{
			cnt[x]--;
			val1[x]-=val;
			val2[x]-=val*val;
		}
		
		x+=lowbit(x);
	}
}
unsigned long long get1(int x){
	int temp=x;
	int num=0;
	int v=0;
	while(x){
		num+=cnt[x];
		v+=val1[x];
		x-=lowbit(x);
	}
	unsigned long long Ans=num*p[temp-1]*p[temp-1]-p[temp-1]*v;
	return Ans;
}
pair<int,int> ask(int x){
	pair<int,int>res;
	while(x){
		res.first+=val2[x];
		res.second+=val1[x];
		x-=lowbit(x);
	}
	return res;
}
unsigned long long get2(int x){
	auto [x1,y1]=ask(n);
	auto [x2,y2]=ask(x);
	int xx=x1-x2;
	int y=y1-y2;
	unsigned long long Ans=xx-y*p[x-1];
	return Ans;
}
void dfs(int u,int f) {
	siz[u] = 1;
	for (auto i : t[u]) {
		if (i == f) continue;
		dfs(i,u);
		siz[u] += siz[i];
		if (siz[i] > siz[son[u]]) {
			son[u] = i;
		}
	}
}

void ins(int u,int f) {
	//jiaru
	add(pos[u],a[u],1);
	Sum+=2*get1(pos[u]) + 2*get2(pos[u]);
	for (auto i : t[u]) {
		if (i == f || i == Son) continue;
		ins(i,u); 
	}
}

void dele(int u,int f) {
	//shanchu
	add(pos[u],a[u],0);
	for (auto i : t[u]) {
		if (i == f || i == Son) continue;
		dele(i,u); 
	}
}

void cal(int u,int f,int rt) {
	//
	Sum+=2*get1(pos[u]) + 2*get2(pos[u]);
	for (auto i : t[u]) {
		if (i == f || i == Son) continue;
		cal(i,u,rt); 
	} 
}


void dfs1(int u,int f,int del) {
	for (auto i : t[u]) {
		if (i == f || i == son[u]) continue;
		dfs1(i,u,0); 
	}
	if (son[u]) {
		dfs1(son[u],u,1);
		Son = son[u];
	}
	Sum=0;
	ins(u,f);
	Son = 0;
	ans[u] = ans[son[u]] + Sum;
	if (del == 0) {
		dele(u,f);
	}
}

void solve(){
	cin >> n;
	for (int i = 1;i < n;i++) {
		int u,v;cin >> u >> v;
		t[u].push_back(v);
		t[v].push_back(u);
	}
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		p.push_back(a[i]);
	}
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	for(int i=1;i<=n;i++){
		pos[i]=get_index(a[i]);
	}
	dfs(1,0);
	dfs1(1,0,0);
	unsigned long long Ans=0;
	for(int i=1;i<=n;i++){
		Ans^=ans[i];
	}
	cout<<Ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}