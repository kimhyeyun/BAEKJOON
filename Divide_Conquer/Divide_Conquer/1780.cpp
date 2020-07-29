#include<iostream>
using namespace std;

int** paper_tile;
int minus_paper = 0, zero_paper = 0, one_paper = 0;

void Go(int start_x, int start_y, int size) {
	if (size == 1) {
		if (paper_tile[start_x][start_y] == -1)
			minus_paper++;
		else if (paper_tile[start_x][start_y] == 0)
			zero_paper++;
		else if (paper_tile[start_x][start_y] == 1)
			one_paper++;
		return;
	}

	for (int i = start_x; i < start_x + size; i++) {
		for (int j = start_y; j < start_y + size; j++) {
			if (paper_tile[i][j] != paper_tile[start_x][start_y]) {
				for (int z = 0; z < 3; z++) {
					for (int r = 0; r < 3; r++)
						Go(start_x + (size / 3) * z, start_y + (size / 3) * r, size / 3);
				}
				return;
			}
		}
	}

	if (paper_tile[start_x][start_y] == -1)
		minus_paper++;
	else if (paper_tile[start_x][start_y] == 0)
		zero_paper++;
	else if (paper_tile[start_x][start_y] == 1)
		one_paper++;
	return;
}

int main() {
	cin.tie(0);
	std::ios_base::sync_with_stdio(false);

	int total_size;
	cin >> total_size;

	paper_tile = (int**)malloc(sizeof(int*) * total_size);

	for (int i = 0; i < total_size; i++)
		paper_tile[i] = (int*)malloc(sizeof(int) * total_size);

	for (int i = 0; i < total_size; i++) {
		for (int j = 0; j < total_size; j++)
			cin >> paper_tile[i][j];
	}

	Go(0, 0, total_size);
	
	cout << minus_paper << "\n" << zero_paper << "\n" << one_paper << "\n";
}