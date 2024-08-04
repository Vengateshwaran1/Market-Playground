#ifndef EMP_H_INCLUDED
#define EMP_H_INCLUDED
void viewstock();
void invoice();
void empaccess(){
    int opt;
    system("cls");
    textcolor(7);
    textbackground(0);
    printf("\n\n\n\t\t\tWelcome to Invoice and Inventory\n");
    printf("\t\t\t1.View Stock.\n");
    printf("\t\t\t2.Invoice\n");
    printf("\t\t\t3.Exit\n");
    printf("\t\t\tEnter Your Choice :");
    scanf("%d",&opt);
    switch (opt){
    case 1:
        viewstock();
        break ;
    case 2 :
        invoice();
        break ;
    case 3:
        exit(0);
        break;
    default :
        textcolor(4);
        printf("\t\t\tEnter A valid option\nPress any key to continue.");
        getch();
        empaccess();
        break ;
    }
}
void invoice(){
    int i=0,j,x,y,k=0,billno=0,l=1,qty;
    char chckname[30];
    int chckprcode;
    float total;
    int chckqty;
    float chckprice;
    float chcktax;
    int opt,j1=0;
    char c;
    char chckname1[30];
    int chckprcode1;
    int chckqty1;
    float chckprice1;
    float chcktax1;
    struct pr p[30],p1;
    FILE *fpr=fopen("billno.txt","r");
    if(fpr==NULL){
        textcolor(4);
        printf("File not opened ");
        exit(0);
    }
    while((fscanf(fpr,"%d",&billno))!=EOF){
        continue;
    }
    fclose(fpr);
    system("cls");
    gotoxy(0,0);
    printf("\t\t\t\tWelcome to Invoice and Inventory\n");
    printf("Bill no:%02d                                                 %13s %13s\n",billno,__DATE__,__TIME__);
    printf("______________________________________________________________________________________\n");
    printf("|%4s|%15s|%30s|%7s|%7s|%7s|%10s|\n","S.no","ProductCode","Item Name","Qty","Price","TAX","Totalprice");
    printf("______________________________________________________________________________________\n");
    while(1){
        FILE *f1=fopen("item.txt","r");
        if(f1==NULL){
            textcolor(4);
            printf("File not opened ");
            exit(0);
        }
        prcode:
        printf("|%-4d|      ",i+1);
        scanf("%d",&p[i].prcode);
        while((fscanf(f1,"%d %s %d %f %f",&chckprcode,chckname,&chckqty,&chckprice,&chcktax))!=EOF){
            if(p[i].prcode==chckprcode){
                strcpy(p[i].name,chckname);
                p[i].price=chckprice;
                l=0;
                break;
            }
        }
        if(l!=0){
            printf("There is No such item available\n");
            getch();
            system("cls");
            printf("\t\t\t\tWelcome to Invoice and Inventory\n");
            printf("Bill no:%02d                                                 %13s %13s\n",billno,__DATE__,__TIME__);
            printf("______________________________________________________________________________________\n");
            printf("|%4s|%15s|%30s|%7s|%7s|%7s|%10s|\n","S.no","ProductCode","Item Name","Qty","Price","TAX","Totalprice");
            printf("______________________________________________________________________________________\n");
            for(j=0;j<i;j++){
                printf("|%-4d|%15d|%30s|%7d|%7.2f|%7.2f|%10.2f|\n",j+1,p[j].prcode,p[j].name,p[j].qty,p[j].price,p[j].tax,p[j].tprice);
                printf("______________________________________________________________________________________\n");
            }
            printf("|%-4d|     ",j+1);
            goto prcode;
        }
        fclose(f1);
        gotoxy(22,6+k);
        printf("|%30s|     ",p[i].name);
        qty :
        scanf("%d",&p[i].qty);
        x-wherex();
        y=wherey();
        if(p[i].qty>chckqty){
            printf("There is only %d stock available\n",chckqty);
            getch();
            system("cls");
            printf("\t\t\t\tWelcome to Invoice and Inventory\n");
            printf("Bill no:%02d                                                 %13s %13s\n",billno,__DATE__,__TIME__);
            printf("______________________________________________________________________________________\n");
            printf("|%4s|%15s|%30s|%7s|%7s|%7s|%10s|\n","S.no","ProductCode","Item Name","Qty","Price","TAX","Totalprice");
            printf("______________________________________________________________________________________\n");
            for(j=0;j<i;j++){
                printf("|%-4d|%15d|%30s|%7d|%7.2f|%7.2f|%10.2f|\n",j+1,p[j].prcode,p[j].name,p[j].qty,p[j].price,p[j].tax,p[j].tprice);
                printf("______________________________________________________________________________________\n");
            }
            printf("|%-4d|%15d|%30s|     ",j+1,p[j].prcode,p[j].name);
            goto qty;
        }
        qty=chckqty-p[i].qty;
        p[i].tax=p[i].qty*chckprice*chcktax;
        p[i].tprice=(p[i].qty*chckprice)+p[i].tax;
        total+=p[i].tprice;
        gotoxy(62,6+k);
        printf("|%7.2f|%7.2f|%10.2f\n",p[i].price,p[i].tax,p[i].tprice);
        printf("______________________________________________________________________________________\n");
        i++;
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
        while(fscanf(fp1,"%d %s %d %f %f",&chckprcode1,chckname1,&chckqty1,&chckprice1,&chcktax1)!=EOF){
              if(chckprcode!=chckprcode1){
                fprintf(fp2,"%d %s %d %f %f\n",chckprcode1,chckname1,chckqty1,chckprice1,chcktax1);
            }
            else{
                fprintf(fp2,"%d %s %d %f %f\n",chckprcode1,chckname1,qty,chckprice1,chcktax1);
            }
        }
        fclose(fp1);
        fclose(fp2);
        c=getch();
        if(c==' '){
            break;
        }
        k+=2;
    }
    printf("                                                            |%8s|%15.2f|\n","total",total);
    printf("                                                            __________________________\n","total",total);
    FILE *f=fopen("invoice.txt","a");
    if(f==NULL){
        printf("File not opened ");
        exit(0);
    }
    fprintf(f,"\t\t\t\tWelcome to Invoice and Inventory\n");
    fprintf(f,"Bill no:%02d                                                 %13s %13s\n",billno,__DATE__,__TIME__);
    fprintf(f,"______________________________________________________________________________________\n");
    fprintf(f,"|%4s|%15s|%30s|%7s|%7s|%7s|%10s|\n","S.no","ProductCode","Item Name","Qty","Price","TAX","Totalprice");
    fprintf(f,"______________________________________________________________________________________\n");
    for(j=0;j<i;j++){
        fprintf(f,"|%-4d|%15d|%30s|%7d|%7.2f|%7.2f|%10.2f|\n",j+1,p[j].prcode,p[j].name,p[j].qty,p[j].price,p[j].tax,p[j].tprice);
        fprintf(f,"______________________________________________________________________________________\n");
    }
    fprintf(f,"                                                            |%8s|%15.2f|\n","total",total);
    fprintf(f,"                                                            __________________________\n","total",total);
    fclose(f);
    FILE *fpr1=fopen("billno.txt","a");
    if(fpr1==NULL){
        textcolor(4);
        printf("File not opened ");
        exit(0);
    }
    fprintf(fpr1,"%d\n",billno+1);
    fclose(fpr1);
    printf("Press any key to continue.");
    getch();
    empaccess();
}
void viewstock(){
    char chckname[30];
    int chckprcode;
    int chckqty;
    float chckprice;
    float chcktax;
    system("cls");
    FILE *fe=fopen("item.txt","r");
    if(fe==NULL){
        printf("File not opened ");
        exit(0);
    }
    printf("%15s %30s %7s %7s %10s\n","ProductCode","Item Name","Qty","TAX","Price");
    while((fscanf(fe,"%d %s %d %f %f",&chckprcode,chckname,&chckqty,&chckprice,&chcktax))!=EOF){
        printf("%15d %30s %7d %7f %10f\n",chckprcode,chckname,chckqty,chcktax,chckprice);
    }
    printf("Press any key to continue.");
    getch();
    empaccess();
}
#endif // EMP_H_INCLUDED
