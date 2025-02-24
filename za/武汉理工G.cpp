//两个换2个
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int res[5]={0},target;
		cin>>res[1]>>res[2]>>res[3]>>target;
		int a,b,mi,mx;
		if(6-target==3)a=1,b=2;
		else if(6-target==4)a=1,b=3;
		else if(6-target==5)a=2,b=3;
		if(res[a]<res[b])mx=b,mi=a;
		else mx=a,mi=b;
		res[mx]-=res[mi];
		if(res[mx]%3==0)cout<<"Yes"<<'\n';
		else cout<<"No"<<'\n';
		
	}
	return 0;
}
