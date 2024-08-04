#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
#include "struct.c"
void addstocks();
void deletestocks();
void addemployee();
void deleteemployee();
void viewbills();
void viewstocks();
void updatestocks();
void adminaccess(){
    int opt;
    system("cls");
    textcolor(7);
    printf("\n\n\n\t\t\tWelcome to Invoice and Inventory\n");
    printf("\t\t\t1.Add Stocks.\n");
    printf("\t\t\t2.Delete Stocks.\n");
    printf("\t\t\t3.Update Stocks.\n");
    printf("\t\t\t4.View Stocks.\n");
    printf("\t\t\t5.Add Employee.\n");
    printf("\t\t\t6.Delete Employee\n");
    printf("\t\t\t7.View Bills\n");
    printf("\t\t\t8.Exit\n");
    printf("\t\t\tEnter Your Choice :");
    scanf("%d",&opt);
    switch (opt){
    case 1:
        addstocks();
        break ;
    case 2 :
        deletestocks();
        break ;
    case 3:
        updatestocks();
        break;
    case 4:
        viewstocks();
        break ;
    case 5:
        addemployee();
        break;
    case 6:
        deleteemployee();
        break;
    case 7:
        viewbills();
        break;
    case 8:
        exit(0);
        break;
    default :
        textcolor(4);
        printf("\t\t\tEnter A valid option\nPress any key to continue.");
        getch();
        adminaccess();
    }
}
void addstocks(){
    int n,i;
    char chckname[30];
    int chckprcode;
    int chckqty;
    float chckprice;
    float chcktax;
    struct pr p;
    FILE *fp=fopen("item.txt","a");
    FILE *fe=fopen("item.txt","r");
    if(fp==NULL){
        textcolor(4);
        printf("File not opened ");
        exit(0);
    }
    if(fe==NULL){
        textcolor(4);
        printf("File not opened ");
        exit(0);
    }
    system("cls");
    printf("\n\n\n\t\t\tAdd Stocks :\n");
    printf("\t\t\tEnter The name of the item :");
    scanf(" %[^\n]s",p.name);
    printf("\t\t\tEnter the item code:");
    scanf("%d",&p.prcode);
    while((fscanf(fe,"%d %s %d %f %f",&chckprcode,chckname,&chckqty,&chckprice,&chcktax))!=EOF){
        if(p.prcode==chckprcode){
            printf("\n\t\t\tThe Product code already exists name already Exists\n");
            printf("\t\t\tPress any key to cotinue");
            getch();
            addstocks();
        }
        else{
            continue;
        }
    }
    printf("\t\t\tEnter the Quantity:");
    scanf("%d",&p.qty);;
    if(p.qty<=0){
        printf("\t\t\tQuantity cannot be less than 1");
        printf("\t\t\tPress any key to cotinue");
        getch();
        addstocks();
    }
    printf("\t\t\tEnter the price:");
    scanf("%f",&p.price);;
    if(p.price<=0.00){
        printf("\t\t\tprice cannot be less than 1");
        printf("\t\t\tPress any key to cotinue");
        getch();
        addstocks();
    }
    printf("\t\t\tEnter the tax:");
    scanf("%f",&p.tax);;
    if(p.tax<0.000){
        printf("\t\t\ttax cannot be less than 1");
        printf("\t\t\tPress any key to cotinue");
        getch();
        addstocks();
    }
    fprintf(fp,"%d %s %d %f %f\n",p.prcode,p.name,p.qty,p.price,p.tax);
    fclose(fp);
    fclose(fe);
    printf("\t\t\tPress any key to cotinue");
    getch();
    adminaccess();
}
void deletestocks(){
    int j,n;
    char c;
    char chckname[30];
    int chckprcode;
    int chckqty;
    float chckprice;
    float chcktax;
    struct pr p;
    FILE *fp=fopen("tempitem.txt","w");
    FILE *fe=fopen("item.txt","r");
    if(fp==NULL){
        textcolor(4);
        printf("File not opened ");
        exit(0);
    }
    if(fe==NULL){
        textcolor(4);
        printf("File not opened ");
        exit(0);
    }
    c = fgetc(fe);
    while (c != EOF)
    {
        fputc(c, fp);
        c = fgetc(fe);
    }
    fclose(fp);
    fclose(fe);
    FILE *fp1=fopen("tempitem.txt","r");
    FILE *fp2=fopen("item.txt","w");
    if(fp1==NULL){
        textcolor(4);
        printf("File not opened ");
        exit(0);
    }
    if(fp2==NULL){
        textcolor(4);
        printf("File not opened ");
        exit(0);
    }
    system("cls");
    j=0;
    printf("\n\n\n\t\t\tItems to be Deleted:\n");
    printf("\t\t\tEnter the Product code:");
    scanf("%d",&p.prcode);
    while(fscanf(fp1,"%d %s %d %f %f",&chckprcode,chckname,&chckqty,&chckprice,&chcktax)!=EOF){
        if(p.prcode!=chckprcode){
            fprintf(fp2,"%d %s %d %f %f\n",chckprcode,chckname,chckqty,chckprice,chcktax);
        }
        else{
            j++;
        }
    }
    fclose(fp1);
    fclose(fp2);
    if(j){
        printf("\t\t\tItem Removed\n");
        printf("\t\t\tPress any key to cotinue");
        getch();
        adminaccess();
    }
    else{
        printf("\t\t\tNo Such Item\n");
        printf("\t\t\tPress any key to cotinue");
        getch();
        adminaccess();
    }
}
void addemployee(){
    int n,i;
    char chckname[30],chckuser[30],chckpass[30];
    struct emp p;
    FILE *fp=fopen("emp.txt","a");
    FILE *fe=fopen("emp.txt","r");
    if(fp==NULL){
        textcolor(4);
        printf("File not opened ");
        exit(0);
    }
    if(fe==NULL){
        textcolor(4);
        printf("File not opened ");
        exit(0);
    }
    system("cls");
    printf("\n\n\n\t\t\tAdd Employee\n");
    printf("\t\t\tEnter The name of the Employee :");
    scanf(" %[^\n]s",p.name);
    printf("\t\t\tEnter the User Name:");
    scanf(" %[^\n]s",p.user);
    while((fscanf(fe,"%s %s %s",chckname,chckuser,chckpass))!=EOF){
        if((strcmp(p.user,chckuser)==0)){
            printf("\n\t\t\tThe user name already Exists\n");
            printf("\t\t\tPress any key to cotinue");
            getch();
            addemployee();
        }
        else{
            continue;
        }
    }
    printf("\t\t\tEnter the Password:");
    scanf(" %[^\n]s",p.pass);
    fprintf(fp,"%s %s %s\n",p.name,p.user,p.pass);
    fclose(fp);
    fclose(fe);
    printf("\t\t\tPress any key to cotinue");
    getch();
    adminaccess();
}
void deleteemployee(){
    int j,n;
    char c;
    char chckname[30],chckuser[30],chckpass[30];
    struct emp p;
    FILE *fp=fopen("tempemp.txt","w");
    FILE *fe=fopen("emp.txt","r");
    if(fp==NULL){
        textcolor(4);
        printf("File not opened ");
        exit(0);
    }
    if(fe==NULL){
        textcolor(4);
        printf("File not opened ");
        exit(0);
    }
    c = fgetc(fe);
    while (c != EOF)
    {
        fputc(c, fp);
        c = fgetc(fe);
    }
    fclose(fp);
    fclose(fe);
    FILE *fp1=fopen("tempemp.txt","r");
    FILE *fp2=fopen("emp.txt","w");
    if(fp1==NULL){
        textcolor(4);
        printf("File not opened ");
        exit(0);
    }
    if(fp2==NULL){
        textcolor(4);
        printf("File not opened ");
        exit(0);
    }
    system("cls");
    printf("\n\n\n\t\t\tEmployees to be Deleted:\n");
    j=0;
    printf("\t\t\tEnter the User Name:");
    scanf(" %[^\n]s",p.user);
    while((fscanf(fp1,"%s %s %s",chckname,chckuser,chckpass))!=EOF){
          if((strcmp(p.user,chckuser)!=0)){
            fprintf(fp2,"%s %s %s\n",chckname,chckuser,chckpass);
        }
        else{
            j++;
        }
    }
    fclose(fp1);
    fclose(fp2);
    if(j){
        printf("\t\t\tEmployee Removed\n");
        printf("\t\t\tPress any key to cotinue");
        getch();
        adminaccess();
    }
    else{
        printf("\t\t\tNo Such Employee\n");
        printf("\t\t\tPress any key to cotinue");
        getch();
        adminaccess();
    }

}
void viewbills(){
    char str[100];
    FILE *fp=fopen("invoice.txt","r");
    while(fscanf(fp," %[^\n]s",str)!=EOF){
        puts(str);
    }
    printf("\t\t\tPress any key to cotinue");
    getch();
    adminaccess();
}
void viewstocks(){
    char chckname[30];
    int chckprcode;
    int chckqty;
    float chckprice;
    float chcktax;
    system("cls");
    FILE *fe=fopen("item.txt","r");
    if(fe==NULL){
        textcolor(4);
        printf("File not opened ");
        exit(0);
    }
    printf("%15s %30s %7s %7s %10s\n","ProductCode","Item Name","Qty","TAX","Price");
    while((fscanf(fe,"%d %s %d %f %f",&chckprcode,chckname,&chckqty,&chckprice,&chcktax))!=EOF){
        printf("%15d %30s %7d %7.2f %10.2f\n",chckprcode,chckname,chckqty,chcktax,chckprice);
    }
    printf("Press any key to continue.");
    getch();
    adminaccess();
}
void updatestocks(){
    int opt,j=0;
    char c;
    char chckname[30];
    int chckprcode;
    int chckqty;
    float chckprice;
    float chcktax;
    struct pr p;
    FILE *fe=fopen("item.txt","r");
    FILE *fp=fopen("tempitem.txt","w");
    if(fp==NULL){
        textcolor(4);
        printf("File not opened ");
        exit(0);
    }
    if(fe==NULL){
        textcolor(4);
        printf("File not opened ");
        exit(0);
    }
    c = fgetc(fe);
    while (c != EOF)
    {
        fputc(c, fp);
        c = fgetc(fe);
    }
    fclose(fp);
    fclose(fe);
    FILE *fp1=fopen("tempitem.txt","r");
    FILE *fp0=fopen("item.txt","w");
    if(fp1==NULL){
        textcolor(4);
        printf("File not opened ");
        exit(0);
    }
    if(fp0==NULL){
        textcolor(4);
        printf("File not opened ");
        exit(0);
    }
    system("cls");
    j=0;
    printf("\n\n\n\t\t\tItems to be Updated:\n");
    printf("\t\t\tEnter the Product code:");
    scanf("%d",&p.prcode);
    while(fscanf(fp1,"%d %s %d %f %f",&chckprcode,chckname,&chckqty,&chckprice,&chcktax)!=EOF){
          if(p.prcode!=chckprcode){
            fprintf(fp0,"%d %s %d %f %f\n",chckprcode,chckname,chckqty,chckprice,chcktax);
        }
        else{
            printf("\t\t\t%d %s %d %f %f\n",chckprcode,chckname,chckqty,chckprice,chcktax);
            j++;
            printf("\t\t\tWhat do you want to update?\n");
            printf("\t\t\t1.Qty\n");
            printf("\t\t\t2.Price\n");
            printf("\t\t\t3.Tax\n");
            printf("\t\t\tEnter your choice:");
            scanf("%d",&opt);
            if(opt==1){
                printf("\t\t\tEnter the Qty:");
                scanf("%d",&p.qty);
                printf("\t\t\t%d %s %d %f %f\n",chckprcode,chckname,p.qty,chckprice,chcktax);
                fprintf(fp0,"%d %s %d %f %f\n",chckprcode,chckname,p.qty,chckprice,chcktax);
                continue;
            }
            if(opt==2){
                printf("\t\t\tEnter the Price:");
                scanf("%f",&p.price);
                printf("\t\t\t%d %s %d %f %f\n",chckprcode,chckname,chckqty,p.price,chcktax);
                fprintf(fp0,"%d %s %d %f %f\n",chckprcode,chckname,chckqty,p.price,chcktax);
                continue;
            }
            if(opt==3){
                printf("\t\t\tEnter the Tax:");
                scanf("%f",&p.tax);
                printf("\t\t\t%d %s %d %f %f\n",chckprcode,chckname,chckqty,chckprice,p.tax);
                fprintf(fp0,"%d %s %d %f %f\n",chckprcode,chckname,chckqty,chckprice,p.tax);
                continue;
            }
            if(opt>3||opt<=0) {
                printf("\t\t\tEnter a vaild option");
                fprintf(fp0,"%d %s %d %f %f\n",chckprcode,chckname,chckqty,chckprice,chcktax);
                printf("\t\t\tPress any key to continue");
                getch();
                adminaccess();
            }
        }
    }
    fclose(fp1);
    fclose(fp0);
    if(j){
        printf("\t\t\tItem Updated\n");
        printf("\t\t\tPress any key to cotinue");
        getch();
        adminaccess();
        }
    else{
        printf("\t\t\tNo Such Item\n");
        printf("\t\t\tPress any key to cotinue");
        getch();
        adminaccess();
    }
}
#endif // ADMIN_H_INCLUDED
