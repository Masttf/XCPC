#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int a[maxn],b[maxn];
int res[maxn];
int js(int l,int r){
	int ll=a[l],rr=a[r];
	int now=0;
	for(int i=l+1;i<=r-1;i++){
		if(a[i]<=ll||a[i]>=rr)continue;
		int p=lower_bound(res+1,res+1+now,a[i])-res;
		if(p==1+now)res[++now]=a[i];
		else res[p]=a[i];
	}
	return now;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,k;cin>>n>>k;
	for(int i=1;i<=k;i++)cin>>b[i];
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(b+1,b+1+k);
	b[k+1]=n+1;
	a[1+n]=INT_MAX;
	int flag=1;
	for(int i=1;i<k;i++){
		if(a[b[i+1]]<=a[b[i]])flag=0;
	}
	if(!flag){
		cout<<"impossible";
		return 0;
	}
	int ans=k;
	for(int i=1;i<=k+1;i++){
		ans+=js(b[i-1],b[i]);
	}
	cout<<ans;
	return 0;
}
