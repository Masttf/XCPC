#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
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
constexpr int N=2e5+5;
void solve(){
	int n,q;cin>>n>>q;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>tr(n+1);
	auto add = [&](int x,int val)->void{
		while(x<=n){
			tr[x]+=val;
			x+=lowbit(x);
		}
	};
	auto ask = [&](int x)->int{
		int res=0;
		while(x){
			res+=tr[x];
			x-=lowbit(x);
		}
		return res;
	};
	auto get = [&](int x)->int{
		int p=0;
		int sum=0;
		for(int i=20;i>=0;i--){
			int v=p+(1ll<<i);
			if(v<=n&&sum+tr[v]<=x){
				sum+=tr[v];
				p=v;
			}
		}
		return p;
	};
	bitset<N>s;
	s[0]=1;
	set<int>z;
	for(int i=1,j=0;i<=n;i++){
		j+=a[i];
		s[j]=1;
		add(i,a[i]);
		if(a[i]==0)z.insert(i);
	}
	for(int i=1;i<=q;i++){
		int t;cin>>t;
		if(t==2){
			int x,val;cin>>x>>val;
			int d=val-a[x];
			int last=a[x];
			int v=ask(x);
			if(a[x]==0)z.erase(x);
			a[x]=val;
			if(a[x]==0)z.insert(x);
			add(x,d);
			bitset<N>temp=(s>>v)<<v;
			if(d>0)temp<<=d;
			else temp>>=(-d);
			if(last==0)v+=1;
			bitset<N>t2=(s<<(N-v))>>(N-v);
			s=temp|t2;
			
		}else{
			int x;cin>>x;
			if(x==0){
				if(z.empty()){
					cout<<-1<<'\n';
				}else{
					cout<<(*(z.begin()))<<' '<<(*(z.begin()))<<'\n';
				}
			}else{
				bitset<N>temp=(s>>x)&s;
				if(temp.any()){
					int sum=temp._Find_first();
					int r=get(sum+x);
					int l=get(sum)+1;
					cout<<l<<' '<<r<<'\n';
				}else{
					cout<<-1<<'\n';
				}
			}
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}