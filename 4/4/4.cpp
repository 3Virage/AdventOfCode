#include <iostream>
#include<fstream>
#include<string>
#include "md5.h"
using namespace std;

int main() {
	
	bool flag = true;
	 int counter = 1;
	 	while (flag) 
	{
		int k = 0;
		string test= "yzbqklnj";
		test += to_string(counter);		
		string md5 = MD5(test).hexdigest();
		for (int i = 0; i < 6; i++)
		if (md5[i] == '0')k++;
		if (k == 6) {
			flag = false;
			cout << counter;
		}
		counter++;
	}

		return 0;
}