#include <stdio.h>
#include <stdlib.h>
enum {
    input_data=1,delete_data,print_all_data,Exit
};
const char takeout[2][9]={"For here","Take out"};
typedef struct food_order_DATA{
    char order;
    int id;
    int price;
    int takeout;
    struct food_order_DATA *next_data;
}data;
void print_data(data * pData);

//data * add_data(data * pData);

data * dfs_remove_data(data * pData, int index,int i);

data * dfs_add_data(data *first_data,data * pData);

void free_data(data * pData);

int main() {
    data *data=NULL;
    int length=0;
    while (1){
        printf("please input a number (1~4)\n");
        printf("(1)input data\n(2)delete data\n(3)print all data\n(4)exit:");
        int step;
        scanf("%d",&step);
        fflush(stdin);
        switch (step) {
            case input_data:
                data=dfs_add_data(data,data);
                length++;
                break;
            case delete_data:
                print_data(data);
                int index;
                do{
                    printf("which one you want to delete:");
                    scanf("%d",&index);
                    fflush(stdin);
                } while (index>length);
                data=dfs_remove_data(data,index,1);
                length--;
                break;
            case print_all_data:
                print_data(data);
                break;
            case Exit:
                free_data(data);
                return 0;
        }
    }
}

void free_data(data * pData) {
    while (pData){
        data *save_data=pData->next_data;
        free(pData);
        pData=save_data;
    }
}

data * dfs_remove_data(data * pData, int index,int i) {
    if(index==i){
        data *save_data=pData->next_data;
        free(pData);
        return save_data;
    }
    pData->next_data=dfs_remove_data(pData->next_data,index,++i);
    return pData;
}


/*data * add_data(data * pData) {
    data *new_data=malloc(sizeof (data));
    if(new_data==NULL){
        fprintf(stderr,"Error:unable to allocate required memory");
        return NULL;
    }
    data  **save_data=&pData;
    while (*save_data) {
        save_data=&(*save_data)->next_data;
    }
    *save_data=new_data;
    printf("enter your order(A,B,C,...)\n");
    scanf(" %c",&(new_data->order));
    fflush(stdin);
    printf("enter your ID(0~1000)\n");
    scanf("%d",&(new_data->id));
    fflush(stdin);
    printf("enter your price(0~10000)\n");
    scanf("%d",&(new_data->price));
    fflush(stdin);
    do{
        printf("enter your For here(0) or Take out(1)\n");
        scanf("%d",&(new_data->takeout));
        fflush(stdin);
    } while (new_data->takeout!=0 && new_data->takeout!=1);
    new_data->next_data=NULL;
    return pData;
}*/
data * dfs_add_data(data *first_data,data * pData) {
    if(!pData){
        free(pData);
        data *new_data=malloc(sizeof (data));
        if(new_data==NULL){
            fprintf(stderr,"Error:unable to allocate required memory");
            free_data(first_data);
            exit(1);
        }
        printf("enter your order(A,B,C,...)\n");
        scanf(" %c",&(new_data->order));
        fflush(stdin);
        printf("enter your ID(0~1000)\n");
        scanf("%d",&(new_data->id));
        fflush(stdin);
        printf("enter your price(0~10000)\n");
        scanf("%d",&(new_data->price));
        fflush(stdin);
        do{
            printf("enter your For here(0) or Take out(1)\n");
            scanf("%d",&(new_data->takeout));
            fflush(stdin);
        } while (new_data->takeout!=0 && new_data->takeout!=1);
        new_data->next_data=NULL;
        return new_data;
    }
    pData->next_data=dfs_add_data(first_data,pData->next_data);
    return pData;
}
void print_data(data * pData) {
    int k=1;
    while (pData) {
        printf("%d. order=%c id=%-4d price=%-5d \"%s\"\n",k++,pData->order,pData->id,pData->price,takeout[pData->takeout]);
        pData= pData->next_data;
    }
}
