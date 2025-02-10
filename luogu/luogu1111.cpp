#include<bits/stdc++.h>
using namespace std;
int f[1005];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void unit(int a,int b){
	int fa=find(a),fb=find(b);
	if(fa==fb)return ;
	f[fa]=fb;
	return ;
}
struct node{
	int a,b,t;
	bool operator <(const node &y)const{
		return t<y.t;
	}
}res[100005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)cin>>res[i].a>>res[i].b>>res[i].t;
	sort(res+1,res+1+m);
	int flag=0;
	int i=1;
	while(i<=m){
		int cur=res[i].t;
		while(res[i].t==cur){
			unit(res[i].a,res[i].b);
			i++;
		}
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(find(j)==j)cnt++;
		}
		if(cnt==1){
			flag=1;
			cout<<cur;
			break;
		}
	}
	if(!flag)cout<<-1;
	return 0;
}
