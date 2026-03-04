#include "audit_mode.h"
#include "validation.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using std::cin, std::cout, std::endl;

char select_delimiter(std::string file){
    std::string extension = file.substr(file.length() - 4);

    if (extension == ".csv"){return ',';}
    else {return '\t';}
}

namespace audit_mode{
    void process_file(std::string input, std::string output){
        //opens the input file and determines delimiter
        std::ifstream input_file(input);
        if (!input_file.is_open()){
            cout << "Error opening file" << endl;
            return;
        }
        char input_delimiter = select_delimiter(input);

        //opens the output file and determines delimiter
        std::ofstream output_file(output, std::ios::app);
        if (!output_file.is_open()){
            cout << "Error opening file." << endl;
            return;
        }
        char output_delimiter = select_delimiter(output);

        //iterates through each line and gets usernsame, email, and password
        std::string username, email, password;
        std::string line;

        while(std::getline(input_file, line)){
            std::stringstream line_stream(line);
            std::getline(line_stream, username, input_delimiter);
            std::getline(line_stream, email, input_delimiter);
            std::getline(line_stream, password);

            if (!validation::is_valid_password(password)){
                output_file << username << output_delimiter
                            << email << output_delimiter
                            << password << endl;
            }
        }

        input_file.close();
        output_file.close();
    }

    void run_menu(){
        int option;

        while (option != 3){
            cout << "----- Menu -----\n"
                 << "1. Check a single password\n"
                 << "2. Process a TSV/CSV file\n"
                 << "3. Quit" << endl;

            cin >> option;
            cin.ignore();

            switch(option){
                case 1:{
                    std::string password;
                    cout << "Enter a password: " << endl;
                    std::getline(cin, password);
                    if (validation::is_valid_password(password)){
                        cout << "Valid" << endl;
                    } else {
                        cout << "Invalid" << endl;
                    }
                    break;
                }
                case 2:{
                    std::string input_file, output_file;
                    cout << "Enter an input file path: ";
                    cin >> input_file;
                    cout << "Enter an output file path: ";
                    cin >> output_file;

                    process_file(input_file, output_file);
                    break;
                }
                case 3:{
                    cout << "Goodbye!" << endl;
                    break;
                }
                default:
                    cout << "Invalid option." << endl;
                    continue;
            }
        }
    }
}
