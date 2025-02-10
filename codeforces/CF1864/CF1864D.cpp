#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x)&-(x)
using namespace std;
const int maxn=3e3+5;
int a[maxn][maxn];
string temp[maxn];
void solve(){
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>temp[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=temp[i-1][j-1]-'0';
		}
	}
	int ans=0;
	vector<int>t1(3*n+1),t2(3*n+1);
	auto updata = [&](int x,int val,vector<int>&t)->void{
		while(x<=2*n-1){
			t[x]+=val;
			x+=lowbit(x);
		}
	};
	auto get = [&](int x,vector<int>&t)->int{
		int res=0;
		while(x){
			res+=t[x];
			x-=lowbit(x);
		}
		return res;
	};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int ct=get(i+j-1,t1)+get(j-i+n,t2);
			if(a[i][j]!=ct%2||(ct%2==0&&a[i][j]==1)){
				ans++;
				updata(i+j-1,1,t1);
				updata(j-i+n+1,-1,t2);
			}
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
