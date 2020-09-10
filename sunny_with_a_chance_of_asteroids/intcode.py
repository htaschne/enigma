
class IntCode:

    def __init__(self, lst):
        self.mem = lst
    def setMem(self, new_mem):
        self.mem = new_mem

    def run(self):
        pc = 0
        while pc < len(self.mem):
            if self.mem[pc] == 1:
                pc += 1
                add1 = self.mem[pc]
                pc += 1
                add2 = self.mem[pc]
                pc += 1
                add3 = self.mem[pc]
                pc += 1

                op1 = mem[add1]
                op2 = mem[add2]

                mem[add3] = op1 + op2

            elif self.mem[pc] == 2:
                pc += 1
                add1 = self.mem[pc]
                pc += 1
                add2 = self.mem[pc]
                pc += 1
                add3 = self.mem[pc]
                pc += 1

                op1 = mem[add1]
                op2 = mem[add2]

                mem[add3] = op1 * op2

            elif self.mem[pc] == 3:
                pc += 1
                inp = int(input())
                add = mem[pc]
                pc += 1
                mem[add] = inp

            elif self.mem[pc] == 4:
                pc += 1
                add = mem[pc]
                print(self.mem[add])
                pc += 1

            elif self.mem[pc] == 99:
                exit(0)

if __name__ == '__main__':
    # que coisa mais feia :(
    mem = [list(map(int, line.split(','))) for line in open('1.in')][0]
    ic = IntCode(mem)
    ic.run()

