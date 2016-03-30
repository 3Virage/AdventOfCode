#include <iostream>
#include <fstream>
using namespace std;
int level = 0;
int counter = 0;
char character;
int main() {
	ifstream datafile;
	
	datafile.open("1.txt");
	cout << datafile.is_open()<<endl;
		while (datafile) {
			datafile >> character;
			if (character == '(')level++;
			if (character == ')')level--;
			counter++;
			cout << level<<" " ;
			if (level == -1) break;
		}
		cout << counter;
		getchar();
		return 0;
}