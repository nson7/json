#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

 int create_js(void)
 {
     cJSON *root;
     /*create json string root*/
     root = cJSON_CreateObject();
     if(!root) {
         printf("get root faild !\n");
         goto EXIT;
     }else printf("get root success!\n");

     {
         cJSON * js_body ;
         cJSON *ye_struct;

         const char *const body = "body";
         const char *const ye = "ye_nson7";
         cJSON_AddItemToObject(root, body, js_body=cJSON_CreateObject());
         cJSON_AddStringToObject(js_body,"name","xiaohui");
         cJSON_AddNumberToObject(js_body,"value",600);
         cJSON_AddStringToObject(js_body, "string", "ir_22");
         cJSON_AddItemToObject(root, ye, ye_struct=cJSON_CreateObject());
         cJSON_AddStringToObject(ye_struct,"name","xiaohui");
         cJSON_AddNumberToObject(ye_struct,"value",600);
         cJSON_AddStringToObject(ye_struct, "string", "ir_22");
         {
         /* char *s = cJSON_PrintUnformatted(root); */
         char *s = cJSON_Print(root);
         if(s){
             printf("create js string is \n%s\n",s);
             free(s);
         }
         }
         cJSON_Delete(root);
     }

     return 0;
 EXIT:
     return -1;
 }

 int main(int argc, char **argv)
 {
     create_js();
     return 0;
 }
