#include <iostream>
#include <bitset>
#include <exception>
#include <string>

#include "IPAddress.h"

int main(int argc, char** argv) {
	IPAddress myIP;
	char choice;	
	
	do{
		system("cls");
		
		std::cout<<"Subnet Generator\n1. Generate\n2. Exit\nChoice:";
		std::cin >> choice;
		
		if(choice == '1'){
			
			system("pause>0");
		}
	}while(choice!='2');
//	std::string binary = std::bitset<8>(128).to_string(); //to binary
   // std::cout<<binary<<"\n";
	
	return 0;
}
