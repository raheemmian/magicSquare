#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
void processMagicSquare(int a[][3], int b[][3]);
void getMagicSquare(int arr[3][3], int c);
int formingMagicSquare(vector<vector<int>> s);

int main(){
	vector<vector<int>> s(3);
	cout << "input 3x3 matrix" << endl;
	for (int i = 0; i < 3; i++) {
		s[i].resize(3);
		for (int j = 0; j < 3; j++) {
			cin >> s[i][j];
		}
	}
	int result = formingMagicSquare(s);
	cout << endl << "minimal cost of turning matrix into magic square: " <<  result << endl;
	return 0;
}

void processMagicSquare(int a[][3], int b[][3]) {
	for (int i = 0; i<3; i++) {
		for (int j = 0; j < 3; j++) {
			a[i][j] = b[i][j];
		}
	}
}
void getMagicSquare(int arr[3][3], int c) {
	if (c == 0) {
		int a[3][3] = { { 8,1,6 },{ 3,5,7 },{ 4,9,2 } };
		processMagicSquare(arr, a);
	}
	else if (c == 1) {
		int a[3][3] = { { 8,3,4 },{ 1,5,9 },{ 6,7,2 } };
		processMagicSquare(arr, a);
	}
	else if (c == 2) {
		int a[3][3] = { { 6,1,8 },{ 7,5,3 },{ 2,9,4 } };
		processMagicSquare(arr, a);
	}
	else if (c == 3) {
		int a[3][3] = { { 6,7,2 },{ 1,5,9 },{ 8,3,4 } };
		processMagicSquare(arr, a);
	}
	else if (c == 4) {
		int a[3][3] = { { 4,3,8 },{ 9,5,1 },{ 2,7,6 } };
		processMagicSquare(arr, a);
	}
	else if (c == 5) {
		int a[3][3] = { { 4,9,2 },{ 3,5,7 },{ 8,1,6 } };
		processMagicSquare(arr, a);
	}
	else if (c == 6) {
		int a[3][3] = { { 2,9,4 },{ 7,5,3 },{ 6,1,8 } };
		processMagicSquare(arr, a);
	}
	else if (c == 7) {
		int a[3][3] = { { 2,7,6 },{ 9,5,1 },{ 4,3,8 } };
		processMagicSquare(arr, a);
	}
}
// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
	//magic constant formula n(n^2 + 1)/2
	int n = s.size();
	int magicConstant = (n*(pow(n, 2) + 1)) / 2;
	int savings = 0;
	int newSavings = 0;
	int counter = 0;
	int difference = 0;
	//define the 8 arrays 
	int magicSquare[3][3];
	//check if adding the first row equals to the magic constant
	while (counter < 8) {
		getMagicSquare(magicSquare, counter);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (s[i][j] != magicSquare[i][j]) {
					difference = s[i][j] - magicSquare[i][j];
					newSavings += abs(difference);
				}
			}
		}
		if (counter == 0 || savings > newSavings) {
			savings = newSavings;
		}
		newSavings = 0;
		counter++;
	}
	return savings;
}