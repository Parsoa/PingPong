#include "converter.hpp"

KSEQ_INIT(gzFile, gzread)

void Converter::run() {
  auto c = Configuration::getInstance();
  string wdir = c->workdir;
  uint num_batches = c->aggregate_batches;
  string line;
  ifstream inf;
  int idx = 1;
  for (int j = 0; j < num_batches; j++) {
    string s_j = std::to_string(j) ;
    string path = wdir + "/solution_batch_" + s_j + ".sfs" ;
    inf.open(path);
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
	++idx;
      }
    }
    inf.close();
  }
}
