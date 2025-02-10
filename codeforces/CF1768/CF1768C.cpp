#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
pair<int,int> res[maxn];
int p[maxn],q[maxn],m1,m2;
bool vis[maxn],v2[maxn];
void solve(){
	memset(vis,0,sizeof(vis));
	memset(v2,0,sizeof(v2));
	int n;cin>>n;
	int flag=1;
	m1=1,m2=1;
	for(int i=1;i<=n;i++){
		cin>>res[i].first,res[i].second=i;
	}
	sort(res+1,res+1+n);
	for(int i=1;i<=n;i++){
		int pos=res[i].second;
		if(!vis[res[i].first]){
			p[pos]=res[i].first;
			vis[res[i].first]=1;
			while(v2[m2])m2++;
			if(m2>res[i].first)flag=0;
			q[pos]=m2;
			v2[m2]=1;
			m2++;
		}else if(!v2[res[i].first]){
			q[pos]=res[i].first;
			v2[res[i].first]=1;
			while(vis[m1])m1++;
			if(m1>res[i].first)flag=0;
			p[pos]=m1;
			vis[m1]=1;
			m1++;
		}else flag=0;
	}
	if(!flag)cout<<"NO"<<'\n';
	else{
		cout<<"YES"<<'\n';
		for(int i=1;i<=n;i++)cout<<p[i]<<' ';
		cout<<'\n';
		for(int i=1;i<=n;i++)cout<<q[i]<<' ';
		cout<<'\n';
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
