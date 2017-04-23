#include <string>

class IPAddress{
	
	private:
		int increment;
		int IPOctets[4] = {-1,-1,-1,-1};
		char IPClass;
		bool _isPrivate;
		
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
			
			increment = 1;
			
			std::cout << "IPv4 Class:" <<IPClass <<"\n Current IP:"<<IPOctets[0]<<"."<<IPOctets[1]<<"."<<IPOctets[2] <<"." <<IPOctets[3] <<"\n number of subnets:";
			std::cin >> amount;
			
			while(increment < amount){
				amount*=2;
			}
			
			std::cout << "Amount for Increment:" <<;
			
		}
	public:
		//setters
		void setIncrement(int increment){
			IPAddress::increment = increment;
		}
		void setIPClass(char IPClass){
			IPAddress::IPClass = IPClass;
		}
		void setOctets(int Octet,int index){
			IPOctets[index] = Octet;
		}
		//getters
		int getIncrement(){
			return increment;
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
		}	
};
