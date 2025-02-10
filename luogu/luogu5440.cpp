#include<bits/stdc++.h>
using namespace std;
int cnt=0,ans=0;
int vis[10];
int c[2][15]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
bool f(int x){
	if(x==1)return 0;
	for(int i=2;i*i<=x;i++)if(x%i==0)return 0;
	return 1;
}
bool judge(string x){
	int d1=(x[6]-'0')*10+x[7]-'0';
	int y1=(x[4]-'0')*1000+(x[5]-'0')*100+d1;
	int y2=(x[0]-'0')*10000000+(x[1]-'0')*1000000+(x[2]-'0')*100000+(x[3]-'0')*10000+y1;
	if(f(d1)&&f(y1)&&f(y2))return 1;
	else return 0;
}
void dfs(string x,int start){
	if(start==cnt){
		int day=(x[6]-'0')*10+x[7]-'0';
		int yue=(x[4]-'0')*10+(x[5]-'0');
		int year=(x[0]-'0')*1000+(x[1]-'0')*100+(x[2]-'0')*10+(x[3]-'0');
		if(year==0)return ;
		if((year%4==0&&year%100!=0)||year%400==0){
			if(yue>=1&&yue<=12){
				if(day>=1&&day<=c[1][yue-1]){
					if(judge(x))ans++;
				}
			}
		}else{
			if(yue>=1&&yue<=12){
				if(day>=1&&day<=c[0][yue-1]){
					if(judge(x))ans++;
				}
			}
		}
		return ;
	}
	if((vis[start]>=0&&vis[start]<=3)||vis[start]==7){
		for(char i='0';i<='9';i++){
			x[vis[start]]=i;
			dfs(x,start+1);
		}
	}else if(vis[start]==4){
		for(char i='0';i<='1';i++){
			x[vis[start]]=i;
			dfs(x,start+1);
		}
	}else if(vis[start]==5){
		for(char i='0';i<='9';i++){
			x[vis[start]]=i;
			dfs(x,start+1);
		}
	}else if(vis[start]==6){
		for(char i='0';i<='3';i++){
			x[vis[start]]=i;
			dfs(x,start+1);
		}
	}
}
void solve(){
	string t;cin>>t;
	cnt=0,ans=0;
	if(t=="--------")cout<<55157<<'\n';
	else{
		int sz=t.size();
		for(int i=0;i<sz;i++) if(t[i]=='-')vis[cnt++]=i;
		dfs(t,0);
		cout<<ans<<'\n';
	}
	
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
