#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Replace {
 private:
  Replace(void);
  ~Replace(void);

  static void _transform(std::string* str,
                        const std::string& s1,
                        const std::string& s2);

 public:
  static void process(const std::string& txt,
                      const std::string& s1,
                      const std::string& s2);
};

Replace::Replace(void) {}

Replace::~Replace(void) {}

void Replace::_transform(std::string* str,
                        const std::string& s1,
                        const std::string& s2) {
  std::size_t index = 0;
  while (true) {
    index = (*str).find(s1, index);
    if (index == std::string::npos)
      break;
    std::string former = (*str).substr(0, index);
    former += s2;
    std::string latter = (*str).substr(index + s1.length());
    index += s2.length();
    (*str) = former + latter;
  }
}

void Replace::process(const std::string& txt,
                      const std::string& s1,
                      const std::string& s2) {
  if (txt.empty() || s1.empty() || s2.empty())
    return;
  std::ifstream in(txt, std::ifstream::in | std::ifstream::binary);
  if (!in.good() && (std::cout << "File Cannot Open" << std::endl))
    return;
  std::ostringstream ss;
  ss << in.rdbuf();
  std::string temp = ss.str();
  in.close();
  Replace::_transform(&temp, s1, s2);
  std::ofstream out(txt + ".replace",
                    std::ofstream::out | std::ofstream::trunc);
  if (!out.good() && (std::cout << "File Cannot Open" << std::endl))
    return;
  out << temp;
  out.close();
}

int main(int argc, char **argv) {
  if (argc !=  4)
    std::cout << "Command Not Formatted Well" << std::endl
          << "./replace [ File Name ] [ String1 for SRC ] [ String2 for DST ]"
          << std::endl;
  else
    Replace::process(argv[1], argv[2], argv[3]);
  return 0;
}
