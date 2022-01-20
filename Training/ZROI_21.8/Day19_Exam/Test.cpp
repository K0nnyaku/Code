#include<bits/stdc++.h>
using namespace std;

    struct Node { 
        int x, y, step, way; 
        Node(int _x = 0, int _y = 0, int _step = 0, int _way = 0) { x = _x, y = _y, step = _step, way = _way; }

        bool friend operator<(Node x, Node y) { return x.step > y.step; }
    };

int Bfs(int x, int y) {
    priority_queue<Node> Q; Q.push(Node(x, y, 1, -1));
    memset(Vis, 0, sizeof Vis);

//    while(!Q.empty()) {
//        Node t = Q.top(); Q.pop();
//        Vis[t.x][t.y] = 1;
//        printf("x = %d, y = %d, step = %d\n", 
//            t.x, t.y, t.step);
//        IOR(i, 0, 4) {
//            int _x = t.x + Wayx[i], _y = t.y + Wayy[i];
//
//            if(Vis[_x][_y]) continue;
//            if(Mp[_x][_y] == '+') return t.step + (t.way != (i == 0 || i == 1) && t.way != -1);
//            if(Mp[_x][_y] == '.')
//                if(t.way == (i == 0 || i == 1) || t.way == -1) Q.push(Node(_x, _y, t.step, (i == 0 || i == 1)));
//                else Q.push(Node(_x, _y, t.step + 1, (i == 0 || i == 1))); 
//        }        
//    }
//    return INF;
}


int main() {

    return 0;
}