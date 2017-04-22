#include <string>

class IPAddress{
	
	private:
		int increment;
		char IPClass;
		std::string IPOctets[4];
	
	public:
		//setters
		void setIncrement(int increment){
			IPAddress::increment = increment;
		}
		void setIPClass(char IPClass){
			IPAddress::IPClass = IPClass;
		}
		void setOctets(std::string Octet,int index){
			IPOctets[index] = Octet;
		}
		//getters
		int getIncrement(){
			return increment;
		}
		char getIPClass(){
			return IPClass;
		}
		std::string getOctets(int index){
			return IPOctets[index];
		}
		
		//computations and stuff
		void 
		
		
};
