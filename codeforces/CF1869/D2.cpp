#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x)&-(x)
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	int sum=0;
	for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
	if(sum%n!=0){
		cout<<"NO\n";
		return ;
	}
	sum/=n;
	int ok=1;
	vector<int>cnt(35);
	vector<int>vis(n+1);
	for(int i=1;i<=n;i++){
		if(a[i]==sum)continue;
		int f=1;
		int d=a[i]-sum;
		if(d<0)d=-d,f=0;
		if(d==(lowbit(d)))vis[i]=1;
		int p=-1;
		for(int j=32;j>=0;j--){
			if(d>>j&1){
				if(p==-1){
					if(f)cnt[j+1]++;
					else cnt[j+1]--;
				}else{
					if(j!=p-1)ok=0;
				}
				p=j;
			}
		}
		if(f)cnt[p]--;
		else cnt[p]++;
	}
	for(int j=0;j<=32;j++){
		for(int i=1;i<=n;i++){
			if(abs(cnt[j])<2)break;
			//cout<<j<<endl;
			if(vis[i]){
				//cout<<j<<' '<<i<<endl;
				int d=a[i]-sum;
				int f=1;
				if(d<0)d=-d,f=-1;
				int t=__lg(d);
				if(t==j&&f*cnt[j]<0){
					//cout<<j<<endl;
					vis[i]=0;
					if(f==-1){
						cnt[j]-=2;
						cnt[j+1]++;
					}else{
						cnt[j]+=2;
						cnt[j+1]--;
					}
				}
			}
		}		
	}
	for(int i=0;i<=32;i++){
		if(cnt[i]!=0)ok=0;
	}
	if(ok)cout<<"YES\n";
	else cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}