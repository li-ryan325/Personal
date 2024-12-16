#include <iostream>

std::string prompt_string(std::string query){
    std::string result(" ");
    std::cout << "Enter " << query << ": ";
    std::cin >> result;
    return result;
}

void print_order(std::string protein, std::string bread, std::string condiment) {
    std::cout << "A " << protein << " sandwich on " << bread << " with " << condiment << std::endl;
}

int main(int argc, char* argv[]) {
    std::string p{prompt_string("protein")};
    std::string b{prompt_string("bread")};
    std::string c{prompt_string("condiment")};

    print_order(p, b, c);
    
    return 0;
}