#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

char * create1()
{
     cJSON *root,*dir1,*dir2,*dir3;
     cJSON *dir4;
     char *out;
     //创建json数组型结构体
     root = cJSON_CreateArray();
     //为数组添加对象
     cJSON_AddItemToArray(root,dir1=cJSON_CreateObject());
     //为对象添加字符串键值对
     cJSON_AddStringToObject(dir1,"name",".");
     cJSON_AddStringToObject(dir1,"path","uploads/");
     cJSON_AddStringToObject(dir1,"flag","true");
     cJSON_AddNumberToObject(dir1, "value", 1);
     cJSON_AddItemToArray(root,dir2=cJSON_CreateObject());
     cJSON_AddStringToObject(dir2,"name","..");
     cJSON_AddStringToObject(dir2,"path","uploads");
     cJSON_AddStringToObject(dir2,"flag","true");
     cJSON_AddNumberToObject(dir2, "value", 9);
     cJSON_AddItemToArray(root,dir3=cJSON_CreateObject());
     cJSON_AddStringToObject(dir3,"name","wang.txt");
     cJSON_AddStringToObject(dir3,"path","uploads/wang.txt");
     cJSON_AddStringToObject(dir3,"flag","false");
     cJSON_AddNumberToObject(dir3, "value", 111);
     cJSON_AddItemToArray(root,dir4=cJSON_CreateObject());
     cJSON_AddStringToObject(dir4,"name","nson7--ye");
     cJSON_AddStringToObject(dir4,"path","/git/ye");
     cJSON_AddStringToObject(dir4,"flag","true");
     cJSON_AddNumberToObject(dir4, "value", 7);
     //将json结构体转换为字符串
     out=cJSON_Print(root);
     //删除
     cJSON_Delete(root);
     return out;
}

void parse1(char *out)
{
     cJSON * root,*arrayItem,*item,*name,*path,*flag;
     cJSON *value;
     int i = 0,size = 0;
     char *pr = NULL,*na = NULL,*pa = NULL,*fl = NULL;
     char *va;

     //将字符串解析成json结构体
     root = cJSON_Parse(out);
     //根据结构体获取数组大小
     size = cJSON_GetArraySize(root);
     //printf("%d\n",size);
     //遍历数组
     for(i=0;i<size;i++)
     {
         //获取第i个数组项
         arrayItem = cJSON_GetArrayItem(root,i);
         if(arrayItem)
         {
              //printf("%s\n","start......");
              //讲json结构体转换成字符串
              pr = cJSON_Print(arrayItem);
              item = cJSON_Parse(pr);
              name = cJSON_GetObjectItem(item,"name");
              path = cJSON_GetObjectItem(item,"path");
              flag = cJSON_GetObjectItem(item,"flag");
              value = cJSON_GetObjectItem(item, "value");
              na = cJSON_Print(name);
              pa = cJSON_Print(path);
              fl = cJSON_Print(flag);
              va = cJSON_Print(value);
              //printf("%s\n",pr);
              printf("name:%s\n",na);
              printf("name1:%s\n",name->valuestring);
              printf("path:%s\n",pa);
              printf("flag:%s\n",fl);
              printf("value:%s\n\n", va);
              printf("value1:%d\n", value->valueint);
         }
     }
}

