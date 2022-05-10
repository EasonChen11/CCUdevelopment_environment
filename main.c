#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int coefficient,exponent;
    struct node *next;
}Node;

void Push(Node ** top, int coefficient,int exponent);

void print_list(Node * top);

void free_data(Node ** top);

void Sort(Node ** top,Node *save);

int main() {
    Node * top = NULL;
    int coefficient,exponent;
    while ( 1 ) {
        printf("Please enter coefficient and exponent:");
        scanf("%d %d", &coefficient,&exponent);
        if(exponent<0)
            break;
        Push(&top, coefficient,exponent);
    }
    print_list(top);
    free_data(&top);
    return 0;
}

void Sort(Node ** top,Node *save) {
    Node *now_point=*top,*father_point=NULL;
    while (now_point){
        if(save->exponent>now_point->exponent)
            break;
        father_point=now_point;
        now_point=now_point->next;
    }
    if(father_point){
        father_point->next=save;
        save->next=now_point;
    }else{
        *top=save;
        save->next=now_point;
    }
}

void free_data(Node ** top) {
    while (*top){
        Node *save=(*top)->next;
        free(*top);
        *top=save;
    }
}

void print_list(Node * top) {
    printf("The result function is -->Y =");
    if(top->coefficient){
            if(top->coefficient<0)
            printf(" - %dX^%d",abs(top->coefficient),top->exponent);
        else
            printf(" %dX^%d",abs(top->coefficient),top->exponent);
    }
    top=top->next;
    while (top){
        if(top->coefficient){
            if(top->exponent){
                if(top->coefficient<0)
                    printf(" - %dX^%d",abs(top->coefficient),top->exponent);
                else
                    printf(" + %dX^%d",abs(top->coefficient),top->exponent);
            }else{
                if(top->coefficient<0)
                    printf(" - %d",abs(top->coefficient));
                else
                    printf(" + %d",abs(top->coefficient));
            }
        }
        top=top->next;
        //system("pause");
    }
}

void Push(Node ** top, int coefficient,int exponent) {
    Node *save= malloc(sizeof (Node));
    save->coefficient=coefficient;
    save->exponent=exponent;
    Sort(top,save);
}
