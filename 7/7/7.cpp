#include <iostream>
#include<fstream>
#include <string>


using namespace std;

class node {
public:
	string name;
	unsigned short int value;
	bool ready; //ready to execute
	node() :name(""), value(0), ready(0) {}
};

class gate {
public:
	node in1;
	node in2;
	node out;
	string operation;
	bool isdone;

	void execute() {
		if (operation == "NOT")
			out.value = ~in1.value;
		else if (operation == "LSHIFT")
			out.value = in1.value << in2.value;
		else if (operation == "RSHIFT")
			out.value = in1.value >> in2.value;
		else if (operation == "AND")
			out.value = in1.value & in2.value;
		else if (operation == "OR")
			out.value = in1.value | in2.value;
		else
			out.value = in1.value;
		isdone = 1;
	}

	gate() :in1(node()), in2(node()), out(node()), operation(""), isdone(0) {}
	void print() { cout << in1.name << "(" << in1.value << ")" << " " << operation << " " << in2.name << "(" << in2.value << ")" << out.name << "(" << out.value << ")" << " " << endl; }
};

int main() {
	ifstream data;
	data.open("7.txt");
	gate  gates[340];
	string cmd;
	bool outflag = 0;
	bool in1flag = 1;
	int i = 0;
	while (data) {
		data >> cmd;
		cout << cmd << endl;
		if (cmd == "NOT" || cmd == "AND" || cmd == "OR" || cmd == "LSHIFT" || cmd == "RSHIFT")
			gates[i].operation = cmd;
		else if (cmd == "->") {
			outflag = 1;
			in1flag = 1;
			i++;
		}
		else
			if (outflag) {
				gates[i - 1].out.name = cmd;
				outflag = 0;
			}
			else if (in1flag) {
				gates[i].in1.name = cmd;
				in1flag = 0;
			}
			else
				gates[i].in2.name = cmd;
	}
	for (int i = 0; i <= 338; i++)
		gates[i].print();

	for (int i = 0; i <= 338; i++) {
		if (isdigit(gates[i].in1.name[0])) {
			gates[i].in1.value = atoi(gates[i].in1.name.c_str());
			gates[i].in1.ready = 1;
		}
		if (isdigit(gates[i].in2.name[0])) {
			gates[i].in2.value = atoi(gates[i].in2.name.c_str());
			gates[i].in2.ready = 1;
		}
		if (isdigit(gates[i].out.name[0])) {
			gates[i].out.value = atoi(gates[i].out.name.c_str());
		}
		gates[i].print();
	}
	for (int j = 0; j <= 338; j++) {
		for (int i = 0; i <= 338; i++) {
			//	gates[i].print();
			if (!gates[i].isdone)
				if ((gates[i].in1.ready && gates[i].in2.ready) || (gates[i].in1.ready && gates[i].operation == "NOT") || (gates[i].in1.ready && gates[i].operation == "LSHIFT") || (gates[i].in1.ready && gates[i].operation == "RSHIFT") || (gates[i].in1.ready && gates[i].operation == ""))
				{
					gates[i].execute();
					//	getchar();
					for (int k = 0; k <= 338; k++) {
						if (gates[k].in1.name == gates[i].out.name) {
							gates[k].in1.value = gates[i].out.value;
							gates[k].in1.ready = 1;
						}
						if (gates[k].in2.name == gates[i].out.name) {
							gates[k].in2.value = gates[i].out.value;
							gates[k].in2.ready = 1;
						}
					}
				}
		}
	}

	for (int i = 0; i <= 338; i++)
		if (gates[i].out.name == "a"&& gates[i].isdone)
			gates[i].print();

	//second star---------------------------------------------------------
	// I've only changed fourth line in txt file


	getchar();
	return 0;
}


