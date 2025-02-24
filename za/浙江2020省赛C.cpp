#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e3+5;
string g[maxn];
void solve(){
	unordered_map<string,int>mm;
	mm[""]=0;
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++)cin>>g[i];
	for(int i=1;i<=m;i++){
		string s;int sc;
		cin>>s>>sc;
		mm[s]=sc;
	}
	int ans=0,flag=1;
	for(int i=0;i<n;i++){
		string temp="";
		for(int j=0;j<n;j++){
			if(g[i][j]!='#')temp+=g[i][j];
			else{
				if(mm.count(temp))ans+=mm[temp];
				else{
					flag=0;
					break;
				}
				temp="";
			}
		}
		if(mm.count(temp))ans+=mm[temp];
		else{
			flag=0;
			break;
		}
		temp="";
		for(int j=0;j<n;j++){
			if(g[j][i]!='#')temp+=g[j][i];
			else{
				if(mm.count(temp))ans+=mm[temp];
				else{
					flag=0;
					break;
				}
				temp="";
			}
		}
		if(mm.count(temp))ans+=mm[temp];
		else{
			flag=0;
			break;
		}
	}
	if(flag)cout<<ans<<'\n';
	else cout<<-1<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
/*
#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int maxn=4e6+5;
int t[maxn][26],cnt[maxn],idx,v[maxn];
string g[1005];
void ins(string s,int k){
	int p=0;
	for(int i=0;i<s.size();i++){
		int x=s[i]-'a';
		if(!t[p][x])t[p][x]=++idx,memset(t[idx],0,sizeof t[idx]),cnt[idx]=0,v[idx]=0;//用到再初始化
		p=t[p][x];
	}
	cnt[p]++;
	v[p]+=k;
}
int query(string s){
	if(s=="")return 0;
	int p=0;
	for(int i=0;i<s.size();i++){
		int x=s[i]-'a';
		if(!t[p][x])return -1;
		p=t[p][x];
	}
	if(cnt[p])return v[p];
	else return -1;
}
void solve(){
	memset(t[0],0,sizeof t[0]);
	cnt[0]=0;
	idx=0;
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++)cin>>g[i];
	for(int i=1;i<=m;i++){
		string s;int sc;
		cin>>s>>sc;
		ins(s,sc);
	}
	long long ans=0,flag=1,t=0;
	for(int i=0;i<n;i++){
		string temp="";
		for(int j=0;j<n;j++){
			if(g[i][j]!='#')temp+=g[i][j];
			else{
				t=query(temp);
				if(t!=-1)ans+=t;
				else{
					flag=0;
					break;
				}
				temp="";
			}
		}
		t=query(temp);
		if(t!=-1)ans+=t;
		else{
			flag=0;
			break;
		}
		temp="";
		for(int j=0;j<n;j++){
			if(g[j][i]!='#')temp+=g[j][i];
			else{
				t=query(temp);
				if(t!=-1)ans+=t;
				else{
					flag=0;
					break;
				}
				temp="";
			}
		}
		t=query(temp);
		if(t!=-1)ans+=t;
		else{
			flag=0;
			break;
		}
	}
	if(flag)cout<<ans<<'\n';
	else cout<<-1<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
 */
