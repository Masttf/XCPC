#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+5;
int a[maxn],add[maxn],l[maxn],r[maxn],diff[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		cin>>add[i]>>l[i]>>r[i];
		diff[l[i]]+=add[i];
		diff[r[i]+1]-=add[i];
	}
	int sum=0,x=-1;
	for(int i=1;i<=n;i++){
		sum+=diff[i];
		if(sum>a[i]){
			while(sum>a[i]){
				diff[l[m]]-=add[m];
				diff[r[m]+1]+=add[m];
				if(l[m]<=i&&i<=r[m]){
					sum-=add[m];
				}
				m--;
			}
			x=m;
		}
	}
	if(x==-1)cout<<0;
	else cout<<-1<<'\n'<<x+1;
	return 0;
}
