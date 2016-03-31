#include <iostream>
#include <fstream>
using namespace std;

int main() {
	/*first star
	ifstream data;
	data.open("8.txt");
	int memcounter = 0;
	int codecounter = 0;
	char character;
	char prev='a';
	while (data) {
		data >> character;
		
		codecounter++;
		memcounter++;
		
	if (character == 'x' && prev == '\\')
			memcounter -= 3;
	
		
if (character == '"')
memcounter--;
if (character == '\\' && prev == '\\') {
	memcounter--;
	character = 'a';
}
		prev = character;
		cout << character << " "<<memcounter<<" "<<codecounter<<" ";
	}
	cout << codecounter-1 << endl;
	cout << memcounter << endl;
	cout << codecounter-1- memcounter << endl;
	*/
//second star
	
		ifstream data;
		data.open("8.txt");
		int encodecounter = 0;
		int codecounter = 0;
		char character='a';
		char prev = 'a';
		char prev2 = 'a';
		bool slash;
		while (data) {
			data >> character;
			codecounter++;
			encodecounter++;
			
			if ((character == '"' && slash))
				encodecounter++;
			if (character == '\\' && prev == '\\'&& !slash)
				slash = 1;
			else
				slash = 0;
			prev2 = prev;
			prev = character;
			cout << character << " " << encodecounter << " " << codecounter << " ";
		}
		cout << encodecounter << endl;
		cout << codecounter << endl;
		cout << encodecounter - codecounter << endl;
	
	getchar();
	return 0;
}