#include<bits/stdc++.h>
#define int long long
using namespace std;
int res[200005];
int n;
int c1(int h){
	int cnt=0;
	int dx=1;
	for(int i=1;i<=n;i++){
		if(h>res[i]){
			h+=res[i]/2;
			cnt++;
		}
		else if(h<=res[i]&&dx==1){
			h*=2;
			dx++;
			i--;
		}else if(h<=res[i]&&dx==2){
			h*=2;
			dx++;
			i--;
		}
		else if(h<=res[i]&&dx==3){
			h*=3;
			dx++;
			i--;
		}
	}
	return cnt;
}
int c2(int h){
	int cnt=0;
	int dx=1;
	for(int i=1;i<=n;i++){
		if(h>res[i]){
			h+=res[i]/2;
			cnt++;
		}
		else if(h<=res[i]&&dx==1){
			h*=2;
			dx++;
			i--;
		}else if(h<=res[i]&&dx==2){
			h*=3;
			dx++;
			i--;
		}
		else if(h<=res[i]&&dx==3){
			h*=2;
			dx++;
			i--;
		}
	}
	return cnt;
}
int c3(int h){
	int cnt=0;
	int dx=1;
	for(int i=1;i<=n;i++){
		if(h>res[i]){
			h+=res[i]/2;
			cnt++;
		}
		else if(h<=res[i]&&dx==1){
			h*=3;
			dx++;
			i--;
		}else if(h<=res[i]&&dx==2){
			h*=2;
			dx++;
			i--;
		}
		else if(h<=res[i]&&dx==3){
			h*=2;
			dx++;
			i--;
		}
	}
	return cnt;
}
signed main(){
	int t;cin>>t;
	for(int j=1;j<=t;j++){
		int h;
		cin>>n>>h;
		memset(res,0,sizeof(res));
		for(int i=1;i<=n;i++){
			cin>>res[i];
		}
		int cnt=0;
		sort(res+1,res+1+n);
		cnt=max(c1(h),c2(h));
		cnt=max(cnt,c3(h));
		cout<<cnt<<'\n';
	}
	return 0;
}
