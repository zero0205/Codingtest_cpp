#include <iostream>

using namespace std;

// int main(){
//     int a, b, c;
//     cin >> a >> b;
//     cin >> c;
//     int hour, min;
//     hour = int(c/60);
//     min = c%60;
//     // minute
//     if (b+min >= 60){
//         hour += 1;
//         b = (b+min-60);
//     }else{
//         b += min;
//     }
//     // hour
//     if (a+hour > 23){
//         a = (a+hour-24);
//     }
//     else{
//         a = a+hour;
//     }
//     cout << a << " " << b;
// }

int main(){
    int a, b, c;
    cin >> a >> b;
    cin >> c;

    int total = a*60+b+c;

    int h = (total/60)%24;
    int m = total%60;

    cout << h << " " << m;
}