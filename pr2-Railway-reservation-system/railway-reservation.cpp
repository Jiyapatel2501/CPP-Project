#include<iostream>
using namespace std;

class Train{
	private:
		
		//Member Varible
		
		string trainName;
	 	string source;	 
		string destination;
		string trainTime;
		int trainNumber;
	
	public:
		
		//static variable
		static int trainCount;
		
		//default constructor
		
		Train(){
			
		}
		
		//parameterized constructor
		
		Train(int number,string name,string source,string destination,string time ){
			this->trainNumber=number;
			this->trainName=name;
			this->source=source;
			this->destination=destination;
			this->trainTime=time;	
			trainCount++;
		}
		
		
		
		//setter function
		
		void inputTrainDetails(string name,string source,string destination,string time){
			this->trainName=name;
			this->source=source;
			this->destination=destination;
			this->trainTime=time;
			trainCount++;
		}
		
		void setTrainNumber(int number){
			this->trainNumber=number;
		}
		
		//getter function
		
		void displayTrainDetails(){
			cout<<"Train Number : "<<trainNumber<<endl<<"Train Name : "<<trainName<<endl<<"Source : "<<source<<endl
			<<"Destination : "<<destination<<endl<<"Train Time : "<<trainTime<<endl;
			getTrainCount();
			
			cout<<"-----------------------------"<<endl;
			
		}
		
		int getTrainNumber(){
			return trainNumber;
		}
		
		//static function
		
		static int getTrainCount(){
			return trainCount;
		}
		
		//destructor
		
		~Train(){
			trainCount--;
		}
	
	
};

class RailwaySystem{
	
	private:
		Train trains[100];
		int totaltrain=0;
	
	public:
		
		//1.train add train
		
		void addTrain(string name,string source,string destination,string time,int number){
			trains[totaltrain].inputTrainDetails(name,source,destination,time);
			trains[totaltrain].setTrainNumber(number);
			totaltrain++;	
		}
		
		//2.display train detail
		
		void displayAllTrains(){
			for(int i=0;i<totaltrain;i++){
				trains[i].displayTrainDetails();
			}
		}
		
		//3.search train by number
		
		void searchTrainByNumber(int number){
			for(int i=0;i<totaltrain;i++){
				if(trains[i].getTrainNumber()==number){
					trains[i].displayTrainDetails();
					return;
				}
			}
			cout<<"Train is Not Found......"<<endl;
		}
		
};

int Train::trainCount=0;

int main(){
	

	int choice,number;
	string name,source,destination,time;
	RailwaySystem irctc;
	
	
	do{
		
		cout<<"--- Railway Reservation System Menu ---"<<endl;
		cout<<"Press 1 to Add New Train Record"<<endl;
		cout<<"Press 2 to Display All Train Records"<<endl;
		cout<<"Press 3 to Search Train by Number"<<endl;
		cout<<"Press 4 to Exit"<<endl;
		cout<<"Enter Your Choice : ";
		cin>>choice;
		cout<<endl;
		switch(choice){
			case 1:
				cout<<"Enter Train number : ";
				cin>>number;
				
				cout<<endl<<"Enter Train name : ";
				cin>>name;
				
				cout<<endl<<"Enter Source : ";
				cin>>source;
				
				cout<<endl<<"Enter Destination : ";
				cin>>destination;
				
				cout<<endl<<"Enter Train timing : ";
				cin>>time;
				
				irctc.addTrain(name,source,destination,time,number);
				break;
				
			case 2:
				irctc.displayAllTrains();
				break;
				
			case 3:
				int num;
				cout<<"Enter Train Number To Search : ";
				cin>>num;
				irctc.searchTrainByNumber(num);
				break;
				
			default:
				cout<<"Exiting the System Thank You..."<<endl;
				break;
				
		}
		
	}while(choice!=4);
	
	return 0;
}






















