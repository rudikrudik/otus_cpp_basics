#pragma once

bool checkFile(); // Проверка файла на его наличие
std::string intToString(unsigned int); // Конвертер числа в строку
long long int findInFile(std::string&); // Поиск положения курсора
void readFile(); // Вывод файла на консоль
void writeFile(std::string&, unsigned int); // Запись результатов в файл

