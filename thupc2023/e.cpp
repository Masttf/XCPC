#include<bits/stdc++.h>
#define int long long
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
struct node{
	int id,b,c;
	bool operator <(const node&y)const{
		if(b!=y.b)return b<y.b;
		else return c<y.c;
	}
};
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	vector<int>b(n+1);
	vector<int>c(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	auto get1 = [&]()->void{
		vector<int>temp(n+1);
		vector<int>cnt=b;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
		for(int i=1;i<=n;i++){
			if(a[i]==0&&b[i]){
				q.push({min(c[i]+1,b[i]),i});
			}
		}
		queue<int>qq;
		for(int i=1;i<=n;i++){
			if(a[i])temp[i]=a[i]+c[i];
			if(a[i]&&b[i]){
				qq.push(i);
			}
		}
		while(!q.empty()){
			if(qq.empty())break;
			int u=qq.front();
			qq.pop();
			int d=min(cnt[u],temp[u]);
			for(int i=1;i<=d;i++){
				if(q.empty())break;
				int v=q.top().second;
				q.pop();
				temp[u]--;
				cnt[u]--;
				temp[v]=c[v]+1;
				qq.push(v);
			}
		}
		int res=0;
		for(int i=1;i<=n;i++){
			res+=min(temp[i],cnt[i]);
		}
		for(int i=1;i<=n;i++){
			int d=res-min(temp[i],cnt[i])+temp[i];
			if(d&&a[i]==0&&b[i]==0)cout<<d+c[i]<<' ';
			else cout<<d<<' ';
		}
		cout<<'\n';
		return ;
	};
	auto get2 = [&]()->int{
		int res=0;
		priority_queue<node>q;
		for(int i=1;i<=n;i++){
			if(a[i]==0&&c[i]){
				q.push({i,b[i]>0?1:0,c[i]});
			}
		}
		vector<int>temp(n+1);
		queue<int>qq;
		for(int i=1;i<=n;i++){
			if(a[i]){
				temp[i]=a[i]+c[i];
				qq.push(i);
				res+=temp[i];
			}
		}
		while(!q.empty()){
			if(qq.empty())break;
			int u=qq.front();
			qq.pop();
			int d=min(temp[u],b[u]);
			for(int i=1;i<=d;i++){
				if(q.empty())break;
				int v=q.top().id;
				q.pop();
				temp[v]=1+c[v];
				res+=c[v];
				qq.push(v);
			}
		}
		return res;
	};
	get1();
	cout<<get2()<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}