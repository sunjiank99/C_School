#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<time.h>



void main()


{
   A:  puts("��ѡ���ܣ�1ע�ᣬ2���룬3����,4�˳�");
     int number;
     
     scanf("%d",&number);
     fflush(stdin);
     
     if(number==1)//ע���� 
     {  
       FILE *input,*output,*output1,*output3;
       
     
       char a[30],filename[30],passname[30],youxiang[30];
       short lenth;
       
      
       //�����ļ������˻���Ϣ 
       
          puts("��������Ҫע����û�����"); 
          gets(a);
          sprintf(filename,"%s.txt",a);
          sprintf(passname,"%smima.txt",a);//�����ļ� 
          sprintf(youxiang,"%s@.txt",a);
          output=fopen(filename,"at");
          
          fputs(" �û���:",output);
          fputs(a,output);
          memset(a,30,sizeof(char));
          fputs("\n",output);
          fclose(output);
       
       
       
        output=fopen(filename,"at");
        output3=fopen(youxiang,"at");
       puts("��������Ҫע������䣺"); 
          fputs(" ����:",output);
          
          gets(a);
          fputs(a,output);
          fputs(a,output3);
          memset(a,30,sizeof(char));
          fputs("\n",output);
          fclose(output3);
          fclose(output);
          
        output1=fopen(passname,"at");
       
          puts("��������Ҫע������룺"); 
          gets(a);
          fputs(a,output1);
          memset(a,30,sizeof(char));
          
          
          fclose(output1);
          
          
          
       puts("��ѡ����Ҫע������");
       puts("1ѧ�� 2��ʦ 3�ҳ� 4 �����û� 5ƽ̨���� ");
       
       
       int shenfen;
       
       scanf("%d",&shenfen); 
       puts("ע��ɹ���������������") ; 
       fflush(stdin);
       
       if(shenfen==1)//  ѧ����  
       {  output=fopen(filename,"at");
                         
         fputs("��ݣ�ѧ��\n",output);
         
         puts("�������ǳƣ�"); 
          fputs(" �ǳ�:",output);
          gets(a);
          fputs(a,output);
          memset(a,30,sizeof(char));
          fputs("\n",output);
          fputs("\n",output);
          fclose(output);
         
          output=fopen(filename,"at");
        puts("������������"); 
          fputs(" ����:",output);
          gets(a);
          fputs(a,output);
          memset(a,30,sizeof(char));
          fputs("\n",output);
          fputs("\n",output);
          fclose(output);
         
          output=fopen(filename,"at");
         puts("�������Ա���Ů��"); 
          fputs(" �ǳ�:",output);
          gets(a);
          fputs(a,output);
          memset(a,30,sizeof(char));
          fputs("\n",output);
          fputs("\n",output);
          fclose(output);
         
          output=fopen(filename,"at");
         puts("������ʡ�ݣ�"); 
          fputs(" ʡ��:",output);
          gets(a);
          fputs(a,output);
          memset(a,30,sizeof(char));
          fputs("\n",output);
          fputs("\n",output);
          fclose(output);
        
         output=fopen(filename,"at");
        puts("��������У�"); 
          fputs(" ����:",output);
          gets(a);
          fputs(a,output);
          memset(a,30,sizeof(char));
          fputs("\n",output);
          fputs("\n",output);
          fclose(output);
         
         output=fopen(filename,"at");
        puts("���������أ�"); 
          fputs(" ����:",output);
          gets(a);
          fputs(a,output);
          memset(a,30,sizeof(char));
          fputs("\n",output);
          fputs("\n",output);
          fclose(output);
          
          output=fopen(filename,"at");
         puts("���������ͣ�"); 
          fputs(" ����:",output);
          gets(a);
          fputs(a,output);
          memset(a,30,sizeof(char));
          fputs("\n",output);
          fputs("\n",output);
          fclose(output);
         
          output=fopen(filename,"at");
        puts("�������꼶��"); 
          fputs(" �꼶:",output);
          gets(a);
          fputs(a,output);
          memset(a,30,sizeof(char));
          fputs("\n",output);
          fputs("\n",output);
          fclose(output);
         
          output=fopen(filename,"at");
         puts("������༶��"); 
          fputs(" �༶:",output);
          gets(a);
          fputs(a,output);
          memset(a,30,sizeof(char));
          fputs("\n",output);
          fputs("\n",output);
          fclose(output);
         
          output=fopen(filename,"at");
         puts("�������Ŀ�汾��"); 
          fputs(" ��Ŀ�汾:",output);
          gets(a);
          fputs(a,output);
          memset(a,30,sizeof(char));
          fputs("\n",output);
          fputs("\n",output);
          fclose(output);
         
         
          
         
                     
       }
       
       if(shenfen==2)//  ��ʦ�� 
       { 
         output=fopen(filename,"at");
         puts("�������ǳƣ�"); 
         fputs("�ǳƣ�",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         
        
         puts("������������"); 
         fputs("������",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         
         puts("�������Ա���/Ů����"); 
         fputs("�Ա�",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("���������գ�"); 
         fputs("���գ�",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         
         puts("������ʡ�ݣ�"); 
         fputs("ʡ�ݣ�",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("��������У�"); 
         fputs("���У�",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("���������أ�"); 
         fputs("���أ�",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("���������ڿ�Ŀ��"); 
         fputs("���ڿ�Ŀ��",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("�����븺��༶��"); 
         fputs("����༶��",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("�Ƿ�����Σ���/��"); 
         fputs("�Ƿ�����Σ�",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("��ʦ�ʸ�֤"); 
         fputs("��ʦ�ʸ�֤��",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         fclose(output);
         
         
          
         
                     
       }
       
       if(shenfen==3)//  �ҳ��� 
       { output=fopen(filename,"at");
       fputs("��ݣ��ҳ�\n",output);
         
         puts("�������ǳƣ�"); 
         fputs("�ǳƣ�",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("������������"); 
         fputs("������",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("�������Ա���/Ů����"); 
         fputs("�Ա�",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("���������գ�"); 
         fputs("���գ�",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         
         puts("������ʡ�ݣ�"); 
         fputs("ʡ�ݣ�",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("��������У�"); 
         fputs("���У�",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("���������أ�"); 
         fputs("���أ�",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("��ѧ���˺ţ�"); 
         fputs("ѧ���˺ţ�",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         fclose(output);
         
         }
         
         if(shenfen==4)//  �����û��� 
       { output=fopen(filename,"at");
         fputs("��ݣ������û�\n",output);
         
         puts("�������ǳƣ�"); 
         fputs("�ǳƣ�",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("������������"); 
         fputs("������",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("�������Ա���/Ů����"); 
         fputs("�Ա�",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("���������գ�"); 
         fputs("���գ�",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         
         puts("������ʡ�ݣ�"); 
         fputs("ʡ�ݣ�",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("��������У�"); 
         fputs("���У�",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("���������أ�"); 
         fputs("���أ�",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("�������ͣ�"); 
         fputs("�������ͣ�",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         fclose(output);
         
         }
         
          if(shenfen==5)//  ƽ̨������ 
       { output=fopen(filename,"at");
         fputs("��ݣ�ƽ̨����\n",output);
         
         puts("�������ǳƣ�"); 
         fputs("�ǳƣ�",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("������������"); 
         fputs("������",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("�������Ա���/Ů����"); 
         fputs("�Ա�",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("���������գ�"); 
         fputs("���գ�",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         
         puts("������ʡ�ݣ�"); 
         fputs("ʡ�ݣ�",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("��������У�"); 
         fputs("���У�",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("���������أ�"); 
         fputs("���أ�",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         
         }
         fputs("\n\n\n",output);
         
         fclose(output);
         
         goto A;
       
       
       
       
       
        
       
       
        
     system("pause");
     
     }
     
     //     �˳��� 
     if(number==4)
     {return;}
     
     
     //    �û������� 
     
     if(number==2)
     
     { char id[30],id1[30],id2[30]; 
       char password[30],password1[30];//�����ļ������� 
       
       FILE *duqu,*duqu1,*duqu2;
        
         
                  
    B:   puts("�������û���");
       
       gets(id);
       sprintf(id1,"%smima.txt",id);
       sprintf(id,"%s.txt",id);
       sprintf(id2,"%s",id);
       
       
       duqu=fopen(id,"rt");//���ļ� 
       
       if(duqu==NULL)
       {printf("û������û���\n"); 
         goto A;            }
      C: puts("����������");
       
       gets(password);
       
       duqu1=fopen(id1,"rt");
       fseek(duqu1,0*sizeof(char),SEEK_SET);
      fgets(password1,20,duqu1);
      
      
      
     if(strcmp(password,password1)==0)
      { puts(" ����ɹ�"); 
        puts(" ������Ϣ��");
        
        
        duqu2=fopen(id2,"rt");
        char ch;
        
        for(;(ch=fgetc(duqu2))!=EOF;)
        { 
        printf("%c",ch);
                               }
        puts(id2);                       
        fclose(duqu2);                       
        
      }
      else
      { memset(password,30,sizeof(char));
        memset(password1,30,sizeof(char));
          puts("���������������������"); 
          goto C;
      }
      
      fclose(duqu);
      fclose(duqu1);
       
        
        system("pause");
       
       }
       //������ 
       
       if(number==3)
       {char zhanghao[30],zhanghao1[30],email[30],email1[30],mima[30],zhanghao3[30];
       FILE *dakai,*xiugai;
       
        puts("�����������˺�");
        
        gets(zhanghao);
        
        sprintf(zhanghao1,"%s@.txt",zhanghao);
        sprintf(zhanghao3,"%smima.txt",zhanghao);
        
        dakai=fopen(zhanghao1,"rt");
        
        if(dakai==NULL)
        {puts("���˻�δע��"); 
        goto A;
        }
        
        puts("��������ע������䣺");
        
        gets(email);
        
        fgets(email1,20,dakai);
        
        
        
        
        
        if(strcmp(email,email1)==0)
        {
            T:puts("���������·���֤��");
            int suijihaoma,i;int haoma[5];char haoma1[6],haoma2[6]; 
            srand((unsigned)time(NULL));
            for(i=0;i<5;i++)
            {suijihaoma=rand()%10;
            
             haoma[i]=suijihaoma;
             printf("%d",haoma[i]);
             haoma1[i]=haoma[i]+'0'; 
             
            }
            haoma1[5]=0;
            printf("\n");
            gets(haoma2);
            
            
            
            
            if(strcmp(haoma1,haoma2)==0)
            { puts("������������"); 
              gets(mima);
              xiugai=fopen(zhanghao3,"w");
              if(xiugai==NULL)
              {puts("�޸�ʧ�ܣ�");
              goto A; 
                              }
              fputs(mima,xiugai);
              puts("�޸ĳɹ���");
              fclose(xiugai);
              
              goto A;                          
                                        
                                        
                                        
            }
            else
            {puts("��֤��������ٴ�����"); 
            goto T;
            }
            
            
            
            
            
            
                                  
        }
        else
        {puts("δ�󶨴�����");
        memset(email,30,sizeof(char));
        memset(email1,30,sizeof(char));
        goto A;
         }
         
         fclose(dakai);
         fclose(dakai);
        system("pause");
        
        
        
        
        
         
        
        
        
        
        
        
                    
                    
                    
                    
       } 
                  
                  
} 



     
     
     
     
     
     
     
     
      
     
     
