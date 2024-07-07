#include <iostream>
#include <fstream>
#include <unistd.h>
#include "gaussian.h"

void print_usage() {
	    std::cout << "Usage: ./program -e expected_value -s std_deviation -n amount_of_values [-o output_file]\n";}
int main(int argc, char *argv[]) {
    int expected_value = 0;
    int std_deviation = 1;
    int amount_of_values = 100;
    const char* output_file = nullptr;
int opt;
    while ((opt = getopt(argc, argv, "he:s:n:o:")) != -1) {
	 switch (opt){
		case 'h':
                       print_usage();
                return 0;
		case 'e':
                expected_value = std::stoi(optarg);
                break;
            case 's':
                std_deviation = std::stoi(optarg);
                break;
            case 'n'
    	     amount_of_values = std::stoi(optarg);
                break;
                case 'o':
                output_file = optarg;
                break;
            default:
                print_usage();
                return 1
		}
	if (output_file){
		std::ofstream out(output_file);
        if (!out) {
            std::cerr << "Failed to open output file\n";
            return 1;
	} 
     print_gaussian_dist(expected_value, std_deviation, amount_of_values, out);
    } else {
        print_gaussian_dist(expected_value, std_deviation, amount_of_values, std::cout);
    }	
    return 0;
    }
