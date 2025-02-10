#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)

void err() {
	cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout<<fixed<<setprecision(10)<<arg<< ' ';
	err(args...);
}
const int Max=1e18;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	int mx=0;
	for(int i=1;i<=n;i++)cin>>a[i],mx=max(mx,a[i]);
	vector<int>f(mx+1);
	for(int i=1;i<=mx;i++)f[i]=i;
	auto find = [&](auto self,int x)->int{
		return f[x]==x?x:f[x]=self(self,f[x]);
	};
	auto merge = [&](int a,int b)->void{
		int fa=find(find,a);
		int fb=find(find,b);
		if(fa==fb)return ;
		f[fa]=fb;
	};
	vector<int>p(mx+1);
	vector<int>pp(n+1);
	for(int i=1;i<=n;i++){
		int x=a[i];
		int pre=-1;
		for(int j=2;j*j<=x;j++){
			if(x%j==0){
				if(pre!=-1)merge(j,pre);
				pre=j;
				p[j]++;
				while(x%j==0)x/=j;
			}
		}
		if(x!=1){
			if(pre!=-1)merge(x,pre);
			pre=x;
		}
		if(pre==-1)pre=1;
		pp[i]=pre;
	}
	int sz=0;
	vector<int>mm(mx+1);
	for(int i=1;i<=mx;i++){
		if(p[i]&&find(find,i)==i)sz++,mm[i]=sz;
	}
	vector<int>ans1,ans2;
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			continue;
		}else{
			if(mm[find(find,pp[i])]%2==0)ans2.push_back(a[i]);
			else ans1.push_back(a[i]);
		}
		
	}
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			if(ans1.size()>ans2.size())ans2.push_back(a[i]);
			else ans1.push_back(a[i]);
		}
	}
	if(ans1.empty()||ans2.empty()){
		cout<<-1<<' '<<-1<<'\n';
		return ;
	}
	cout<<ans1.size()<<' '<<ans2.size()<<'\n';
	for(auto x:ans1)cout<<x<<' ';
	cout<<'\n';
	for(auto x:ans2)cout<<x<<' ';
	cout<<'\n';
	
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}