//
// Created by ysche on 2022/3/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void *a,const void *b){
    return (int*)b>=(int*)a;
}
int main(){
    char s[1000000];
    fgets(s,sizeof (s),stdin);
    for (int i = 0; i < strlen(s); ++i) {
        if(s[i]>96)
            s[i]-=32;
    }
    puts(s);
    qsort(s, strlen(s),sizeof (s[0]),compare);
    puts(s);
}
