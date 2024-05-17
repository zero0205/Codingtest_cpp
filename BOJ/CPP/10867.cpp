#include <iostream>
#include <set>

using namespace std;

int main(){
    int n;
    cin >> n;
    set<int> s;
    int tmp;
    for(int i=0;i<n;i++){
        scanf("%d", &tmp);
        s.insert(tmp);
    }
    for(set<int>::iterator iter=s.begin();iter!=s.end();iter++){
        printf("%d ", *iter);
    }
    return 0;
}