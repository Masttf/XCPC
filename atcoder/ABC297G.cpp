#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,l,r;cin>>n>>l>>r;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]<l)a[i]=0;
		else{
			a[i]%=(l+r);
			a[i]/=l;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans^=a[i];
	if(ans)cout<<"First";
	else cout<<"Second";
	return 0;
}
/*打表程序
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=105;
int sg[maxn];
bool vis[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int l,r;cin>>l>>r;
	vector<int>s;
	for(int i=l;i<=r;i++)s.push_back(i);
	
	for(int i=1;i<=100;i++){
		memset(vis,0,sizeof vis);
		for(int j=0;s[j]<=i;j++){// 遍历它可能到的值取mex
			vis[sg[i-s[j]]]=1;
		}
		for(int j=0;j<=100;j++){//ta的mex
			if(!vis[j]){
				sg[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=100;i++){
		cout<<i<<' '<<sg[i]<<'\n';
	}
	return 0;
}
 */
