//#include<iostream>
//#include<stdio.h>
//#include<string>
//using namespace std;
//
//int main() {
//	string str;
//	cin >> str;
//	int index = str.length();
//	int N;
//	cin >> N;
//
//	for(int i=0;i<N;i++){
//		char c;
//		cin >> c;
//		switch (c) {
//		case'L':
//			if (index == 0)
//				break;
//			else
//				index--;
//			break;
//
//		case 'D':
//			if (index == str.length())
//				break;
//			else
//				index++;
//			break;
//
//		case 'B':
//			if (index == 0)
//				break;
//			else {
//				str.erase(index - 1, 1);
//				index--;
//				break;
//			}
//
//		case 'P':
//			string c;
//			cin >> c;
//			str.insert(index,c);
//			index += 1;
//
//		}
//	}
//	cout << str;
//}

#include<iostream>
#include<string>
#include<list>
#include<cstdio>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	string str;
	list<char> editor;

	cin >> str >> n;

	for (char c : str)
		editor.push_back(c);

	auto cursor = editor.end();

	for(int i=0;i<n;i++){
		char x;
		cin >> x;
		if (x == 'P') {
			char c;
			cin >> c;
			editor.insert(cursor, c);
		}
		else if (x == 'L') {
			if (cursor != editor.begin())
				cursor--;
		}
		else if (x == 'D') {
			if (cursor != editor.end())
				cursor++;
		}
		else if (x == 'B') {
			if (cursor != editor.begin()) {
				cursor--;
				cursor=editor.erase(cursor);
			}
		}
	}
	for (char x : editor)
		cout << x;
}