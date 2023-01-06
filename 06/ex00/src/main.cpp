#include <fstream>
#include <iostream>

void display_file(std::ifstream &file)
{
    char c;

    while (file) {
        c = file.get();
        if (c == -1)
            break;
        std::cout << c;
    }
    std::cout << std::endl;
}
int main(int argc, char **argv)
{
    std::ifstream file;

    for (int i = 1; i < argc; i++) {
        file.open(argv[i]);
        if (!file.is_open()) {
            std::cerr << argv[0] << ": " << argv[i];
            std::cerr << ": No such file or directory" << std::endl;
            continue;
        }
        display_file(file);
        file.close();
    }
    return (0);
}