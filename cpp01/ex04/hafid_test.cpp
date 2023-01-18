#include <iostream>
#include <fstream>
#include <string>

class Replace {
    public:
        static void process(const std::string& filename, const std::string& s1, const std::string& s2);

    private:
       Replace(void);
       ~Replace(void);
};

Replace::Replace(void) {}

Replace::~Replace(void) {}

void Replace::process(const std::string& filename, const std::string& s1, const std::string& s2)
{
    // Open the input file
    std::ifstream in(filename);
    if (!in) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }
    // Create the output filename
    std::string out_filename = filename + ".replace";

    // Open the output file
    std::ofstream out(out_filename);
    if (!out) {
        std::cerr << "Error: Unable to create file " << out_filename << std::endl;
        return;
    }
    // Copy the file contents and perform replacement
    std::string line;
    while (std::getline(in, line)) {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            //Implementation
            std::string firstPart = line.substr(0, pos); 
            std::string secondPart = line.substr(pos + s1.length());
            line = firstPart + s2 + secondPart;
            pos += s2.length();
        }
        out << line << std::endl;
    }

    // Close the files
    in.close();
    out.close();
}

int main(int argc, char* argv[]) {
    // Check for the correct number of arguments
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    Replace::process(argv[1], argv[2], argv[3]);
    // Replace::process(filename, s1, s2);
    return 0;
}
