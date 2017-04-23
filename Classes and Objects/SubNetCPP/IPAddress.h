#include <string>

class IPAddress{
	
	private:
		int increment;
		int IPOctets[4];
		char IPClass;
		bool _isPrivate;
		
		void setFirstOctet(){
			system("cls");
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
		
		void setSucceddingOctets(){
			
			do{
				system("cls");
				
				std::cout <<"IPv4 Class:" <<IPClass <<"\n Current IP:"<<IPOctets[0] <<"\n Second Octet:";
				std::cin >> IPOctets[1];
			}while(IPOctets[1] < 0 || IPOctets[1] > 255);
			
			do{
				
			}while();
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
		}
};
