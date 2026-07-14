#include<iostream>
using namespace std;
class BankAccount{
	private:
		double accountNumber;	
		string accountHolderName;
		double balance;
		
	public:
		
		string type;
		BankAccount(){
			
		}
		
		BankAccount(double accountNumber,string accountHolderName,double balance,string type){
			this->accountNumber=accountNumber;
			this->accountHolderName=accountHolderName;
			this->balance=balance;
			this->type;
		}
		
		void deposit(double d_amount){
			balance+=d_amount;
		}
		
		void withdraw(double w_amount){
			balance-=w_amount;
		}
		
		void setAccountInfo(double accountNumber,string accountHolderName,double balance,string type){
			this->accountNumber=accountNumber;
			this->accountHolderName=accountHolderName;
			this->balance=balance;
			this->type=type;
		}
		
		string gettype(){
			return type;
		}
		
		double getBalance(){
//			cout<<"Current Balance : "<<balance<<endl;
			return balance;
		}
		
		double acc_num(){
			return accountNumber;
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
		
		SavingsAccount(double accountNumber,string accountHolderName,double balance,string type)
		:BankAccount(accountNumber,accountHolderName,balance,type)
		{
			
		}
		
		void setSavingsAccountinfo(double accountNumber,string accountHolderName,double balance,string type){
			BankAccount::setAccountInfo(accountNumber,accountHolderName,balance,type);
		}
		
		
		void calculateInterest(){
			interest=(getBalance())*0.05;
		}
		
		void getInterest(){
			cout<<"Interest : "<<interest<<endl;
		}
		
		void getSavingsAccountinfo(){
			BankAccount::displayAcoountInfo();
			cout<<"Interest Rate : "<<interestRate<<endl;
			cout<<"Interest : "<<interest<<endl;
		}
		~SavingsAccount(){
			
		}
};

class CheckingAccount:public BankAccount{
	private:
		double overdraftLimit;
		
	public:
		
		CheckingAccount(){
			
		}
		
		CheckingAccount(double accountNumber,string accountHolderName,double balance,string type,double overdraftLimit)
		:BankAccount(accountNumber,accountHolderName,balance,type)
		{
			this->overdraftLimit=overdraftLimit;
		}
		
		void setCheckingAccountinfo(double accountNumber,string accountHolderName,double balance,string type,double overdraftLimit){
			BankAccount::setAccountInfo(accountNumber,accountHolderName,balance,type);
			this->overdraftLimit=overdraftLimit;
		}
		
		double checkOverdraft(){
		
			double limit=getBalance()+overdraftLimit;
			return limit;
		}
		
		void withdraw(double amount){
			
			double limit = checkOverdraft();
			
//			cout<<"Enter Withdrawal Amount : ";
//			cin>>amount;
			if(amount<= limit){
				BankAccount::withdraw(amount);
				cout<<"Withdrawal Successful...."<<endl;
			}else{
				cout<<"Overdraft Limit Exceeded...."<<endl;
			}
		}
		
		void getCheckingAccountinfo(){
			BankAccount::displayAcoountInfo();
			cout<<"Overdraft Limit : "<<overdraftLimit<<endl;
		}
		
