﻿#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<std::string, int> queue;

    std::string input;
    while (std::cin >> input) {
        if (input == "Next") {
            // Найти первую фамилию в отсортированной очереди
            auto it = queue.begin();
            if (it != queue.end()) {
                std::cout << it->first << "\n";

                if (--queue[it->first] == 0) {
                    // Если больше нет людей с такой фамилией, удалить её из очереди
                    queue.erase(it);
                }
            }
        }
        else if (input == "q") {
            break;
        }
        else {
            ++queue[input];
        }
    }
}
