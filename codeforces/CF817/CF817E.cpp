#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e6+5;
int t[maxn][2];
int cnt[maxn],tot=1;
void add(int x){
	int p=1;
	for(int i=30;i>=0;i--){
		int d=(x>>i)&1;
		if(!t[p][d])t[p][d]=++tot;
		p=t[p][d];
		cnt[p]++;
	}
	return ;
}
void del(int x){
	int p=1;
	for(int i=30;i>=0;i--){
		int d=(x>>i)&1;
		p=t[p][d];
		cnt[p]--;
	}
	return ;
}
int ask(int x,int l){
	int res=0;
	int p=1;
	for(int i=30;i>=0;i--){
		int d=(l>>i)&1;
		int k=(x>>i)&1;
		if(d){
			res+=cnt[t[p][k]];
			p=t[p][1-k];
		}else p=t[p][k];
	}
	return res;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int q;cin>>q;
	while(q--){
		int t;cin>>t;
		if(t==1){
			int x;cin>>x;
			add(x);
		}else if(t==2){
			int x;cin>>x;
			del(x);
		}else{
			int x,y;cin>>x>>y;
			cout<<ask(x,y)<<'\n';
		}
	}
	return 0;
}
