#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//h sunartisi gia diagrafi proiontos apo to stock den prolaba na tin teleiwsw... den douleuei kanonika.

/*edw einai ta struckts pou eftia3a gia tous pelates kai ta proionta*/
typedef struct pelatis {
    int anagnwristiko;
    char name[50], epwnumo[50];
    char dieuthinsi[50];
}pelates;


typedef struct podilato {
    int anagnwristiko, megethosPlaisiou, posotita;
    char etairia[50],typos[50];
}podilata;


/*edw einai oi sunartiseis pou xreisimopoiw gia kathe entoli tou menu*/
void arxikopoihshPelatwn(pelates *rootPe){rootPe=NULL;}
void arxikopoihshProiontwn(podilata *rootPo){rootPo=NULL;}
pelates insertPelati(pelates *rootPe);
void printList_pelatwn();
void menu();
void printList_proiontwn();
void diagrafi_pelati();
podilata insertProion(podilata *rootPo);
void diagrafi_proion();
void allagh_posotitas(podilata *rootPo);
void allagh_d();


//sto kuriws programma apla kalw tis sunartiseis gia kathe epilogi tou menou.
int main(int argc, char *argv[]){
    int x, anagnwristiko;
    char a='c';
    char b='q', c;
    pelates *rootPe;
    podilata *rootPo;
    
    FILE *pelatwn;
    FILE *podilatwn;
    if((pelatwn=fopen("Pelates.txt" , "a+")) == NULL)
        printf("File.could.not.be.opened\n");
    if((podilatwn=fopen("Podilata.txt" , "a+")) == NULL)
        printf("File.could.not.be.opened\n");
    rewind(pelatwn);
    fscanf(pelatwn, "%c", &a);
    if(a!=2){fprintf(pelatwn, "%-17s %-12s %-15s %-10s\n", "ANAGNWRISTIKO","ONOMA","EPWNUMO","DIEUTHINSI");}
    rewind(podilatwn);
    fscanf(podilatwn, "%c", &b);
    if(b!=2){fprintf(podilatwn, "%-17s %-18s %-15s %-15s %-15s\n", "ANAGNWRISTIKO","MEGETHOSPLAISIOU","POSOTITA","ETAIRIA","TYPOS");}
    while(1){
        arxikopoihshPelatwn(rootPe);
        arxikopoihshProiontwn(rootPo);
        menu();
        scanf("%d", &x);
        c=getchar();
        switch(x){
            case 1:
                rewind(pelatwn);
                insertPelati(rootPe);
                printf("O pelatis kataxwrithike epituxws...\n\n\n");
                rewind(pelatwn);
                break;
            case 2:
                diagrafi_pelati();
                break;
            case 3:
                printList_pelatwn();
                break;
            case 4:
                rewind(podilatwn);
                insertProion(rootPo);
                printf("To podilato kataxwrithike epituxws...\n\n\n");
                rewind(podilatwn);
                break;
            case 5:
                diagrafi_proion();
                break;
            case 6:
                printList_proiontwn();    
                break;
            case 7:
                allagh_posotitas(rootPo);
                break;
            case 8:
                fclose(pelatwn);
                fclose(podilatwn);
                system("PAUSE");
                return(0); 
            case 9:
                 allagh_d();
                 break;
        }
        printf("\n");
    }
}



/*auti einai i sunartisi pou dimiourgei neo kombo kai prosthetei enan neo pelati sti lista*/
pelates insertPelati(pelates *rootPe){
    int anagnwristiko;
    char name[50], epwnumo[50], dieuthinsi[50];
    FILE *pelatwn;
    if((pelatwn=fopen("Pelates.txt" , "a+")) == NULL)
        printf("File.could.not.be.opened\n");

    rootPe = (pelates *)malloc(sizeof(pelates));
    rewind(pelatwn);
    printf("Dwste anagnwristiko pelati(5 arithmoi):\n");
    scanf("%d", &anagnwristiko);
    rootPe->anagnwristiko = anagnwristiko;
    fprintf(pelatwn, "%-18d", rootPe->anagnwristiko);
    printf("Dwste onoma pelati:\n");
    scanf("%s", name);
    strcpy(rootPe->name,name);
    fprintf(pelatwn, "%-13s", rootPe->name);
    printf("Dwste epwnumo pelati:\n");
    scanf("%s", epwnumo);
    strcpy(rootPe->epwnumo,epwnumo);
    fprintf(pelatwn, "%-16s", rootPe->epwnumo);
    printf("Dwste dieuthinsi pelati:\n");
    scanf("%s", dieuthinsi);
    strcpy(rootPe->dieuthinsi,dieuthinsi);
    fprintf(pelatwn, "%-10s\n", rootPe->dieuthinsi);
    
    fclose(pelatwn);
    return *rootPe;
}


