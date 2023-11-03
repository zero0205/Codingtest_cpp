#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        int p;
        cin >> p;
        vector<pair<int, string>>player;
        for (int i=0;i<p;i++){
            int cost;
            string name;
            cin >> cost >> name;
            player.push_back(make_pair(cost, name));
        }
        sort(player.begin(), player.end());
        cout << player.back().second << endl;
    }
}