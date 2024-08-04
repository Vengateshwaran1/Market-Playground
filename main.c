#define usad "admin"
#define psad "admin"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "admin.h"
#include "emp.h"
#include "conio.c"

int passcheck(char *,char *);
int main()
{
    int i=0,n;
    char usname[30],psname[30],c;
        system("cls");
        textcolor(7);
        printf("\n\n\n\t\t\tWelcome to Invoice and Inventory\n");
        printf("\t\t\tUsername : ");
        gets(usname);
        printf("\t\t\tPassword : ");
        i=0;
        while((c=getch())!=13){
            psname[i]=c;
            printf("*");
            i++;
        }
        psname[i]='\0';
        if(strcmp(usname,usad)==0&&strcmp(psname,psad)==0){
            adminaccess();
        }
        else{
            n=passcheck(usname,psname);
            if(n==1){
                empaccess();
            }
            else{
                textcolor(4);
                printf("\n\t\t\tUsername or Password is in vaild\n\t\t\tPress any key to continue.");
                getch();
                main();
            }
        }
    return 0;
}
int passcheck(char *us,char *ps){
    int reval=0;
    char usname[30],psname[30],name[30];
    FILE *fe=fopen("emp.txt","r");
    if(fe==NULL){
        printf("File not opened ");
        exit(1);
    }
    while((fscanf(fe,"%s %s %s",name,usname,psname))!=EOF){
        if((strcmp(usname,us)==0)&&(strcmp(psname,ps)==0)){
            reval=1;
            break ;
        }
    }
    fclose(fe);
    return reval;
}
