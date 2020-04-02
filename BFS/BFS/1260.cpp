//영주코드

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

stack<int> stackDFS;
queue<int> queueBFS;

void DFS(int V, int N, int* visited, int* edge[]) {
    //   stackDFS.push(V);               // stack 지워서 해결 해보기

       // 방문했을 때, 방문여부배열을 1로
    visited[V] = 1;
    cout << V << " ";                     // 해당 노드 출력

    for (int i = 1; i <= N; i++)
    {
        if (edge[V][i] == 1 && visited[i] != 1)         // 노드가 연결되어 있고, 방문 전 노드라면 
        {
            //   stackDFS.pop();
            DFS(i, N, visited, edge);               // DFS(i) --> i 방문하고 그 다음엔 i와 연결된 노드 -> ...
        }
    }
}

void BFS(int V, int N, int* visited, int* edge[]) {
    queueBFS.push(V);               // FIFO 구조인 큐를 이용 --> 방문하는 노드 큐에 넣기

    while (!queueBFS.empty())         // 큐가 빌 때까지 반복
    {
        int search = queueBFS.front();

        // 큐의 FRONT가 방문 전이라면 출력 후 POP / 방문했다면 그냥 POP
        if (visited[search] != 1)
        {
            cout << search << " ";
        }
        queueBFS.pop();

        // 방문 여부 노드 1로 
        visited[search] = 1;

        // 큐의 FRONT와 연결되어 있고, 방문 전 노드라면 QUEUE에 넣어줌
        for (int i = 1; i <= N; i++)
        {
            if (edge[search][i] == 1 && visited[i] != 1)
            {
                queueBFS.push(i);
            }
        }
    }
}

int main() {
    // 노드 개수, 간선 개수, 시작 노드
    int N, M, V;

    int a, b;

    // 방문 여부를 알려주는 배열(0 : 방문 전/ 1 : 방문 후)
    int* visited;

    // 간선 연결 여부를 알려주는 2차원 배열( 연결 O : 1/ 연결 X: 0)
    int** edge;

    cin >> N >> M >> V;


    visited = new int[N + 1];
    for (int i = 0; i < N + 1; i++)
    {
        visited[i] = 0;
    }

    edge = new int* [N + 1];
    for (int i = 0; i < N + 1; i++)
    {
        edge[i] = new int[N + 1];
    }

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        edge[a][b] = 1;
        edge[b][a] = 1;
    }

    DFS(V, N, visited, edge);
    cout << endl;

    for (int i = 0; i < N + 1; i++)
    {
        visited[i] = 0;
    }

    BFS(V, N, visited, edge);
    cout << endl;

}


//나녕코드
//
//  main.cpp
//  DFS BFS - 1260번 DFS와 BFS
//
//  Created by 김난영 on 2020/03/12.
//  Copyright © 2020 KimNanyoung. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int N, M, V;
vector<int> vec;

vector<int> vec2;
stack<int> Stack;
queue<int> Queue;

void dfs(int start, int visitedArr[], int** gra) {

    visitedArr[start] = 1;      //처음 시작 노드는 방문된 것
    Stack.push(start);          //스택에 넣음
    vec.push_back(start);        //vec 벡터는 answer 임



    while (!Stack.empty()) {      //스택에 아무것도 없을 때 까지 반복

        bool chk = false;

        int i;
        for (i = 1; i <= N; i++) {


            if ((gra[start][i] == 1) && (visitedArr[i] == 0)) {           //노드가 연결되어있고 방문한 노드가 아니면
                Stack.push(i);          //노드를 스택에 넣고
                visitedArr[i] = 1;        //방문했다고 표시하고
                start = i;              //시작 노드를 연결된 노드로 바꿈
                vec.push_back(i);
                chk = true;             //연결된 노드가 있다는 것을 나타냄
                break;                  //dfs 이므로 break 하고 for문 나감
            }


        }
        if (chk == false) {                     //연결된 노드가 없으면(막다른 길이면)
            Stack.pop();                    //스택에서 꺼냄
            if (Stack.empty() != true) {
                start = Stack.top();        //스택이 비지 않았으면 시작노드는 스택의 맨 위 노드
            }
        }


    }
    // cout << "dfs : ";
    for (int j = 0; j < vec.size(); j++) {

        cout << vec[j] << " ";
    }
    cout << endl;


}


