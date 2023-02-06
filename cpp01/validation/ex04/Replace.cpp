#include "Replace.hpp"

void Replace::changeWord(const std::string& fn, const std::string& what, const std::string& with)
{
    std::ifstream in(fn);
    if (!in)
    {
        std::cerr << "Error: Unable to open input file " << fn << std::endl;
        return ;
    }

    std::string ofn = fn + ".replace";

    std::ofstream out(ofn);
    if (!out)
    {
        std::cerr << "Error: Unable to open output file " << ofn << std::endl;
        return ;
    }

    std::string line;
    while (std::getline(in, line))
    {
        int pos = 0;
        while ((pos = line.find(what, pos)) != std::string::npos)
        {
            std::string fpart = line.substr(0, pos);
            std::string npart = line.substr(pos + what.length());
            line = fpart + with + npart;
            pos += with.length();
        }
        out << line << std::endl;
    }

    in.close();
    out.close();
    
}

Replace::Replace(void)
{}

Replace::~Replace()
{}

