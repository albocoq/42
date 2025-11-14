#include "sedIsForLosers.hpp"

int main(int argc, char **argv) {

  if (argc != 4) {
    std::cout << "Three commands are needed: ./Sed_is_for_losers filename s1 s2" << std::endl;
    return 1;
  }
  std::string filename = argv[1];
  std::string s1 = argv[2];
  std::string s2 = argv[3];

  std::ifstream f(filename);
  if (!f.is_open()) {
    std::cout << "cannot open or file " << filename << " does not exist." << std::endl;
    return 1;
  }

  std::ofstream outfile;

  outfile.open(filename + ".replace");
  if (!outfile.is_open()) {
    std::cout << "cannot create outfile.txt" << std::endl;
    f.close();
    return 1;
  }

  std::string s;

  while (getline(f, s))
    outfile << caracteurChange(s, s1, s2) << std::endl;

  outfile.close();
  f.close();
  return 0;
}