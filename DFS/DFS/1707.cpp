#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

#define MAX 20002

int T, V, E; //testcase,����,������ ����

vector<int> graph[MAX];
int visited[MAX] = { 0, };//0: �湮X, 1:RED, 2:BLUE
bool flag;

void DFS(int start,int color) { //graph�� dfs�ϸ鼭 �����ϴٸ� ���� �ݴ�� �־��ֱ�
	visited[start] = color; 
	for (int i = 0; i <graph[start].size(); i++) {
		int next = graph[start][i];
		if (!visited[next])
			DFS(next, 3 - color);

	}
}

void Search() { //������ ������ ��� �ٸ� ������ �˻�
	for (int i = 1; i <= V; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			int next = graph[i][j];
			if (visited[i] == visited[next])
				flag = true;
		}
	}
}

int main() {
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> V >> E;
		flag = false;
		for (int i = 1; i <= V; i++) {
			visited[i] = 0;
			graph[i].clear();
		}

		for (int i = 0; i < E; i++) {
			int x, y;
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		for (int i = 1; i <= V; i++) {
			if(!visited[i])
				DFS(i, 1);
		}
		Search();

		if (flag)
			printf("NO\n");
		else
			printf("YES\n");

	
	}
}
