#include <vector>
#include <cstdio>

using namespace std;

class IntCode {
private:
	vector<int> memory;
	enum opcode {
		ADD = 1,
		MUL = 2,
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
				case HLT: {
					return memory[0];
				}
			}
		}
		return -1;
	}
};

int main() {
	int pos; vector<int> mem;
	while (scanf("%d,", &pos) != EOF) {
		mem.push_back(pos);
	}

	mem[1] = 12;
	mem[2] = 2;

	IntCode ic(mem);
	// ic.run();

	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			mem[1] = i;
			mem[2] = j;
			ic.setMemory(mem);
			int resp = ic.run();
			if (resp == 19690720) {
				printf("%d\n", 100*i + j);
				return 0;
			}
		}
	}

	return 0;
}
