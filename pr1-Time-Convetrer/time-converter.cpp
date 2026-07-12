#include<iostream>
using namespace std;

class time_convo{
	public:
	
		void sec_convo(int sec){
			int min,h;
			h=sec/3600;
			cout<<"The hours of "<<sec<<" is :"<<h<<endl;
			min=sec/60;
			cout<<"The minutes of "<<sec<<" is :"<<min<<endl;
			cout<<"----------------------------------"<<endl;
		}
		
		void sec_count(int sec,int min,int h){
			int ans;
			ans=sec+(h*3600)+(min*60);
			cout<<"The total second is :"<<ans<<endl;	
			cout<<"----------------------------------"<<endl;
		}	
	
};

int main(){
	
	time_convo t1;
	int choice,sec,h,min;
	
	do{
		cout<<"Press 1 to Convert second into Minutes and hours"<<endl;
		cout<<"Press 2 to Count total second"<<endl;
		cout<<"Press 3 to Exit"<<endl;
		cout<<"Enter your choice :";
		cin>>choice;
		cout<<"----------------------------------"<<endl;
		
		switch(choice){
			case 1:
				cout<<"Enter seconds to convert :";
				cin>>sec;
				t1.sec_convo(sec);
				break;
			
			case 2:
				cout<<"Enter seconds to count :";
				cin>>sec;
				cout<<"Enter minutes to count :";
				cin>>min;
				cout<<"Enter hours to count :";
				cin>>h;
				t1.sec_count(sec,min,h);
				break;
				
			case 3:
				cout<<"Exiting From System..."<<endl;
				break;
				
			default:
				cout<<"Invalid Choice!"<<endl;
				break;
				
		}	
	}while(choice!=3);
	
	return 0;
}