#include<iostream>
using namespace std;

class Train{
	private:
		
		int trainNumber;
		string trainName;
	 	string source;	 
		string destination;
		string trainTime;
	
	public:
		
		//default constructor
		
		Train(){
			
		}
		
		//parameterized constructor
		
		Train(int number,string name,string source,string destination,string time ){
			trainNumber=number;
			trainName=name;
			this->source=source;
			this->destination=destination;
			trainTime=time;	
//			getTrainCount();
		}
		
		//static variable
		
		static int trainCount;
		
		//setter function
		
		void inputTrainDetails(int number,string name,string source,string destination,string time){
			trainNumber=number;
			trainName=name;
			this->source=source;
			this->destination=destination;
			trainTime=time;
//			getTrainCount();
		}
		
		//getter function
		
		void displayTrainDetails(){
			cout<<"Train Number : "<<trainNumber<<endl<<"Train Name : "<<trainName<<endl<<"Source : "<<source<<endl
			<<"Destination : "<<destination<<endl<<"Train Time : "<<trainTime<<endl;
			getTrainCount();
			
			cout<<"-----------------------------"<<endl;
			
		}
		
		//static function
		
		static void getTrainCount(){
			trainCount++;
			cout<<"Train count :"<<trainCount<<endl;
		}
		
		//destructor
		
		~Train(){
			trainCount--;
		}
	
	
};

int Train::trainCount=0;

int main(){
	
	Train t1;
	int number,n;
	cout<<"Enter record number :";
	cin>>n;
	Train trains[n];
	string name,source,destination,time;
	
	
	for(int i=0;i<n;i++){
		cout<<endl<<"Train "<<i+1<<" Detail :"<<endl;
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
		
		cout<<endl;
		trains[i].inputTrainDetails(number,name,source,destination,time);
	}
	
	for(int i=0;i<n;i++){
		trains[i].displayTrainDetails();
	}
	
	
	return 0;
}






















