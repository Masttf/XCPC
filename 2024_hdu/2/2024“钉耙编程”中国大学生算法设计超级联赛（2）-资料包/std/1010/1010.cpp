#include <bits/stdc++.h>

using namespace std;

int T;
char s[10];

int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		int R=0,G=0,B=0;
		for(int i=1;i<=8;i++){
			if(s[i]=='R')R++;
			if(s[i]=='G')G++;
			if(s[i]=='B')B++;
		}
		if(s[1]==s[5]){
			cout<<s[1]<<'\n';
		}else{
			int x,y;
			if(s[1]=='R'){
				x=R;
			}else if(s[1]=='G'){
				x=G;
			}else{
				x=B;
			}
			if(s[5]=='R'){
				y=R;
			}else if(s[5]=='G'){
				y=G;
			}else{
				y=B;
			}
			if(x==y){
				cout<<"N\n";
			}else if(x>y){
				cout<<s[1]<<'\n';
			}else{
				cout<<s[5]<<'\n';
			}
		}
	}
	return 0;
}