#include "header.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const std::string s1 = "S1";
	const std::string g1 = "G1";
	const std::string s2 = "S2";
	const std::string g2 = "G2";

	appendFiles(s1, g1, s2);
	appendFiles(g1, s1, g2);

	return 0;
}