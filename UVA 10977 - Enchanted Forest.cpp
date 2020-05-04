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
const ll sz = 201;
const ll mod = 1000000007;

int kx[] = {1,-1,0,0};
int ky[] = {0,0,1,-1};

int r,c,m,x,y,n,l;
int grid[sz+1][sz+1],level[sz+1][sz+1];

bool valid(int xx,int yy){
    if(xx>=1&&xx<=r&&yy>=1&&yy<=c&&level[xx][yy]==-1&&grid[xx][yy]==-1) return true;
    else return false;
}

void bfs(){
    queue<pii> pq;
    pq.push({1,1});
    level[1][1] = 0;
    while(!pq.empty()){
        pii par = pq.front();
        pq.pop();
        for(int i=0;i<4;i++){
            int xx = par.ff + kx[i];
            int yy = par.ss + ky[i];
            if(valid(xx,yy)){
                level[xx][yy] = level[par.ff][par.ss] + 1;
                pq.push({xx,yy});
            }
        }
    }
}

int main()
{
    //read;
    //write;

    while(scanf("%d %d",&r,&c)==2){
        if(r==0 && c==0) break;
        mem(grid,-1);
        mem(level,-1);
        scanf("%d",&m);
        while(m--){
            scanf("%d %d",&x,&y);
            grid[x][y] =1;
        }
        scanf("%d",&n);
        while(n--){
            int cx,cy;
            scanf("%d %d %d",&cx,&cy,&l);
            grid[cx][cy] = 1;
            queue<pii> pq;
            pq.push({cx,cy});
            bool vis[sz+1][sz+1] = {0};
            while(!pq.empty()){
                pii par = pq.front();
                pq.pop();
                for(int i=0;i<4;i++){
                    int xx = par.ff + kx[i];
                    int yy = par.ss + ky[i];
                    if(xx>=1 && xx<=r && yy>=1 && yy<=c && vis[xx][yy]==0){
                        int a = abs(cx - xx); a *= a;
                        int b = abs(cy - yy); b *= b;
                        int s = (a+b);
                        int rad = (l*l);
                        if(s - rad <= 0){
                            grid[xx][yy] = 1;
                            vis[xx][yy]=1;
                            pq.push({xx,yy});
                        }
                    }
                }
            }
        }
        bfs();
        if(level[r][c]==-1) puts("Impossible.");
        else printf("%d\n",level[r][c]);
    }

    return 0;
}
