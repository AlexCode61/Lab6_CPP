#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include <random>
#include <fstream>
#include <sstream>

const std::string directory = "c:\\Users\\aleks\\source\\repos\\Lab5_CPP\\task_1\\files\\";

bool open_file(std::string file_name);
std::string newLines(std::string file_name);
void fill_file(std::string file_name, std::string str);