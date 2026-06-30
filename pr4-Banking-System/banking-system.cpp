#include<iostream>
using namespace std;
class BankAccount{
	private:
		double accountNumber;	
		string accountHolderName;
	
	protected:
		double balance;
		
	public:
		
		BankAccount(){
			
		}
		
		BankAccount(double accountNumber,string accountHolderName,double balance){
			this->accountNumber=accountNumber;
			this->accountHolderName=accountHolderName;
			this->balance=balance;
		}
		
		void deposit(double d_amount){
			balance+=d_amount;
		}
		
		void withdraw(double w_amount){
			balance-=w_amount;
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

class SavingsAccount:public BankAccount{
	private:
		float interestRate=5;
		int interest;
		
	public:
		
		SavingsAccount(){
			
		}
		
		SavingsAccount(double accountNumber,string accountHolderName,double balance)
		:BankAccount(accountNumber,accountHolderName,balance)
		{
			
		}
		
		void setSavingsAccountinfo(double accountNumber,string accountHolderName,double balance){
			BankAccount::setAccountInfo(accountNumber,accountHolderName,balance);
		}
		
		void getSavingsAccountinfo(){
			BankAccount::displayAcoountInfo();
			cout<<"Interest Rate : "<<interestRate<<endl;
			cout<<"Interest : "<<interest<<endl;
		}
		
		void calculateInterest(){
			interest=balance*0.05;
		}
		
		void getInterest(){
			cout<<"Interest : "<<interest<<endl;
		}
		
		~SavingsAccount(){
			
		}
};

class FixedDepositAccount:public BankAccount{
	private:
		int term;
		int interestRate=8;
		int interest;
		
	public:
		FixedDepositAccount(){
			
		}
		
		FixedDepositAccount(double accountNumber,string accountHolderName,double balance,int term)
		:BankAccount(accountNumber,accountHolderName,balance)
		{
			this->term=term;
		}
		
		void setFixedDepositAccountinfo(double accountNumber,string accountHolderName,double balance,int term){
			BankAccount::setAccountInfo(accountNumber,accountHolderName,balance);
			this->term=term;
		}
		
		void calculateInterest(){
			interest=balance*0.08*term;
		}
		
		void getFixedDepositAccountinfo(){
			BankAccount::displayAcoountInfo();
			cout<<"Interest Rate : "<<interestRate<<endl;
			cout<<"Term : "<<term<<endl;
			cout<<"Interest : "<<interest<<endl;
			
		}
		
		
		void getInterest(){
			cout<<"Interest : "<<interest<<endl;
		}
		
		~FixedDepositAccount(){
			
		}	
};

int main(){
	
//	BankAccount b1;
//	b1.setAccountInfo(1,"jiya",200000);
//	b1.displayAcoountInfo();
//	b1.deposit(1000);
//	b1.withdraw(5000);
//	b1.getBalance();
//	
//	
//	SavingsAccount s1;
//	s1.setSavingsAccountinfo(2,"sfsdfgd",1000);
//	s1.calculateInterest();
//	s1.getSavingsAccountinfo();
//	
//	FixedDepositAccount f1;
//	f1.setFixedDepositAccountinfo(3,"abcd",20000,2);
//	f1.calculateInterest();
//	f1.getFixedDepositAccountinfo();
////	s1.getInterest();



	
	return 0;
}

