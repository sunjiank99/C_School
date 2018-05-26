#include<stdio.h>
#define size 5
#include"color.h"
struct node_area  //�ڵ�����
{
   int node[3][3];
   int up;
   int down;
   int left;
   int right;
   int count;
   int wentcount;     // ������
   int printcount;
} ;
struct node_path
{
   int y;
   int x;

};
typedef struct node_path  PATH;

typedef struct node_area NODE;
NODE node[size][size];
PATH path[size*size];
int startx,starty;
int endx,endy;
int pathcount=0;

initnode()     //��ʼ���ڵ�����
{
    int hang,lie;
    int nodecountx,nodecounty;
    for(nodecounty=0;nodecounty<size;nodecounty++)
     {
       for(nodecountx=0;nodecountx<size;nodecountx++)
       {
       for(lie=0;lie<3;lie++)
        {
         for(hang=0;hang<3;hang++)
             {
                node[nodecounty][nodecountx].node[lie][hang]=0;
             }
        }
       }

     }
}
inithinder()   //�����ϰ�
{
      srand((int)time(NULL));
      int flag;
      int nodecountx,nodecounty;
      for(nodecounty=0;nodecounty<size;nodecounty++)
      {
         for(nodecountx=0;nodecountx<size;nodecountx++)
      {
         flag=rand()%2;
         if(flag==1)    //�������ϰ�
         {
                node[nodecounty][nodecountx].node[0][2]=1;
                node[nodecounty][nodecountx].node[1][2]=1;
                node[nodecounty][nodecountx].node[2][2]=1;
         }
         else            //�������ϰ�
         {
                node[nodecounty][nodecountx].node[2][0]=1;
                node[nodecounty][nodecountx].node[2][1]=1;
                node[nodecounty][nodecountx].node[2][2]=1;

         }
      }
      }
}
outputmatrix()//�������
{
     int coorx,coory; // ����x��y��
     int xd=0,yd=0;


     for(coorx=0;coorx<size*3;coorx++)
     {   if(coorx%3==1)
         {printf("%9d",xd);
           xd++;
         }
     }
     printf("\n");
     for(coory=0;coory<size*3;coory++)
      {    if(coory%3==1)
          {
           printf("%3d",yd);
           yd++;
          }
          else
          {printf("   ");
          }
          for(coorx=0;coorx<size*3;coorx++)

        {    if(node[coory/3][coorx/3].node[coory%3][coorx%3]==1)

           {
              BLACK_RED;

             printf("%3d",node[coory/3][coorx/3].node[coory%3][coorx%3]);
              BLACK_WHITE;
           }
            else
            {
                printf("%3d",node[coory/3][coorx/3].node[coory%3][coorx%3]);

            }

        }
          printf("\n");

       }

}

init_direction()
{
    int nodecountx,nodecounty;
    for(nodecounty=0;nodecounty<size;nodecounty++)
    {
        for(nodecountx=0;nodecountx<size;nodecountx++)
        {
            node[nodecounty][nodecountx].up=0;
            node[nodecounty][nodecountx].down=0;
            node[nodecounty][nodecountx].left=0;
            node[nodecounty][nodecountx].right=0;
            node[nodecounty][nodecountx].count=0;
            node[nodecounty][nodecountx].wentcount=0;
            node[nodecounty][nodecountx].printcount=0;
            /*node[nodecounty][nodecountx].chuup=0;
            node[nodecounty][nodecountx].chudown=0;
            node[nodecounty][nodecountx].chuleft=0;
            node[nodecounty][nodecountx].churight=0;*/

            }

    }
    for(nodecountx=0;nodecountx<size;nodecountx++)
    {
        node[0][nodecountx].up=1;
        node[size-1][nodecountx].down=1;
        node[nodecountx][0].left=1;
        node[nodecountx][size-1].right=1;
    }



}
init_outcount()
{
  int countx,county;
  for(county=0;county<size;county++)
  {
     for(countx=0;countx<size;countx++)
     {
           if(node[county][countx].node[0][1]==0&&node[county-1][countx].node[2][1]==0&&county!=0)   //���ϳ��ڣ�
           {
              node[county][countx].count++;
           }
           if(node[county][countx].node[2][1]==0&&node[county+1][countx].node[0][1]==0&&county!=size-1)    // ���³��ڣ�
           {
              node[county][countx].count++;
           }
           if(node[county][countx].node[1][0]==0&&node[county][countx-1].node[1][2]==0&&countx!=0)    //������ڣ�
            {
               node[county][countx].count++;
            }
            if(node[county][countx].node[1][2]==0&&node[county][countx+1].node[1][0]==0&&countx!=size-1)  //���ҳ��ڣ�

             {
                 node[county][countx].count++;
             }
     }

  }

}


