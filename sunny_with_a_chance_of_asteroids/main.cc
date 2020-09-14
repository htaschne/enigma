
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class IntCode {
private:
	vector<int> memory;
	enum opcode {
		ADD = 1,
		MUL = 2,
		STA = 3,
		PRT = 4,
		HLT = 99
	};
public:
	// methods
	IntCode(vector<int> mem) {
		memory = mem;
	}

	void setMemory(vector<int> new_mem) {
		memory = new_mem;
	}

	int run() {
		size_t pc = 0; // program counter
		while (pc < memory.size()) {
			int instruction = memory[pc++];
			switch (instruction) {
				case ADD: {
					int addr1 = memory[pc++];
					int addr2 = memory[pc++];
					int addr3 = memory[pc++];
					int op1 = memory[addr1];
					int op2 = memory[addr2];
					memory[addr3] = op1 + op2;
					break;
				}
				case MUL: {
					int addr1 = memory[pc++];
					int addr2 = memory[pc++];
					int addr3 = memory[pc++];
					int op1 = memory[addr1];
					int op2 = memory[addr2];
					memory[addr3] = op1 * op2;
					break;
				}
				case STA: {
					int input; scanf("%d", &input); // doesn't work if enter 3. wtf?
					memory[--pc] = input; // not sure why isn't it pc++ or just pc.
					break;
				}
				case PRT: {
					printf("%d\n", memory[memory[pc]]); // maybe this shouldn't add new line
					break;
				}
				case HLT: {
					return memory[0];
				}
			}
		}
		return -1;
	}
};

void parseCSVIntoMem(string filename, vector<int> &mem) {
	fstream input(filename);

	string line;
	getline(input, line);
	stringstream ss(line);

	for (int i; ss >> i;) {
		mem.push_back(i);
		if (ss.peek() == ',') ss.ignore();
	}

}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "usage: ./a.out <filename>\n");
		return 1;
	}

	string filename = argv[1];
	vector<int> mem;
	parseCSVIntoMem(filename, mem);


	IntCode ic(mem);
	ic.run();

	return 0;
}
