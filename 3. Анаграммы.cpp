#include <iostream>
#include <map>
#include <string>

bool areAnagrams(const std::string& str1, const std::string& str2) {
    if (str1.length() != str2.length()) {
        return false;
    }

    std::map<char, int> charCount;

    //частота символов первой строки
    for (char c : str1) {
        ++charCount[c];
    }

    //проверка второй строки, уменьшение счетчиков символов
    for (char c : str2) {
        auto it = charCount.find(c);

        if (it == charCount.end()) {  //Если символ отсутствует в первой строке
            return false;
        }

        if (--it->second == 0) {  //Если достиг нуля
            charCount.erase(it);
        }
    }

    //если все символы совпадают
    return charCount.empty();
}

int main() {
    system("chcp 1251"); // Установить кодировку
    std::string word1 = "лекарство";
    std::string word2 = "стекловар";

    if (areAnagrams(word1, word2)) {
        std::cout << "'" << word1 << "' и '" << word2 << "' являются анаграммами." << std::endl;
    }
    else {
        std::cout << "'" << word1 << "' и '" << word2 << "' не являются анаграммами." << std::endl;
    }

    return 0;
}
