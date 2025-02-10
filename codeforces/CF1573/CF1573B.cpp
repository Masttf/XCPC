#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int a[maxn],b[maxn],res[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];//肯定是第一个数就出现结果
	for(int i=1;i<=n;i++)cin>>b[i];//需要一个换到前面
	int last=2,p=1;
	for(int i=1;i<=n;i++){
		if(last>2*n)break;
		if(b[i]>=last){
			res[p]+=i-1;
			res[b[i]/2+1]-=i-1;
			last=b[i]+2;
			p=b[i]/2+1;
		}
	}
	for(int i=1;i<=n;i++)res[i]+=res[i-1];
	int mi=INT_MAX;
	for(int i=1;i<=n;i++){
		int t=i-1+res[(a[i]+1)/2];
		mi=min(mi,t);
	}
	cout<<mi<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
