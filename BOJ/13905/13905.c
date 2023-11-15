#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int start;
    int end;
    int max_w;
}lst;

// 내림차순 정렬
int cmp(const void *a, const void *b){
    lst *pa = (lst *)a;
    lst *pb = (lst *)b;
    if(pa->max_w > pb->max_w) return -1;
    else if(pa->max_w == pb->max_w) return 0;
    else return 1;
}

int find_parent(int x, int parent[]){
    if(parent[x] != x)
        parent[x] = find_parent(parent[x], parent);
    return parent[x];
}

void union_parent(int a, int b, int parent[]){
    a = find_parent(a, parent);
    b = find_parent(b, parent);

    if(a == b) return;

    if(a < b){
        parent[b] = a;
    }else{
        parent[a] = b;
    }
}


int main(){
    int n, m, s, e;
    int h1, h2, k;
    scanf("%d %d", &n, &m);
    scanf("%d %d", &s, &e);
    lst* arr = (lst *)malloc(sizeof(lst)*m);
    for(int i=0;i<m;i++){
        scanf("%d %d %d", &arr[i].start, &arr[i].end, &arr[i].max_w);
    }

    int *parent = (int *)malloc(sizeof(int)*(n+1));
    for(int i=1;i<n+1;i++){
        parent[i] = i;
    }

    // 정렬
    qsort(arr, m, sizeof(lst), cmp);

    // Kruskal
    int ans = 0;
    for(int i=0;i<m;i++){
        union_parent(arr[i].start, arr[i].end, parent);
        if(find_parent(s, parent) == find_parent(e, parent)){
            ans = arr[i].max_w;
            break;
        }
    }
    printf("%d", ans);

    free(arr);
    free(parent);

    return 0;
}