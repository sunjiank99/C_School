#include<stdio.h>
#define MAX_VERTEX_NUM 20
#define InfoType  int
#define VertexType char

typedef struct ArcBox
{
  int tailvex,headvex;
  struct ArcBox *hlink,*tlink;
  InfoType *info;
} ArcBox;

typedef struct VexNode
{
     VertexType data;
     ArcBox *firstin,*firstout;
} VexNode;


typedef struct
{
    VexNode xlist[MAX_VERTEX_NUM] ;
    int vexnum,arcnum;
}OLGraph;
int LocateVex(OLGraph *G,char v)
{
   int i;

   for(i=0;i<G->vexnum;i++)
   {
       if(v==G->xlist[i].data)
       {
           return i;
       }
    }
}


int CreateDG(OLGraph *G)
{   int i,k,j;
    scanf("%d %d",&G->vexnum,&G->arcnum);
    fflush(stdin);

    for(i=0;i<G->vexnum;i++)
    {
       scanf("%c",&G->xlist[i].data); //input vexnode's name
       fflush(stdin);
       G->xlist[i].firstin=NULL;
       G->xlist[i].firstout=NULL;
    }
    for(k=0;k<G->arcnum;k++)
    {    ArcBox *p;
         char v1,v2;

         scanf("%c %c",&v1,&v2);
         fflush(stdin);
         i=LocateVex(G,v1);j=LocateVex(G,v2);
         p=(ArcBox *)malloc(sizeof(ArcBox));

         p->tailvex=i;p->headvex=j;
         p->hlink=G->xlist[j].firstin;
         p->tlink=G->xlist[i].firstout;
         G->xlist[j].firstin=G->xlist[i].firstout=p;

    }
    return 1;
}

int DFSTraverse(OLGraph *G)    //depth first search
{
    int visit[G->vexnum];
    int i;

    for(i=0;i<G->vexnum;i++)   //初始化访问标志数组
    {
        visit[i]=0;
    }

    for(i=0;i<G->vexnum;i++)
    {
        if(!visit[i])
        {
            DFS(G,i,visit);
        }

    }
    return 1;
}

int DFS( OLGraph *G,int i,int *visit)
{
    int w;
    w=next(G,i);  //找到下一个相邻节点
    visit[i]=1;
    printf("%c",G->xlist[i].data);   //访问顶点函数 可扩展
    if(w&&!visit[w])
    {
        DFS(G,w,visit);
    }

    return 1 ;

}
int next(OLGraph *G,int i)
{
     if(G->xlist[i].firstout)

    {
        return G->xlist[i].firstout->headvex;
    }
    else
    {
       return 0;
    }

}



int BFStraverse(OLGraph *G)
{

     int visit[G->vexnum];
     int i;
     ArcBox *w;
     for(i=0;i<G->vexnum;i++)
     {
        visit[i]=0;

     }


     for(i=0;i<G->vexnum;i++)
     {

               if(!visit[i])
               {
                   printf("%c",G->xlist[i].data);  //访问函数
                   visit[i]=1;
               }
               for(w=G->xlist[i].firstout;w;w=w->tlink)
               {
                   if(!visit[w->headvex])
                   {
                       visit[w->headvex]=1;
                       printf("%c",G->xlist[w->headvex].data); //访问函数
                   }

               }
           }

}









main()
{ OLGraph G;
 if(!CreateDG(&G))
 {
    puts("fail to build xlist ");
 }
 else
 {

    puts("success to build xlist");
 }
 puts("深度遍历");
 DFSTraverse(&G);
 puts("");
 puts("广度遍历");
 BFStraverse(&G);


}




