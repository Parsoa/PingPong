#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <vector>
#include <iostream>

#include "cxxopts.hpp"
#include "bed_utils.hpp"

using namespace std ;

class Configuration {

private:
    static Configuration* instance ;

public:
    static Configuration* getInstance() ;

    void parse(int argc, char* argv[]) ;

    int cutoff = 5 ;
    int overlap = 0 ;
    int threads = 4 ;
    int coverage = 50 ;
    int batch_size = 1000 ;
    int aggregate_batches = 0 ;
    int min_string_length = 0 ; // not enforced by default

    bool binary ;
    bool aggregate ;

    std::string bed ;
    std::string bam ;
    std::string vcf ;
    std::string type ;
    std::string workdir ;
    std::string append ;
    std::string index ;
    std::string fastq ;
    std::string fasta ;
    std::string reference ;

private:

    Configuration() ;

    Configuration(Configuration const&) = delete ;
    void operator=(Configuration const&) = delete ;

    Configuration& operator[](std::string) ;
    
    cxxopts::Options parser ;
};

#endif
