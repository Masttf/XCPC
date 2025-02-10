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
constexpr int Max=1e9;
void solve(){
    int n,m;cin>>n>>m;
    vector a(n+1,vector<int>(m+1));
    vector<int>res;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++)cin>>a[i][j];
    }
	auto get = [&](int i,int j)->int{
		return (i-1)*m+j;
	};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x;cin>>x;
			if(x==1)res.push_back(get(i,j));
		}
	}
	if(res.size()<=1){
		cout<<0<<'\n';
		return ;
	}
	vector<int>f(n*m+1);
	auto find = [&](auto self,int x)->int{
		return f[x]==x?x:f[x]=self(self,f[x]);
	};
	auto merge = [&](int a,int b)->void{
		int fa=find(find,a);
		int fb=find(find,b);
		if(fa==fb)return ;
		f[fa]=fb;
	};
	
	auto check = [&](int x)->bool{
		for(int i=1;i<=n*m;i++){
			f[i]=i;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<m;j++){
				if(abs(a[i][j]-a[i][j+1])<=x)merge(get(i,j),get(i,j+1));
			}
		}
		for(int i=1;i<n;i++){
			for(int j=1;j<=m;j++){
				if(abs(a[i][j]-a[i+1][j])<=x)merge(get(i,j),get(i+1,j));
			}
		}
		int fa=find(find,res[0]);
		for(auto x:res){
			if(find(find,x)!=fa)return false;
		}
		return true;
	};
	int ans=Max;
	int l=0,r=Max;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	cout<<ans<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}