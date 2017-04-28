#include <string>
#include <bitset>
#include <stdlib.h>
#include <cmath>
#include <algorithm>

class IPAddress{
	
	private:
		
		int MaxSubnets;
		int BorrowedBits;
		int IPOctets[4] = {-1,-1,-1,-1};
		int newSubnetMask[4] = {-1,-1,-1,-1};
		int increment = 0;
		
		char IPClass;
		bool _isPrivate;

		std::string binaryOctets[4];
		
		void setFirstOctet(){
		
			if(IPClass == 'A'|| IPClass == 'a'){
				do{
					system("cls");
					
					std::cout << "IPv4 Class:"<<IPClass<<"\nFirst Octet:";
					std::cin >> IPOctets[0];
					
				}while(IPOctets[0] < 0 || IPOctets[0] > 127);
			
			}
			else
			if(IPClass == 'B' || IPClass == 'b'){
				do{
					system("cls");
					
					std::cout << "IPv4 Class:"<<IPClass<<"\nFirst Octet:";
					std::cin >> IPOctets[0];
				}while(IPOctets[0] < 128 || IPOctets[0] > 191);
			}
			else
			if(IPClass == 'C' || IPClass == 'c'){
				do{
					system("cls");
					
					std::cout << "IPv4 Class:"<<IPClass<<"\nFirst Octet:";
					std::cin >> IPOctets[0];
				}while(IPOctets[0] < 192 || IPOctets[0] > 223);
			}
	}
		
		void setSuccedingOctets(){	
			do{
				system("cls");
				
				std::cout <<"IPv4 Class:" <<IPClass <<"\n Current IP:"<<IPOctets[0] <<"\n Second Octet:";
				std::cin >> IPOctets[1];
			}while(IPOctets[1] < 0 || IPOctets[1] > 255);
			
			do{
				system("cls");
				
				std::cout <<"IPv4 Class:" <<IPClass <<"\n Current IP:"<<IPOctets[0] <<"." <<IPOctets[1] <<"\n Third Octet:";
				std::cin >> IPOctets[2];
			}while(IPOctets[2] < 0 || IPOctets[2] > 255);
			
			do{
				system("cls");
				
				std::cout << "IPv4 Class:" <<IPClass <<"\n Current IP:" <<IPOctets[0] <<"." <<IPOctets[1] <<"." << IPOctets[2] <<"\n Fourth Octet:";
				std::cin >> IPOctets[3];
			}while(IPOctets[3] < 0 || IPOctets[3] > 255);
		}
		
		void setSubnetAmount(){
			
				system("cls");		
				
				int amount;
				BorrowedBits = 0;
				
				MaxSubnets = 1;
			do{
			
				std::cout << "IPv4 Class:" <<IPClass <<"\nCurrent IP:"<<IPOctets[0]<<"."<<IPOctets[1]<<"."<<IPOctets[2] <<"." <<IPOctets[3] <<"\nNumber of subnets:";
				std::cin >> amount;
			
			}while(amount < 1);
			
				while(MaxSubnets < amount){
					MaxSubnets*=2;
					BorrowedBits++;
				}
				
				if(amount < 1)
					MaxSubnets = 0;

				std::cout << "Amount for MaxSubnets:" <<MaxSubnets <<"\nBorrowed Bits:" <<BorrowedBits;
				system("pause>0");
		}
		
		void CalculateSubnet(){
			system("cls");
			
			std::cout << "IPv4 Class:" <<IPClass <<"\nCurrent IP:"<<IPOctets[0]<<"."<<IPOctets[1]<<"."<<IPOctets[2] <<"." <<IPOctets[3] << "Amount for MaxSubnets:" <<MaxSubnets <<"\nBorrowed Bits:" <<BorrowedBits <<std::endl;
			
			if(IPClass == 'A'||IPClass == 'a'){
				for(int i = 0 ; i < sizeof(newSubnetMask)/sizeof(*newSubnetMask); i++){
					if(i == 0)
						newSubnetMask[i] = 255;
						else
							newSubnetMask[i] = 0;
				}
			}
			if(IPClass == 'B'||IPClass == 'b'){
				for(int i = 0 ; i < sizeof(newSubnetMask)/sizeof(*newSubnetMask); i++){
					if(i <=1)
						newSubnetMask[i] = 255;
						else
							newSubnetMask[i] = 0;
			}
		}
			if(IPClass == 'C' || IPClass == 'c'){
				for(int i = 0 ; i < sizeof(newSubnetMask)/sizeof(*newSubnetMask); i++){
					if(i <= 2)
						newSubnetMask[i] = 255;
						else
							newSubnetMask[i] = 0;
			}	
		}
		
		for(int i = 0; i < sizeof(newSubnetMask)/sizeof(*newSubnetMask); i++){
			std::cout << newSubnetMask[i];
			
			if(i <3)
				std::cout << ".";
		}
		system("pause>0");
	}
		