/*aui einai i sunartisi pou emfanizei to menu me tis entoles pou mporei na kanei o xristis*/
void menu(){
    printf("MENU :\n");
    printf("Kataxerisi pelati (1)\nDiagrafi petati (2)\nProboli listas pelatwn(3)\n");
    printf("Eisagwgi proiontos sto stock (4)\nDiagrafi proiontos sto stock (5)\n");
    printf("Proboli listas proiontos (6)\nAllagh posotitas enos proiontos (7)\n");
    printf("E3odos programmatos (8)\nAllagh dieuthinsis (9)\n");
}


/*auti einai i sunartisi pou emfanizei ti lista twn pelatwn pou briskontai sto arxeio*/
void printList_pelatwn(){
    int counter=0;
    FILE *pelatwn;
    if((pelatwn=fopen("Pelates.txt" , "a+")) == NULL)
        printf("File.could.not.be.opened\n");
    char out;
    printf("\n"); 
    rewind(pelatwn);
    while((out=fgetc(pelatwn)) != EOF){
        printf("%c",out);
    }
    printf("\n");
    fclose(pelatwn);
}


/*auti einai i sunartisi pou emfanizei ta proionta pou briskontai sto arxeio*/
void printList_proiontwn(){
    FILE *podilatwn;
    if((podilatwn=fopen("Podilata.txt" , "a+")) == NULL)
        printf("File.could.not.be.opened\n");
    char out;
    printf("\n"); 
    rewind(podilatwn);
    while((out=fgetc(podilatwn)) != EOF){
        printf("%c",out);
    }
    printf("\n");
    fclose(podilatwn);
}


/*auti einai i sunartisi pou diagrafei kapoio pelati apo to arxeio*/
/*antigrafei to arxeio pelatwn se ena allo arxeio 'target' kai an brei ton pelati pou
einai gia diagrafi ton grafei se ena trito arxeio to 'deleted' kai meta antigrafei
to target to opoio den exei ton pelati pou theloume na diagrapsoume sto kanoniko arxeio 
twn pelatwn*/
void diagrafi_pelati(){
    int i, counter=0, binco=0, keno=0;
    char code[1000]={0}, x[1000]={0};
    FILE *pelatwn;
    if((pelatwn=fopen("Pelates.txt" , "a+")) == NULL)
        printf("File.could.not.be.opened\n");
    printf("Dwste to anagnwristiko tou pelati gia diagrafi\n");
    scanf("%s", x); 
    
	FILE *target;
    FILE *deleted;
    target=fopen("target.txt","w+");
    deleted=fopen("deleted.txt", "w+");
	char input1;
    counter=0;
    binco=0;
    keno=0;
    rewind(pelatwn);
	while((input1=fgetc(pelatwn)) != EOF){
        if(binco==1){
            if(keno==5){keno++;
                continue;}
            else{
                fputc(input1,target);
                keno++;
                continue;
            }
        }
        if((input1>='a' && input1<='z') || (input1>='A' && input1<='Z') || input1==' ' || input1=='\n'){
            fputc(input1,target);
        }
        if(input1>='0' && input1<='9' && counter!=5){
            code[counter]=input1;
            counter++;
            continue;
        }
        if(counter==5){
            for(i=0;i<5;i++){
                if(code[i]!=x[i]){
                    counter=0;
                    break;
                 } 
            }
            if(i==5){
                printf("Brethike o pelatis...\n");
                fprintf(deleted,"%s", code);
                do{ 
                    if(input1>='0' && input1<='9'){break;}
                    fputc(input1,deleted);
                }
                while((input1=fgetc(pelatwn)) != EOF);
                counter=0;
                binco=1;
                if(binco==1){
                    fputc(input1,target);
                    continue;
                    keno++;
                }
            printf("O pelatis diagraftike! Deite to arxeio!\n");
            }
            else{fprintf(target,"%s", code);}
            counter=0;
        }        
    } 
    fclose(pelatwn); 
    fclose(target);
    fclose(deleted);
    if(binco==1){
        if((pelatwn=fopen("Pelates.txt" , "w+")) == NULL)
            printf("File.could.not.be.opened\n");
        if((target=fopen("target.txt" , "a+")) == NULL)
            printf("File.could.not.be.opened\n");
        while((input1=fgetc(target)) != EOF){
            fputc(input1,pelatwn);
        }
    }
}

