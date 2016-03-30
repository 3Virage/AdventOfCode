#include <iostream>
#include<fstream>
#include <string>

using namespace std;
int main() {
	ifstream data;
	data.open("5.txt");
	if (!data.is_open())cout << "ERROR";
	string nice;
	int count = 0;
	bool xyz;
	bool pjpj;
	while (data) {
		xyz = false;
		pjpj = false;
		getline(data, nice);
		for (int i = 1; i < nice.length(); i++) {
			if (nice[i + 1] == nice[i - 1] && nice[i] != nice[i - 1])
				xyz = true;
			for (int j = i + 1; j < nice.length() - 1; j++)
				if (nice[i - 1] == nice[j] && nice[i] == nice[j + 1])
					pjpj = true;
		}
		cout << nice << endl << " " << xyz << " " << pjpj << " " << endl;
		if (xyz&&pjpj)
			count++;
		cout << count << endl;
	}
	cout << count;
	system("PAUSE");
	return 0;
}