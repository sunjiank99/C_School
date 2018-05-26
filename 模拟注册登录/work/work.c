#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<time.h>



void main()


{
   A:  puts("请选择功能：1注册，2登入，3找密,4退出");
     int number;
     
     scanf("%d",&number);
     fflush(stdin);
     
     if(number==1)//注册区 
     {  
       FILE *input,*output,*output1,*output3;
       
     
       char a[30],filename[30],passname[30],youxiang[30];
       short lenth;
       
      
       //本地文件储存账户信息 
       
          puts("请输入您要注册的用户名："); 
          gets(a);
          sprintf(filename,"%s.txt",a);
          sprintf(passname,"%smima.txt",a);//密码文件 
          sprintf(youxiang,"%s@.txt",a);
          output=fopen(filename,"at");
          
          fputs(" 用户名:",output);
          fputs(a,output);
          memset(a,30,sizeof(char));
          fputs("\n",output);
          fclose(output);
       
       
       
        output=fopen(filename,"at");
        output3=fopen(youxiang,"at");
       puts("请输入您要注册的邮箱："); 
          fputs(" 邮箱:",output);
          
          gets(a);
          fputs(a,output);
          fputs(a,output3);
          memset(a,30,sizeof(char));
          fputs("\n",output);
          fclose(output3);
          fclose(output);
          
        output1=fopen(passname,"at");
       
          puts("请输入您要注册的密码："); 
          gets(a);
          fputs(a,output1);
          memset(a,30,sizeof(char));
          
          
          fclose(output1);
          
          
          
       puts("请选择您要注册的身份");
       puts("1学生 2老师 3家长 4 渠道用户 5平台代理 ");
       
       
       int shenfen;
       
       scanf("%d",&shenfen); 
       puts("注册成功，请您完善资料") ; 
       fflush(stdin);
       
       if(shenfen==1)//  学生区  
       {  output=fopen(filename,"at");
                         
         fputs("身份：学生\n",output);
         
         puts("请输入昵称："); 
          fputs(" 昵称:",output);
          gets(a);
          fputs(a,output);
          memset(a,30,sizeof(char));
          fputs("\n",output);
          fputs("\n",output);
          fclose(output);
         
          output=fopen(filename,"at");
        puts("请输入姓名："); 
          fputs(" 姓名:",output);
          gets(a);
          fputs(a,output);
          memset(a,30,sizeof(char));
          fputs("\n",output);
          fputs("\n",output);
          fclose(output);
         
          output=fopen(filename,"at");
         puts("请输入性别男女："); 
          fputs(" 昵称:",output);
          gets(a);
          fputs(a,output);
          memset(a,30,sizeof(char));
          fputs("\n",output);
          fputs("\n",output);
          fclose(output);
         
          output=fopen(filename,"at");
         puts("请输入省份："); 
          fputs(" 省份:",output);
          gets(a);
          fputs(a,output);
          memset(a,30,sizeof(char));
          fputs("\n",output);
          fputs("\n",output);
          fclose(output);
        
         output=fopen(filename,"at");
        puts("请输入城市："); 
          fputs(" 城市:",output);
          gets(a);
          fputs(a,output);
          memset(a,30,sizeof(char));
          fputs("\n",output);
          fputs("\n",output);
          fclose(output);
         
         output=fopen(filename,"at");
        puts("请输入区县："); 
          fputs(" 区县:",output);
          gets(a);
          fputs(a,output);
          memset(a,30,sizeof(char));
          fputs("\n",output);
          fputs("\n",output);
          fclose(output);
          
          output=fopen(filename,"at");
         puts("请输入类型："); 
          fputs(" 类型:",output);
          gets(a);
          fputs(a,output);
          memset(a,30,sizeof(char));
          fputs("\n",output);
          fputs("\n",output);
          fclose(output);
         
          output=fopen(filename,"at");
        puts("请输入年级："); 
          fputs(" 年级:",output);
          gets(a);
          fputs(a,output);
          memset(a,30,sizeof(char));
          fputs("\n",output);
          fputs("\n",output);
          fclose(output);
         
          output=fopen(filename,"at");
         puts("请输入班级："); 
          fputs(" 班级:",output);
          gets(a);
          fputs(a,output);
          memset(a,30,sizeof(char));
          fputs("\n",output);
          fputs("\n",output);
          fclose(output);
         
          output=fopen(filename,"at");
         puts("请输入科目版本："); 
          fputs(" 科目版本:",output);
          gets(a);
          fputs(a,output);
          memset(a,30,sizeof(char));
          fputs("\n",output);
          fputs("\n",output);
          fclose(output);
         
         
          
         
                     
       }
       
       if(shenfen==2)//  老师区 
       { 
         output=fopen(filename,"at");
         puts("请输入昵称："); 
         fputs("昵称：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         
        
         puts("请输入姓名："); 
         fputs("姓名：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         
         puts("请输入性别（男/女）："); 
         fputs("性别：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("请输入生日："); 
         fputs("生日：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         
         puts("请输入省份："); 
         fputs("省份：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("请输入城市："); 
         fputs("城市：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("请输入区县："); 
         fputs("区县：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("请输入所授科目："); 
         fputs("所授科目：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("请输入负责班级："); 
         fputs("负责班级：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("是否班主任（是/否）"); 
         fputs("是否班主任：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("教师资格证"); 
         fputs("教师资格证：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         fclose(output);
         
         
          
         
                     
       }
       
       if(shenfen==3)//  家长区 
       { output=fopen(filename,"at");
       fputs("身份：家长\n",output);
         
         puts("请输入昵称："); 
         fputs("昵称：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("请输入姓名："); 
         fputs("姓名：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("请输入性别（男/女）："); 
         fputs("性别：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("请输入生日："); 
         fputs("生日：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         
         puts("请输入省份："); 
         fputs("省份：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("请输入城市："); 
         fputs("城市：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("请输入区县："); 
         fputs("区县：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("绑定学生账号："); 
         fputs("学生账号：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         fclose(output);
         
         }
         
         if(shenfen==4)//  渠道用户区 
       { output=fopen(filename,"at");
         fputs("身份：渠道用户\n",output);
         
         puts("请输入昵称："); 
         fputs("昵称：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("请输入姓名："); 
         fputs("姓名：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("请输入性别（男/女）："); 
         fputs("性别：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("请输入生日："); 
         fputs("生日：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         
         puts("请输入省份："); 
         fputs("省份：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("请输入城市："); 
         fputs("城市：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("请输入区县："); 
         fputs("区县：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("渠道类型："); 
         fputs("渠道类型：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         fclose(output);
         
         }
         
          if(shenfen==5)//  平台代理区 
       { output=fopen(filename,"at");
         fputs("身份：平台代理\n",output);
         
         puts("请输入昵称："); 
         fputs("昵称：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("请输入姓名："); 
         fputs("姓名：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("请输入性别（男/女）："); 
         fputs("性别：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("请输入生日："); 
         fputs("生日：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         
         puts("请输入省份："); 
         fputs("省份：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("请输入城市："); 
         fputs("城市：",output);
         gets(a);
         fputs(a,output);
         memset(a,30,sizeof(char));
         fputs("\n",output) ;
         
         puts("请输入区县："); 
         fputs("区县：",output);
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
     
     //     退出区 
     if(number==4)
     {return;}
     
     
     //    用户登入区 
     
     if(number==2)
     
     { char id[30],id1[30],id2[30]; 
       char password[30],password1[30];//本地文件缓冲区 
       
       FILE *duqu,*duqu1,*duqu2;
        
         
                  
    B:   puts("请输入用户名");
       
       gets(id);
       sprintf(id1,"%smima.txt",id);
       sprintf(id,"%s.txt",id);
       sprintf(id2,"%s",id);
       
       
       duqu=fopen(id,"rt");//打开文件 
       
       if(duqu==NULL)
       {printf("没有这个用户名\n"); 
         goto A;            }
      C: puts("请输入密码");
       
       gets(password);
       
       duqu1=fopen(id1,"rt");
       fseek(duqu1,0*sizeof(char),SEEK_SET);
      fgets(password1,20,duqu1);
      
      
      
     if(strcmp(password,password1)==0)
      { puts(" 登入成功"); 
        puts(" 您的信息：");
        
        
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
          puts("密码错误，请重新输入密码"); 
          goto C;
      }
      
      fclose(duqu);
      fclose(duqu1);
       
        
        system("pause");
       
       }
       //改密区 
       
       if(number==3)
       {char zhanghao[30],zhanghao1[30],email[30],email1[30],mima[30],zhanghao3[30];
       FILE *dakai,*xiugai;
       
        puts("请输入您的账号");
        
        gets(zhanghao);
        
        sprintf(zhanghao1,"%s@.txt",zhanghao);
        sprintf(zhanghao3,"%smima.txt",zhanghao);
        
        dakai=fopen(zhanghao1,"rt");
        
        if(dakai==NULL)
        {puts("此账户未注册"); 
        goto A;
        }
        
        puts("请输入你注册的邮箱：");
        
        gets(email);
        
        fgets(email1,20,dakai);
        
        
        
        
        
        if(strcmp(email,email1)==0)
        {
            T:puts("请您输入下方验证码");
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
            { puts("请输入新密码"); 
              gets(mima);
              xiugai=fopen(zhanghao3,"w");
              if(xiugai==NULL)
              {puts("修改失败！");
              goto A; 
                              }
              fputs(mima,xiugai);
              puts("修改成功！");
              fclose(xiugai);
              
              goto A;                          
                                        
                                        
                                        
            }
            else
            {puts("验证码错误，请再次输入"); 
            goto T;
            }
            
            
            
            
            
            
                                  
        }
        else
        {puts("未绑定此邮箱");
        memset(email,30,sizeof(char));
        memset(email1,30,sizeof(char));
        goto A;
         }
         
         fclose(dakai);
         fclose(dakai);
        system("pause");
        
        
        
        
        
         
        
        
        
        
        
        
                    
                    
                    
                    
       } 
                  
                  
} 



     
     
     
     
     
     
     
     
      
     
     
