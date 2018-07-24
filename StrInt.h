#include <string>
using std::string;

string int2str(int n) {
	try {
		string s = "";
		char c[11] = {0};
		int top = -1;
		if (n < 0) {
			s = "-";
			n = - n;
		}
		do {
			c[++ top] = n % 10 + '0';
			n/= 10;
		} while (n != 0);
		for (int i = top; i >= 0; -- i) 
			s.append(1, c[i]);
		return s;
	} catch (...) {return "";}
}

int str2int(string s) {
	try {
		int n = 0;
		bool flag = false;
		if (s.at(0) == '-') {
			flag = true;
			s.erase(0, 1);
		}
		int c = s.size();
		for (int i = 0; i < c; ++ i) 
			n = n * 10 + (s.at(i) - '0');
		return flag ?- n : n;
	} catch (...) {return 0;}
}


