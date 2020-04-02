#include<iostream>
#include<queue>

using namespace std;

#define MAX 101

int N;
char picture[MAX][MAX]; //그림 행렬
bool visited[MAX][MAX] = { false, };  //비적녹색약인의 시선
bool visitedC[MAX][MAX] = { false, }; //적녹색약인의 시선

int dirx[] = { -1,1,0,0 }; //방향 위아래오왼
int diry[] = { 0,0,-1,1 };

//비적녹색약인의 시선
void countNormal(int a, int b) {
	queue<pair<int, int> > q;
	visited[a][b] = true;

	q.push(make_pair(a, b));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dirx[i];
			int ny = y+diry[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (picture[nx][ny] == picture[x][y] && !visited[nx][ny]) { //색이 같은 경우만 같은 영역으로
					q.push(make_pair(nx, ny));
					visited[nx][ny] = true;
				}
			}
		}
	}
}

//적녹색약인의 시선
void countColor(int a, int b) {
	queue<pair<int, int> > qC;
	visitedC[a][b] = true;

	qC.push(make_pair(a, b));

	while (!qC.empty()) {
		int x = qC.front().first;
		int y = qC.front().second;

		qC.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dirx[i];
			int ny = y + diry[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (picture[nx][ny] == picture[x][y] && !visitedC[nx][ny]) { //같은경우 뿐아니라
					qC.push(make_pair(nx, ny));
					visitedC[nx][ny] = true;
				}
				//다르더라도 인접한 빨강과 초록은 같은색으로 보임
				else if (((picture[x][y] == 'R' && picture[nx][ny] == 'G') || (picture[x][y] == 'G' && picture[nx][ny] == 'R')) && !visitedC[nx][ny]) {
					qC.push(make_pair(nx, ny));
					visitedC[nx][ny] = true;

				}
			}
		}
	}
}




int main() {
	int cntn = 0;
	int cntc = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> picture[j][i];
		}
	}

	for(int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[j][i]) {
				countNormal(j, i);
				cntn++;
			}
			if (!visitedC[j][i]) {
				countColor(j, i);
				cntc++;
			}
		}
	}



	printf("%d\n%d\n", cntn,cntc);
}