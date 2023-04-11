#include <stdio.h>
#include <string.h>

int *prefix(char *p){
    static int pie[100];
    pie[0]=0;
    int k=0;
    for(int i=1;i<strlen(p);i++){
        while (k>0 && p[k]!=p[i]){
            k=pie[k];
        }
    if(p[k]==p[i]){
        k=k+1;
    }
    pie[i]=k;
    }
    return pie;
}

int main(){
    int *pie,q=0;
    char sen[20]="ababcdabc",sent[10]="abc";
    int len1=strlen(sen);
    int len2=strlen(sent);
    pie=prefix(sen);
    // printf("The length is %d and %d\n",len1,len2);
    // for(int i=0;i<len1;i++){
    //   printf("position is %d\n ",pie[i]);}
       
    for (int i=0;i<len1;i++){
        while(q>0 && sent[q]!=sen[i]){
            q=pie[q-1];
        }
        if(sent[q]==sen[i]){
            q=q+1;
        }
        if(q==len2){
            printf("pattern starts with stuff at index %d\n",i-len2+1);
            q=pie[q-1];
        }
    }   
    return 0;
}
