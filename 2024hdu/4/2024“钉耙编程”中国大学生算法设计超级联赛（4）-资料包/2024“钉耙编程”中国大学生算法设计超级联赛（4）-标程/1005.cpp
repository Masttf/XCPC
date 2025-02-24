#include<cstdio>
const int N=805;
int Case,n,m,hp,dmg,i,j;char f[N];
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d%d%d%d",&n,&m,&hp,&dmg);
    for(i=0;i<m;i++)f[i]=' ';
    int top=(hp-1)/m;
    int lim=(hp-1)%m;
    int col=top%5+'A';
    int nxt=(top+4)%5+'A';
    if(top)for(i=0;i<m;i++)f[i]=nxt;
    for(i=0;i<=lim;i++)f[i]=col;
    if(dmg>m)dmg=m;
    while(dmg--){
      f[lim]='.';
      lim=(lim+m-1)%m;
    }
    putchar('+');
    for(i=0;i<m;i++)putchar('-');
    puts("+");
    for(i=0;i<n;i++){
      putchar('|');
      for(j=0;j<m;j++)putchar(f[j]);
      puts("|");
    }
    putchar('+');
    for(i=0;i<m;i++)putchar('-');
    puts("+");
  }
}