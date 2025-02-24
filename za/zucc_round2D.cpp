#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+5;
int n,m;
int res[maxn];
bool check(int x){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(res[i]<x){
			cnt+=(x-res[i])/4;
			if((x-res[i])%4!=0)cnt++;
		}
		if(cnt>m)return false;
	}
	return cnt<=m;
}
signed main(){
	cin.sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>res[i];
	}
	int ans=-1,left=1,right=5000000000000000000;
	while(left<=right){
		int mid=(left+right)>>1;
		if(check(mid))ans=mid,left=mid+1;
		else right=mid-1;
	}
	cout<<ans;
	return 0;
}
