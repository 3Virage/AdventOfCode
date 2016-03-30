#include <iostream>
#include<fstream>
using namespace std;
int main() {
	ifstream data;
	data.open("2.txt");
	int l = 0, w = 0, h = 0, surface = 0, add = 0, ribbon = 0,addrib=0;
	char k;
	if (!data.is_open())cout << "ERROR";

	while (data) {
		data >> l;
		data.ignore(1);
		data >> w;
		data.ignore(1);
		data >> h;
		data.ignore(1);
		if (l >= h&&l >= w) { add = h*w; addrib = 2 * h + 2 * w; }
		if (w >= h&&w >= l){add = h*l; addrib = 2 * l + 2 * h;
	}
	if (h >= l&&h >= w){add = l*w; addrib = 2 * l + 2 * w;
}

		surface += 2*l*w + 2*w*h + 2*h*l+add;
		ribbon += addrib + l*w*h;
		cout << surface<<endl;
		cout <<ribbon<< endl;
	}
	cin >> l;
	return 0;
}