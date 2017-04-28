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
		
		if
		(choice == '1'){
			myIP.createIP();
		}
	}while(choice!='2');
	system("pause>0");
	return 0;
}	
