#include <fstream>
#include <string>

// RE-replace function

int main(int ac, char **av)
{
    if(ac != 4)
        return 1;

    std::string s1 = av[2];
    if(s1.empty())
        return 1;

    size_t pos = 0; 
    std::string s2 = av[3];
    std::string file = av[1];
    std::string file_replace = file + ".replace";
    std::string input;
    std::ifstream inFile(file.c_str());
    if(inFile.fail())
        return 1;
    std::ofstream outFile(file_replace.c_str());
    if(outFile.fail())
        return 1;

    while(std::getline(inFile,input))
    {
        pos = 0;
        while((pos = input.find(s1, pos)) != std::string::npos)
        {
            input.erase(pos,s1.length());
            input.insert(pos,s2);
            pos += s2.length();
        }
        outFile << input << "\n";
    }
    return 0;
}
