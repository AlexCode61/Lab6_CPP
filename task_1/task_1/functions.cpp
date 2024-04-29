#include "header.h"

int count_words(std::string line) {
	int count_words = std::count(line.begin(), line.end(), ' ');
	return (count_words+1);
}
std::string processLine(const std::string line) {
	std::string word;
	int count = 0;
	int k = 1;
	std::string new_line;

	for (int i = 0; i < line.length() + 1; ++i) {
		if ((line[i] == ' ') || (line[i] == '\0')) {
			if (word.length() >= 3 && word.length() <= 5) {
				count++;
				if (((count_words(line) - k) == 1) && (count % 2 != 0)) {
					new_line += word + " ";
				}
				//std::cout << word << "***" << k << std::endl;
			}
			else {
				new_line += word + ' ';
			}
			k++;
			word = "";
		}
		else {
			word = word + line[i];
		}
	}
	return new_line;
}

std::string newLines(std::string file_name) {
	std::string line, new_str;
	std::string directory_file = directory + file_name + ".txt";
	std::ifstream file(directory_file);
	while (!file.eof()) {
		getline(file, line);
		//std::cout << line << std::endl;
		//std::cout << count_words(line) << std::endl;
		new_str += processLine(line)+'\n';
		std::cout << line << std::endl;
		line = "";
	}
	file.close();
	return new_str;
}

void fill_file(std::string file_name, std::string str) {
	std::string line, new_str;
	std::string directory_file = directory + file_name + ".txt";
	std::ofstream file(directory_file);
	file << str;
	std::cout << "File Update" << std::endl;
}

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
		std::cout << "ERROR OPEN FILE"<<std::endl;
		return false;
	}
}