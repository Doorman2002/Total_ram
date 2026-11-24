#include<stdio.h>
#include<stdlib.h>


void ram(void);


void main(){

    // printf("Hello");
    ram();
}


void ram(){
    // system("pwd");
    char t_ram[]="MemTotal:";

    char buffer[256];
    FILE *fp= popen("cat /proc/meminfo","r");

    if (fp == NULL){
        perror("unable to open the file");
        return;
    }

    while(fgets(buffer,sizeof(buffer),fp) != NULL){
        
        // printf("%s",buffer);
        int match=0;
        for (int i=0; t_ram[i] != '\0'; i++){
            if (buffer[i] != t_ram[i]){
                match =0;
                break;
            }
            else if ( buffer[i] ==t_ram[i]){
                match=1;

            }
        }
        char ram[256];
        if (match==1){
         int start_point=9;
         int j =0;
         char first_store[32];
        while( buffer[start_point] ==' '){
            start_point++;
        }
        for (start_point;start_point < sizeof(buffer) && (buffer[start_point] !='k'); start_point++) {
            // printf("%c",buffer[start_point]);
            first_store[j]=buffer[start_point];
            j++;
        }
        first_store[j]='\0';
        // printf("%s",first_store);
        // type cast the first store

        int total_ram=atoi(first_store);
        float t_ram=(float) total_ram;
        
        printf("%.2f GB total RAM",t_ram/1024/1024);
               
         
        }

    }
    pclose(fp);
}