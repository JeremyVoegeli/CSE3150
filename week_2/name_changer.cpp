#include <iostream>

int main() {
    char name[7] = {'J', 'e', 'r', 'e', 'm', 'y', '\0'};
    name[0] = 'T';
    std::cout << name << std::endl;
    return 0;
}
