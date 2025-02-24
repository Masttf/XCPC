#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int flag=1;//1表示a
	while(n!=0||m!=0){
		if(n-2!=0&&m-1!=0||n-1!=0&&m-2!=0){
			if(n!=0)n--;
			else m--;
			if(flag==1)flag=0;
			else flag=1;
		}else break;
	}
	if(flag==0)cout<<"a";
	else cout<<"b";
	return 0;
}
