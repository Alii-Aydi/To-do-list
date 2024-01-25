#include <stdio.h>
#include <stdlib.h>

int main()
{
    char list[50][100];
    char element[100],q;
    int i,j,k;
    int*pk=&k;
    *pk=0;
    FILE*todo;
    printf("Wellcome to your todo list !! \nPlease enter your first quest\n");
    scanf("%[^\n]%*c",element);
    for(j=0;j<50;j++){
        for(i=0;i<100;i++){
            list[j][i]=' ';
        }
    }
    for(i=0;i<strlen(element);i++){
        list[0][i]=element[i];
    }
    while(q!='q'){
        printf("What todo now ??\n");
        printf("(a):to add (d):to delete (p):to print your quests (q):to quiet\n");
        do{
            scanf("%c",&q);
        }while(q!='a'&&q!='p'&&q!='q'&&q!='d');
        if(q=='a'){
            add(list,element,pk);
        }else if(q=='p'){
            todo=fopen("Todolist","w");
            printf("***************************\n");
            for(j=0;j<=k;j++){
                fprintf(todo,"%d)",j+1);
                printf("%d)",j+1);
                for(i=0;i<100;i++){
                    printf("%c",list[j][i]);
                    fprintf(todo,"%c",list[j][i]);
                }
                printf("\n");
                fprintf(todo,"\n");
            }
            printf("***************************\n");
            fclose(todo);
         }else if(q=='d'){
             delet(list,element,pk);
         }
    }
    return 0;
}
void add(char list[][100],char element[],int*k){
    printf("Add your next quest :\n");
    *k=*k+1;
    getchar();
    scanf("%[^\n]%*c",element);
    int i;
    for(i=0;i<strlen(element);i++){
        list[*k][i]=element[i];
    }
}
void delet(char list[][100],char element[],int*k){
    *k=*k-1;
    int position,i,j;
    printf("give the index of the quest to delete : ");
    do{
        scanf("%d",&position);
    }while(position<1||position>strlen(list));
    position--;
    for(j=position;j<50;j++){
        for(i=0;i<100;i++){
            list[j][i]=list[j+1][i];
        }
    }
}

