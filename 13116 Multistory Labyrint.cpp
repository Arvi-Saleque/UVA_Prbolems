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
#define FAST  ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define sqr(x) ((x)*(x))
#define endl '\n'

using ll = long long int;
const ll sz = 101;
const ll mod = 1000000007;

int kx[] = {1,-1,0,0,0,0};
int ky[] = {0,0,1,-1,0,0};
int kz[] = {0,0,0,0,1,-1};

struct node{
    int flr,cx,cy;
    node(){};
    node(int _f, int _x, int _y){
        cx = _x;
        cy = _y;
        flr = _f;
    }
};

int l,w,h,dis[sz][sz][sz];
char grid[sz][sz][sz];
bool vis[sz][sz][sz];
node start,fn;

bool valid(int x,int y,int z){
    if(x >= 1 && x <= l && y >= 1 && y <= w && z >= 1 && z <= h) return true;
    else return false;
}

void bfs(){
    queue<node> pq;
    pq.push(start);
    dis[start.flr][start.cx][start.cy]  = 0;
    vis[start.flr][start.cx][start.cy]  = 1;
    bool flag = false;
    while(!pq.empty()){
        node par = pq.front();
        pq.pop();
        for(int i=0;i<6;i++){
            int x = par.cx + kx[i];
            int y = par.cy + ky[i];
            int z = par.flr + kz[i];
            if(valid(x,y,z)){
                if(grid[z][x][y]=='#') continue;
                if(i==4 || i==5){
                    if(grid[par.flr][par.cx][par.cy]!='-' || grid[z][x][y]!='-') continue;
                }
                if(vis[z][x][y]) continue;
                vis[z][x][y] = 1;
                dis[z][x][y] = dis[par.flr][par.cx][par.cy] + 1;
                pq.push(node(z,x,y));
                if(grid[z][x][y]=='E'){
                    flag = true;
                    break;
                }
            }
        }
        if(flag) break;
    }
}


int main()
{
    FAST;
    //write;
    //read;
    while(1){
        mem(dis,-1);
        mem(vis,0);
        cin >> l >> w >> h;
        if(l == 0 && w == 0 && h == 0) break;
        for(int k=1;k<=h;k++){
            for(int i=1;i<=l;i++){
                for(int j=1;j<=w;j++){
                    cin >> grid[k][i][j];
                    if(grid[k][i][j]=='S') start = node(k,i,j);
                    if(grid[k][i][j]=='E') fn = node(k,i,j);
                }
            }
        }

        bfs();
        //printf("%d\n",vis[fn.cx][fn.cy][fn.flr]);
        cout << dis[fn.flr][fn.cx][fn.cy] << endl;
    }

    return 0;
}
