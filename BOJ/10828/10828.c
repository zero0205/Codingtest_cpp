#include <stdio.h>
#include <string.h>

int stack[10001] = {0};
int t = -1;

void push(int x){
    stack[++t] = x;
}

int pop(){
    return t == -1 ? -1 : stack[t--];
}

int size(){
    return t+1;
}

int empty(){
    return t == -1 ? 1 : 0;
}

int top(){
    return t == -1 ? -1 : stack[t];
}

int main(){
    int n, x;
    char cmd[10];
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%s", cmd);
        if(strcmp("push", cmd) == 0){
            scanf("%d", &x);
            push(x);
        }else if(strcmp("pop", cmd) == 0){
            printf("%d\n", pop());
        }else if(strcmp("size", cmd) == 0){
            printf("%d\n", size());
        }else if(strcmp("empty", cmd) == 0){
            printf("%d\n", empty());
        }else if(strcmp("top", cmd) == 0){
            printf("%d\n", top());}
    }
    return 0;
}