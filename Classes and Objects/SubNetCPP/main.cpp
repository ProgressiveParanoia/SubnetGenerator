#include <iostream>
#include <bitset>
#include <string>

#include "IPAddress.h"

int main(int argc, char** argv) {
	IPAddress myIP;
	
	std::string binary = std::bitset<8>(128).to_string(); //to binary
    std::cout<<binary<<"\n";
	
	return 0;
}
