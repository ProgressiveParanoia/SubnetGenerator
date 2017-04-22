#include <string>

class IPAddress{
	
	private:
		int increment;
		int IPOctets[4];
		char IPClass;
		
		void setFirstOctet(){
			if(IPClass == 'A'|| IPClass == 'a'){
				do{
					std::cout << "First Octet:";
					std::cin >> IPOctets[0];
				}while(IPOctets[0] < 0 && IPOctets[0] > 127);
			}
			else
			if(IPClass == 'B' || IPClass == 'b'){
				do{
					std::cout << "First Octet:";
					std::cin >> IPOctets[0];
				}while(IPOctets[0] < 128 && IPOctets[0] > 191);
			}
			else
			if(IPClass == 'C' || IPClass == 'c'){
				do{
					std::cout << "First Octet";
					std::cin >> IPOctets[0];
				}while(IPOctets[0] < 192 && IPOctets[0] > 223);
			}
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
		}
};
