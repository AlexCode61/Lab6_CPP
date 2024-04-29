#include "header.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string file_name, str;
    
    do{
        std::cout << "Введите имя файла: ";
        getline(std::cin, file_name);
    } while (!open_file(file_name));
    std::cout << "Изменение файла." << std::endl;
    str = newLines(file_name);
    std::cout << "Новая информация файла."<< std::endl;
    std::cout << str;
    fill_file(file_name, str);
    return 0;
}