/*auti einai i sunartisi pou eisagei ena neo proiwn sto arxeio*/
podilata insertProion(podilata *rootPo){
    int anagnwristiko, megethosPlaisiou, posotita;
    char etairia[50],typos[50];
    FILE *podilatwn;
    if((podilatwn=fopen("Podilata.txt" , "a+")) == NULL)
        printf("File.could.not.be.opened\n");

    rootPo = (podilata *)malloc(sizeof(podilata));
    rewind(podilatwn);
    printf("Dwste anagnwristiko proiontos(5 arithmoi):\n");
    scanf("%d", &anagnwristiko);
    rootPo->anagnwristiko = anagnwristiko;
    fprintf(podilatwn, "%-18d", rootPo->anagnwristiko);
    printf("Dwste megethos plaisiou(45-55):\n");
    scanf("%d", &megethosPlaisiou);
    rootPo->megethosPlaisiou = megethosPlaisiou;
    fprintf(podilatwn, "%-19d", rootPo->megethosPlaisiou);
    printf("Dwste posotita proiontos(0-99):\n");
    scanf("%d",&posotita);
    rootPo->posotita = posotita;
    fprintf(podilatwn, "%-16d", rootPo->posotita);
    printf("Dwste etairia:\n");
    scanf("%s", etairia);
    strcpy(rootPo->etairia,etairia);
    fprintf(podilatwn, "%-16s", rootPo->etairia);
    printf("Dwste typo:\n");
    scanf("%s", typos);
    strcpy(rootPo->typos,typos);
    fprintf(podilatwn, "%-16s\n", rootPo->typos);

    fclose(podilatwn);
    return *rootPo;
}


/*auti einai i sunartisi pou diagrafi kapoio proion apo to arxeio thn opoia den prolaba na tin teleiwsw....*/
void diagrafi_proion(){
	FILE *target=fopen("target.txt","w+");
	char input1;
    int i, counter=0, binco=0, keno=0;
    char code[1000]={0}, x[1000]={0};
    FILE *podilatwn;
    if((podilatwn=fopen("Podilata.txt" , "a+")) == NULL)
        printf("File.could.not.be.opened\n");
    printf("Dwste to anagnwristiko tou proiontos gia diagrafi\n");
    scanf("%s", x); 
    
    FILE *deleted;
    deleted=fopen("deleted.txt", "w+");
    counter=0;
    binco=0;
    keno=0;
    rewind(podilatwn);
	while((input1=fgetc(podilatwn)) != EOF){
        if(binco==1){
            printf("0");
            fputc(input1,target);
            continue;
        }
        if((input1>='a' && input1<='z') || (input1>='A' && input1<='Z') || input1==' '){
            printf("1\n");
            fputc(input1,target);
        }
        if(input1='\n' && counter!=5){fputc(input1,target);
            printf("2\n");
            while(1){
                input1=fgetc(podilatwn);
                if(input1>='0' && input1<='9'){
                    for(i=0;i<5;i++){
                        input1=fgetc(podilatwn);
                        code[counter]=input1;
                        counter++;
                    }
                    break;
                }
                else{fputc(input1,target);}
            }
        }
        if(counter==5){
            printf("3\n");
            for(i=0;i<5;i++){
                if(code[i]!=x[i]){
                    counter=0;
                    break;
                 } 
            }
            if(i==5){
                printf("4\n");
                printf("Brethike to proin...\n");
                fprintf(deleted,"%s", code);
                while((input1=fgetc(podilatwn)) != EOF){
                    if(input1='\n'){break;}
                    fputc(input1,deleted);
                }
                counter=0;
                binco=1;
                if(binco==1){
                    fputc(input1,target);
                    continue;
                    keno++;
                }
            printf("O pelatis diagraftike! Deite to arxeio!\n");
            }
        } 
        else{fprintf(target,"%s", code);}
        counter=0;     
    } 
    fclose(podilatwn);
    fclose(target);
    fclose(deleted);
    if(binco==1){
        if((podilatwn=fopen("Podilata.txt" , "w+")) == NULL)
            printf("File.could.not.be.opened\n");
        if((target=fopen("target.txt" , "a+")) == NULL)
            printf("File.could.not.be.opened\n");
        while((input1=fgetc(target)) != EOF){
            fputc(input1,podilatwn);
        }
    }
}


