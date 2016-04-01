#include <iostream>
#include <fstream>
#include <string>
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
			while (data) {
			string str;
			data >> str;
			encodecounter+=2;
			for (int i = 0; i < str.size(); i++) {
				if (str[i] == '\\' || str[i] == '"')
					encodecounter++;
			}
			cout << str << " " << encodecounter << " " ;
		}

	getchar();
	return 0;
}