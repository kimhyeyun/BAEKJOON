#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

#define MAX 102
int N, M, K;
int BigBox[MAX][MAX] = { 0, }; //큰 모눈종이
bool checkBig[MAX][MAX] = { false, }; //방문하였는지 확인하는 배열

void makeBox(int a,int b,int c,int d) { //색칠해주는 함수
	for (int i = 0; i < (c - a); i++) { //여기서는 주어지는 좌표가 꼭짓점 좌표이므로 그차이만큼 색칠
		for (int j = 0; j < (d - b); j++) { //마찬가지, y축
			BigBox[a + i][b + j] = 1; //색칠
		}
	}
}

int checkYeongYeok(int a,int b) { //색칠이 안되어있는 부분 넓이확인
	int dx[] = { 0,0,-1,1 };
	int dy[] = { -1,1,0,0 };  //방향

	int sz = 1;  //각 영역의 크기 변수

	queue<pair<int, int> > q; 
	q.push(make_pair(a, b));
	checkBig[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) { 
				if (BigBox[nx][ny] == 0 && !checkBig[nx][ny]) { //색이 안칠해져있고 방문하지 않았다면
					sz++; //넓이 늘려주고
					q.push(make_pair(nx, ny));  //q에 푸쉬
					checkBig[nx][ny] = true; //방문했음을 표기
				}
			}

		}
	}
	return sz; //확인한 영역의 넓이 return
}

int main() {
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;

		cin >> x1 >> y1 >> x2 >> y2; //(x1,y1) : 왼쪽 위 좌표/ (x2,y2): 아랫쪽 밑 좌표
		makeBox(x1, y1, x2, y2); //색칠
	}
	int num = 0; //영역의 갯수 변수
	vector<int> size; //각 영역의 넓이를 담아놓는 vector 

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (BigBox[j][i] == 0 && !checkBig[j][i]) {
				size.push_back(checkYeongYeok(j, i));
				num++;
			}
		}
	}
	printf("%d\n", num);
	sort(size.begin(), size.end()); //ㄱ오름차순으로 정렬
	for (int i = 0; i < size.size(); i++)
		printf("%d ", size[i]);
}