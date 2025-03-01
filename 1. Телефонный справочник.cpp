#include <iostream>
#include <map>
#include <vector>
#include <string>

void addContact(const std::string& phoneNumber, const std::string& lastName,
    std::map<std::string, std::string>& phoneToName,
    std::map<std::string, std::vector<std::string>>& nameToPhones) {
    phoneToName[phoneNumber] = lastName;
    nameToPhones[lastName].push_back(phoneNumber);
}

void findSurnameByPhone(const std::string& phoneNumber,
    const std::map<std::string, std::string>& phoneToName) {
    auto it = phoneToName.find(phoneNumber);
    if (it != phoneToName.end()) {
        std::cout << it->second << std::endl;
    }
    else {
        std::cout << "Не найден" << std::endl;
    }
}

void findPhonesBySurname(const std::string& lastName,
    const std::map<std::string, std::vector<std::string>>& nameToPhones) {
    auto it = nameToPhones.find(lastName);
    if (it != nameToPhones.end()) {
        for (const auto& phone : it->second) {
            std::cout << phone << ' ';
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Не найден" << std::endl;
    }
}

int main() {
    system("chcp 1251"); // Установить кодировку
    std::map<std::string, std::string> phoneToName;   //Ключ - номер телефона -> Фамилия
    std::map<std::string, std::vector<std::string>> nameToPhones; //Ключ - фамилия -> Список номеров

    std::string command;
    while (true) {
        std::cout << "Введите команду (add/surname/phone/q): ";
        std::cin >> command;

        if (command == "q") {
            break;
        }
        else if (command == "add") {
            std::string phoneNumber, lastName;
            std::cin >> phoneNumber >> lastName;
            addContact(phoneNumber, lastName, phoneToName, nameToPhones);
        }
        else if (command == "surname") {
            std::string phoneNumber;
            std::cin >> phoneNumber;
            findSurnameByPhone(phoneNumber, phoneToName);
        }
        else if (command == "phone") {
            std::string lastName;
            std::cin >> lastName;
            findPhonesBySurname(lastName, nameToPhones);
        }
        else {
            std::cout << "Неверная команда" << std::endl;
        }
    }

    return 0;
}
