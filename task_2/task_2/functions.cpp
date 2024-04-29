#include "header.h"

bool open_file(std::string file_name) {
	std::string directory_file = directory + file_name + ".txt";
	std::ifstream file(directory_file);

	if (file) {
		std::cout << "File " << file_name << " Open." << std::endl;
		if (file.peek() == EOF) {
			std::cout << "File empty.";
			return false;
		}
		else {
			return true;
		}
	}
	else {
		std::cout << "ERROR OPEN FILE" << std::endl;
		return false;
	}
}

int appendFiles(const std::string& s1, const std::string& g1, const std::string& s2) {
	std::string directory_file_s1 = directory + s1 + ".txt";
	std::ifstream file_s1(directory_file_s1);
	std::string directory_file_g1 = directory + g1 + ".txt";
	std::ifstream file_g1(directory_file_g1);

	if (!file_s1.is_open() || !file_g1.is_open()) {
		std::cerr << "Ошибка: не удалось открыть файлы s1 and g1" << std::endl;
		return 1;
	}
	std::string directory_file_s2 = directory + s2 + ".txt";
	std::ofstream file_s2(directory_file_s2);

	if (!file_s2.is_open()) {
		std::cerr << "Ошибка: не удалось создать файл s2" << std::endl;
		return 1;
	}

	file_s2 << file_s1.rdbuf();
	file_s2 << file_g1.rdbuf();
	std::cout << "Содержимое файлов успешно объединено в " << s2 << std::endl;

	return 0;
}