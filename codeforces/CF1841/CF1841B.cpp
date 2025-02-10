#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
bool vis[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	deque<int>q;
	int flag=0;
	for(int i=1;i<=n;i++){
		if(q.empty())q.push_back(a[i]),vis[i]=1;
		else{
			if(!flag){
				if(a[i]>=q.back()){
					q.push_back(a[i]);
					vis[i]=1;
				}else if(a[i]<=q.front()){
					q.push_back(a[i]);
					flag=1;
					vis[i]=1;
				}
			}else{
				if(q.back()<=a[i]&&a[i]<=q.front()){
					q.push_back(a[i]);
					vis[i]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)cout<<vis[i];
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
