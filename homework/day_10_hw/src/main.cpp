#include <iostream>
#include "validation.h"
#include "audit_mode.h"
using std::cout, std::endl, validation::is_valid_password, audit_mode::run_menu,
audit_mode::process_file;

int main(int argc, char* argv[]){
    if (argc == 3){
        process_file(argv[1], argv[2]);
        return 0;
    }
    run_menu();
    return 0;
}