void bfs(int start, int visitedArr[], int** gra) {



    visitedArr[start] = 1;
    Queue.push(start);
    vec2.push_back(start);



    while (!Queue.empty()) {

        int i;
        for (i = 1; i <= N; i++) {


            if ((gra[start][i] == 1) && (visitedArr[i] == 0)) {       //bfs 라서 break 없이 연결된 노드는 쭉 방문
                Queue.push(i);
                visitedArr[i] = 1;
                vec2.push_back(i);

            }


        }
        Queue.pop();                    //연결된 자식들 다 돌면 맨 앞에 있는 노드(부모노드) 삭제
        start = Queue.front();          //맨 앞의 노드(삭제된 부모노드의 자식 중 숫자가 제일 작은 노드)를 시작 노드로 설정





    }


    //cout << "bfs : ";
    for (int j = 0; j < vec2.size(); j++) {

        cout << vec2[j] << " ";
    }




}





int main() {




    cin >> N >> M >> V;



    int* visitedArr = new int[N + 1];     //0,1 ~ N               //방문한 노드인지 아닌지 구분. 0이면 방문x 1이면 방문o

    for (int i = 0; i < N + 1; i++) {
        visitedArr[i] = 0;                                      //처음엔 0으로 초기화
    }

    int** graph;                                                //연결된 간선을 나타내는 2차원 배ㅕㅇㄹ
    graph = new int* [N + 1];
    for (int i = 0; i < N + 1; i++) {
        graph[i] = new int[N + 1];
    }

    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            graph[i][j] = 0;
        }
    }


    int a, b = 0;
    for (int i = 0; i < M; i++) {

        cin >> a >> b;

        graph[a][b] = 1;                                        //a노드와 b노드가 연결되었으면 1로 표시
        graph[b][a] = 1;

    }







    //dfs(V, int (*visitedArr), int (*graph)[N + 1]);


    dfs(V, visitedArr, graph);

    for (int i = 0; i < N + 1; i++) {
        visitedArr[i] = 0;                      //dfs 실행 후 visitedArr 초기화
    }
    bfs(V, visitedArr, graph);



    return 0;
}




#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;
#define MAX 1001


//재풀이
#define MAX 1001
vector<vector<int>> graph(MAX, vector<int>(MAX, 0)); //vector로 이차원배열 생성
bool visited[MAX] = { false, };
int N;
void BFS(int start);
void DFS(int start);

int main() {
    int  M, V;
    cin >> N >> M >> V;

    int A, B;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        graph[A][B] = 1;
        graph[B][A] = 1;
    }
    DFS(V);
    cout << "\n";
    BFS(V);

}

//깊이 탐색 -> 쭉
void DFS(int start) {
    cout << start << " "; //출력
    visited[start] = true; //방문했음

    for (int i = 1; i <= N; i++) {
        if (graph[start][i] == 1 && !visited[i]) { //방문하지 않았고, edge로 연결되어있으면
            DFS(i); //넘어가서 그 vertex로 dfs() 호출
        }
    }
    return;
}

//넓이탐색
void BFS(int start) {
    queue<int> q;

    visited[start] = false; //dfs에서 true로 바꾸어줬기 때문에 false로 
    q.push(start); //시작점을 q에 push

    while (!q.empty()) { //q가 빌때까지
        int a = q.front();
        cout << q.front() << " ";
        q.pop(); //출력후에는 pop

        for (int i = 1; i <= N; i++) {
            if (graph[a][i] == 1 && visited[i]) { //연결되어있고 방문하지 않았다면
                q.push(i); //q에 푸시
                visited[i] = false;
            }
        }
    }
    return;
}

