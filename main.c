#include <stdio.h>
#include <gtk/gtk.h>
#include<malloc.h>
#include<string.h>
/*void init();//学生信息初始化
void addstu();//增加学生信息
void delstu();//删除学生信息
void viewstu();//查看学生信息
void modstu();//修改学生信息
void initcourse();//课程初始化
void add();//增加课程
void delete();//删除课程
void view();//查看课程
void modify();//修改课程
 `pkg-config --cflags --libs gtk+-3.0`
 gcc main.c sim/stuinfo.c -o main `pkg-config --cflags --libs gtk+-3.0`
*/
GtkWidget *window=NULL;//主界面
GtkWidget *stuwindow=NULL;//学生信息界面
GtkWidget *wdinit=NULL;//信息初始化界面
GtkWidget *wdfiname=NULL;//文件名界面
GtkWidget *wdinsu=NULL;//初始化成功
GtkWidget *stuinfo=NULL;//学生信息
GtkWidget *addstuwd=NULL;//增加的学生信息
typedef struct St{
    GtkWidget *a1;
    GtkWidget *a2;
    GtkWidget *a3;
    GtkWidget *a0;
    GtkWidget *a4;
    GtkWidget *a5;
    GtkWidget *a6;
    char* cnum;
    char* cname;
    int flag;
}st;
st sst;
char *aa[8];//学生信息储存用于操作
void callback1(GtkButton *button1,gpointer arg);//学生信息管理界面
void callback2(GtkButton *button1,gpointer arg);//课程信息管理界面
void callstuinit(GtkButton *bt1,gpointer arg);//学生信息初始化
void callstuinit2(GtkButton *bt1,gpointer arg);//课程信息初始化
void finainput(GtkButton *btinit1,gpointer arg);//文件导入名
void finainput2(GtkButton *btinit1,gpointer arg);//文件导入名2
void fileinput(GtkWidget *finaentry,gpointer arg);//开始文件导入
void fileinput2(GtkWidget *finaentry,gpointer arg);//开始文件导入2
void mscreen(GtkWidget *btback,gpointer arg);//返回主界面
void stinfosc(GtkWidget *btx,gpointer arg);//学生信息add
void stinfosc2(GtkWidget *btx,gpointer arg);//课程信息add
void addinfo(GtkWidget *bt,gpointer arg);//增加的学生信息
void add2info(GtkWidget *bt,gpointer arg);//增加的课程信息
void addinfo2(GtkWidget *bt,gpointer arg);//键盘导入
void add2info2(GtkWidget *bt,gpointer arg);//键盘导入2
void addcfirm(GtkButton *s,gpointer arg);//增加学生确定后
void add2cfirm(GtkButton *s,gpointer arg);//增加课程确定后
void addcfirm2(GtkButton *s,gpointer arg);//键盘导入确定后
void add2cfirm2(GtkButton *s,gpointer arg);//键盘导入确定后2
void stdel(GtkButton *s,gpointer arg);//学生信息del
void stdel2(GtkButton *s,gpointer arg);//课程信息del
void delinfo(GtkButton *s,gpointer arg);//删除的学生信息
void delinfo2(GtkButton *s,gpointer arg);//删除的课程信息
void delcfirm(GtkButton *s,gpointer arg);//删除确定后
void delcfirm2(GtkButton *s,gpointer arg);//删除确定后2
void viewst(GtkButton *s,gpointer arg);//查看学生信息
void viewco(GtkButton *s,gpointer arg);//查看课程信息
void viewst2(GtkButton *s,gpointer arg);//查看指定学生
void viewco2(GtkButton *s,gpointer arg);//查看指定课程
void viewst3(GtkButton *s,gpointer arg);//查看那指定学生信息
void viewco3(GtkButton *s,gpointer arg);//查看那指定课程信息
void most(GtkButton *s,gpointer arg);//要修改的学生姓名或者学号
void cmost(GtkButton *s,gpointer arg);//要修改的课程姓名或者学号
void most2(GtkButton *s,gpointer arg);//修改学生信息
void cmost2(GtkButton *s,gpointer arg);//修改课程信息
void most3(GtkButton *s,gpointer arg);//修改学生信息确定后
void cmost3(GtkButton *s,gpointer arg);//修改课程信息确定后
void cmost3(GtkButton *s,gpointer arg)
{
    gtk_widget_hide(addstuwd);
    st* ar=(st*)arg;
    aa[0]=gtk_entry_get_text(ar->a0);
    aa[1]=gtk_entry_get_text(ar->a1);
    aa[2]=gtk_entry_get_text(ar->a2);
    aa[3]=gtk_entry_get_text(ar->a3);
    aa[4]=gtk_entry_get_text(ar->a4);
    aa[5]=gtk_entry_get_text(ar->a5);
    aa[6]=gtk_entry_get_text(ar->a6);
    char ss[100],bf[100];
    sprintf(ss, "%s %s %s %s %s %s %s\n", aa[0], aa[1],aa[2],aa[3],aa[4],aa[5],aa[6]);
    if(sst.flag==1){
        modco(sst.cnum,ss);
    }else if(sst.flag==2){
        modco2(sst.cname,ss);
    }else{
        ;
    }
    gtk_widget_show_all(window);
}
void most3(GtkButton *s,gpointer arg)
{
    gtk_widget_hide(addstuwd);
    st* ar=(st*)arg;
    aa[0]=gtk_entry_get_text(ar->a0);
    aa[1]=gtk_entry_get_text(ar->a1);
    aa[2]=gtk_entry_get_text(ar->a2);
    aa[3]=gtk_entry_get_text(ar->a3);
    char ss[100],bf[100];
    sprintf(ss, "%s %s %s %s\n", aa[0], aa[1],aa[2],aa[3]);
    if(sst.flag==1){
        modstu(sst.cnum,ss);
    }else if(sst.flag==2){
        modstu2(sst.cname,ss);
    }else{
        ;
    }
    gtk_widget_show_all(window);
}
void cmost2(GtkButton *s,gpointer arg)
{
    st* ar=(st*)arg;
    aa[0]=gtk_entry_get_text(ar->a0);
    aa[1]=gtk_entry_get_text(ar->a1);
    if(strlen(aa[0])>1){
        sst.flag=1;
        sst.cnum=aa[0];
    }else if(strlen(aa[0])<1&&strlen(aa[1])>1){
        sst.flag=2;
        sst.cname=aa[1];
    }else{
        ;
    }
    gtk_widget_hide(addstuwd);
    addstuwd=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(addstuwd),"增加的课程信息");
    gtk_widget_set_size_request(addstuwd,800,800);
    GtkWidget* fixadd=gtk_fixed_new();
    GtkImage* imadd=gtk_image_new_from_file("image/add.png");
    gtk_fixed_put(GTK_FIXED(fixadd),imadd,0,0);
    gtk_container_add(GTK_CONTAINER(addstuwd),fixadd);
    GtkWidget *titadd=gtk_label_new("新增课程信息");
    gtk_label_set_markup(GTK_LABEL(titadd),"<span font_desc='25'>新增课程信息</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),titadd,390,110);
    GtkWidget *num=gtk_label_new("课程编号");
    gtk_label_set_markup(GTK_LABEL(num) ,"<span font_desc='20'>课程编号：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),num,300,180);
    GtkWidget *numm=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(numm), 6);
    gtk_fixed_put(GTK_FIXED(fixadd),numm,480,190);
    GtkWidget *name=gtk_label_new("课程名称");
    gtk_label_set_markup(GTK_LABEL(name),"<span font_desc='20'>课程名称：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),name,300,230);
    GtkWidget *namee=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(namee), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),namee,480,240);
    GtkWidget *sc=gtk_label_new("课程性质");
    gtk_label_set_markup(GTK_LABEL(sc),"<span font_desc='20'>课程性质：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),sc,300,280);
    GtkWidget *scc=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(scc), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),scc,480,290);
    GtkWidget *tot=gtk_label_new("授课学时");
    gtk_label_set_markup(GTK_LABEL(tot),"<span font_desc='20'>授课学时：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),tot,300,330);
    GtkWidget *tott=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(tott), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),tott,480,340);
    GtkWidget *tot2=gtk_label_new("学分");
    gtk_label_set_markup(GTK_LABEL(tot2),"<span font_desc='20'>学分：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),tot2,300,380);
    GtkWidget *tott2=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(tott2), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),tott2,480,390);
    GtkWidget *tot3=gtk_label_new("课程已选人");
    gtk_label_set_markup(GTK_LABEL(tot3),"<span font_desc='20'>课程已选人：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),tot3,300,430);
    GtkWidget *tott3=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(tott3), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),tott3,480,440);
    GtkWidget *tot4=gtk_label_new("课程人数上限");
    gtk_label_set_markup(GTK_LABEL(tot4),"<span font_desc='20'>课程人数上限：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),tot4,300,480);
    GtkWidget *tott4=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(tott4), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),tott4,480,490);
    GtkWidget *addback=gtk_button_new_with_label("返回");
    GtkWidget *addback1=gtk_bin_get_child(GTK_WIDGET(addback));
    gtk_label_set_markup(GTK_LABEL(addback1),"<span font_desc='20'>返回</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),addback,500,580);
    gtk_widget_set_size_request(addback,130, 20);
    g_signal_connect(G_OBJECT(addback),"clicked",G_CALLBACK(mscreen),addstuwd);
    sst.a0=GTK_ENTRY(numm);
    sst.a1=GTK_ENTRY(namee);
    sst.a2=GTK_ENTRY(scc);
    sst.a3=GTK_ENTRY(tott);
    sst.a4=GTK_ENTRY(tott2);
    sst.a5=GTK_ENTRY(tott3);
    sst.a6=GTK_ENTRY(tott4);
    GtkWidget *addlog=gtk_button_new_with_label("确定");
    GtkWidget *addlog1=gtk_bin_get_child(GTK_WIDGET(addlog));
    gtk_label_set_markup(GTK_LABEL(addlog1),"<span font_desc='20'>确定</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),addlog,300,580);
    gtk_widget_set_size_request(addlog,130, 20);
    g_signal_connect(G_OBJECT(addlog),"clicked",G_CALLBACK(cmost3),&sst);
    g_signal_connect(G_OBJECT(addstuwd),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_widget_show_all(addstuwd);
}
void most2(GtkButton *s,gpointer arg)
{
    st* ar=(st*)arg;
    aa[0]=gtk_entry_get_text(ar->a0);
    aa[1]=gtk_entry_get_text(ar->a1);
    if(strlen(aa[0])>1){
        sst.flag=1;
        sst.cnum=aa[0];
    }else if(strlen(aa[0])<1&&strlen(aa[1])>1){
        sst.flag=2;
        sst.cname=aa[1];
    }else{
        ;
    }
    gtk_widget_hide(addstuwd);
    addstuwd=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(addstuwd),"修改的学生信息");
    gtk_widget_set_size_request(addstuwd,800,800);
    GtkWidget* fixadd=gtk_fixed_new();
    GtkImage* imadd=gtk_image_new_from_file("image/add.png");
    gtk_fixed_put(GTK_FIXED(fixadd),imadd,0,0);
    gtk_container_add(GTK_CONTAINER(addstuwd),fixadd);
    GtkWidget *titadd=gtk_label_new("修改学生信息");
    gtk_label_set_markup(GTK_LABEL(titadd),"<span font_desc='25'>修改学生信息</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),titadd,390,110);
    GtkWidget *num=gtk_label_new("学号");
    gtk_label_set_markup(GTK_LABEL(num) ,"<span font_desc='20'>学号：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),num,300,180);
    GtkWidget *numm=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(numm), 6);
    gtk_fixed_put(GTK_FIXED(fixadd),numm,480,190);
    GtkWidget *name=gtk_label_new("姓名");
    gtk_label_set_markup(GTK_LABEL(name),"<span font_desc='20'>姓名：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),name,300,280);
    GtkWidget *namee=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(namee), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),namee,480,290);
    GtkWidget *sc=gtk_label_new("已选课程");
    gtk_label_set_markup(GTK_LABEL(sc),"<span font_desc='20'>已选课程：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),sc,300,380);
    GtkWidget *scc=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(scc), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),scc,480,390);
    GtkWidget *tot=gtk_label_new("总学分");
    gtk_label_set_markup(GTK_LABEL(tot),"<span font_desc='20'>总学分：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),tot,300,480);
    GtkWidget *tott=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(tott), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),tott,480,490);
    GtkWidget *addback=gtk_button_new_with_label("返回");
    GtkWidget *addback1=gtk_bin_get_child(GTK_WIDGET(addback));
    gtk_label_set_markup(GTK_LABEL(addback1),"<span font_desc='20'>返回</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),addback,500,580);
    gtk_widget_set_size_request(addback,130, 20);
    g_signal_connect(G_OBJECT(addback),"clicked",G_CALLBACK(mscreen),addstuwd);
    sst.a0=GTK_ENTRY(numm);
    sst.a1=GTK_ENTRY(namee);
    sst.a2=GTK_ENTRY(scc);
    sst.a3=GTK_ENTRY(tott);
    GtkWidget *addlog=gtk_button_new_with_label("确定");
    GtkWidget *addlog1=gtk_bin_get_child(GTK_WIDGET(addlog));
    gtk_label_set_markup(GTK_LABEL(addlog1),"<span font_desc='20'>确定</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),addlog,300,580);
    gtk_widget_set_size_request(addlog,130, 20);
    g_signal_connect(G_OBJECT(addlog),"clicked",G_CALLBACK(most3),&sst);
    g_signal_connect(G_OBJECT(addstuwd),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_widget_show_all(addstuwd);
}
void cmost(GtkButton *s,gpointer arg)
{
    addstuwd=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(addstuwd),"修改的课程信息");
    gtk_widget_set_size_request(addstuwd,800,800);
    GtkWidget* fixadd=gtk_fixed_new();
    GtkImage* imadd=gtk_image_new_from_file("image/add.png");
    gtk_fixed_put(GTK_FIXED(fixadd),imadd,0,0);
    gtk_container_add(GTK_CONTAINER(addstuwd),fixadd);
    GtkWidget *titadd=gtk_label_new("修改课程信息");
    gtk_label_set_markup(GTK_LABEL(titadd),"<span font_desc='25'>修改课程信息</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),titadd,390,110);
    GtkWidget *num=gtk_label_new("课程编号");
    gtk_label_set_markup(GTK_LABEL(num) ,"<span font_desc='20'>课程编号：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),num,300,180);
    GtkWidget *numm=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(numm), 6);
    gtk_fixed_put(GTK_FIXED(fixadd),numm,480,190);
    GtkWidget *name=gtk_label_new("课程名称");
    gtk_label_set_markup(GTK_LABEL(name),"<span font_desc='20'>课程名称：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),name,300,280);
    GtkWidget *namee=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(namee), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),namee,480,290);
    GtkWidget *addback=gtk_button_new_with_label("返回");
    GtkWidget *addback1=gtk_bin_get_child(GTK_WIDGET(addback));
    gtk_label_set_markup(GTK_LABEL(addback1),"<span font_desc='20'>返回</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),addback,500,400);
    gtk_widget_set_size_request(addback,130, 20);
    g_signal_connect(G_OBJECT(addback),"clicked",G_CALLBACK(mscreen),addstuwd);
    sst.a0=GTK_ENTRY(numm);
    sst.a1=GTK_ENTRY(namee);
    GtkWidget *addlog=gtk_button_new_with_label("确定");
    GtkWidget *addlog1=gtk_bin_get_child(GTK_WIDGET(addlog));
    gtk_label_set_markup(GTK_LABEL(addlog1),"<span font_desc='20'>确定</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),addlog,300,400);
    gtk_widget_set_size_request(addlog,130, 20);
    g_signal_connect(G_OBJECT(addlog),"clicked",G_CALLBACK(cmost2),&sst);
    g_signal_connect(G_OBJECT(addstuwd),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_widget_show_all(addstuwd);
}
void most(GtkButton *s,gpointer arg)
{
    addstuwd=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(addstuwd),"修改的学生信息");
    gtk_widget_set_size_request(addstuwd,800,800);
    GtkWidget* fixadd=gtk_fixed_new();
    GtkImage* imadd=gtk_image_new_from_file("image/add.png");
    gtk_fixed_put(GTK_FIXED(fixadd),imadd,0,0);
    gtk_container_add(GTK_CONTAINER(addstuwd),fixadd);
    GtkWidget *titadd=gtk_label_new("修改学生信息");
    gtk_label_set_markup(GTK_LABEL(titadd),"<span font_desc='25'>修改学生信息</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),titadd,390,110);
    GtkWidget *num=gtk_label_new("学号");
    gtk_label_set_markup(GTK_LABEL(num) ,"<span font_desc='20'>学号：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),num,300,180);
    GtkWidget *numm=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(numm), 6);
    gtk_fixed_put(GTK_FIXED(fixadd),numm,480,190);
    GtkWidget *name=gtk_label_new("姓名");
    gtk_label_set_markup(GTK_LABEL(name),"<span font_desc='20'>姓名：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),name,300,280);
    GtkWidget *namee=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(namee), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),namee,480,290);
    GtkWidget *addback=gtk_button_new_with_label("返回");
    GtkWidget *addback1=gtk_bin_get_child(GTK_WIDGET(addback));
    gtk_label_set_markup(GTK_LABEL(addback1),"<span font_desc='20'>返回</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),addback,500,400);
    gtk_widget_set_size_request(addback,130, 20);
    g_signal_connect(G_OBJECT(addback),"clicked",G_CALLBACK(mscreen),addstuwd);
    sst.a0=GTK_ENTRY(numm);
    sst.a1=GTK_ENTRY(namee);
    GtkWidget *addlog=gtk_button_new_with_label("确定");
    GtkWidget *addlog1=gtk_bin_get_child(GTK_WIDGET(addlog));
    gtk_label_set_markup(GTK_LABEL(addlog1),"<span font_desc='20'>确定</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),addlog,300,400);
    gtk_widget_set_size_request(addlog,130, 20);
    g_signal_connect(G_OBJECT(addlog),"clicked",G_CALLBACK(most2),&sst);
    g_signal_connect(G_OBJECT(addstuwd),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_widget_show_all(addstuwd);
}
void viewco3(GtkButton *s,gpointer arg)
{
    gtk_widget_hide(addstuwd);
    gtk_widget_hide(stuinfo);
    st* ar=(st*)arg;
    aa[0]=gtk_entry_get_text(ar->a0);
    aa[1]=gtk_entry_get_text(ar->a1);
    wdfiname=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(wdfiname),"指定课程信息");
    gtk_widget_set_size_request(wdfiname,600,250);
    GtkWidget *fixfina=gtk_fixed_new();
    GtkImage *imfina=gtk_image_new_from_file ("image/fina.png");
    gtk_fixed_put(GTK_FIXED(fixfina),imfina,0,0);
    gtk_container_add(GTK_CONTAINER(wdfiname),fixfina);
    char num[7],bf[100];
    FILE* f=fopen("scm/infoco.txt","r");
    if(strlen(aa[0])>1){
        while(fgets(bf,100,f)!=NULL){
        for(int i=0;i<strlen(bf);i++){
            num[i+1]='\0';
            if(bf[i]==' ')
                break;
            num[i]=bf[i];
        }
        if(strcmp(num,aa[0])==0){
            GtkWidget *llb=gtk_label_new(bf);
            PangoFontDescription *desc_info = pango_font_description_from_string("25");
            gtk_widget_modify_font (llb, desc_info);
            pango_font_description_free(desc_info);
            gtk_fixed_put(GTK_FIXED(fixfina),llb,330,60);
        }
    }
    }else if(strlen(aa[0])<1&&strlen(aa[1])>0){
        while(fgets(bf,100,f)!=NULL){
        int k=0,j=0;
        for(int i=0;i<strlen(bf);i++){
            num[i+1]='\0';
            if(bf[i]==' '){
                j++;
                continue;
            }
            if(j==2){
                break;
            }
            if(j==1){
                num[k]=bf[i];
                k++;
            }
        }
        if(strcmp(num,aa[1])==0){
            GtkWidget *llb=gtk_label_new(bf);
            PangoFontDescription *desc_info = pango_font_description_from_string("25");
            gtk_widget_modify_font (llb, desc_info);
            pango_font_description_free(desc_info);
            gtk_fixed_put(GTK_FIXED(fixfina),llb,330,60);
        }
    }
    }else{
        ;
    }
    fclose(f);
    GtkWidget *btfina=gtk_button_new_with_label("确定");
    GtkWidget *btfina1=gtk_bin_get_child(GTK_WIDGET(btfina));
    gtk_label_set_markup(GTK_LABEL(btfina1),"<span  font_desc='25'>确定</span>");
    gtk_fixed_put(GTK_FIXED(fixfina),btfina,450,180);
    gtk_widget_set_size_request(btfina1,100, 50);
    g_signal_connect(btfina,"clicked",G_CALLBACK(mscreen),wdfiname);
    g_signal_connect(G_OBJECT(wdfiname), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show_all(wdfiname);
}
void viewst3(GtkButton *s,gpointer arg)
{
    gtk_widget_hide(addstuwd);
    gtk_widget_hide(stuinfo);
    st* ar=(st*)arg;
    aa[0]=gtk_entry_get_text(ar->a0);
    aa[1]=gtk_entry_get_text(ar->a1);
    wdfiname=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(wdfiname),"指定学生信息");
    gtk_widget_set_size_request(wdfiname,600,250);
    GtkWidget *fixfina=gtk_fixed_new();
    GtkImage *imfina=gtk_image_new_from_file ("image/fina.png");
    gtk_fixed_put(GTK_FIXED(fixfina),imfina,0,0);
    gtk_container_add(GTK_CONTAINER(wdfiname),fixfina);
    char num[7],bf[100];
    FILE* f=fopen("sim/info.txt","r");
    if(strlen(aa[0])>1){
        while(fgets(bf,100,f)!=NULL){
        for(int i=0;i<strlen(bf);i++){
            if(bf[i]==' ')
                break;
            num[i]=bf[i];
        }
        if(strcmp(num,aa[0])==0){
            GtkWidget *llb=gtk_label_new(bf);
            PangoFontDescription *desc_info = pango_font_description_from_string("25");
            gtk_widget_modify_font (llb, desc_info);
            pango_font_description_free(desc_info);
            gtk_fixed_put(GTK_FIXED(fixfina),llb,250,60);
        }
    }
    }else if(strlen(aa[0])<1&&strlen(aa[1])>0){
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
                k++;
            }
        }
        if(strcmp(num,aa[1])==0){
            GtkWidget *llb=gtk_label_new(bf);
            PangoFontDescription *desc_info = pango_font_description_from_string("25");
            gtk_widget_modify_font (llb, desc_info);
            pango_font_description_free(desc_info);
            gtk_fixed_put(GTK_FIXED(fixfina),llb,250,60);
        }
    }
    }else{
        ;
    }
    fclose(f);
    GtkWidget *btfina=gtk_button_new_with_label("确定");
    GtkWidget *btfina1=gtk_bin_get_child(GTK_WIDGET(btfina));
    gtk_label_set_markup(GTK_LABEL(btfina1),"<span  font_desc='25'>确定</span>");
    gtk_fixed_put(GTK_FIXED(fixfina),btfina,450,180);
    gtk_widget_set_size_request(btfina1,100, 50);
    g_signal_connect(btfina,"clicked",G_CALLBACK(mscreen),wdfiname);
    g_signal_connect(G_OBJECT(wdfiname), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show_all(wdfiname);
}
void viewco2(GtkButton *s,gpointer arg)
{
    addstuwd=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(addstuwd),"查看的课程信息");
    gtk_widget_set_size_request(addstuwd,800,800);
    GtkWidget* fixadd=gtk_fixed_new();
    GtkImage* imadd=gtk_image_new_from_file("image/add.png");
    gtk_fixed_put(GTK_FIXED(fixadd),imadd,0,0);
    gtk_container_add(GTK_CONTAINER(addstuwd),fixadd);
    GtkWidget *titadd=gtk_label_new("查看课程信息");
    gtk_label_set_markup(GTK_LABEL(titadd),"<span font_desc='25'>查看课程信息</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),titadd,390,110);
    GtkWidget *num=gtk_label_new("课程编号");
    gtk_label_set_markup(GTK_LABEL(num) ,"<span font_desc='20'>课程编号：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),num,300,180);
    GtkWidget *numm=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(numm), 6);
    gtk_fixed_put(GTK_FIXED(fixadd),numm,480,190);
    GtkWidget *name=gtk_label_new("课程名称");
    gtk_label_set_markup(GTK_LABEL(name),"<span font_desc='20'>课程名称：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),name,300,280);
    GtkWidget *namee=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(namee), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),namee,480,290);
    GtkWidget *addback=gtk_button_new_with_label("返回");
    GtkWidget *addback1=gtk_bin_get_child(GTK_WIDGET(addback));
    gtk_label_set_markup(GTK_LABEL(addback1),"<span font_desc='20'>返回</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),addback,500,400);
    gtk_widget_set_size_request(addback,130, 20);
    g_signal_connect(G_OBJECT(addback),"clicked",G_CALLBACK(mscreen),addstuwd);
    sst.a0=GTK_ENTRY(numm);
    sst.a1=GTK_ENTRY(namee);
    GtkWidget *addlog=gtk_button_new_with_label("确定");
    GtkWidget *addlog1=gtk_bin_get_child(GTK_WIDGET(addlog));
    gtk_label_set_markup(GTK_LABEL(addlog1),"<span font_desc='20'>确定</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),addlog,300,400);
    gtk_widget_set_size_request(addlog,130, 20);
    g_signal_connect(G_OBJECT(addlog),"clicked",G_CALLBACK(viewco3),&sst);
    g_signal_connect(G_OBJECT(addstuwd),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_widget_show_all(addstuwd);
}
void viewst2(GtkButton *s,gpointer arg)
{
    addstuwd=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(addstuwd),"查看的学生信息");
    gtk_widget_set_size_request(addstuwd,800,800);
    GtkWidget* fixadd=gtk_fixed_new();
    GtkImage* imadd=gtk_image_new_from_file("image/add.png");
    gtk_fixed_put(GTK_FIXED(fixadd),imadd,0,0);
    gtk_container_add(GTK_CONTAINER(addstuwd),fixadd);
    GtkWidget *titadd=gtk_label_new("查看学生信息");
    gtk_label_set_markup(GTK_LABEL(titadd),"<span font_desc='25'>查看学生信息</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),titadd,390,110);
    GtkWidget *num=gtk_label_new("学号");
    gtk_label_set_markup(GTK_LABEL(num) ,"<span font_desc='20'>学号：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),num,300,180);
    GtkWidget *numm=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(numm), 6);
    gtk_fixed_put(GTK_FIXED(fixadd),numm,480,190);
    GtkWidget *name=gtk_label_new("姓名");
    gtk_label_set_markup(GTK_LABEL(name),"<span font_desc='20'>姓名：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),name,300,280);
    GtkWidget *namee=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(namee), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),namee,480,290);
    GtkWidget *addback=gtk_button_new_with_label("返回");
    GtkWidget *addback1=gtk_bin_get_child(GTK_WIDGET(addback));
    gtk_label_set_markup(GTK_LABEL(addback1),"<span font_desc='20'>返回</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),addback,500,400);
    gtk_widget_set_size_request(addback,130, 20);
    g_signal_connect(G_OBJECT(addback),"clicked",G_CALLBACK(mscreen),addstuwd);
    sst.a0=GTK_ENTRY(numm);
    sst.a1=GTK_ENTRY(namee);
    GtkWidget *addlog=gtk_button_new_with_label("确定");
    GtkWidget *addlog1=gtk_bin_get_child(GTK_WIDGET(addlog));
    gtk_label_set_markup(GTK_LABEL(addlog1),"<span font_desc='20'>确定</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),addlog,300,400);
    gtk_widget_set_size_request(addlog,130, 20);
    g_signal_connect(G_OBJECT(addlog),"clicked",G_CALLBACK(viewst3),&sst);
    g_signal_connect(G_OBJECT(addstuwd),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_widget_show_all(addstuwd);
}
void viewco(GtkButton *s,gpointer arg)
{
    gtk_widget_hide(stuwindow);
    stuinfo=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(stuinfo),"课程信息");
    gtk_widget_set_size_request(stuinfo,1024,1024);
    GtkWidget* fixinfo=gtk_fixed_new();
    GtkWidget* iminfo=gtk_image_new_from_file("image/stuinfo.png");
    gtk_fixed_put(GTK_FIXED(fixinfo),iminfo,0,0);
    GtkWidget *tit=gtk_label_new("课 程 信 息");
    gtk_label_set_markup(GTK_LABEL(tit),"<span font_desc='35'>课 程 信 息</span>");
    gtk_fixed_put(GTK_FIXED(fixinfo),tit,520,60);
    GtkWidget *lb[20];
    FILE* f=fopen("scm/infoco.txt","r");
    char bf[100];
    int i=0;
    GtkWidget *scrlledwd;
    scrlledwd = gtk_scrolled_window_new(NULL,NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrlledwd),
                                   GTK_POLICY_AUTOMATIC,GTK_POLICY_ALWAYS);
    while(fgets(bf,100,f)!=NULL){
        if(strlen(bf)<2){
            continue;
        }
        lb[i]=gtk_label_new(bf);
        PangoFontDescription *desc_info = pango_font_description_from_string("25");
        gtk_widget_modify_font (lb[i], desc_info);
        pango_font_description_free(desc_info);
        gtk_fixed_put(GTK_FIXED(fixinfo),lb[i],350,180+40*i);
        i++;
    }
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrlledwd),fixinfo);
    gtk_container_add(GTK_CONTAINER(stuinfo),scrlledwd);
    GtkWidget *infoback=gtk_button_new_with_label("返回");
    GtkWidget *infoback1=gtk_bin_get_child(GTK_WIDGET(infoback));
    gtk_label_set_markup(GTK_LABEL(infoback1),"<span font_desc='25'>返回</span>");
    gtk_fixed_put(GTK_FIXED(fixinfo),infoback,720,130);
    gtk_widget_set_size_request(infoback,110, 25);
    g_signal_connect(G_OBJECT(infoback),"clicked",G_CALLBACK(mscreen),stuinfo);
    GtkWidget *addstu=gtk_button_new_with_label("查看");
    GtkWidget *addstu1=gtk_bin_get_child(GTK_WIDGET(addstu));
    gtk_label_set_markup(GTK_LABEL(addstu1),"<span font_desc='25'>查看</span>");
    gtk_fixed_put(GTK_FIXED(fixinfo),addstu,430,130);
    gtk_widget_set_size_request(addstu,110, 25);
    g_signal_connect(G_OBJECT(addstu),"clicked",G_CALLBACK(viewco2),stuinfo);
    g_signal_connect(G_OBJECT(stuinfo),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_widget_show_all(stuinfo);
}
void viewst(GtkButton *s,gpointer arg)
{
    gtk_widget_hide(stuwindow);
    stuinfo=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(stuinfo),"学生信息");
    gtk_widget_set_size_request(stuinfo,1024,1024);
    GtkWidget* fixinfo=gtk_fixed_new();
    GtkWidget* iminfo=gtk_image_new_from_file("image/stuinfo.png");
    gtk_fixed_put(GTK_FIXED(fixinfo),iminfo,0,0);
    GtkWidget *tit=gtk_label_new("学 生 信 息");
    gtk_label_set_markup(GTK_LABEL(tit),"<span font_desc='35'>学 生 信 息</span>");
    gtk_fixed_put(GTK_FIXED(fixinfo),tit,520,60);
    GtkWidget *lb[20];
    FILE* f=fopen("sim/info.txt","r");
    char bf[100];
    int i=0;
    GtkWidget *scrlledwd;
    scrlledwd = gtk_scrolled_window_new(NULL,NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrlledwd),
                                   GTK_POLICY_AUTOMATIC,GTK_POLICY_ALWAYS);
    while(fgets(bf,100,f)!=NULL){
        if(strlen(bf)<2){
            continue;
        }
        lb[i]=gtk_label_new(bf);
        PangoFontDescription *desc_info = pango_font_description_from_string("25");
        gtk_widget_modify_font (lb[i], desc_info);
        pango_font_description_free(desc_info);
        gtk_fixed_put(GTK_FIXED(fixinfo),lb[i],400,180+40*i);
        i++;
    }
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrlledwd),fixinfo);
    gtk_container_add(GTK_CONTAINER(stuinfo),scrlledwd);
    GtkWidget *infoback=gtk_button_new_with_label("返回");
    GtkWidget *infoback1=gtk_bin_get_child(GTK_WIDGET(infoback));
    gtk_label_set_markup(GTK_LABEL(infoback1),"<span font_desc='25'>返回</span>");
    gtk_fixed_put(GTK_FIXED(fixinfo),infoback,720,130);
    gtk_widget_set_size_request(infoback,110, 25);
    g_signal_connect(G_OBJECT(infoback),"clicked",G_CALLBACK(mscreen),stuinfo);
    GtkWidget *addstu=gtk_button_new_with_label("查看");
    GtkWidget *addstu1=gtk_bin_get_child(GTK_WIDGET(addstu));
    gtk_label_set_markup(GTK_LABEL(addstu1),"<span font_desc='25'>查看</span>");
    gtk_fixed_put(GTK_FIXED(fixinfo),addstu,430,130);
    gtk_widget_set_size_request(addstu,110, 25);
    g_signal_connect(G_OBJECT(addstu),"clicked",G_CALLBACK(viewst2),stuinfo);
    g_signal_connect(G_OBJECT(stuinfo),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_widget_show_all(stuinfo);
}
void delcfirm2(GtkButton *s,gpointer arg)
{
    gtk_widget_hide(addstuwd);
    gtk_widget_hide(stuinfo);
    st* ar=(st*)arg;
    aa[0]=gtk_entry_get_text(ar->a0);
    aa[1]=gtk_entry_get_text(ar->a1);
    if(strlen(aa[0])>1){
        delcor(aa[0]);
    }else if(strlen(aa[0])<1&&strlen(aa[1])>1){
        delcor2(aa[1]);
    }else{
        ;
    }
    gtk_widget_show_all(window);
}
void delcfirm(GtkButton *s,gpointer arg)
{
    gtk_widget_hide(addstuwd);
    gtk_widget_hide(stuinfo);
    st* ar=(st*)arg;
    aa[0]=gtk_entry_get_text(ar->a0);
    aa[1]=gtk_entry_get_text(ar->a1);
    if(strlen(aa[0])>1){
        delstu(aa[0]);
    }else if(strlen(aa[0])<1&&strlen(aa[1])>1){
        delstu2(aa[1]);
    }else{
        ;
    }
    gtk_widget_show_all(window);
}
void delinfo2(GtkButton *s,gpointer arg)
{
    addstuwd=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(addstuwd),"删除的课程信息");
    gtk_widget_set_size_request(addstuwd,800,800);
    GtkWidget* fixadd=gtk_fixed_new();
    GtkImage* imadd=gtk_image_new_from_file("image/add.png");
    gtk_fixed_put(GTK_FIXED(fixadd),imadd,0,0);
    gtk_container_add(GTK_CONTAINER(addstuwd),fixadd);
    GtkWidget *titadd=gtk_label_new("删除课程信息");
    gtk_label_set_markup(GTK_LABEL(titadd),"<span font_desc='25'>删除课程信息</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),titadd,390,110);
    GtkWidget *num=gtk_label_new("课程编号");
    gtk_label_set_markup(GTK_LABEL(num) ,"<span font_desc='20'>课程编号：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),num,300,180);
    GtkWidget *numm=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(numm), 6);
    gtk_fixed_put(GTK_FIXED(fixadd),numm,480,190);
    GtkWidget *name=gtk_label_new("课程名称");
    gtk_label_set_markup(GTK_LABEL(name),"<span font_desc='20'>课程名称：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),name,300,280);
    GtkWidget *namee=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(namee), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),namee,480,290);
    GtkWidget *addback=gtk_button_new_with_label("返回");
    GtkWidget *addback1=gtk_bin_get_child(GTK_WIDGET(addback));
    gtk_label_set_markup(GTK_LABEL(addback1),"<span font_desc='20'>返回</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),addback,500,400);
    gtk_widget_set_size_request(addback,130, 20);
    g_signal_connect(G_OBJECT(addback),"clicked",G_CALLBACK(mscreen),addstuwd);
    sst.a0=GTK_ENTRY(numm);
    sst.a1=GTK_ENTRY(namee);
    GtkWidget *addlog=gtk_button_new_with_label("确定");
    GtkWidget *addlog1=gtk_bin_get_child(GTK_WIDGET(addlog));
    gtk_label_set_markup(GTK_LABEL(addlog1),"<span font_desc='20'>确定</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),addlog,300,400);
    gtk_widget_set_size_request(addlog,130, 20);
    g_signal_connect(G_OBJECT(addlog),"clicked",G_CALLBACK(delcfirm2),&sst);
    g_signal_connect(G_OBJECT(addstuwd),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_widget_show_all(addstuwd);
}
void delinfo(GtkButton *s,gpointer arg)
{
    addstuwd=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(addstuwd),"删除的学生信息");
    gtk_widget_set_size_request(addstuwd,800,800);
    GtkWidget* fixadd=gtk_fixed_new();
    GtkImage* imadd=gtk_image_new_from_file("image/add.png");
    gtk_fixed_put(GTK_FIXED(fixadd),imadd,0,0);
    gtk_container_add(GTK_CONTAINER(addstuwd),fixadd);
    GtkWidget *titadd=gtk_label_new("删除学生信息");
    gtk_label_set_markup(GTK_LABEL(titadd),"<span font_desc='25'>删除学生信息</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),titadd,390,110);
    GtkWidget *num=gtk_label_new("学号");
    gtk_label_set_markup(GTK_LABEL(num) ,"<span font_desc='20'>学号：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),num,300,180);
    GtkWidget *numm=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(numm), 6);
    gtk_fixed_put(GTK_FIXED(fixadd),numm,480,190);
    GtkWidget *name=gtk_label_new("姓名");
    gtk_label_set_markup(GTK_LABEL(name),"<span font_desc='20'>姓名：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),name,300,280);
    GtkWidget *namee=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(namee), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),namee,480,290);
    GtkWidget *addback=gtk_button_new_with_label("返回");
    GtkWidget *addback1=gtk_bin_get_child(GTK_WIDGET(addback));
    gtk_label_set_markup(GTK_LABEL(addback1),"<span font_desc='20'>返回</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),addback,500,400);
    gtk_widget_set_size_request(addback,130, 20);
    g_signal_connect(G_OBJECT(addback),"clicked",G_CALLBACK(mscreen),addstuwd);
    sst.a0=GTK_ENTRY(numm);
    sst.a1=GTK_ENTRY(namee);
    GtkWidget *addlog=gtk_button_new_with_label("确定");
    GtkWidget *addlog1=gtk_bin_get_child(GTK_WIDGET(addlog));
    gtk_label_set_markup(GTK_LABEL(addlog1),"<span font_desc='20'>确定</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),addlog,300,400);
    gtk_widget_set_size_request(addlog,130, 20);
    g_signal_connect(G_OBJECT(addlog),"clicked",G_CALLBACK(delcfirm),&sst);
    g_signal_connect(G_OBJECT(addstuwd),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_widget_show_all(addstuwd);
}
void stdel2(GtkButton *s,gpointer arg)
{
    gtk_widget_hide(stuwindow);
    stuinfo=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(stuinfo),"课程信息");
    gtk_widget_set_size_request(stuinfo,1024,1024);
    GtkWidget* fixinfo=gtk_fixed_new();
    GtkWidget* iminfo=gtk_image_new_from_file("image/stuinfo.png");
    gtk_fixed_put(GTK_FIXED(fixinfo),iminfo,0,0);
    GtkWidget *tit=gtk_label_new("课 程 信 息");
    gtk_label_set_markup(GTK_LABEL(tit),"<span font_desc='35'>课 程 信 息</span>");
    gtk_fixed_put(GTK_FIXED(fixinfo),tit,520,60);
    GtkWidget *lb[20];
    FILE* f=fopen("scm/infoco.txt","r");
    char bf[100];
    int i=0;
    GtkWidget *scrlledwd;
    scrlledwd = gtk_scrolled_window_new(NULL,NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrlledwd),
                                   GTK_POLICY_AUTOMATIC,GTK_POLICY_ALWAYS);
    while(fgets(bf,100,f)!=NULL){
        if(strlen(bf)<2){
            continue;
        }
        lb[i]=gtk_label_new(bf);
        PangoFontDescription *desc_info = pango_font_description_from_string("25");
        gtk_widget_modify_font (lb[i], desc_info);
        pango_font_description_free(desc_info);
        gtk_fixed_put(GTK_FIXED(fixinfo),lb[i],350,180+40*i);
        i++;
    }
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrlledwd),fixinfo);
    gtk_container_add(GTK_CONTAINER(stuinfo),scrlledwd);
    GtkWidget *infoback=gtk_button_new_with_label("返回");
    GtkWidget *infoback1=gtk_bin_get_child(GTK_WIDGET(infoback));
    gtk_label_set_markup(GTK_LABEL(infoback1),"<span font_desc='25'>返回</span>");
    gtk_fixed_put(GTK_FIXED(fixinfo),infoback,720,130);
    gtk_widget_set_size_request(infoback,110, 25);
    g_signal_connect(G_OBJECT(infoback),"clicked",G_CALLBACK(mscreen),stuinfo);
    GtkWidget *addstu=gtk_button_new_with_label("删除");
    GtkWidget *addstu1=gtk_bin_get_child(GTK_WIDGET(addstu));
    gtk_label_set_markup(GTK_LABEL(addstu1),"<span font_desc='25'>删除</span>");
    gtk_fixed_put(GTK_FIXED(fixinfo),addstu,430,130);
    gtk_widget_set_size_request(addstu,110, 25);
    g_signal_connect(G_OBJECT(addstu),"clicked",G_CALLBACK(delinfo2),NULL);
    g_signal_connect(G_OBJECT(stuinfo),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_widget_show_all(stuinfo);
}
void stdel(GtkButton *s,gpointer arg)
{
    gtk_widget_hide(stuwindow);
    stuinfo=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(stuinfo),"学生信息");
    gtk_widget_set_size_request(stuinfo,1024,1024);
    GtkWidget* fixinfo=gtk_fixed_new();
    GtkWidget* iminfo=gtk_image_new_from_file("image/stuinfo.png");
    gtk_fixed_put(GTK_FIXED(fixinfo),iminfo,0,0);
    GtkWidget *tit=gtk_label_new("学 生 信 息");
    gtk_label_set_markup(GTK_LABEL(tit),"<span font_desc='35'>学 生 信 息</span>");
    gtk_fixed_put(GTK_FIXED(fixinfo),tit,520,60);
    GtkWidget *lb[20];
    FILE* f=fopen("sim/info.txt","r");
    char bf[100];
    int i=0;
    GtkWidget *scrlledwd;
    scrlledwd = gtk_scrolled_window_new(NULL,NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrlledwd),
                                   GTK_POLICY_AUTOMATIC,GTK_POLICY_ALWAYS);
    while(fgets(bf,100,f)!=NULL){
        if(strlen(bf)<2){
            continue;
        }
        lb[i]=gtk_label_new(bf);
        PangoFontDescription *desc_info = pango_font_description_from_string("25");
        gtk_widget_modify_font (lb[i], desc_info);
        pango_font_description_free(desc_info);
        gtk_fixed_put(GTK_FIXED(fixinfo),lb[i],400,180+40*i);
        i++;
    }
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrlledwd),fixinfo);
    gtk_container_add(GTK_CONTAINER(stuinfo),scrlledwd);
    GtkWidget *infoback=gtk_button_new_with_label("返回");
    GtkWidget *infoback1=gtk_bin_get_child(GTK_WIDGET(infoback));
    gtk_label_set_markup(GTK_LABEL(infoback1),"<span font_desc='25'>返回</span>");
    gtk_fixed_put(GTK_FIXED(fixinfo),infoback,720,130);
    gtk_widget_set_size_request(infoback,110, 25);
    g_signal_connect(G_OBJECT(infoback),"clicked",G_CALLBACK(mscreen),stuinfo);
    GtkWidget *addstu=gtk_button_new_with_label("删除");
    GtkWidget *addstu1=gtk_bin_get_child(GTK_WIDGET(addstu));
    gtk_label_set_markup(GTK_LABEL(addstu1),"<span font_desc='25'>删除</span>");
    gtk_fixed_put(GTK_FIXED(fixinfo),addstu,430,130);
    gtk_widget_set_size_request(addstu,110, 25);
    g_signal_connect(G_OBJECT(addstu),"clicked",G_CALLBACK(delinfo),NULL);
    g_signal_connect(G_OBJECT(stuinfo),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_widget_show_all(stuinfo);
}
void add2cfirm2(GtkButton *s,gpointer arg)
{
    gtk_widget_hide(addstuwd);
    st* ar=(st*)arg;
    aa[0]=gtk_entry_get_text(ar->a0);
    aa[1]=gtk_entry_get_text(ar->a1);
    aa[2]=gtk_entry_get_text(ar->a2);
    aa[3]=gtk_entry_get_text(ar->a3);
    aa[4]=gtk_entry_get_text(ar->a4);
    aa[5]=gtk_entry_get_text(ar->a5);
    aa[6]=gtk_entry_get_text(ar->a6);
    char ss[100];
    sprintf(ss, "%s %s %s %s %s %s %s\n", aa[0], aa[1],aa[2],aa[3],aa[4],aa[5],aa[6]);
    addcor(ss);
    gtk_widget_show_all(window);
}
void addcfirm2(GtkButton *s,gpointer arg)
{
    gtk_widget_hide(addstuwd);
    st* ar=(st*)arg;
    aa[0]=gtk_entry_get_text(ar->a0);
    aa[1]=gtk_entry_get_text(ar->a1);
    aa[2]=gtk_entry_get_text(ar->a2);
    aa[3]=gtk_entry_get_text(ar->a3);
    char ss[100];
    sprintf(ss, "%s %s %s %s\n", aa[0], aa[1],aa[2],aa[3]);
    addstu(ss);
    gtk_widget_show_all(window);
}
void add2cfirm(GtkButton *s,gpointer arg)
{
    gtk_widget_hide(addstuwd);
    gtk_widget_hide(stuinfo);
    st* ar=(st*)arg;
    aa[0]=gtk_entry_get_text(ar->a0);
    aa[1]=gtk_entry_get_text(ar->a1);
    aa[2]=gtk_entry_get_text(ar->a2);
    aa[3]=gtk_entry_get_text(ar->a3);
    aa[4]=gtk_entry_get_text(ar->a4);
    aa[5]=gtk_entry_get_text(ar->a5);
    aa[6]=gtk_entry_get_text(ar->a6);
    char ss[100];
    sprintf(ss, "%s %s %s %s %s %s %s\n", aa[0], aa[1],aa[2],aa[3],aa[4],aa[5],aa[6]);
    addcor(ss);
    gtk_widget_show_all(window);
}
void addcfirm(GtkButton *s,gpointer arg)
{
    gtk_widget_hide(addstuwd);
    gtk_widget_hide(stuinfo);
    st* ar=(st*)arg;
    aa[0]=gtk_entry_get_text(ar->a0);
    aa[1]=gtk_entry_get_text(ar->a1);
    aa[2]=gtk_entry_get_text(ar->a2);
    aa[3]=gtk_entry_get_text(ar->a3);
    char ss[100];
    sprintf(ss, "%s %s %s %s\n", aa[0], aa[1],aa[2],aa[3]);
    addstu(ss);
    gtk_widget_show_all(window);
}
void add2info2(GtkWidget *bt,gpointer arg)
{
    addstuwd=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(addstuwd),"增加的课程信息");
    gtk_widget_set_size_request(addstuwd,800,800);
    GtkWidget* fixadd=gtk_fixed_new();
    GtkImage* imadd=gtk_image_new_from_file("image/add.png");
    gtk_fixed_put(GTK_FIXED(fixadd),imadd,0,0);
    gtk_container_add(GTK_CONTAINER(addstuwd),fixadd);
    GtkWidget *titadd=gtk_label_new("新增课程信息");
    gtk_label_set_markup(GTK_LABEL(titadd),"<span font_desc='25'>新增课程信息</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),titadd,390,110);
    GtkWidget *num=gtk_label_new("课程编号");
    gtk_label_set_markup(GTK_LABEL(num) ,"<span font_desc='20'>课程编号：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),num,300,180);
    GtkWidget *numm=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(numm), 6);
    gtk_fixed_put(GTK_FIXED(fixadd),numm,480,190);
    GtkWidget *name=gtk_label_new("课程名称");
    gtk_label_set_markup(GTK_LABEL(name),"<span font_desc='20'>课程名称：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),name,300,230);
    GtkWidget *namee=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(namee), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),namee,480,240);
    GtkWidget *sc=gtk_label_new("课程性质");
    gtk_label_set_markup(GTK_LABEL(sc),"<span font_desc='20'>课程性质：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),sc,300,280);
    GtkWidget *scc=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(scc), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),scc,480,290);
    GtkWidget *tot=gtk_label_new("授课学时");
    gtk_label_set_markup(GTK_LABEL(tot),"<span font_desc='20'>授课学时：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),tot,300,330);
    GtkWidget *tott=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(tott), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),tott,480,340);
    GtkWidget *tot2=gtk_label_new("学分");
    gtk_label_set_markup(GTK_LABEL(tot2),"<span font_desc='20'>学分：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),tot2,300,380);
    GtkWidget *tott2=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(tott2), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),tott2,480,390);
    GtkWidget *tot3=gtk_label_new("课程已选人");
    gtk_label_set_markup(GTK_LABEL(tot3),"<span font_desc='20'>课程已选人：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),tot3,300,430);
    GtkWidget *tott3=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(tott3), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),tott3,480,440);
    GtkWidget *tot4=gtk_label_new("课程人数上限");
    gtk_label_set_markup(GTK_LABEL(tot4),"<span font_desc='20'>课程人数上限：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),tot4,300,480);
    GtkWidget *tott4=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(tott4), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),tott4,480,490);
    GtkWidget *addback=gtk_button_new_with_label("返回");
    GtkWidget *addback1=gtk_bin_get_child(GTK_WIDGET(addback));
    gtk_label_set_markup(GTK_LABEL(addback1),"<span font_desc='20'>返回</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),addback,500,580);
    gtk_widget_set_size_request(addback,130, 20);
    g_signal_connect(G_OBJECT(addback),"clicked",G_CALLBACK(mscreen),addstuwd);
    sst.a0=GTK_ENTRY(numm);
    sst.a1=GTK_ENTRY(namee);
    sst.a2=GTK_ENTRY(scc);
    sst.a3=GTK_ENTRY(tott);
    sst.a4=GTK_ENTRY(tott2);
    sst.a5=GTK_ENTRY(tott3);
    sst.a6=GTK_ENTRY(tott4);
    GtkWidget *addlog=gtk_button_new_with_label("确定");
    GtkWidget *addlog1=gtk_bin_get_child(GTK_WIDGET(addlog));
    gtk_label_set_markup(GTK_LABEL(addlog1),"<span font_desc='20'>确定</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),addlog,300,580);
    gtk_widget_set_size_request(addlog,130, 20);
    g_signal_connect(G_OBJECT(addlog),"clicked",G_CALLBACK(add2cfirm2),&sst);
    g_signal_connect(G_OBJECT(addstuwd),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_widget_show_all(addstuwd);
}
void addinfo2(GtkWidget *bt,gpointer arg)
{
    addstuwd=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(addstuwd),"增加的学生信息");
    gtk_widget_set_size_request(addstuwd,800,800);
    GtkWidget* fixadd=gtk_fixed_new();
    GtkImage* imadd=gtk_image_new_from_file("image/add.png");
    gtk_fixed_put(GTK_FIXED(fixadd),imadd,0,0);
    gtk_container_add(GTK_CONTAINER(addstuwd),fixadd);
    GtkWidget *titadd=gtk_label_new("增加学生信息");
    gtk_label_set_markup(GTK_LABEL(titadd),"<span font_desc='25'>增加学生信息</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),titadd,390,110);
    GtkWidget *num=gtk_label_new("学号");
    gtk_label_set_markup(GTK_LABEL(num) ,"<span font_desc='20'>学号：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),num,300,180);
    GtkWidget *numm=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(numm), 6);
    gtk_fixed_put(GTK_FIXED(fixadd),numm,480,190);
    GtkWidget *name=gtk_label_new("姓名");
    gtk_label_set_markup(GTK_LABEL(name),"<span font_desc='20'>姓名：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),name,300,280);
    GtkWidget *namee=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(namee), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),namee,480,290);
    GtkWidget *sc=gtk_label_new("已选课程");
    gtk_label_set_markup(GTK_LABEL(sc),"<span font_desc='20'>已选课程：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),sc,300,380);
    GtkWidget *scc=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(scc), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),scc,480,390);
    GtkWidget *tot=gtk_label_new("总学分");
    gtk_label_set_markup(GTK_LABEL(tot),"<span font_desc='20'>总学分：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),tot,300,480);
    GtkWidget *tott=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(tott), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),tott,480,490);
    GtkWidget *addback=gtk_button_new_with_label("返回");
    GtkWidget *addback1=gtk_bin_get_child(GTK_WIDGET(addback));
    gtk_label_set_markup(GTK_LABEL(addback1),"<span font_desc='20'>返回</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),addback,500,580);
    gtk_widget_set_size_request(addback,130, 20);
    g_signal_connect(G_OBJECT(addback),"clicked",G_CALLBACK(mscreen),addstuwd);
    sst.a0=GTK_ENTRY(numm);
    sst.a1=GTK_ENTRY(namee);
    sst.a2=GTK_ENTRY(scc);
    sst.a3=GTK_ENTRY(tott);
    GtkWidget *addlog=gtk_button_new_with_label("确定");
    GtkWidget *addlog1=gtk_bin_get_child(GTK_WIDGET(addlog));
    gtk_label_set_markup(GTK_LABEL(addlog1),"<span font_desc='20'>确定</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),addlog,300,580);
    gtk_widget_set_size_request(addlog,130, 20);
    g_signal_connect(G_OBJECT(addlog),"clicked",G_CALLBACK(addcfirm2),&sst);
    g_signal_connect(G_OBJECT(addstuwd),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_widget_show_all(addstuwd);
}
void add2info(GtkWidget *bt,gpointer arg)
{
    addstuwd=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(addstuwd),"增加的课程信息");
    gtk_widget_set_size_request(addstuwd,800,800);
    GtkWidget* fixadd=gtk_fixed_new();
    GtkImage* imadd=gtk_image_new_from_file("image/add.png");
    gtk_fixed_put(GTK_FIXED(fixadd),imadd,0,0);
    gtk_container_add(GTK_CONTAINER(addstuwd),fixadd);
    GtkWidget *titadd=gtk_label_new("新增课程信息");
    gtk_label_set_markup(GTK_LABEL(titadd),"<span font_desc='25'>新增课程信息</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),titadd,390,110);
    GtkWidget *num=gtk_label_new("课程编号");
    gtk_label_set_markup(GTK_LABEL(num) ,"<span font_desc='20'>课程编号：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),num,300,180);
    GtkWidget *numm=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(numm), 6);
    gtk_fixed_put(GTK_FIXED(fixadd),numm,480,190);
    GtkWidget *name=gtk_label_new("课程名称");
    gtk_label_set_markup(GTK_LABEL(name),"<span font_desc='20'>课程名称：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),name,300,230);
    GtkWidget *namee=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(namee), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),namee,480,240);
    GtkWidget *sc=gtk_label_new("课程性质");
    gtk_label_set_markup(GTK_LABEL(sc),"<span font_desc='20'>课程性质：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),sc,300,280);
    GtkWidget *scc=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(scc), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),scc,480,290);
    GtkWidget *tot=gtk_label_new("授课学时");
    gtk_label_set_markup(GTK_LABEL(tot),"<span font_desc='20'>授课学时：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),tot,300,330);
    GtkWidget *tott=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(tott), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),tott,480,340);
    GtkWidget *tot2=gtk_label_new("学分");
    gtk_label_set_markup(GTK_LABEL(tot2),"<span font_desc='20'>学分：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),tot2,300,380);
    GtkWidget *tott2=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(tott2), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),tott2,480,390);
    GtkWidget *tot3=gtk_label_new("课程已选人");
    gtk_label_set_markup(GTK_LABEL(tot3),"<span font_desc='20'>课程已选人：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),tot3,300,430);
    GtkWidget *tott3=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(tott3), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),tott3,480,440);
    GtkWidget *tot4=gtk_label_new("课程人数上限");
    gtk_label_set_markup(GTK_LABEL(tot4),"<span font_desc='20'>课程人数上限：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),tot4,300,480);
    GtkWidget *tott4=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(tott4), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),tott4,480,490);
    GtkWidget *addback=gtk_button_new_with_label("返回");
    GtkWidget *addback1=gtk_bin_get_child(GTK_WIDGET(addback));
    gtk_label_set_markup(GTK_LABEL(addback1),"<span font_desc='20'>返回</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),addback,500,580);
    gtk_widget_set_size_request(addback,130, 20);
    g_signal_connect(G_OBJECT(addback),"clicked",G_CALLBACK(mscreen),addstuwd);
    sst.a0=GTK_ENTRY(numm);
    sst.a1=GTK_ENTRY(namee);
    sst.a2=GTK_ENTRY(scc);
    sst.a3=GTK_ENTRY(tott);
    sst.a4=GTK_ENTRY(tott2);
    sst.a5=GTK_ENTRY(tott3);
    sst.a6=GTK_ENTRY(tott4);
    GtkWidget *addlog=gtk_button_new_with_label("确定");
    GtkWidget *addlog1=gtk_bin_get_child(GTK_WIDGET(addlog));
    gtk_label_set_markup(GTK_LABEL(addlog1),"<span font_desc='20'>确定</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),addlog,300,580);
    gtk_widget_set_size_request(addlog,130, 20);
    g_signal_connect(G_OBJECT(addlog),"clicked",G_CALLBACK(add2cfirm),&sst);
    g_signal_connect(G_OBJECT(addstuwd),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_widget_show_all(addstuwd);
}
void addinfo(GtkWidget *bt,gpointer arg)
{
    addstuwd=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(addstuwd),"增加的学生信息");
    gtk_widget_set_size_request(addstuwd,800,800);
    GtkWidget* fixadd=gtk_fixed_new();
    GtkImage* imadd=gtk_image_new_from_file("image/add.png");
    gtk_fixed_put(GTK_FIXED(fixadd),imadd,0,0);
    gtk_container_add(GTK_CONTAINER(addstuwd),fixadd);
    GtkWidget *titadd=gtk_label_new("增加学生信息");
    gtk_label_set_markup(GTK_LABEL(titadd),"<span font_desc='25'>增加学生信息</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),titadd,390,110);
    GtkWidget *num=gtk_label_new("学号");
    gtk_label_set_markup(GTK_LABEL(num) ,"<span font_desc='20'>学号：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),num,300,180);
    GtkWidget *numm=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(numm), 6);
    gtk_fixed_put(GTK_FIXED(fixadd),numm,480,190);
    GtkWidget *name=gtk_label_new("姓名");
    gtk_label_set_markup(GTK_LABEL(name),"<span font_desc='20'>姓名：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),name,300,280);
    GtkWidget *namee=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(namee), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),namee,480,290);
    GtkWidget *sc=gtk_label_new("已选课程");
    gtk_label_set_markup(GTK_LABEL(sc),"<span font_desc='20'>已选课程：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),sc,300,380);
    GtkWidget *scc=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(scc), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),scc,480,390);
    GtkWidget *tot=gtk_label_new("总学分");
    gtk_label_set_markup(GTK_LABEL(tot),"<span font_desc='20'>总学分：</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),tot,300,480);
    GtkWidget *tott=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(tott), 10);
    gtk_fixed_put(GTK_FIXED(fixadd),tott,480,490);
    GtkWidget *addback=gtk_button_new_with_label("返回");
    GtkWidget *addback1=gtk_bin_get_child(GTK_WIDGET(addback));
    gtk_label_set_markup(GTK_LABEL(addback1),"<span font_desc='20'>返回</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),addback,500,580);
    gtk_widget_set_size_request(addback,130, 20);
    g_signal_connect(G_OBJECT(addback),"clicked",G_CALLBACK(mscreen),addstuwd);
    sst.a0=GTK_ENTRY(numm);
    sst.a1=GTK_ENTRY(namee);
    sst.a2=GTK_ENTRY(scc);
    sst.a3=GTK_ENTRY(tott);
    GtkWidget *addlog=gtk_button_new_with_label("确定");
    GtkWidget *addlog1=gtk_bin_get_child(GTK_WIDGET(addlog));
    gtk_label_set_markup(GTK_LABEL(addlog1),"<span font_desc='20'>确定</span>");
    gtk_fixed_put(GTK_FIXED(fixadd),addlog,300,580);
    gtk_widget_set_size_request(addlog,130, 20);
    g_signal_connect(G_OBJECT(addlog),"clicked",G_CALLBACK(addcfirm),&sst);
    g_signal_connect(G_OBJECT(addstuwd),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_widget_show_all(addstuwd);
}
void stinfosc2(GtkWidget *btx,gpointer arg)
{
    gtk_widget_hide(stuwindow);
    stuinfo=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(stuinfo),"课程信息");
    gtk_widget_set_size_request(stuinfo,1024,1024);
    GtkWidget* fixinfo=gtk_fixed_new();
    GtkWidget* iminfo=gtk_image_new_from_file("image/stuinfo.png");
    gtk_fixed_put(GTK_FIXED(fixinfo),iminfo,0,0);
    GtkWidget *tit=gtk_label_new("课 程 信 息");
    gtk_label_set_markup(GTK_LABEL(tit),"<span font_desc='35'>课 程 信 息</span>");
    gtk_fixed_put(GTK_FIXED(fixinfo),tit,520,60);
    GtkWidget *lb[20];
    FILE* f=fopen("scm/infoco.txt","r");
    char bf[100];
    int i=0;
    GtkWidget *scrlledwd;
    scrlledwd = gtk_scrolled_window_new(NULL,NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrlledwd),
                                   GTK_POLICY_AUTOMATIC,GTK_POLICY_ALWAYS);
    while(fgets(bf,100,f)!=NULL){
        if(strlen(bf)<2){
            continue;
        }
        lb[i]=gtk_label_new(bf);
        PangoFontDescription *desc_info = pango_font_description_from_string("25");
        gtk_widget_modify_font (lb[i], desc_info);
        pango_font_description_free(desc_info);
        gtk_fixed_put(GTK_FIXED(fixinfo),lb[i],450,180+40*i);
        i++;
    }
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrlledwd),fixinfo);
    gtk_container_add(GTK_CONTAINER(stuinfo),scrlledwd);
    GtkWidget *infoback=gtk_button_new_with_label("返回");
    GtkWidget *infoback1=gtk_bin_get_child(GTK_WIDGET(infoback));
    gtk_label_set_markup(GTK_LABEL(infoback1),"<span font_desc='25'>返回</span>");
    gtk_fixed_put(GTK_FIXED(fixinfo),infoback,720,130);
    gtk_widget_set_size_request(infoback,110, 25);
    g_signal_connect(G_OBJECT(infoback),"clicked",G_CALLBACK(mscreen),stuinfo);
    GtkWidget *addstu=gtk_button_new_with_label("增加");
    GtkWidget *addstu1=gtk_bin_get_child(GTK_WIDGET(addstu));
    gtk_label_set_markup(GTK_LABEL(addstu1),"<span font_desc='25'>增加</span>");
    gtk_fixed_put(GTK_FIXED(fixinfo),addstu,430,130);
    gtk_widget_set_size_request(addstu,110, 25);
    g_signal_connect(G_OBJECT(addstu),"clicked",G_CALLBACK(add2info),NULL);
    g_signal_connect(G_OBJECT(stuinfo),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_widget_show_all(stuinfo);
}
void stinfosc(GtkWidget *btx,gpointer arg)
{
    gtk_widget_hide(stuwindow);
    stuinfo=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(stuinfo),"学生信息");
    gtk_widget_set_size_request(stuinfo,1024,1024);
    GtkWidget* fixinfo=gtk_fixed_new();
    GtkWidget* iminfo=gtk_image_new_from_file("image/stuinfo.png");
    gtk_fixed_put(GTK_FIXED(fixinfo),iminfo,0,0);
    GtkWidget *tit=gtk_label_new("学 生 信 息");
    gtk_label_set_markup(GTK_LABEL(tit),"<span font_desc='35'>学 生 信 息</span>");
    gtk_fixed_put(GTK_FIXED(fixinfo),tit,520,60);
    GtkWidget *lb[20];
    FILE* f=fopen("sim/info.txt","r");
    char bf[100];
    int i=0;
    GtkWidget *scrlledwd;
    scrlledwd = gtk_scrolled_window_new(NULL,NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrlledwd),
                                   GTK_POLICY_AUTOMATIC,GTK_POLICY_ALWAYS);
    while(fgets(bf,100,f)!=NULL){
        if(strlen(bf)<2){
            continue;
        }
        lb[i]=gtk_label_new(bf);
        PangoFontDescription *desc_info = pango_font_description_from_string("25");
        gtk_widget_modify_font (lb[i], desc_info);
        pango_font_description_free(desc_info);
        gtk_fixed_put(GTK_FIXED(fixinfo),lb[i],400,180+40*i);
        i++;
    }
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrlledwd),fixinfo);
    gtk_container_add(GTK_CONTAINER(stuinfo),scrlledwd);
    GtkWidget *infoback=gtk_button_new_with_label("返回");
    GtkWidget *infoback1=gtk_bin_get_child(GTK_WIDGET(infoback));
    gtk_label_set_markup(GTK_LABEL(infoback1),"<span font_desc='25'>返回</span>");
    gtk_fixed_put(GTK_FIXED(fixinfo),infoback,720,130);
    gtk_widget_set_size_request(infoback,110, 25);
    g_signal_connect(G_OBJECT(infoback),"clicked",G_CALLBACK(mscreen),stuinfo);
    GtkWidget *addstu=gtk_button_new_with_label("增加");
    GtkWidget *addstu1=gtk_bin_get_child(GTK_WIDGET(addstu));
    gtk_label_set_markup(GTK_LABEL(addstu1),"<span font_desc='25'>增加</span>");
    gtk_fixed_put(GTK_FIXED(fixinfo),addstu,430,130);
    gtk_widget_set_size_request(addstu,110, 25);
    g_signal_connect(G_OBJECT(addstu),"clicked",G_CALLBACK(addinfo),NULL);
    g_signal_connect(G_OBJECT(stuinfo),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_widget_show_all(stuinfo);
}
void mscreen(GtkWidget *btback,gpointer arg)
{
    gtk_widget_hide(arg);
    gtk_widget_show_all(window);
}
void fileinput2(GtkWidget *finaentry,gpointer arg)
{
    const char *filename=gtk_entry_get_text(GTK_ENTRY(arg));
    gtk_widget_hide(stuwindow);
    gtk_widget_hide(wdinit);
    gtk_widget_hide(wdfiname);
    if(fopen(filename,"r")==NULL){
        wdinsu=gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(wdinsu),"初始化失败");
        gtk_widget_set_size_request(wdinsu,600,250);
        GtkWidget* fixinsu=gtk_fixed_new();
        GtkImage* iminsu=gtk_image_new_from_file("image/insu.png");
        gtk_fixed_put(GTK_FIXED(fixinsu),iminsu,0,0);
        gtk_container_add(GTK_CONTAINER(wdinsu),fixinsu);
        GtkWidget *lbinsu=gtk_label_new("课程信息初始化失败");
        gtk_label_set_markup(GTK_LABEL(lbinsu),"<span  font_desc='25'>课程信息初始化失败</span>");
        gtk_widget_set_size_request(lbinsu,60,80);
        gtk_fixed_put(GTK_FIXED(fixinsu),lbinsu,200,40);
        GtkWidget *btback=gtk_button_new_with_label("返回");
        GtkWidget *btback1=gtk_bin_get_child(GTK_WIDGET(btback));
        gtk_label_set_markup(GTK_LABEL(btback1),"<span font_desc='25'>返回</span>");
        gtk_fixed_put(GTK_FIXED(fixinsu),btback,280,150);
        gtk_widget_set_size_request(btback,130, 40);
        g_signal_connect(G_OBJECT(btback),"clicked",G_CALLBACK(mscreen),wdinsu);
        g_signal_connect(G_OBJECT(wdinsu), "destroy", G_CALLBACK(gtk_main_quit), NULL);
        gtk_widget_show_all(wdinsu);
    }else{
        init2(filename);
        wdinsu=gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(wdinsu),"初始化成功");
        gtk_widget_set_size_request(wdinsu,600,250);
        GtkWidget* fixinsu=gtk_fixed_new();
        GtkImage* iminsu=gtk_image_new_from_file("image/insu.png");
        gtk_fixed_put(GTK_FIXED(fixinsu),iminsu,0,0);
        gtk_container_add(GTK_CONTAINER(wdinsu),fixinsu);
        GtkWidget *lbinsu=gtk_label_new("课程信息初始化成功");
        gtk_label_set_markup(GTK_LABEL(lbinsu),"<span  font_desc='25'>课程信息初始化成功</span>");
        gtk_widget_set_size_request(lbinsu,60,80);
        gtk_fixed_put(GTK_FIXED(fixinsu),lbinsu,200,40);
        GtkWidget *btback=gtk_button_new_with_label("返回");
        GtkWidget *btback1=gtk_bin_get_child(GTK_WIDGET(btback));
        gtk_label_set_markup(GTK_LABEL(btback1),"<span font_desc='25'>返回</span>");
        gtk_fixed_put(GTK_FIXED(fixinsu),btback,280,150);
        gtk_widget_set_size_request(btback,130, 40);
        g_signal_connect(G_OBJECT(btback),"clicked",G_CALLBACK(mscreen),wdinsu);
        g_signal_connect(G_OBJECT(wdinsu), "destroy", G_CALLBACK(gtk_main_quit), NULL);
        gtk_widget_show_all(wdinsu);
    }
}
void fileinput(GtkWidget *finaentry,gpointer arg)
{
    const char *filename=gtk_entry_get_text(GTK_ENTRY(arg));
    gtk_widget_hide(stuwindow);
    gtk_widget_hide(wdinit);
    gtk_widget_hide(wdfiname);
    if(fopen(filename,"r")==NULL){
        wdinsu=gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(wdinsu),"初始化失败");
        gtk_widget_set_size_request(wdinsu,600,250);
        GtkWidget* fixinsu=gtk_fixed_new();
        GtkImage* iminsu=gtk_image_new_from_file("image/insu.png");
        gtk_fixed_put(GTK_FIXED(fixinsu),iminsu,0,0);
        gtk_container_add(GTK_CONTAINER(wdinsu),fixinsu);
        GtkWidget *lbinsu=gtk_label_new("学生信息初始化失败");
        gtk_label_set_markup(GTK_LABEL(lbinsu),"<span  font_desc='25'>学生信息初始化失败</span>");
        gtk_widget_set_size_request(lbinsu,60,80);
        gtk_fixed_put(GTK_FIXED(fixinsu),lbinsu,200,40);
        GtkWidget *btback=gtk_button_new_with_label("返回");
        GtkWidget *btback1=gtk_bin_get_child(GTK_WIDGET(btback));
        gtk_label_set_markup(GTK_LABEL(btback1),"<span font_desc='25'>返回</span>");
        gtk_fixed_put(GTK_FIXED(fixinsu),btback,280,150);
        gtk_widget_set_size_request(btback,130, 40);
        g_signal_connect(G_OBJECT(btback),"clicked",G_CALLBACK(mscreen),wdinsu);
        g_signal_connect(G_OBJECT(wdinsu), "destroy", G_CALLBACK(gtk_main_quit), NULL);
        gtk_widget_show_all(wdinsu);
    }else{
        init1(filename);
        wdinsu=gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(wdinsu),"初始化成功");
        gtk_widget_set_size_request(wdinsu,600,250);
        GtkWidget* fixinsu=gtk_fixed_new();
        GtkImage* iminsu=gtk_image_new_from_file("image/insu.png");
        gtk_fixed_put(GTK_FIXED(fixinsu),iminsu,0,0);
        gtk_container_add(GTK_CONTAINER(wdinsu),fixinsu);
        GtkWidget *lbinsu=gtk_label_new("学生信息初始化成功");
        gtk_label_set_markup(GTK_LABEL(lbinsu),"<span  font_desc='25'>学生信息初始化成功</span>");
        gtk_widget_set_size_request(lbinsu,60,80);
        gtk_fixed_put(GTK_FIXED(fixinsu),lbinsu,200,40);
        GtkWidget *btback=gtk_button_new_with_label("返回");
        GtkWidget *btback1=gtk_bin_get_child(GTK_WIDGET(btback));
        gtk_label_set_markup(GTK_LABEL(btback1),"<span font_desc='25'>返回</span>");
        gtk_fixed_put(GTK_FIXED(fixinsu),btback,280,150);
        gtk_widget_set_size_request(btback,130, 40);
        g_signal_connect(G_OBJECT(btback),"clicked",G_CALLBACK(mscreen),wdinsu);
        g_signal_connect(G_OBJECT(wdinsu), "destroy", G_CALLBACK(gtk_main_quit), NULL);
        gtk_widget_show_all(wdinsu);
    }
}
void finainput2(GtkButton *btinit1,gpointer arg)
{
    wdfiname=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(wdfiname),"文件名");
    gtk_widget_set_size_request(wdfiname,600,250);
    GtkWidget *fixfina=gtk_fixed_new();
    GtkImage *imfina=gtk_image_new_from_file ("image/fina.png");
    gtk_fixed_put(GTK_FIXED(fixfina),imfina,0,0);
    gtk_container_add(GTK_CONTAINER(wdfiname),fixfina);
    GtkWidget *lbfina=gtk_label_new("请输入文件名：");
    gtk_label_set_markup(GTK_LABEL(lbfina),"<span  font_desc='25'>请输入文件名：</span>");
    gtk_widget_set_size_request(lbfina,100,80);
    gtk_fixed_put(GTK_FIXED(fixfina),lbfina,250,60);
    GtkWidget *finaentry=gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(fixfina),finaentry,500,80);
    gtk_widget_set_size_request(finaentry,100,50);
    g_signal_connect(finaentry,"activate",G_CALLBACK(fileinput),finaentry);
    GtkWidget *btfina=gtk_button_new_with_label("确定");
    GtkWidget *btfina1=gtk_bin_get_child(GTK_WIDGET(btfina));
    gtk_label_set_markup(GTK_LABEL(btfina1),"<span  font_desc='25'>确定</span>");
    gtk_fixed_put(GTK_FIXED(fixfina),btfina,450,180);
    gtk_widget_set_size_request(btfina1,100, 50);
    g_signal_connect(btfina,"clicked",G_CALLBACK(fileinput2),finaentry);
    g_signal_connect(G_OBJECT(wdfiname), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show_all(wdfiname);
}
void finainput(GtkButton *btinit1,gpointer arg)
{
    wdfiname=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(wdfiname),"文件名");
    gtk_widget_set_size_request(wdfiname,600,250);
    GtkWidget *fixfina=gtk_fixed_new();
    GtkImage *imfina=gtk_image_new_from_file ("image/fina.png");
    gtk_fixed_put(GTK_FIXED(fixfina),imfina,0,0);
    gtk_container_add(GTK_CONTAINER(wdfiname),fixfina);
    GtkWidget *lbfina=gtk_label_new("请输入文件名：");
    gtk_label_set_markup(GTK_LABEL(lbfina),"<span  font_desc='25'>请输入文件名：</span>");
    gtk_widget_set_size_request(lbfina,100,80);
    gtk_fixed_put(GTK_FIXED(fixfina),lbfina,250,60);
    GtkWidget *finaentry=gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(fixfina),finaentry,500,80);
    gtk_widget_set_size_request(finaentry,100,50);
    g_signal_connect(finaentry,"activate",G_CALLBACK(fileinput),finaentry);
    GtkWidget *btfina=gtk_button_new_with_label("确定");
    GtkWidget *btfina1=gtk_bin_get_child(GTK_WIDGET(btfina));
    gtk_label_set_markup(GTK_LABEL(btfina1),"<span  font_desc='25'>确定</span>");
    gtk_fixed_put(GTK_FIXED(fixfina),btfina,450,180);
    gtk_widget_set_size_request(btfina1,100, 50);
    g_signal_connect(btfina,"clicked",G_CALLBACK(fileinput),finaentry);
    g_signal_connect(G_OBJECT(wdfiname), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show_all(wdfiname);
}
void callstuinit2(GtkButton *bt1,gpointer arg)
{
    wdinit=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_app_paintable (wdinit, TRUE);
    gtk_window_set_title(GTK_WINDOW(wdinit),"课程信息初始化方式");
    gtk_widget_set_size_request(wdinit,700,400);
    GtkWidget *fixinit=gtk_fixed_new();
    GtkImage *iminit=gtk_image_new_from_file ("image/init.png");
    gtk_fixed_put(GTK_FIXED(fixinit),iminit,0,0);
    gtk_container_add(GTK_CONTAINER(wdinit),fixinit);
    GtkWidget *lbinit=gtk_label_new("课程信息初始化方式");
    gtk_label_set_markup(GTK_LABEL(lbinit),"<span  font_desc='35'>课程信息初始化方式</span>");
    gtk_widget_set_size_request(lbinit,100,80);
    gtk_fixed_put(GTK_FIXED(fixinit),lbinit,210,60);
    GtkWidget *btinit1=gtk_button_new_with_label("文件导入");
    GtkWidget *bti1=gtk_bin_get_child(GTK_WIDGET(btinit1));
    gtk_label_set_markup(GTK_LABEL(bti1),"<span  font_desc='25'>文件导入</span>");
    gtk_fixed_put(GTK_FIXED(fixinit),btinit1,230,180);
    gtk_widget_set_size_request(bti1,100, 70);
    g_signal_connect(btinit1,"clicked",G_CALLBACK(finainput2),NULL);
    GtkWidget *btinit2=gtk_button_new_with_label("键盘输入");
    GtkWidget *bti2=gtk_bin_get_child(GTK_WIDGET(btinit2));
    gtk_label_set_markup(GTK_LABEL(bti2),"<span  font_desc='25'>键盘输入</span>");
    gtk_fixed_put(GTK_FIXED(fixinit),btinit2,430,180);
    gtk_widget_set_size_request(bti2,100, 70);
    g_signal_connect(btinit2,"clicked",G_CALLBACK(add2info2),NULL);
    gtk_widget_show_all(wdinit);
    g_signal_connect(G_OBJECT(wdinit), "destroy", G_CALLBACK(gtk_main_quit), NULL);
}
void callstuinit(GtkButton *bt1,gpointer arg)
{
    wdinit=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_app_paintable (wdinit, TRUE);
    gtk_window_set_title(GTK_WINDOW(wdinit),"学生信息初始化方式");
    gtk_widget_set_size_request(wdinit,700,400);
    GtkWidget *fixinit=gtk_fixed_new();
    GtkImage *iminit=gtk_image_new_from_file ("image/init.png");
    gtk_fixed_put(GTK_FIXED(fixinit),iminit,0,0);
    gtk_container_add(GTK_CONTAINER(wdinit),fixinit);
    GtkWidget *lbinit=gtk_label_new("学生信息初始化方式");
    gtk_label_set_markup(GTK_LABEL(lbinit),"<span  font_desc='35'>学生信息初始化方式</span>");
    gtk_widget_set_size_request(lbinit,100,80);
    gtk_fixed_put(GTK_FIXED(fixinit),lbinit,210,60);
    GtkWidget *btinit1=gtk_button_new_with_label("文件导入");
    GtkWidget *bti1=gtk_bin_get_child(GTK_WIDGET(btinit1));
    gtk_label_set_markup(GTK_LABEL(bti1),"<span  font_desc='25'>文件导入</span>");
    gtk_fixed_put(GTK_FIXED(fixinit),btinit1,230,180);
    gtk_widget_set_size_request(bti1,100, 70);
    g_signal_connect(btinit1,"clicked",G_CALLBACK(finainput),NULL);
    GtkWidget *btinit2=gtk_button_new_with_label("键盘输入");
    GtkWidget *bti2=gtk_bin_get_child(GTK_WIDGET(btinit2));
    gtk_label_set_markup(GTK_LABEL(bti2),"<span  font_desc='25'>键盘输入</span>");
    gtk_fixed_put(GTK_FIXED(fixinit),btinit2,430,180);
    gtk_widget_set_size_request(bti2,100, 70);
    g_signal_connect(btinit2,"clicked",G_CALLBACK(addinfo2),NULL);
    gtk_widget_show_all(wdinit);
    g_signal_connect(G_OBJECT(wdinit), "destroy", G_CALLBACK(gtk_main_quit), NULL);
}
void callback2(GtkButton *button1,gpointer arg)
{
    gtk_widget_hide(window);
    stuwindow=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_app_paintable (stuwindow, TRUE);
    gtk_window_set_title(GTK_WINDOW(stuwindow),"课程信息管理");
    gtk_widget_set_size_request(stuwindow,1024,1024);
    GtkWidget *fixed2=gtk_fixed_new();
    GtkImage *image2;
    image2 = gtk_image_new_from_file ("image/2.png");
    gtk_fixed_put(GTK_FIXED(fixed2),image2,0,0);
    gtk_container_add(GTK_CONTAINER(stuwindow),fixed2);
    GtkWidget *label=gtk_label_new("课程信息管理");
    gtk_label_set_markup(GTK_LABEL(label),"<span  font_desc='35'>课程信息管理</span>");
    gtk_widget_set_size_request(label,100,80);
    gtk_fixed_put(GTK_FIXED(fixed2),label,600,100);
/*void init();//学生信息初始化
void addstu();//增加学生信息
void delstu();//删除学生信息
void viewstu();//查看学生信息
void modstu();//修改学生信息
*/
    GtkWidget *bt1=gtk_button_new_with_label("课程信息初始化");
    GtkWidget *blb1=gtk_bin_get_child(GTK_WIDGET(bt1));
    gtk_label_set_markup(GTK_LABEL(blb1),"<span  font_desc='25'>课程信息初始化</span>");
    gtk_fixed_put(GTK_FIXED(fixed2),bt1,620,200);
    gtk_widget_set_size_request(bt1,250, 70);
    g_signal_connect(bt1,"clicked",G_CALLBACK(callstuinit2),NULL);
    GtkWidget *bt2=gtk_button_new_with_label("新增课程信息");
    GtkWidget *blb2=gtk_bin_get_child(GTK_WIDGET(bt2));
    gtk_label_set_markup(GTK_LABEL(blb2),"<span  font_desc='25'>新增课程信息</span>");
    gtk_fixed_put(GTK_FIXED(fixed2),bt2,620,300);
    gtk_widget_set_size_request(bt2,250, 70);
    g_signal_connect(bt2,"clicked",G_CALLBACK(stinfosc2),NULL);
    GtkWidget *bt3=gtk_button_new_with_label("删除课程信息");
    GtkWidget *blb3=gtk_bin_get_child(GTK_WIDGET(bt3));
    gtk_label_set_markup(GTK_LABEL(blb3),"<span  font_desc='25'>删除课程信息</span>");
    gtk_fixed_put(GTK_FIXED(fixed2),bt3,620,400);
    gtk_widget_set_size_request(bt3,250, 70);
    g_signal_connect(bt3,"clicked",G_CALLBACK(stdel2),NULL);
    GtkWidget *bt4=gtk_button_new_with_label("查看课程信息");
    GtkWidget *blb4=gtk_bin_get_child(GTK_WIDGET(bt4));
    gtk_label_set_markup(GTK_LABEL(blb4),"<span  font_desc='25'>查看课程信息</span>");
    gtk_fixed_put(GTK_FIXED(fixed2),bt4,620,500);
    gtk_widget_set_size_request(bt4,250, 70);
    g_signal_connect(bt4,"clicked",G_CALLBACK(viewco),NULL);
    GtkWidget *bt5=gtk_button_new_with_label("修改学课程信息");
    GtkWidget *blb5=gtk_bin_get_child(GTK_WIDGET(bt5));
    gtk_label_set_markup(GTK_LABEL(blb5),"<span  font_desc='25'>修改课程信息</span>");
    gtk_fixed_put(GTK_FIXED(fixed2),bt5,620,600);
    gtk_widget_set_size_request(bt5,250, 70);
    g_signal_connect(bt5,"clicked",G_CALLBACK(cmost),NULL);
    gtk_widget_show_all(stuwindow);
    g_signal_connect(G_OBJECT(stuwindow), "destroy", G_CALLBACK(gtk_main_quit), NULL);
}
void callback1(GtkButton *button1,gpointer arg)
{
    gtk_widget_hide(window);
    stuwindow=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_app_paintable (stuwindow, TRUE);
    gtk_window_set_title(GTK_WINDOW(stuwindow),"学生信息管理");
    gtk_widget_set_size_request(stuwindow,1024,1024);
    GtkWidget *fixed2=gtk_fixed_new();
    GtkImage *image2;
    image2 = gtk_image_new_from_file ("image/2.png");
    gtk_fixed_put(GTK_FIXED(fixed2),image2,0,0);
    gtk_container_add(GTK_CONTAINER(stuwindow),fixed2);
    GtkWidget *label=gtk_label_new("学生信息管理");
    gtk_label_set_markup(GTK_LABEL(label),"<span  font_desc='35'>学生信息管理</span>");
    gtk_widget_set_size_request(label,100,80);
    gtk_fixed_put(GTK_FIXED(fixed2),label,600,100);
/*void init();//学生信息初始化
void addstu();//增加学生信息
void delstu();//删除学生信息
void viewstu();//查看学生信息
void modstu();//修改学生信息
*/
    GtkWidget *bt1=gtk_button_new_with_label("学生信息初始化");
    GtkWidget *blb1=gtk_bin_get_child(GTK_WIDGET(bt1));
    gtk_label_set_markup(GTK_LABEL(blb1),"<span  font_desc='25'>学生信息初始化</span>");
    gtk_fixed_put(GTK_FIXED(fixed2),bt1,620,200);
    gtk_widget_set_size_request(bt1,250, 70);
    g_signal_connect(bt1,"clicked",G_CALLBACK(callstuinit),NULL);
    GtkWidget *bt2=gtk_button_new_with_label("增加学生信息");
    GtkWidget *blb2=gtk_bin_get_child(GTK_WIDGET(bt2));
    gtk_label_set_markup(GTK_LABEL(blb2),"<span  font_desc='25'>增加学生信息</span>");
    gtk_fixed_put(GTK_FIXED(fixed2),bt2,620,300);
    gtk_widget_set_size_request(bt2,250, 70);
    g_signal_connect(bt2,"clicked",G_CALLBACK(stinfosc),NULL);
    GtkWidget *bt3=gtk_button_new_with_label("删除学生信息");
    GtkWidget *blb3=gtk_bin_get_child(GTK_WIDGET(bt3));
    gtk_label_set_markup(GTK_LABEL(blb3),"<span  font_desc='25'>删除学生信息</span>");
    gtk_fixed_put(GTK_FIXED(fixed2),bt3,620,400);
    gtk_widget_set_size_request(bt3,250, 70);
    g_signal_connect(bt3,"clicked",G_CALLBACK(stdel),NULL);
    GtkWidget *bt4=gtk_button_new_with_label("查看学生信息");
    GtkWidget *blb4=gtk_bin_get_child(GTK_WIDGET(bt4));
    gtk_label_set_markup(GTK_LABEL(blb4),"<span  font_desc='25'>查看学生信息</span>");
    gtk_fixed_put(GTK_FIXED(fixed2),bt4,620,500);
    gtk_widget_set_size_request(bt4,250, 70);
    g_signal_connect(bt4,"clicked",G_CALLBACK(viewst),NULL);
    GtkWidget *bt5=gtk_button_new_with_label("修改学生信息");
    GtkWidget *blb5=gtk_bin_get_child(GTK_WIDGET(bt5));
    gtk_label_set_markup(GTK_LABEL(blb5),"<span  font_desc='25'>修改学生信息</span>");
    gtk_fixed_put(GTK_FIXED(fixed2),bt5,620,600);
    gtk_widget_set_size_request(bt5,250, 70);
    g_signal_connect(bt5,"clicked",G_CALLBACK(most),NULL);
    gtk_widget_show_all(stuwindow);
    g_signal_connect(G_OBJECT(stuwindow), "destroy", G_CALLBACK(gtk_main_quit), NULL);
}
int main(int argc,char* argv[])
{
    gtk_init(&argc,&argv);
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_app_paintable (window, TRUE);
    gtk_window_set_title(GTK_WINDOW(window),"学生选课系统管理");
    gtk_widget_set_size_request(window,1024,1024);
    GtkWidget *fixed=gtk_fixed_new();
    GtkImage *imagew;
    imagew = gtk_image_new_from_file ("image/1.png");
    gtk_fixed_put(GTK_FIXED(fixed),imagew,0,0);
    gtk_container_add(GTK_CONTAINER(window),fixed);
    GtkWidget *button1=gtk_button_new_with_label("学生信息管理");
    GtkWidget *blb1=gtk_bin_get_child(GTK_WIDGET(button1));
    gtk_label_set_markup(GTK_LABEL(blb1),"<span  font_desc='25'>学生信息管理</span>");
    gtk_fixed_put(GTK_FIXED(fixed),button1,700,360);
    gtk_widget_set_size_request(button1,250, 70);
    g_signal_connect(button1,"clicked",G_CALLBACK(callback1),NULL);
    GtkWidget *button2=gtk_button_new_with_label("课程信息管理");
    GtkWidget *blb2=gtk_bin_get_child(GTK_WIDGET(button2));
    gtk_label_set_markup(GTK_LABEL(blb2),"<span  font_desc='25'>课程信息管理</span>");
    gtk_fixed_put(GTK_FIXED(fixed),button2,700,500);
    gtk_widget_set_size_request(button2,250, 70);
    g_signal_connect(button2,"clicked",G_CALLBACK(callback2),NULL);
    GtkWidget *label=gtk_label_new("学生选课系统");
    gtk_label_set_markup(GTK_LABEL(label),"<span  font_desc='35'>学生选课系统</span>");
    gtk_widget_set_size_request(label,300,100);
    gtk_fixed_put(GTK_FIXED(fixed),label,680,200);
    gtk_widget_show_all(window);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_main();
    return 0;
}
