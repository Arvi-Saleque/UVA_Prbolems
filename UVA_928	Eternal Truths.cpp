#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define plll pair<pll,ll>
#define ff first
#define ss second
#define sfi(a) scanf("%d",&a)
#define sfi2(a,b) scanf("%d %d",&a,&b)
#define sfi3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sfll(a) scanf("%lld",&a)
#define all(a) a.begin(),a.end()
#define inf 1e7
#define m_p make_pair
#define min3(a,b,c) min(a,min(b,c))
#define pb push_back
#define mem(x,val) memset(x,val,sizeof(x))
#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
#define FAST  ios_base::sync_with_stdio(0);cout.tie(0)
#define sqr(x) ((x)*(x))

using ll = long long int;
const ll sz = 301;
const ll mod = 1000000007;

int kx[] = {1,-1,0,0};
int ky[] = {0,0,1,-1};

int r,c,level[sz+1][sz+1][4];
char grid[sz+1][sz+1];

bool valid(int x,int y){
    if(x>=0 && x<r && y>=0 && y<c && grid[x][y]!='#') return true;
    else return false;
}

void bfs(pii s){
    queue<pair<pair<int,int>,int>> pq;
    pq.push({s,1});
    level[s.ff][s.ss][3] = 0;
    bool flag = false;
    for(int k=1;k<=900000;k++){
        if(flag || pq.empty()) break;
        pair<pair<int,int>,int> par = pq.front();
        pq.pop();
        for(int i=0;i<4;i++){
            int x = par.ff.ff + (kx[i]*par.ss);
            int y = par.ff.ss + (ky[i]*par.ss);
            bool check = true;
            if(valid(x,y)){
                for(int tmp = 1;tmp<=par.ss;tmp++){
                    int xx = par.ff.ff + (kx[i]*tmp);
                    int yy = par.ff.ss + (ky[i]*tmp);
                    if(xx<0||xx>=r||yy<0||yy>=c) continue;
                    if(grid[xx][yy]=='#') {
                        check = false;
                        break;
                    }
                }
                if(check){
                    if(level[x][y][par.ss]!=-1) continue;
                    int vv = par.ss - 1;
                    if(vv==0) vv = 3;
                    level[x][y][par.ss] = level[par.ff.ff][par.ff.ss][vv] + 1;
                    int val = par.ss+1;
                    if(val==4) val = 1;
                    pq.push({{x,y},val});
                    if(grid[x][y]=='E'){
                        flag = true;
                        break;
                    }
                }
            }
        }
    }
}

int main()
{
    //read;
    //write;

    int t; scanf("%d",&t);
    while(t--){
        mem(level,-1);
        scanf("%d %d",&r,&c);
        pii src,des;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                scanf(" %c",&grid[i][j]);
                if(grid[i][j]=='S'){
                    src = {i,j};
                }
                else if(grid[i][j]=='E'){
                    des = {i,j};
                }
            }
        }
        bfs(src);
        bool flag = false;
        for(int i=1;i<=3;i++){
            if(level[des.ff][des.ss][i]!=-1){
                printf("%d\n",level[des.ff][des.ss][i]);
                flag = true;
                break;
            }
        }
        if(!flag) puts("NO");
    }

    return 0;
}
