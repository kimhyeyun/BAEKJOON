#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;

#define MAX 11

struct balls {
    int depth;
    int rx, ry, bx, by;
};


int irx, iry, ibx, iby, hx, hy; //빨,파,구멍의 좌표

int N, M, ans = -1;
int map[MAX][MAX];
int dir[][2] = { {1,0},{0,1},{-1,0},{0,-1} };
bool visited[MAX][MAX][MAX][MAX];
string str;

void move(int& x, int& y, int d) {
    while (1) {
        x += dir[d][0];
        y += dir[d][1];
        if (map[x][y] == 1) {
            x -= dir[d][0];
            y -= dir[d][1];
            break;
        }
        else if (map[x][y] == 2)
            break;
    }
}

int main() {
    scanf_s("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < M; j++) {
            switch (str[j]) {
            case '.':
                map[i][j] = 0; break;
            case'#':
                map[i][j] = 1; break;
            case'O':
                map[i][j] = 2; hx = i, hy = j; break;
            case'R':
                irx = i, iry = j; break;
            case'B':
                ibx = i, iby = j; break;
            }
        }
    }

    queue<balls> q;
    q.push({ 0,irx,iry,ibx,iby });
    visited[irx][iry][ibx][iby] = true;

    while (!q.empty()) {
        balls cur = q.front();
        q.pop();

        if (cur.depth > 10)
            break;
        if (cur.rx == hx && cur.ry == hy) {
            ans = cur.depth;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int rx = cur.rx;
            int ry = cur.ry;
            int bx = cur.bx;
            int by = cur.by;

            move(rx, ry, i);
            move(bx, by, i);

            if (bx == hx && by == hy)
                continue;
            if (rx == bx && ry == by) {
                //이동후 같아지면 이전 위치를 확인해서 빨간공 또는 파란공을 이동시킴
                switch (i) {
                case 0:
                    cur.rx < cur.bx ? rx-- : bx--; break;
                case 2:
                    cur.rx < cur.bx ? bx++ : rx++; break;
                case 1:
                    cur.ry < cur.by ? ry-- : by--; break;
                case 3:
                    cur.ry < cur.by ? by++ : ry++; break;
                }
            }

            if (!visited[rx][ry][bx][by]) {
                balls next = { cur.depth + 1,rx,ry,bx,by };
                q.push(next);
                visited[rx][ry][bx][by] = true;
            }
        }
    }
    printf("%d\n", ans);

}