int go(int y,int x)
{    //printf("(%d,%d)\n",y,x);
     if(x==endx&&y==endy)
     {
          printf("���Ե���\n");
          return 1;
     }

     if(node[y][x].up==0&&node[y][x].node[0][1]==0&&node[y-1][x].node[2][1]==0&&node[y-1][x].down==0) // ������
     {
          node[y][x].up=1;
          node[y][x].wentcount++;
          path[pathcount].y=y;
          path[pathcount].x=x;
          pathcount++;
          y=y-1;
          go(y,x);

     }

     else if(node[y][x].down==0&&node[y][x].node[2][1]==0&&node[y+1][x].node[0][1]==0&&node[y+1][x].up==0)  // ������
     {
         node[y][x].down=1;
         node[y][x].wentcount++;
         path[pathcount].y=y;
          path[pathcount].x=x;
          pathcount++;
         y=y+1;
         go(y,x);
     }
     else if(node[y][x].left==0&&node[y][x].node[1][0]==0&&node[y][x-1].node[1][2]==0&&node[y][x-1].right==0)   //������
     {
         node[y][x].left=1;
         node[y][x].wentcount++;
         path[pathcount].y=y;
          path[pathcount].x=x;
          pathcount++;
         x=x-1;
         go(y,x);
     }
     else if(node[y][x].right==0&&node[y][x].node[1][2]==0&&node[y][x+1].node[1][0]==0&&node[y][x+1].left==0)   //������
     {
         node[y][x].right=1;
         node[y][x].wentcount++;
         path[pathcount].y=y;
          path[pathcount].x=x;
          pathcount++;
         x=x+1;
         go(y,x);
     }
     else if(node[y][x].up==0&&node[y][x].node[0][1]==0&&node[y-1][x].node[2][1]==0&&node[y-1][x].down==1)// �ٴ�������
     {
          node[y][x].up=1;
          node[y][x].wentcount++;
          path[pathcount].y=y;
          path[pathcount].x=x;
          pathcount++;
          y=y-1;
          go(y,x);
     }
      else if(node[y][x].down==0&&node[y][x].node[2][1]==0&&node[y+1][x].node[0][1]==0&&node[y+1][x].up==1)  //  �ٴ�������
     {
         node[y][x].down=1;
         node[y][x].wentcount++;
         path[pathcount].y=y;
          path[pathcount].x=x;
          pathcount++;
         y=y+1;
         go(y,x);
     }
      else if(node[y][x].left==0&&node[y][x].node[1][0]==0&&node[y][x-1].node[1][2]==0&&node[y][x-1].right==1)   //�ٴ�������
     {
         node[y][x].left=1;
         node[y][x].wentcount++;
         path[pathcount].y=y;
          path[pathcount].x=x;
          pathcount++;
         x=x-1;
         go(y,x);
     }
     else if(node[y][x].right==0&&node[y][x].node[1][2]==0&&node[y][x+1].node[1][0]==0&&node[y][x+1].left==1)   //�ٴ�������
     {
         node[y][x].right=1;
         node[y][x].wentcount++;
         path[pathcount].y=y;
          path[pathcount].x=x;
          pathcount++;
         x=x+1;
         go(y,x);
     }
       else
     {
         //printf("û��ͨ·");
         return 0;
     }





}
outputpath()
{     printf("\n·��Ϊ\n(%d,%d)\n",starty,startx);
      int i;
      for(i=0;i<size*size;i++)
      {
         if(node[path[i].y][path[i].x].wentcount==2&&node[path[i].y][path[i].x].count==2||node[path[i].y][path[i].x].wentcount==3)
         {
             continue;
         }
         if(node[path[i].y][path[i].x].count!=1&&node[path[i].y][path[i].x].printcount==0)
         {
          node[path[i].y][path[i].x].printcount++;
         printf("(%d,%d)",path[i].y,path[i].x);
         printf("\n");
         }

      }
      printf("(%d,%d)\n",endy,endx);
}





main()
{


   initnode();
   inithinder();
   outputmatrix();
   init_direction();
   init_outcount();

   printf("�������y,x");
   scanf("%d,%d",&starty,&startx);
   printf("�������յ�y,x");
   scanf("%d,%d",&endy,&endx);
   //printf("�켣Ϊ\n");
   int flog;
   flog=go(starty,startx);


    if(flog==1)
   {
      outputpath();
    }
    if(flog==0)
    {
        puts("û��ͨ·");
    }

   system("pause");
}
