#include <iostream>
#include <bitset>
#include <exception>
#include <string>

#include "IPAddress.h"

int main(int argc, char** argv) {
	IPAddress myIP;
	char choice;	
	int test=1,target;
	std::cin >> target;
	
	while(test < target){
		test*=2;
	}
	
	do{
		system("cls");
		
		std::cout<<"Subnet Generator\n1. Generate\n2. Exit\nChoice:";
		std::cin >> choice;
		
		if(choice == '1'){
			myIP.createIP();
			system("pause>0");
		}
	}while(choice!='2');
	
//	std::string binary = std::bitset<8>(128).to_string(); //to binary
   // std::cout<<binary<<"\n";
	 
	return 0;
}	
