#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void init2(char* f);//课程初始化
void addcor(char* s);//add
void delcor(char *s);//del1
void delcor2(char* s);//del2
void modco(char* cnum,char* s);//mod1
void nodco2(char* cname,char*s);//mod2
void modco2(char* cname,char* s)
{
    FILE* logst=fopen("log.txt","a");
    FILE* f=fopen("scm/infoco.txt","r");
    FILE* copy=fopen("scm/copy.txt","w");
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
            fprintf(logst,"课程信息：(将) %s (修改为) %s",bf,s);
            for(i=0;i<strlen(s);i++){
                bf[i]=s[i];
            }
            bf[i]='\0';
        }
        fprintf(copy,"%s",bf);
    }
    fclose(f);
    fclose(copy);
    f=fopen("scm/infoco.txt","w");
    copy=fopen("scm/copy.txt","r");
    while(fgets(bf,100,copy)!=NULL){
        fprintf(f,"%s",bf);
    }
    fclose(f);
    fclose(copy);
}
void modco(char* cnum,char* s)
{
    FILE* logst=fopen("log.txt","a");
    FILE* f=fopen("scm/infoco.txt","r");
    FILE* copy=fopen("scm/copy.txt","w");
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
            fprintf(logst,"课程信息：(将) %s (修改为) %s",bf,s);
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
    f=fopen("scm/infoco.txt","w");
    copy=fopen("scm/copy.txt","r");
    while(fgets(bf,100,copy)!=NULL){
        fprintf(f,"%s",bf);
    }
    fclose(f);
    fclose(copy);
}
void delcor2(char* s)
{
    FILE* f=fopen("scm/infoco.txt","r");
    FILE* copy=fopen("scm/copy.txt","w");
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
    f=fopen("scm/infoco.txt","w");
    copy=fopen("scm/copy.txt","r");
    while(fgets(bf,100,copy)!=NULL){
        fprintf(f,"%s",bf);
    }
    fclose(f);
    fclose(copy);
}
void delcor(char *s)
{
    FILE* f=fopen("scm/infoco.txt","r");
    FILE* copy=fopen("scm/copy.txt","w");
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
    f=fopen("scm/infoco.txt","w");
    copy=fopen("scm/copy.txt","r");
    while(fgets(bf,100,copy)!=NULL){
        fprintf(f,"%s",bf);
    }
    fclose(f);
    fclose(copy);
}
void addcor(char *s)
{
    FILE* f=fopen("scm/infoco.txt","a");
    fprintf(f,"%s",s);
    fclose(f);
}
void init2(char *f)
{
        FILE *info=fopen("scm/infoco.txt","w");
        FILE *ff=fopen(f,"r");
        char bf[100];
        while(fgets(bf,100,ff)!=NULL){
            fprintf(info,"%s",bf);
        }
        fclose(info);
        fclose(ff);
}
//新增课程，删除课程，查看某课程详细信息（学分，课时，所选学生列表等），修改某课程的信息（学分，课时，所选学生列表等）

