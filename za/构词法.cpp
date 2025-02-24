#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
string pre[maxn],sup[maxn];
int n,m,q;
void solve(string x){
	string ans1="";
	int len1=x.size();
	for(int i=1;i<=n;i++){
		int flag=1;
		int len=pre[i].size();
		for(int j=0;j<len;j++){
			if(x[j]!=pre[i][j]){
				flag=0;
				break;
			}
		}
		if(flag){
			ans1=pre[i];
			break;
		}
	}
	string ans2="";
	for(int i=1;i<=m;i++){
		int flag=1;
		int len=sup[i].size();
		for(int j=1;j<=len;j++){
			if(x[len1-j]!=sup[i][len-j]){
				flag=0;
				break;
			}
		}
		if(flag){
			ans2=sup[i];
			break;
		}
	}
	int start=ans1.size(),end=ans2.size();
	for(int i=start;i<len1-end;i++){
		cout<<x[i];
	}
	cout<<'\n';
	return ;
}
int main(){
	cin>>n>>m>>q;
	string x;
	for(int i=1;i<=n;i++)cin>>pre[i];
	for(int i=1;i<=m;i++)cin>>sup[i];
	for(int i=1;i<=q;i++){
		cin>>x;
		solve(x);
	}
	return 0;
}
