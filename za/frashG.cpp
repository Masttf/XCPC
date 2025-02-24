#include<bits/stdc++.h>
using namespace std;
int res[10];
void slove(){
	memset(res,0,sizeof(res));
	for(int i=0;i<=6;i++){
		cin>>res[i];
	}
	for(int i=0;i<=5;i++){
		if(res[i]<res[i+1]){
			cout<<-1<<'\n';
			return ;
		}
	}//首先要有序
	//贪心考虑如果能接到上一个就接到上一个
	if(res[0]==res[6])cout<<1<<'\n';
	else cout<<res[0]-res[6]<<'\n';
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		slove();
	}
	return 0;
}
