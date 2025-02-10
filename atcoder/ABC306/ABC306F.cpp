#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
using namespace std;
struct node{
	int val;
	int w1,w2;
	bool operator <(const node&y)const{
		return val<y.val;
	}
};
void solve(){
	int n,m;cin>>n>>m;
	vector<vector<int>>a(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cin>>a[i][j];
	}

	vector<node>p;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			p.push_back({a[i][j],i,j});
		}
	}
	sort(p.begin(),p.end());

	vector<int>t(n+1);
	auto updata = [&](int x)->void{
		while(x<=n){
			t[x]++;
			x+=lowbit(x);
		}
		return ;
	};

	auto ask = [&](int x)->int{
		int res=0;
		while(x){
			res+=t[x];
			x-=lowbit(x);
		}
		return res;
	};

	//cout<<"YES"<<endl;
	int ans=0;
	int sum=0;
	for(auto [val,i,j]:p){
		//cout<<val<<' '<<i<<' '<<j<<endl;
		updata(i);
		sum++;
		ans+=(n-i)*j+sum-ask(i);
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