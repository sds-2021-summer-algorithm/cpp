#include <bits/stdc++.h>
#define LIMIT 1000000000

using namespace std;

void PUSH(long long num);		// cmd id : 0
void POP();						// cmd id : 1
void INV();						// cmd id : 2
void DUP();						// cmd id : 3
void SWP();						// cmd id : 4
void ADD();						// cmd id : 5
void SUB();						// cmd id : 6
void MUL();						// cmd id : 7
void DIV();						// cmd id : 8
void MOD();						// cmd id : 9

bool read_program();
void run_program(int input);

struct cmd {
	int id;
	long long num;
	cmd(int _id, long long _n) : id(_id), num(_n) {};
};

bool error;
vector<cmd> program;
deque<long long> STACK;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (1) {
		if (read_program())
			return 0;

		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			int v;
			cin >> v;

			run_program(v);

			if (!error) {
				cout << STACK.front() << '\n';
			}
			else {
				cout << "ERROR\n";
			}

			error = false;
			STACK.clear();
		}

		cout << '\n';
		program.clear();
	}
}

bool read_program() {
	while (1) {
		string s;
		cin >> s;

		if (s == "END") {
			break;
		}
		else if (s == "NUM") {
			long long num;
			cin >> num;
			program.push_back(cmd(0, num));
		}
		else if (s == "POP") {
			program.push_back(cmd(1, 0));
		}
		else if (s == "INV") {
			program.push_back(cmd(2, 0));
		}
		else if (s == "DUP") {
			program.push_back(cmd(3, 0));
		}
		else if (s == "SWP") {
			program.push_back(cmd(4, 0));
		}
		else if (s == "ADD") {
			program.push_back(cmd(5, 0));
		}
		else if (s == "SUB") {
			program.push_back(cmd(6, 0));
		}
		else if (s == "MUL") {
			program.push_back(cmd(7, 0));
		}
		else if (s == "DIV") {
			program.push_back(cmd(8, 0));
		}
		else if (s == "MOD") {
			program.push_back(cmd(9, 0));
		}
		else if (s == "QUIT") {
			return true;
		}
	}
	return false;
}

void run_program(int input) {
	STACK.push_back(input);

	for (cmd &c : program) {
		if (error) return;

		int id = c.id;
		int num = c.num;

		switch (id) {
		case 0:
			PUSH(num);
			break;
		case 1:
			POP();
			break;
		case 2:
			INV();
			break;
		case 3:
			DUP();
			break;
		case 4:
			SWP();
			break;
		case 5:
			ADD();
			break;
		case 6:
			SUB();
			break;
		case 7:
			MUL();
			break;
		case 8:
			DIV();
			break;
		case 9:
			MOD();
			break;
		}
	}

	if (STACK.size() != 1) {
		error = true;
	}
}

void PUSH(long long num) {
	STACK.push_front(num);
}

void POP() {
	if (!STACK.empty())
		STACK.pop_front();
	else
		error = true;
}

void INV() {
	if (!STACK.empty())
		STACK[0] = -STACK[0];
	else
		error = true;
}

void DUP() {
	if (!STACK.empty()) {
		long long n = STACK.front();
		STACK.push_front(n);
	}
	else {
		error = true;
	}
}

void SWP() {
	if (STACK.size() < 2) {
		error = true;
	}
	else {
		long long tmp;
		tmp = STACK[0];
		STACK[0] = STACK[1];
		STACK[1] = tmp;
	}
}

void ADD() {
	if (STACK.size() < 2) {
		error = true;
		return;
	}

	long long result = STACK[0] + STACK[1];
	if (abs(result) > LIMIT) {
		error = true;
	}
	else {
		STACK.pop_front();
		STACK[0] = result;
	}
}

void SUB() {
	if (STACK.size() < 2) {
		error = true;
		return;
	}

	long long result = STACK[1] - STACK[0];
	if (abs(result) > LIMIT) {
		error = true;
	}
	else {
		STACK.pop_front();
		STACK[0] = result;
	}
}

void MUL() {
	if (STACK.size() < 2) {
		error = true;
		return;
	}

	long long result = STACK[0] * STACK[1];
	if (abs(result) > LIMIT) {
		error = true;
	}
	else {
		STACK.pop_front();
		STACK[0] = result;
	}
}

void DIV() {
	if (STACK.size() < 2) {
		error = true;
		return;
	}

	if (STACK[0] == 0) {
		error = true;
		return;
	}
	
	int cnt = 0;
	if (STACK[0] < 0) cnt++;
	if (STACK[1] < 0) cnt++;
	long long result = abs(STACK[1]) / abs(STACK[0]);
	if (cnt == 1) result = -result;

	if (abs(result) > LIMIT) {
		error = true;
	}
	else {
		STACK.pop_front();
		STACK[0] = result;
	}
}

void MOD() {
	if (STACK.size() < 2) {
		error = true;
		return;
	}

	if (STACK[0] == 0) {
		error = true;
		return;
	}

	long long result = abs(STACK[1]) % abs(STACK[0]);
	if (STACK[1] < 0) result = -result;

	if (abs(result) > LIMIT) {
		error = true;
	}
	else {
		STACK.pop_front();
		STACK[0] = result;
	}
}
