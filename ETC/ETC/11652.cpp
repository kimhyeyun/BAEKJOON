#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
 using namespace std;

 bool comp(const pair<long long, int>& a, const pair<long long, int>& b) {
     if (a.second == b.second)
         return a.first < b.first;
     return a.second > b.second;
 }

int main() {
    vector < pair < long long,int> > cards;
    map <long long, int> m;
    
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        m[x]++;
    }
    sort(cards.begin(), cards.end());
    for (int i = 0; i < cards.size(); i++) {
        
    }
    //copy(,,,back_insert()) : 복사함수
    copy(m.begin(), m.end(), back_inserter(cards));
    sort(cards.begin(), cards.end(), comp);
    printf("%lld\n", cards[0].first);

}