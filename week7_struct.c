
#include <stdio.h>
struct p{char name[8];int HP,DEF,ATK;};
void Game(int attacker, int target, struct p player[3]);
int main() {

    char tital[][4]={"job","HP","DEF","ATK"};
    struct p player[3]={
            {"Warrior",70,40,20},
            {"Wizard",30,15,60},
            {"Archer",40,30,40}
    };
    do{
        for (int i = 0; i < 4; ++i) {
            if(i==0)
                printf("%- 9s",tital[i]);
            else
                printf("%- 4s",tital[i]);
        }
        printf("\n");
        for (int i = 0; i < 3; ++i) {
            printf("%- 8s%- 4d% 4d% 4d\n",player[i].name,player[i].HP,player[i].DEF,player[i].ATK);
        }
        if(player[0].HP<=0 || player[1].HP<=0 || player[2].HP<=0)
            break;
        int attacker,target;
        do{
            printf("Please select an attacker:(1)Warrior (2)Wizard (3)Archer: ");
            scanf("%d",&attacker);
            printf("Please select an target:(1)Warrior (2)Wizard (3)Archer: ");
            scanf("%d",&target);
            if(attacker==target)
                printf("You can not select same player!!!\n");
            else if(attacker>3 || target>3)
                printf("no player!\n");
        }while(attacker==target || attacker>3 || target>3);
        Game(attacker,target,player);
    }while(1);
    for (int i = 0; i < 3; ++i) {
        if(player[i].HP<=0){
            printf("%s Died! Game over!\n",player[i].name);
            break;
        }
    }
    return 0;
}
void Game(int attacker, int target, struct p player[3]){
    attacker-=1;
    target-=1;
    if(player[target].DEF<player[attacker].ATK){
        player[target].HP-=(player[attacker].ATK-player[target].DEF);
        player[target].DEF=0;
    }else{
        player[target].DEF-=player[attacker].ATK;
    }
    if(player[target].HP<=0){
        player[target].HP=0;
        player[target].ATK=0;
    }
}