char * create2()
{
     cJSON *root,*dir,*child,*subdir,*dir1,*dir2,*dir3;
     char *out;
     root=cJSON_CreateObject();

     cJSON_AddItemToObject(root,"Root",dir=cJSON_CreateObject());
     cJSON_AddStringToObject(dir,"name","/");
     cJSON_AddStringToObject(dir,"path","/");
     cJSON_AddStringToObject(dir,"flag","true");

     cJSON_AddItemToObject(root,"Child",subdir = cJSON_CreateArray());
     cJSON_AddItemToObject(subdir,"dira",dir1=cJSON_CreateObject());
     cJSON_AddStringToObject(dir1,"name",".");
     cJSON_AddStringToObject(dir1,"path","/./");
     cJSON_AddStringToObject(dir1,"flag","true");
     cJSON_AddItemToObject(subdir,"dira",dir2=cJSON_CreateObject());
     cJSON_AddStringToObject(dir2,"name","..");
     cJSON_AddStringToObject(dir2,"path","/../");
     cJSON_AddStringToObject(dir2,"flag","true");
     cJSON_AddItemToObject(subdir,"dira",dir3=cJSON_CreateObject());
     cJSON_AddStringToObject(dir3,"name","uploads");
     cJSON_AddStringToObject(dir3,"path","/uploads/");
     cJSON_AddStringToObject(dir3,"flag","true");

     out=cJSON_Print(root);
     cJSON_Delete(root);
     return out;
}

void parse2(char *out)
{
     cJSON * root,*Root,*Child,*arrayItem,*item,*name,*path,*flag;
     int i = 0,size = 0;
     char *pr = NULL,*na = NULL,*pa = NULL,*fl = NULL;
     root = cJSON_Parse(out);
     if(root)
     {
         Root = cJSON_GetObjectItem(root,"Root");
         if(Root)
         {
              name = cJSON_GetObjectItem(Root,"name");
              path = cJSON_GetObjectItem(Root,"path");
              flag = cJSON_GetObjectItem(Root,"flag");
              na = cJSON_Print(name);
              pa = cJSON_Print(path);
              fl = cJSON_Print(flag);
              printf("Root:\n");
              printf("name:%s\n",na);
              printf("path:%s\n",pa);
              printf("flag:%s\n\n",fl);
         }
         Child = cJSON_GetObjectItem(root,"Child");
         if(Child)
         {
              size = cJSON_GetArraySize(Child);
              //printf("%d\n",size);
              printf("Child:\n");
              for(i=0;i<size;i++)
              {
                   arrayItem = cJSON_GetArrayItem(Child,i);
                   if(arrayItem)
                   {
                       //printf("%s\n","start......");
                       pr = cJSON_Print(arrayItem);
                       item = cJSON_Parse(pr);
                       name = cJSON_GetObjectItem(item,"name");
                       path = cJSON_GetObjectItem(item,"path");
                       flag = cJSON_GetObjectItem(item,"flag");
                       na = cJSON_Print(name);
                       pa = cJSON_Print(path);
                       fl = cJSON_Print(flag);
                       //printf("%s\n",pr);
                       printf("name:%s\n",na);
                       printf("path:%s\n",pa);
                       printf("flag:%s\n\n",fl);
                   }
              }
         }
     }
}

char * create3()
{
     cJSON *root,*img,*thm;
     char *out;
     int nums[4]={100,200,300,400};
     root=cJSON_CreateObject();
     cJSON_AddItemToObject(root, "Root", img=cJSON_CreateObject());
     cJSON_AddNumberToObject(img,"key",800);
     cJSON_AddNumberToObject(img,"value",600);
     cJSON_AddStringToObject(img,"Title","Sugon");
     cJSON_AddItemToObject(img,"child",thm=cJSON_CreateObject());
     cJSON_AddNumberToObject(thm,"key",125);
     cJSON_AddStringToObject(thm,"value","100");
         cJSON_AddStringToObject(thm,"Url","www.sugon.com");
     cJSON_AddItemToObject(img,"nums", cJSON_CreateIntArray(nums,4));
     out=cJSON_Print(root);
     cJSON_Delete(root);
     return out;
}

