#include <iostream>
#include<fstream>
#include <string>


using namespace std;

class node {
	string name;
	int value;
};

class gate {
	node in1;
	node in2;
	node out;
	enum operation;

	int execute();
};