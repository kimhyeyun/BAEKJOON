#include<iostream>
#include<stdio.h>
using namespace std;

char map[3500][6500];

void solve(int N, int x, int y) {
    if (N == 3) {
        map[x][y] = '*';
        map[x + 1][y + 1] = '*';
        map[x + 1][y - 1] = '*';

        map[x + 2][y - 2] = '*';
        map[x + 2][y - 1] = '*';
        map[x + 2][y] = '*';
        map[x + 2][y + 1] = '*';
        map[x + 2][y + 2] = '*';

        return;
   }

    solve(N / 2, x, y);
    solve(N / 2, x + N / 2, y - N / 2);
    solve(N / 2, x + (N / 2), y + N / 2);
}

int main() {
    cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    solve(N, 0, N - 1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N ; j++) {
            if (map[i][j] == '*')
                cout << map[i][j];
            else
                cout << " ";
        }
        cout << "\n";
    }
}