void parse3(char *out)
{
     cJSON *root,*Root,*Child, *key, *value, *Title, *Url, *Nums, *arrayItem, *nums, *pr, *item;
     int size, i;
     char *k, *va, *Ti, *t, *nu;
     root = cJSON_Parse(out);
     if(root)
     {
         Root = cJSON_GetObjectItem(root,"Root");
         if(Root)
         {
              key = cJSON_GetObjectItem(Root,"key");
              value = cJSON_GetObjectItem(Root,"value");
              Title = cJSON_GetObjectItem(Root,"Title");
              k = cJSON_Print(key);
              va = cJSON_Print(value);
              Ti = cJSON_Print(Title);
              printf("Root:\n");
              printf("key:%s\n",k);
              printf("value:%s\n",va);
              printf("Title:%s\n\n",Ti);
         }
         Child = cJSON_GetObjectItem(Root,"child");
         if(Child)
         {
            key = cJSON_GetObjectItem(Child,"key");
            value = cJSON_GetObjectItem(Child,"value");
            Url = cJSON_GetObjectItem(Child,"Url");
            k = cJSON_Print(key);
            va = cJSON_Print(value);
            t = cJSON_Print(Url);
            //printf("%s\n",pr);
            printf("key:%s\n",k);
            printf("value:%s\n",va);
            printf("thm:%s\n\n",t);
         }
         Nums = cJSON_GetObjectItem(Root,"nums");
         if(Nums)
         {
              size = cJSON_GetArraySize(Nums);
              //printf("%d\n",size);
              for(i=0;i<size;i++)
              {
                   arrayItem = cJSON_GetArrayItem(Nums,i);
                   if(arrayItem)
                   {
                       printf("nums=%d\n", arrayItem->valueint);
                   }
              }
         }
     }
}

char * create4()
{
     cJSON *root,*dir1,*dir2, *dir;
     char *out;
     const char *ro = "Root";
     root=cJSON_CreateObject();
     cJSON_AddItemToObject(root,ro,dir1=cJSON_CreateArray());
     cJSON_AddNumberToObject(dir1,"key",800);
     cJSON_AddNumberToObject(dir1,"value",600);
     cJSON_AddStringToObject(dir1,"Title","key and value");
     cJSON_AddItemToObject(root,"Child",dir2=cJSON_CreateArray());
     cJSON_AddNumberToObject(dir2,"value",125);
     cJSON_AddStringToObject(dir2,"key","100");
     cJSON_AddStringToObject(dir2,"Title","value and key");
     out=cJSON_Print(root);
     cJSON_Delete(root);
     return out;
}


void parse4(char *out)
{
     cJSON * root,*Root,*Child,*arrayItem,*item,*key,*value,*Title;
     int i = 0,size = 0;
     char *pr = NULL,*na = NULL,*pa = NULL,*fl = NULL;
     root = cJSON_Parse(out);
     if(root)
     {
         Root = cJSON_GetObjectItem(root,"Root");
         if(Root)
         {
              size = cJSON_GetArraySize(Root);
              //printf("%d\n",size);
              for(i=0;i<size;i++)
              {
                   arrayItem = cJSON_GetArrayItem(Root,i);
                   if(arrayItem)
                   {
                       pr = cJSON_Print(arrayItem);
                       printf("pr=%s\n", pr);
                   }
              }
         }
         Child = cJSON_GetObjectItem(root,"Child");
         if(Child)
         {
              size = cJSON_GetArraySize(Child);
              //printf("%d\n",size);
              for(i=0;i<size;i++)
              {
                   arrayItem = cJSON_GetArrayItem(Child,i);
                   if(arrayItem)
                   {
                       pr = cJSON_Print(arrayItem);
                       printf("pr=%s\n", pr);
                   }
              }
         }
     }
}

int main()
{
     /* char *out1 = create1(); */
     /* char *out2 = create2(); */
     char *out3 = create3();
     /* char *out4 = create4(); */
     /* printf("%s\n\n\n",out1); */
     /* parse1(out1); */
     /* printf("%s\n\n\n",out2); */
     /* parse2(out2); */
     printf("%s\n\n\n",out3);
     parse3(out3);
     /* printf("%s\n\n\n",out4); */
     /* parse4(out4); */
     return 0;
}