/*auti einai i sunartisi pou allazei tin posotita ,eite tin meiwnei eite tin au3anei, enos proiontos apo to arxeio*/
/*zhtaei tin posotita pou thelei o xristis na balei anti gia auti pou exei to proion kai tin allazei
xreisimopoiwntas pali ena bohthiko arxeio to 'deleted'*/
void allagh_posotitas(podilata *rootPo){
    char x[1000]={0}, y[1000]={0}, code[1000]={0};
    char adeio=' ';
    char input1;
    int counter=0, counterP=0, binco=0, i, j;
    char posotita[1000]={0};
    FILE *podilatwn;
    FILE *deleted;
    if((podilatwn=fopen("Podilata.txt" , "a+")) == NULL)
        printf("File.could.not.be.opened\n");
    if((deleted=fopen("deleted.txt" , "w+")) == NULL)
        printf("File.could.not.be.opened\n");
    printf("Dwste to anagnwristiko tou proiontos pou epithumeite na alla3ete tin posotita:\n");
    scanf("%s", x);
    printf("Dwste tin epithumith posotita gia allagh:\n");
    scanf("%s", y);
    rewind(podilatwn);
	while((input1=fgetc(podilatwn)) != EOF){
        if((input1>='a' && input1<='z') || (input1>='A' && input1<='Z') || input1==' ' || input1>='0' && input1<='9' ){
            fputc(input1,deleted);
            continue;
        }
        if(binco==1){if(input1=='\n'){fputc(input1,deleted);}}
        if(binco==0){
            if(input1=='\n'){
                fputc(input1,deleted);
                while((input1=fgetc(podilatwn)) != ' ' && input1>='0' && input1<='9'){
                    code[counter]=input1;
                    counter++;
                }
                fputc(input1,deleted);
                if(counter==5){
                    for(i=0;i<5;i++){
                        if(code[i]!=x[i]){printf("lathos\n");
                            counter=0;
                            break;
                        } 
                    }
                }
                if(i==5){
                    printf("Brethike to proion...\n");
                    fprintf(deleted, "%s", code);
                    for(j=0;j<31;j++){input1=fgetc(podilatwn);
                        fputc(input1,deleted); 
                    }
                    for(i=0;y[i]!='\0';i++);
                    while((input1=fgetc(podilatwn))!=' '){
                        counterP++;
                    }
                    if(i==counterP){
                        for(i=0;y[i]!='\0';i++){fputc(y[i],deleted);}
                        fputc(input1,deleted);
                    }
                    if(i<counterP){fputc(y[0],deleted);
                        fputc(input1,deleted);
                        fputc(input1,deleted);}
                    if(i>counterP){for(i=0;y[i]!='\0';i++){fputc(y[i],deleted);}}
                    counter=0;
                    binco=1;
                    printf("H posotita alla3e! Deite to arxeio!\n"); 
                }
                else{fprintf(deleted,"%s", code);}
                counter=0;
            }
        }
    }
    fclose(podilatwn); 
    fclose(deleted);
    if(binco==1){
        if((podilatwn=fopen("Podilata.txt" , "w+")) == NULL)
            printf("File.could.not.be.opened\n");
        if((deleted=fopen("deleted.txt" , "a+")) == NULL)
            printf("File.could.not.be.opened\n");
        while((input1=fgetc(deleted)) != EOF){
            fputc(input1,podilatwn);
        }
    }
}


void allagh_d(){
     int i, counter=0, binco=0, keno=0;
    char code[1000]={0}, x[1000]={0}, h[1000]={0};
    FILE *pelatwn;
    if((pelatwn=fopen("Pelates.txt" , "a+")) == NULL)
        printf("File.could.not.be.opened\n");
    printf("Dwste to anagnwristiko tou pelati gia allaghs dieuthinsis:\n");
    scanf("%s", x); 
    printf("Dwste ti nea dieuthinsi:\n");
    scanf("%s", h);
    
	FILE *target;
    FILE *deleted;
    target=fopen("target.txt","w+");
    deleted=fopen("deleted.txt", "w+");
	char input1;
    counter=0;
    binco=0;
    keno=0;
    rewind(pelatwn);
	while((input1=fgetc(pelatwn)) != EOF){
        if(binco==1){
            fputc(input1,target);
            continue;
        }
        if((input1>='a' && input1<='z') || (input1>='A' && input1<='Z') || input1==' ' || input1=='\n'){
            fputc(input1,target);
        }
        if(input1>='0' && input1<='9' && counter!=5){
            code[counter]=input1;
            counter++;
            continue;
        }
        if(counter==5){
            for(i=0;i<5;i++){
                if(code[i]!=x[i]){
                    counter=0;
                    break;
                 } 
            }
            if(i==5){
                printf("Brethike o pelatis...\n");
                fprintf(target,"%s", code);
                for(i=0;i<41;i++){
                    input1=fgetc(pelatwn);
                    fputc(input1,target);
                }
                fprintf(target,"%s\n", h);
                while((input1=fgetc(pelatwn))!='\n'){
                    input1=fgetc(pelatwn);
                }
                counter=0;
                binco=1;
                if(binco==1){
                    continue;
                    keno++;
                }
            printf("H allagh egine!!\n");
            }
            else{fprintf(target,"%s", code);}
            counter=0;
        }        
    } 
    fclose(pelatwn); 
    fclose(target);
    fclose(deleted);
    if(binco==1){
        if((pelatwn=fopen("Pelates.txt" , "w+")) == NULL)
            printf("File.could.not.be.opened\n");
        if((target=fopen("target.txt" , "a+")) == NULL)
            printf("File.could.not.be.opened\n");
        while((input1=fgetc(target)) != EOF){
            fputc(input1,pelatwn);
        }
    }
     
}
