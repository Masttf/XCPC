#include<bits/stdc++.h>
using namespace std;
string x,y;
char a[100];//a数组对应x字符串对应的y的码
char b[100];//b数组对应y字符串对应的x的码
int len,cnt;
int main(){
	cin>>x>>y;
	len=x.length();
	for(int i=0;i<len;i++){
		//1要求原码只能对应一个密码
		//2要求密码只能对应一个原码
		if(a[x[i]]=='\0'&&b[y[i]]=='\0'){//把原码与密码建立关系
			a[x[i]]=y[i];
			b[y[i]]=x[i];
			cnt++;
		}else if(a[x[i]]!=y[i]){
			cout<<"Failed";
			return 0;
		}
	}
	if(cnt<26){
		cout<<"Failed";
		return 0;
	}
	string t;
	cin>>t;
	for(int i=0;i<t.length();i++){
		cout<<a[t[i]];
	}
	return 0;
}
