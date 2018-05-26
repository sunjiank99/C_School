#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 20
#define infoType int
#define VertexType char
typedef struct ArcNode
{
   int adjvex;        //�û���ָ��Ķ���λ��
   struct ArcNode  *nextarc;   //ָ����һ������ָ��
   infoType *info;   //�û������Ϣ��ָ��

} ArcNode;

typedef struct VNode

{
	VertexType data ;   //�������Ϣ
	ArcNode *firstarc;   //ָ���һ�������ö���Ļ���ָ��

} VNode,AdjList[MAX_VERTEX_NUM];

typedef struct
{
   AdjList vertices;
   int vexnum,arcnum;   //ͼ�ĵ�ǰ�������ͻ���
   int kind;            //ͼ������ͱ�־
} ALGraph;

int LocateVex(ALGraph G,char v)
{    int i;
	for(i=0;i<G.vexnum;i++)
	{
		if(v==G.vertices[i].data)
		{
		   return i;
		}
	}
}
int CreateList(ALGraph *G,int i,ArcNode *p)
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
int CreateAL(ALGraph *G)  //�����ڽӱ�
{
	ArcNode *p;int i;
	int k;
	puts("����������ͼ�Ľڵ����ͱ�����%d %d��");
	scanf_s("%d %d",&G->vexnum,&G->arcnum);
	fflush(stdin);
	
	puts("������ڵ������");

	for(i=0;i<G->vexnum;i++)
	{   
		scanf("%c",&G->vertices[i].data);
		fflush(stdin);     //����ڵ���Ϣ
		G->vertices[i].firstarc=NULL;
	}
	puts("���������ڵĽڵ㣨%c %c��");
	for( k=0;k<G->arcnum;k++)
	{   char v1,v2;
	    int i,j;
	    scanf("%c %c",&v1,&v2);fflush(stdin);     //������

	    i=LocateVex(*G,v1); j=LocateVex(*G,v2);
		p=(ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex=j;
		p->nextarc=NULL;

		CreateList(G,i,p);
    }
	return 0;
}

int AlterMat(ArcNode *p,int k,int *AdjMat)    //�޸ľ���
		{
			int i=p->adjvex;
			AdjMat[i*MAX_VERTEX_NUM+k]=1;
			AdjMat[k*MAX_VERTEX_NUM+i]=1;


			if(p->nextarc!=NULL)
				{    p=p->nextarc;
					AlterMat(p,k,AdjMat);
				}
				return 1;
		}
	    
	
		int Visit(ALGraph *G,int k,int *AdjMat)  //��������
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

	puts("�ڽӾ���Ϊ��");
	OutputAdj(&G); 
	


	system("pause");

}
