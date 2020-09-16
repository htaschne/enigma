#include <iostream>

using namespace std;


int simula(string in, int jump, int count) {

	auto pula = [&](size_t pos, int cont, string s) {
		while (cont) {
			pos++;
			if ( pos == s.length() ) pos = 0;
			if ( s[pos] != '+' ) cont--;
		}
		return pos;
	};

	// cout << "simula com jump: " << jump << endl;
	size_t pos = 0;
	int vivos = in.length();

	while (count > 0) {
		pos = pula(pos, (jump+1)%vivos, in);
		if ( in[pos] == '0' ) return 0;
		in[pos] = '+';
		// cout << in << endl;
		count--;
		vivos--;
		pos = pula( pos, 1, in );
	}
	return jump;
}

int main() {
	string in;
	cin >> in;
	// cout << "input: " << in << endl;
	int res, jump = 0;
	int ones = 0;
	for (int i = 0; i < (int) in.size(); ++i) if (in[i] == '1') ones++;
	do {
		res = simula(in, jump, ones); // Entao aqui a gente ta colocando uma referencia, nao?
		jump++;
	} while (res == 0); // E isso nao reseta a string  :(
	cout << "resposta: " << res << endl;
}
