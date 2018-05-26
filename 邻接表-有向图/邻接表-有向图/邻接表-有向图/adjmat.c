#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 20
#define infoType int   //弧信息 可定义
#define VertexType char  //节点信息可定义
typedef struct ArcNode
{
   int adjvex;        //该弧所指向的顶点位置
   struct ArcNode  *nextarc;   //指向下一条弧的指针
   infoType *info;   //该弧相关信息的指针

} ArcNode;

typedef struct VNode

{
	VertexType data ;   //顶点信息
	ArcNode *firstarc;   //指向第一条依附该顶点的弧的指针

} VNode,AdjList[MAX_VERTEX_NUM];

typedef struct
{
   AdjList vertices;
   int vexnum,arcnum;   //图的当前顶点数和弧数
   int kind;            //图的种类和标志
} ALGraph;

int LocateVex(ALGraph G,char v)   //返回节点位置
{    int i;
	for(i=0;i<G.vexnum;i++)
	{
		if(v==G.vertices[i].data)
		{
		   return i;
		}
	}
}
int CreateList(ALGraph *G,int i,ArcNode *p)   //创建结点链表
{
if(G->vertices[i].firstarc==NULL)
{
	G->vertices[i].firstarc=p;
}
else
{      ArcNode *p0;
       p0=G->vertices[i].firstarc;
	   while(p0->nextarc!=NULL)
	{

	    p0=p0->nextarc;
	}
	p0->nextarc=p;
}
}
int CreateAL(ALGraph *G)  //创建邻接表
{
	ArcNode *p;int i;
	int k;
	puts("请输入有向图的节点数和边数（%d %d）");
	scanf_s("%d %d",&G->vexnum,&G->arcnum);
	fflush(stdin);
	
	puts("请输入节点的名称");

	for(i=0;i<G->vexnum;i++)
	{   
		scanf("%c",&G->vertices[i].data);
		fflush(stdin);     //输入节点信息
		G->vertices[i].firstarc=NULL;
	}
	puts("请输入相邻的节点（%c %c）");
	for( k=0;k<G->arcnum;k++)
	{   char v1,v2;
	    int i,j;
	    scanf("%c %c",&v1,&v2);fflush(stdin);     //输入结点

	    i=LocateVex(*G,v1); j=LocateVex(*G,v2);
		p=(ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex=j;
		p->nextarc=NULL;

		CreateList(G,i,p);
    }
	return 0;
}

int AlterMat(ArcNode *p,int k,int *AdjMat)    //修改矩阵
		{
			int i=p->adjvex;
			//AdjMat[i*MAX_VERTEX_NUM+k]=1;
			AdjMat[k*MAX_VERTEX_NUM+i]=1;


			if(p->nextarc!=NULL)
				{    p=p->nextarc;
					AlterMat(p,k,AdjMat);
				}
				return 1;
		}
	    
	
		int Visit(ALGraph *G,int k,int *AdjMat)  //访问链表
		{	  
				ArcNode *p;
				p=G->vertices[k].firstarc;
				if(p!=NULL)

				{AlterMat(p,k,AdjMat);}
				return 1;

		}	
int OutputAdj(ALGraph *G)
{    int a=G->vexnum;
     int k,l;
	 int AdjMat[MAX_VERTEX_NUM][MAX_VERTEX_NUM];



	 for(k=0;k<a;k++)
		{ for(l=0;l<a;l++)
		 {
		    AdjMat[k][l]=0;

		 }
	    }
	 for(k=0;k<G->vexnum;k++)
	 {   
		 
				
		Visit(G,k,&AdjMat[0][0]);
		

	 }
	 printf(" ");
	 for(k=0;k<a;k++)
	 { 
		 printf("%4c",G->vertices[k].data);
	 }
	 printf("\n");
	 for(k=0;k<a;k++)
	 {  printf("%c",G->vertices[k].data);
		 for(l=0;l<a;l++)
			{
				printf("%4d",AdjMat[k][l]);
			 }
		 printf("\n");
	 }




	
}

main()
{   ALGraph G;


	if(!CreateAL(&G))
	{
	   puts("success to build ALGraph");
	}

	puts("邻接矩阵为：");
	OutputAdj(&G); 
	


	system("pause");

}
