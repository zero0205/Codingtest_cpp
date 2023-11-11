#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
   
    priority_queue<int> left;
    priority_queue<int> right;
    int n, tmp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        if(left.size()==right.size()){
            left.push(tmp);
        }else{
            right.push(-tmp);
        }
        if(!left.empty() and !right.empty() and left.top() > -right.top()){
           int l, r;
           l = left.top();
           r = right.top();
           left.pop();
           right.pop();
           left.push(-r);
           right.push(-l);
        }
        cout << left.top() << "\n";
    }
    
    return 0;
}