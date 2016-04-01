#include <iostream>
#include<fstream>
#include<string>
using namespace std;


class route {
public:
	string start;
	string stop;
	int length;

	void print() { cout << start << " " << stop << " " << length << endl; }


};

route seek(string s1, string s2,route *routes) {
	for (int i = 0; i < 40; i++)
		if( (routes[i].start == s1 && routes[i].stop == s2)||(routes[i].start == s2 && routes[i].stop == s1)){
			return routes[i];
		}
	cout << "not found";
}

void permutacje(string *city, route *routes, int left, int right) {
	if (left >= right) return;
	
		string temp;
		temp = city[left];
		city[left] = city[right];
		city[right] = temp;

		permutacje(city, routes, left+1, right);

		temp = city[left];
		city[left] = city[right];
		city[right] = temp;

	route temp1 = seek(city[left], city[right], routes);
	temp1.print();
}

int main(){
	ifstream data("9.txt");
	string s;
	route routes[40];
	string city[] = { "AlphaCentauri","Snowdin","Tambi","Faerun","Norrath","Straylight","Tristram","Arbre","AlphaCentauri" };//8 el 
	int i = 0;
	while (data) {
		
		data >> routes[i].start;
		data >> s;
		data >> routes[i].stop;
		data >> s;
		data >> routes[i].length;

		routes[i].print();
		i++;
	}

	
		permutacje(city, routes, 0,7);

	getchar();
	return 0;
}

