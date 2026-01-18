#include<stdio.h>

int main(){
    FILE *fp;
    
    char name[50] = "tanmay";

    fp = fopen("data.txt", "w");
    
    if(fp == NULL){
        printf("ERROR IN THE FILE");
    }else {
        printf("FILE OPENED SUCCESSFULLY\n");
        fputs("tanmay", fp);
        fputs("\n", fp);
        fputs(name , fp);
        fputs("\n", fp);
        fprintf(fp, "Tanmay Pagare");
        fclose(fp);
        printf("THE DATA HAS BEEN ADDED SUCCESSFULLY\n");
    }
    return 0;
}