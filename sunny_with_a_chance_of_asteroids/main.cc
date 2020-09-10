#include <iostream>
#include <iterator>
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
					int input; cin >> input;
					memory[pc++] = input;
					break;
				}
				case PRT: {
					printf("%d", memory[pc++]);
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

vector<string> getNextLineAndSplitIntoTokens(istream& str)
{
	vector<string>   result;
	string				   line;
	getline(str,line);

	stringstream		   lineStream(line);
	string				   cell;

	while(getline(lineStream,cell, ','))
	{
		result.push_back(cell);
	}
	// This checks for a trailing comma with no data after it.
	if (!lineStream && cell.empty())
	{
		// If there was a trailing comma then add an empty element.
		result.push_back("");
	}
	return result;
}

int main(int argc, char *argv[]) {
	if (argc < 2) return 1;

	string filename = argv[1];

	return 0;
}

