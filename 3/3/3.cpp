#include <iostream>
#include<fstream>
using namespace std;

int main() {
	ifstream data;
	data.open("3.txt");
	int counter = 1, y = 0, x = 0,c=0;
	bool flag = false;
	int  y1 = 0, x1 = 0;
	bool flag1 = false;
	char k;
	int X[10000], Y[10000];
	int X1[10000], Y1[10000];
	if (!data.is_open())cout << "ERR";
	X[0] = 0;
	Y[0] = 0;
	c = 1;
	while (data) {
		data >> k;
		if (k == '^')y++;
		if (k == 'v')y--;
		if (k == '>')x++; 
		if (k == '<')x--;
		flag = true;
		for (int i = 0; i < counter; i++) {			
			if (X[i] == x&& Y[i] == y)flag = false;
			if (X1[i] == x&& Y1[i] == y)flag = false;
		}
		X[counter] = x;
		Y[counter] = y;
		if (flag)c++;
		data >> k;
		if (k == '^')y1++;
		if (k == 'v')y1--;
		if (k == '>')x1++;
		if (k == '<')x1--;
		flag1 = true;
		for (int i = 0; i < counter; i++) {
			if (X1[i] == x1 && Y1[i] == y1)flag1 = false;
			if (X[i] == x1&& Y[i] == y1)flag1 = false;
		}
		X1[counter] = x1;
		Y1[counter] = y1;
		if (flag1)c++;
		counter++;
	}
	cout << c << endl;
	cin >> k;
	return 0;
}