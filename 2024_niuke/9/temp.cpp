#include<bits/stdc++.h>//Anrew确实要快一点,实测 
using namespace std;
const int maxn=5e4+5;
int n,m=0;
struct node{
    int x,y;
}p[maxn],ch[maxn];

inline int read(){
    int x=0,f=1;char a=getchar();
    while(!isdigit(a)) {if(a=='-') f=-1;a=getchar();}
    while(isdigit(a)) {x=(x<<3)+(x<<1)+a-'0';a=getchar();}
    return x*f;
}

int dis(node a,node b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int cross(node p0,node p1,node p2){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

int cmp(node a,node b){//排序，对于x，y坐标
	return (a.x!=b.x) ? (a.x<b.x):(a.y<b.y);
}

void andrew(){//先右到左遍历找凸包，在左到右找
    sort(p,p+n,cmp);
    for(int i=0;i<n;++i){
        while(m>1&&cross(ch[m-2],ch[m-1],p[i])<=0) m--;
        ch[m++]=p[i];
    }
    int k=m;
    for(int i=n-2;i>=0;--i){
        while(m>k&&cross(ch[m-2],ch[m-1],p[i])<=0) m--;
        ch[m++]=p[i];
    }
    if(n>1) m--;
}

int rotating_calipers(){//旋转卡壳同上
    int j=1,ans=0;
    for(int i=0;i<m;++i){
        while(cross(ch[i],ch[i+1],ch[j])<cross(ch[i],ch[i+1],ch[j+1])) j=(j+1)%m;
        ans=max(ans,max(dis(ch[i],ch[j]),dis(ch[i+1],ch[j])));
    }
    return ans;
}

int main(){
	//freopen("a.txt","r",stdin);
    n=read();
    for(int i=0;i<n;++i)
        p[i].x=read(),p[i].y=read();
    cout << m << '\n';
    andrew();
    cout << m << '\n';
    printf("%d",rotating_calipers());
    return 0;
}