		void CalculateSubnetMask(){
			std::cout << std::endl <<"Subnet Mask in Binary:";
			
			for(int i = 0; i <  sizeof(newSubnetMask)/sizeof(*newSubnetMask); i++){
				int test = 0;
				std::string binary = std::bitset<8>(newSubnetMask[i]).to_string(); //to binary	
				binaryOctets[i] = binary;
				
				if(IPClass == 'A'|| IPClass == 'a'){
					for(int x = 0; x < BorrowedBits; x++){
						binaryOctets[1][x] = '1';
					} 
				}
				if(IPClass == 'B'|| IPClass == 'b'){
					for(int x = 0; x < BorrowedBits; x++){
						binaryOctets[2][x] = '1';
					} 
				}
				
				if(IPClass == 'C'|| IPClass == 'c'){
					for(int x = 0; x < BorrowedBits; x++){
						binaryOctets[3][x] = '1';
					} 
				}
				
				
				std::cout<<binaryOctets[i];
				
				if(i <3)
					std::cout << ".";
				else 
					std::cout<<std::endl;	
				
				
				
			}
			
				if(IPClass == 'A'|| IPClass == 'a'){
					reverse(binaryOctets[1].begin(),binaryOctets[1].end());
					
					for(int j = 0; j < binaryOctets[1].size(); j++){
						newSubnetMask[1] += (int(binaryOctets[1][j]) - 48) * pow(2,j);
						std::cout << j <<":" <<newSubnetMask[1] <<":" <<(int(binaryOctets[1][j]) - 48) <<std::endl;
					
						if(newSubnetMask[1] != 0 && increment == 0)	
							increment = newSubnetMask[1];					
					}
				}
			
			if(IPClass == 'B'|| IPClass == 'b'){
				reverse(binaryOctets[2].begin(),binaryOctets[2].end());
				
				for(int j = 0; j < binaryOctets[2].size(); ++j){
					newSubnetMask[2] += (int(binaryOctets[2].at(j)) - 48) * pow(2,j);
				
					if(newSubnetMask[2] != 0 && increment == 0)	
						increment = newSubnetMask[2];
				}
			}
			
			if(IPClass == 'C'|| IPClass == 'c'){
				reverse(binaryOctets[3].begin(),binaryOctets[3].end());
				
				for(int j = 0; j < binaryOctets[3].size(); ++j){
					newSubnetMask[3] += (int(binaryOctets[3].at(j)) - 48) * pow(2,j);
				
					if(newSubnetMask[3] != 0 && increment == 0)	
						increment = newSubnetMask[3];
				}
			}
			
			std::cout << "New Subnet Mask:";  
			
			for(int x = 0; x < sizeof(newSubnetMask)/sizeof(*newSubnetMask); x++){
				std::cout<<newSubnetMask[x];
				
				if(x < 3){
					std::cout<<".";				
				}else
					std::cout<<std::endl;	
			}	
			std::cout << "Increment:" << increment <<std::endl <<std::endl;				
		}
		
		void CalculateNetworkAddress(){
			if(IPClass == 'A'|| IPClass == 'a'){
				for(int i = 0; i < MaxSubnets; i++){
					if(IPOctets[1] < 255){
						IPOctets[1] += increment;
					}else{
						IPOctets[2]++;
						IPOctets[1] = 0;
					}		
					std::cout<<"Network Address:" << IPOctets[0] <<"." <<IPOctets[1] << "." <<IPOctets[2] <<"." <<IPOctets[3] 
					<<" Broadcast Address:" << IPOctets[0] <<"." <<IPOctets[1] << "." <<IPOctets[2] <<"." <<IPOctets[3]+(increment-1) <<std::endl;
				}
			}else
				if(IPClass == 'B'|| IPClass == 'b'){
					for(int i = 0; i < MaxSubnets; i++){
						if(IPOctets[2] < 255){
							IPOctets[3] += increment;
						}else{
							IPOctets[3]++;
							IPOctets[2] = 0;
						}		
						std::cout<<"Network Address:" << IPOctets[0] <<"." <<IPOctets[1] << "." <<IPOctets[2] <<"." <<IPOctets[3] 
						<<" Broadcast Address:" << IPOctets[0] <<"." <<IPOctets[1] << "." <<IPOctets[2] <<"." <<IPOctets[3]+(increment-1) <<std::endl;
					}
				}else
					if(IPClass == 'C'||IPClass == 'c'){
						for(int i = 0; i < MaxSubnets; i++){
							if(IPOctets[3] < 255){
								IPOctets[3] += increment;
							}else{
								IPOctets[2]++;
								IPOctets[3] = 0;
							}		
							
							int broadcastOctet = IPOctets[3]+(increment-1);
							std::cout<<"Network Address:" << IPOctets[0] <<"." <<IPOctets[1] << "." <<IPOctets[2] <<"." <<IPOctets[3] 
							<<" Broadcast Address:" << IPOctets[0] <<"." <<IPOctets[1] << "." <<IPOctets[2] <<"." <<broadcastOctet <<std::endl;
						}
					}	
		}
		
		void TabulateData(){
			std::cout<<"SUBNET  Network Address  Host Address Range  Broadcast Address\n";
			for(int i = 0; i < MaxSubnets; i++){
				std::cout <<"SN  " << i <<"|" <<std::endl;
			}
		}
	public:
		//setters
		void setMaxSubnets(int MaxSubnets){
			IPAddress::MaxSubnets = MaxSubnets;
		}
		void setIPClass(char IPClass){
			IPAddress::IPClass = IPClass;
		}
		void setOctets(int Octet,int index){
			IPOctets[index] = Octet;
		}
		//getters
		int getMaxSubnets(){
			return MaxSubnets;
		}
		bool isPrivate(){
			return _isPrivate;
		}
		char getIPClass(){
			return IPClass;
		}
		int getOctets(int index){
			return IPOctets[index];
		}
		

		void displayInfo(){
			std::cout<<"Class:"<<IPClass;
		}
		
		//computations and stuff
		void createIP(){
			do{		
				system("cls");
			
				std::cout << "Input IPV4 Address Class (A-C)";
				std::cin >> IPClass;
	
			}while(IPClass != 'A' && IPClass != 'a' && IPClass != 'B' && IPClass != 'b' && IPClass != 'C' && IPClass != 'c');
			
			setFirstOctet();
			setSuccedingOctets();
			setSubnetAmount();
			CalculateSubnet();
			CalculateSubnetMask();
			CalculateNetworkAddress();
		//	TabulateData();
			
			system("pause>0");
		}	 
};
