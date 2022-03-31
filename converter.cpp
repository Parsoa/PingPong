#include "converter.hpp"

KSEQ_INIT(gzFile, gzread)

void Converter::run() {
  auto c = Configuration::getInstance();
  string sfs_path = c->bed;

  string line;
  ifstream inf(sfs_path);
  int idx = 1;
  if (inf.is_open()) {
    string info[5];
    string read_name;
    while (getline(inf, line)) {
      stringstream ssin(line);
      int i = 0;
      while (ssin.good() && i < 5)
	ssin >> info[i++];
      if (info[0].compare("*") != 0) {
	read_name = info[0];
	idx = 1;
      }
      string seq = info[1];
      int s = stoi(info[2]);
      int l = stoi(info[3]);
      string qual (l, '~');
      cout << "@" << read_name << "#" << idx << "#" << s << "#" << s + l - 1 << "\n"
	   << seq << "\n"
	   << "+"
	   << "\n"
	   << qual << endl;
      ++idx ;
    }
  }
}
