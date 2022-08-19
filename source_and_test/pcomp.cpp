#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
string cmd,op,func,tp,var;
char ch;
string read_s() {
	scanf(" ");
	string ans;
	while(ch = getchar()) {
		if(ch == '\r' || ch == '\n' || ch == ' ') break;
		ans += ch;
	}
	return ans;
}
string read_p() {
	scanf(" ");
	string ans;
	while(ch = getchar()) {
		if(ch == '(') break;
		ans += ch;
	}
	return ans;
}
string read_r() {
	scanf(" ");
	string ans;
	while(ch = getchar()) {
		if(ch == '\r' || ch == '\n') break;
		ans += ch;
	}
	return ans;
}
string read_c() {
	scanf(" ");
	string ans;
	while(ch = getchar()) {
		if(ch == ';') break;
		ans += ch;
	}
	return ans;
}
bool read_cr(string &ans) {
	scanf(" ");
	ans = "";
	while(ch = getchar()) {
		if(ch == ';') return 0;
		else if(ch == '\r' || ch == '\n') return 1;
		ans += ch;
	}
}
int main(int argc,char* argv[]) {
	if(argc < 2) return 0;
	freopen(argv[1],"r",stdin);
	if(argc < 3) freopen("test.cpp","w",stdout);
	else freopen(argv[2],"w",stdout);
	while(1) {
		cmd = read_s();
		if(cmd == "init") {
			printf("#include<bits/stdc++.h>\n");
			printf("#define llong long long\n");
			printf("#define ldouble long double\n");
			printf("#define ushort unsigned short\n");
			printf("#define uint unsigned int\n");
			printf("#define ulong unsigned long\n");
			printf("#define ullong unsigned llong\n");
			printf("using namespace std;\n");
		} else if(cmd == "cpp") {
			scanf(" ");
			while(1) {
				op = read_r();
				if(op == "end") break;
				cout << op << endl;
			}
		} else if(cmd == "exithq") break;
		else if(cmd == "func") {
			tp = read_s();
			cout << tp << " ";
			func = read_p();
			if(func == "hooch") printf("main");
			else cout << func;
			printf("(");
			op = read_r();
			cout << op;
			printf("{\n");
		} else if(cmd == "end") printf("}");
		else if(cmd == "var") {
			tp = read_s();
			cout << tp << " ";
			op = read_r();
			cout << op;
		} else if(cmd == "if" || cmd == "elseif") {
			if(cmd == "if") printf("if(");
			else printf("else if(");
			while(1) {
				op = read_s();
				if(op == "then") {
					printf("){");
					break;
				}
				cout << op;
			}
		} else if(cmd == "for") {
			printf("for(");
			tp = read_c();
			cout << tp << ";";
			op = read_c();
			cout << op << ";";
			op = read_r();
			cout << op << "){";
		} else if(cmd == "loop_while") {
			printf("while(");
			op = read_r();
			cout << op << "){";
		} else if(cmd == "label") {
			tp = read_r();
			cout << tp << ":";
		} else if(cmd == "goto") {
			tp = read_r();
			cout << "goto " << tp << ";";
		} else if(cmd == "class") {
			printf("class ");
			var = read_r();
			cout << var << "{";
		} else if(cmd == "public" || cmd == "private" || cmd == "protected") {
			cout << cmd << ":";
		} else if(cmd == "shout") {
			op = read_r();
			cout << op;
		} else if(cmd == "fkhooch") {
			printf("break");
		} else if(cmd == "sthooch") {
			printf("continue");
		} else if(cmd == "return") {
			printf("return ");
			var = read_r();
			cout << var;
		} else if(cmd == "input") {
			printf("cin");
			while(1) {
				bool f = read_cr(var);
				cout << ">>" << var;
				if(f) break;
			}
		} else if(cmd == "output") {
			printf("cout");
			while(1) {
				bool f = read_cr(var);
				cout << "<<" << var;
				if(f) break;
			}
		} else if(cmd == "@") read_r();
		else if(cmd == "else") {
			printf("else{");
		}
		else {
			op = read_r();
			cout << cmd + op;
		}
		printf(";\n");
	}
	return 0;
}
