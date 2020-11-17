#include <stdio.h>
#include<string.h>
#include<malloc.h>
//新增学生信息，修改学生信息，删除学生信息，按学号，姓名查看修改某学生详细信息
void init1(char *f);//文件导入
void addstu(char* s);//add
void delstu(char *s);//del1
void delstu2(char *s);//del2
void modstu(char* cnum,char *s);//mod1
void modstu2(char* cname,char* s);//mod2
void init1(char *f)
{
        FILE *info=fopen("sim/info.txt","w");
        FILE *ff=fopen(f,"r");
        char bf[100];
        while(fgets(bf,100,ff)!=NULL){
            fprintf(info,"%s",bf);
        }
        fclose(info);
        fclose(ff);
}
void addstu(char *s)
{
    FILE* f=fopen("sim/info.txt","a");
    fprintf(f,"%s",s);
    fclose(f);
}
void delstu(char *s)
{
    FILE* f=fopen("sim/info.txt","r");
    FILE* copy=fopen("sim/copy.txt","w");
    char bf[100],num[10];
    while(fgets(bf,100,f)!=NULL){
        int i=0;
        for(i=0;i<strlen(bf);i++){
            if(bf[i]==' ')
                break;
            num[i]=bf[i];
        }
        num[i]='\0';
        if(strcmp(num,s)==0){
            continue;
        }
        fprintf(copy,"%s",bf);
    }
    fclose(f);
    fclose(copy);
    f=fopen("sim/info.txt","w");
    copy=fopen("sim/copy.txt","r");
    while(fgets(bf,100,copy)!=NULL){
        fprintf(f,"%s",bf);
    }
    fclose(f);
    fclose(copy);
}
void delstu2(char *s)
{
    FILE* f=fopen("sim/info.txt","r");
    FILE* copy=fopen("sim/copy.txt","w");
    char bf[100],num[7];
    while(fgets(bf,100,f)!=NULL){
        int k=0,j=0;
        for(int i=0;i<strlen(bf);i++){
            if(bf[i]==' '){
                j++;
                continue;
            }
            if(j==2){
                break;
            }
            if(j==1){
                num[k]=bf[i];
                num[k+1]='\0';
                k++;
            }
        }
        if(strcmp(num,s)==0){
            continue;
        }
        fprintf(copy,"%s",bf);
    }
    fclose(f);
    fclose(copy);
    f=fopen("sim/info.txt","w");
    copy=fopen("sim/copy.txt","r");
    while(fgets(bf,100,copy)!=NULL){
        fprintf(f,"%s",bf);
    }
    fclose(f);
    fclose(copy);
}
void modstu(char* cnum,char* s)
{
    FILE* logst=fopen("log.txt","a");
    FILE* f=fopen("sim/info.txt","r");
    FILE* copy=fopen("sim/copy.txt","w");
    char num[8],bf[100];
    while(fgets(bf,100,f)!=NULL){
        for(int i=0;i<strlen(bf);i++){
            if(bf[i]==' '){
                break;
            }
            num[i]=bf[i];
            num[i+1]='\0';
        }
        if(strcmp(cnum,num)==0){
            bf[strlen(bf)-1]='\0';
            fprintf(logst,"学生信息：(将) %s (修改为) %s",bf,s);
            int i;
            for(i=0;i<strlen(s);i++){
                bf[i]=s[i];
            }
            bf[i]='\0';
        }
        fprintf(copy,"%s",bf);
    }
    fclose(f);
    fclose(copy);
    f=fopen("sim/info.txt","w");
    copy=fopen("sim/copy.txt","r");
    while(fgets(bf,100,copy)!=NULL){
        fprintf(f,"%s",bf);
    }
    fclose(f);
    fclose(copy);
}
void modstu2(char* cname,char* s)
{
    FILE* logst=fopen("log.txt","a");
    FILE* f=fopen("sim/info.txt","r");
    FILE* copy=fopen("sim/copy.txt","w");
    char num[8],bf[100];
    while(fgets(bf,100,f)!=NULL){
        int i,j=0,k=0;
        for(int i=0;i<strlen(bf);i++){
            if(bf[i]==' '){
                j++;
                continue;
            }
            if(j==2){
                break;
            }
            if(j==1){
                num[k]=bf[i];
                num[k+1]='\0';
                k++;
            }
        }
        if(strcmp(cname,num)==0){
            bf[strlen(bf)-1]='\0';
            fprintf(logst,"学生信息：(将) %s (修改为) %s",bf,s);
            int i;
            for(i=0;i<strlen(s);i++){
                bf[i]=s[i];
            }
            bf[i]='\0';
        }
        fprintf(copy,"%s",bf);
    }
    fclose(f);
    fclose(copy);
    f=fopen("sim/info.txt","w");
    copy=fopen("sim/copy.txt","r");
    while(fgets(bf,100,copy)!=NULL){
        fprintf(f,"%s",bf);
    }
    fclose(f);
    fclose(copy);
}
