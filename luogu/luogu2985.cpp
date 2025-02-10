#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e4+5;
int n,d;
int res[maxn];
int t[maxn],aaa[maxn];
bool check(int x){
	int start=0,cnt=1,mi=999999999999;
	for(int i=1;i<=n;i++){
		start+=res[i];
		t[i]=cnt;
		while(start>=x&&cnt<d){
			mi=min(mi,start);
			start/=2;
			cnt++;
		}
	}
	mi=min(mi,start);
	if(cnt<d)return 0;
	else return mi>=x;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>d;
	int sum=0;
	for(int i=1;i<=n;i++)cin>>res[i],sum+=res[i];
	int ans=0,left=0,right=sum;
	while(left<=right){
		int mid=(left+right)>>1;
		if(check(mid)){
			ans=mid;left=mid+1;
			for(int i=1;i<=n;i++){
				aaa[i]=t[i];
			}
		}
		else right=mid-1;
	}
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++)cout<<aaa[i]<<'\n';
	return 0;
}
