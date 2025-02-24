#include<bits/stdc++.h>
#define int __int128
using namespace std;
const int maxn=3e5+5;
pair<int,int>a[maxn];
int mx[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,h;cin>>n>>h;
	for(int i=1;i<=n;i++){
		long long x,y;cin>>x>>y;
		a[i].first=x;
		a[i].second=y;
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)mx[i]=max(mx[i+1],a[i].second);
	long long ans=-1;
	int pre=0;
	for(int i=1;i<=n;i++){
		int k=(pre+mx[i]-1)/mx[i];
		k--;
		k=min(k,a[i].first);
		k=max(a[i-1].first,k);
		if(h>pre*(k-a[i-1].first))h-=pre*(k-a[i-1].first);
		else{
			ans=(h+pre-1)/pre+a[i-1].first;
			h=0;
			break;
		}
		int t=mx[i]*(a[i].first-k)*(a[i].first+k+1)/2;
		if(h>t)h-=t;
		else{
			for(int j=k+1;j<=a[i].first;j++){
				h-=mx[i]*j;
				if(h<=0){
					ans=j;
					break;
				}
			}
			break;
		}
		int j=i;
		while(j<=n&&a[j].first==a[i].first){
			pre=max(pre,a[j].second*a[j].first);
			j++;
		}
		i=j-1;
	}
	if(h>0)ans=(h+pre-1)/pre+a[n].first;
	cout<<ans;
	return 0;
}
