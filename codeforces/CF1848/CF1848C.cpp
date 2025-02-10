#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1),b(n+1);
	vector<int>res(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++){
		int cnt=0;
		int p1=a[i],p2=b[i];
		if(p1==0&&p2==0){
			res[i]=-1;
			continue;
		}
		while(p1!=0){
			if(p2==0){
				p1=0;
				cnt++;
				continue;
			}
			if(p1>=2*p2){
				int k=p1/(2*p2);
				cnt+=3*k;
				p1-=k*2*p2;
			}else{
				int tem=p2;
				p2=abs(p2-p1);
				p1=tem;
				cnt++;
			}
		}
		res[i]=cnt;
	}
	int p=-1;
	for(int i=1;i<=n;i++){
		if(res[i]==-1)continue;
		if(p==-1)p=res[i];
		else{
			int k=abs(res[i]-p);
			if(k%3!=0){
				cout<<"NO\n";
				return ;
			}else p=max(res[i],p);
		}
	}
	cout<<"YES\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
