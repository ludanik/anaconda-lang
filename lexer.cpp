#include <string>
#include "lexer.h"

static int gettok() {
	static int LastChar = ' ';

	while (isspace(LastChar)) {
		LastChar = getchar();
	}

	if (isalpha(LastChar)) {
		IdentifierStr = LastChar;
		while (isalnum(LastChar = getchar())) {
			IdentifierStr += LastChar;
		}

		if (IdentifierStr == "def") 
			return tok_def;
		else if (IdentifierStr == "extern")
			return tok_extern;
		return tok_identifier;
	}

	if (isdigit(LastChar) || LastChar == '.') {
		std::string NumStr;
		do {
			NumStr += LastChar;
			LastChar = getchar();
		} while (isdigit(LastChar) || LastChar == '.');

		NumVal = strtod(NumStr.c_str(),0);
		return tok_number;
	}

	if (LastChar == '#') {
		do {
			LastChar = getchar();
		}
		while (LastChar != EOF && LastChar != '\n' && LastChar != '\r');	

		if (LastChar != EOF) {
			return gettok();
		}
	}

	if (LastChar == EOF) {
		return tok_eof;
	}

	int ThisChar = LastChar;
	LastChar = getchar();
	return ThisChar;
}


