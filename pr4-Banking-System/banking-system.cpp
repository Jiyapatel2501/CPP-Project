#include<iostream>

class BankAccount{
	private:
		double accountNumber;	
		string accountHolderName;
		double balance;
		
	public:
		
		BankAccount(){
			
		}
		
		BankAccount(double accountNumber,string accountHolderName,double balance){
			this->accountNumber=accountNumber;
			this->accountHolderName=accountHolderName;
			this->balance=balance;
		}
		
		void deposit(double deposit_amount){
			balance+=deposit_amount;
		}
		
		void withdraw(double withdraw_amount){
			balance-=withdraw_amount;
		}
		
		void setAccountInfo(double accountNumber,string accountHolderName,double balance){
			this->accountNumber=accountNumber;
			this->accountHolderName=accountHolderName;
			this->balance=balance;
		}
		
		void getBalance(){
			cout<<"Current Balance : "<<balance<<endl;
		}
		
		void displayAcoountInfo(){
			cout<<"Account Number : "<<accountNumber<<endl<<"Account Holder Name : "<<accountHolderName<<endl
			<<"Balance : "<<balance<<endl; 
		}
		
		~BankAccount(){
			
		}
};