#include <iostream>
#include <fstream>
#include <string>

const std::string URED = "\e[4;31m";
const std::string RESET = "\e[0;37m";

void search_replace(std::string& main_str, const std::string& to_be_search, const std::string& to_be_replace) {
    std::string::size_type pos = 0;
    while((pos = main_str.find(to_be_search, pos)) != std::string::npos) 
	{
        main_str.erase(pos, to_be_search.length());
        main_str.insert(pos, to_be_replace);
        pos += to_be_replace.length();
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cout << "Invalid number of arguments.\n";
        return 1;
    }

    std::string filename(argv[1]);
    std::string s1(argv[2]);
    std::string s2(argv[3]);

    std::ifstream input(filename);
    if (!input) 
	{
        std::cout  << URED<< "Cannot open file: " << filename << '\n' << RESET;
        return 1;
    }

    std::string replace_file = filename + ".replace";
    std::ofstream output(replace_file);
    if (!output) 
	{
        std::cout << URED << "Cannot create file: " << replace_file << '\n' << RESET;
        return 1;
    }

    std::string line;
    while (std::getline(input, line)) 
	{
		search_replace(line,s1,s2);
        output << line << '\n';
    }

    input.close();
    output.close();

    return 0;
}