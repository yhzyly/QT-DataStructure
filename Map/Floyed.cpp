#include <stdio.h>
#include<string>
using namespace std;
#define MAXV 100
#define INF 99999

int A[MAXV][MAXV],path[MAXV][MAXV],dis;
int* c=new int[10],flag=0;//编号
typedef struct
{
    int edges[MAXV][MAXV];
    int n,e;
} Mg;
void ppath(int i,int j)
{
    if(A[i][j]!=INF&&i!=j){
    int k;
    k=path[i][j];
    if (k==-1)
        return;
    ppath(i,k);
//    printf("%d,",k);
    c[++flag]=k;
    ppath(k,j);
    dis=A[i][j];
    }
}
void DisPath(int n)
{
    int i,j;
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            if(A[i][j]!=INF&&i!=j)
            {
                printf("从%d到%d路径为:",i,j);
                printf("%d,",i);
                ppath(i,j);
                printf("%d",j);
                printf("\t路径长度为:%d\n",A[i][j]);
            }
}

void floyd(Mg g)
{
    int i,j,k,n=g.n;
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
        {
            if(g.edges[i][j])
            {
            A[i][j]=g.edges[i][j];
            path[i][j]=-1;
            }
        }
    for (k=0; k<n; k++)
    {
        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
                if (A[i][k]!=INF&&A[k][j]!=INF&&A[i][j]>(A[i][k]+A[k][j]))//注意判断条件
                {
                    A[i][j]=A[i][k]+A[k][j];
                    path[i][j]=k;
                }
    }
//    for(i=0;i<n;i++)
//       {
//for(j=0;j<n;j++)
//    {
//        printf("%d ",A[i][j]);
//    }
//    printf("\n");
//       }
//    printf("\n输出最短路径:\n");
//    DisPath(n);
}
//int main()
//{
//    Mg g;
//    scanf("%d %d",&g.n,&g.e);
//    int i,j;
//    for(i=0; i<g.n; i++)
//        for(j=0; j<g.n; j++)
//        {
//            if(i==j)
//                A[i][j]=0;
//            else
//                A[i][j]=INF;
//        }
//    for(i=g.e; i>0; i--)
//    {
//        int v1,v2,Q;
//        scanf("%d %d %d",&v1,&v2,&Q);
//        g.edges[v1][v2]=Q;
//    }
//    floyd(g);
//    return 0;
//}

string Prim(Mg g,int start)
{
   int minw[g.n+1];//store the shortest distance from visited node to node i
   int vis[g.n+1];
   int tmp=sizeof(vis) / sizeof(vis[0]);
   for (int i = 0; i < tmp; i++){
        vis[i]=0;
      minw[i]=INF;
    }
   vis[start] = 1; //add the start node into visited array
   for (int i =0; i < g.n; ++i){
      minw[i] = A[i][start];//every distance to node vis
      if(minw[i]==0) minw[i]=INF;
      }
   int index=start, mmin;
   string str=to_string(start+1);
   for (int i = 0; i < g.n-1; ++i) {
//      str+="->"+to_string(index);
      mmin = INF;
      for (int j = 0; j < g.n; ++j) //取出到Vnew中某个点边权最小的点
         if (!vis[j] && minw[j] < mmin && minw[j]!=0) index = j, mmin = minw[j];//mmin is the shortest distance to vis
      vis[index] = 1;//add node index into visited array
      str+="->"+to_string(index+1);
      // ans += mmin;
      for (int j = 0; j < g.n; ++j) //用每次新加入的点更新其他点到Vnew中点的最小边权
         if(!vis[j] && A[j][index] < minw[j] && minw[j]!=0) minw[j] = A[j][index];//update the distance if new edge has shorter length
//      cout<<"->"<<index<<" is: "<<mmin<<endl;
      str+="("+to_string(mmin)+")";
   }
   return str;
}
