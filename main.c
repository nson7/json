/*************************************************************************
    > File Name: main.c
	> Author: nson7
	> Mail: nson7@sina.com
	> Created Time: 2016年08月18日 星期四 11时59分56秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

int main(int argc, char **argv)
{
     char *s = "{\"list\":[\"name1\",\"name2\"]}";

     cJSON *root = cJSON_Parse(s);
     if(!root) {
         printf("get root faild !\n");
         return -1;
     }
         cJSON *js_list = cJSON_GetObjectItem(root, "list");
          if(!js_list){
              printf("no list!\n");
              return -1;
          }

          int array_size = cJSON_GetArraySize(js_list);
          printf("array size is %d\n",array_size);
          int i = 0;
          cJSON *item;
          for(i=0; i< array_size; i++) {
              item = cJSON_GetArrayItem(js_list, i);
              printf("item type is %d\n",item->type);
              printf("%s\n",item->valuestring);
          }

            if(root)
                cJSON_Delete(root);
              return 0;
          }
