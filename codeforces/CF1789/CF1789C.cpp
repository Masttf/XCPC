#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
void solve(){
	map<int,int>ma;
	map<int,int>l;
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=n*m*(m+1)/2;
	int last=0;//记录上一组的贡献
	for(int i=1;i<=m;i++){//受暴力启发，不用每次再遍历一次只需要一个存储即可，因为每次只改变一个
		int p,x;cin>>p>>x;
		if(x==a[p]){
			ans+=last;
			continue;
		}//当这个数一直的数组里时不用更新，拿出时更新即可
		ma[a[p]]+=i-l[a[p]];//统计在前i个里面有多少个a[p]
		last-=i-ma[a[p]];//减去这个数的贡献
		a[p]=x;
		last+=i-ma[x];//加上新加的数的贡献
		ans+=last;
		l[x]=i;//记录某个数开始的位置便于统计有多少个
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
/*
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
void solve(){
	map<int,int>ma;
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],ma[a[i]]++;
	int ans=n*m*(m+1)/2;
	for(int i=1;i<=m;i++){
		int p,x;cin>>p>>x;
		a[p]=x;
		for(int j=1;j<=n;j++){//暴力统计每个数的贡献
			ans+=i-ma[a[j]];
			ma[a[j]]++;
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
 */