		~CheckingAccount(){
			
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
		
		FixedDepositAccount(double accountNumber,string accountHolderName,double balance,string type,int term)
		:BankAccount(accountNumber,accountHolderName,balance,type)
		{
			this->term=term;
		}
		
		void setFixedDepositAccountinfo(double accountNumber,string accountHolderName,double balance,string type,int term){
			BankAccount::setAccountInfo(accountNumber,accountHolderName,balance,type);
			this->term=term;
		}
		
		void calculateInterest(){
			interest=getBalance()*0.08*term;
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
	
	double a_num,balance,term,overdraft,w_amount,d_amount,amount;
	int choice,wd_choice,acc_choice;
	string holder,type,yes_no;
	
	BankAccount *bankarr[100];
	int index=0;
	
	do{
		cout<<"-------------------------------------"<<endl;
		cout<<"Press 1 to Create Account"<<endl;
		cout<<"Press 2 to Withdraw"<<endl;
		cout<<"Press 3 to Deposit"<<endl;
		cout<<"Press 4 to See Your Account Info"<<endl;
		cout<<"Press 5 to Exit"<<endl;
		cout<<"-------------------------------------"<<endl;
		
		cout<<"Enter Your Choice : ";
		cin>>choice;
		
		switch(choice){
			
			case 1:{
				
				cout<<"Press 1 to Create Saving Account "<<endl;
				cout<<"Press 2 to Create Checking Account "<<endl;
				cout<<"Press 3 to Create Fix Deposite Account "<<endl;
				
				cout<<"Enter Your Choice : ";
				cin>>acc_choice;
				cout<<"-------------------------------------"<<endl;
				
				switch(acc_choice){
					
					case 1:{
						
						
						cout<<"Enter Account Number : ";
						cin>>a_num;
						cout<<"Enter Account Holder Name : ";
						cin>>holder;
						cout<<"Enter Account Balance : ";
						cin>>balance;
						type="SavingAccount";
		
						SavingsAccount *s=new SavingsAccount();
						s->setSavingsAccountinfo(a_num,holder,balance,type);
						bankarr[index]=s;
						index++;
				
						break;
						
					}
					
					case 2:{
						
						cout<<"Enter Account Number : ";
						cin>>a_num;
						cout<<"Enter Account Holder Name : ";
						cin>>holder;
						cout<<"Enter Account Balance : ";
						cin>>balance;
						type="checkingAccount";
						cout<<"Set Overdraft Limit : ";
						cin>>overdraft;
						
						CheckingAccount *c=new CheckingAccount();
						c->setCheckingAccountinfo(a_num,holder,balance,type,overdraft);
						bankarr[index]=c;
						index++;
						
						break;
					}
							
					case 3:{
						
						
						cout<<"Enter Account Number : ";
						cin>>a_num;
						cout<<"Enter Account Holder Name : ";
						cin>>holder;
						cout<<"Enter Account Balance : ";
						cin>>balance;
						type="fixDeposit";
						cout<<"Enter Your Term : ";
						cin>>term;
						
						FixedDepositAccount *f=new FixedDepositAccount();
						f->setFixedDepositAccountinfo(a_num,holder,balance,type,term);
						bankarr[index]=f;
						index++;
						
						break;
						
					}
						
					default:
						
						cout<<"Invalid Choice..."<<endl;
						break;
							
				}
				
				break;
			}

			case 2:{
				
				cout<<"Enter Account Number : ";
				cin>>a_num;
				
				bool flag=false;
				
				for(int i=0;i<index;i++){
					if(bankarr[i]->acc_num()==a_num){
						flag=true;
						if(bankarr[i]->gettype()=="SavingAccount"){
							cout<<"Enter Amount to Withdraw : ";
							cin>>w_amount;
							bankarr[i]->withdraw(w_amount);
							cout<<"-------------------------------------"<<endl;
						}else if(bankarr[i]->gettype()=="checkingAccount"){
							cout<<"Enter Amount to Withdraw : ";
							cin>>w_amount;
							((CheckingAccount*)bankarr[i])->withdraw(w_amount);
							cout<<"-------------------------------------"<<endl;
						}else if(bankarr[i]->gettype()=="fixDeposit"){
							cout<<"Can't Withdraw from Fix Deposit..."<<endl;
							cout<<"-------------------------------------"<<endl;
						}else{
							cout<<"Something is Wrong..."<<endl;
							cout<<"-------------------------------------"<<endl;
							break;
						}
						
						break;
					}
				}
				
				if(flag==false){
					cout<<"Account Number Not Found!"<<endl;
					cout<<"-------------------------------------"<<endl;
				}
				break;
			}
				
			case 3:{
				
				cout<<"Enter Account Number : ";
				cin>>a_num;
				
				bool flag=false;
				
				for(int i=0;i<index;i++){
					if(bankarr[i]->acc_num()==a_num){
						flag=true;
						if(bankarr[i]->gettype()=="SavingAccount"){
							cout<<"Enter Amount to Deposit : ";
							cin>>d_amount;
							bankarr[i]->deposit(d_amount);
							cout<<"-------------------------------------"<<endl;
						}else if(bankarr[i]->gettype()=="checkingAccount"){
							cout<<"Enter Amount to Deposit : ";
							cin>>d_amount;
							((CheckingAccount*)bankarr[i])->deposit(d_amount);
							cout<<"-------------------------------------"<<endl;
						}else if(bankarr[i]->gettype()=="fixDeposit"){
							cout<<"Can't Deposit from Fix Deposit..."<<endl;
							cout<<"-------------------------------------"<<endl;
						}else{
							cout<<"Something is Wrong..."<<endl;
							cout<<"-------------------------------------"<<endl;
							break;
						}
						
						break;
					}
				}
				
				if(flag==false){
					cout<<"Account Number Not Found!"<<endl;
					cout<<"-------------------------------------"<<endl;
				}

				
				break;
			}
				 	
			case 4:{
				
				cout<<"Enter Account Number : ";
				cin>>a_num;
				
				bool flag=false;
				
				for(int i=0;i<index;i++){
					if(bankarr[i]->acc_num()==a_num){
						flag=true;
						if(bankarr[i]->gettype()=="SavingAccount"){
							((SavingsAccount*)bankarr[i])->calculateInterest();
							((SavingsAccount*)bankarr[i])->getSavingsAccountinfo();
							cout<<"-------------------------------------"<<endl;
						}else if(bankarr[i]->gettype()=="checkingAccount"){
							((CheckingAccount*)bankarr[i])->getCheckingAccountinfo();
							cout<<"-------------------------------------"<<endl;
						}else{
							
							((FixedDepositAccount*)bankarr[i])->calculateInterest();
							((FixedDepositAccount*)bankarr[i])->getFixedDepositAccountinfo();
							cout<<"-------------------------------------"<<endl;
						}
					}
				}
					
				if(flag==false){
					cout<<"Account Number Not Found!"<<endl;
					cout<<"-------------------------------------"<<endl;
				}
				
				break;
			}
			
		
			default:{
				cout<<"Exited From System..."<<endl;
				break;
			}
		}		
			
	}while(choice!=5);
	
	return 0;
}

