#include<iostream>
using namespace std;
class BankAccount{
	private:
		double accountNumber;	
		string accountHolderName;
	
	protected:
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
		
		void getBalance(){
			cout<<"Current Balance : "<<balance<<endl;
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
			interest=balance*0.05;
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
		
			double limit=balance+overdraftLimit;
			return limit;
		}
		
		void withdraw(double amount){
			
			double limit = checkOverdraft();
			
			cout<<"Enter Withdrawal Amount : ";
			cin>>amount;
			if(amount<= limit){
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
	
	double a_num,balance,term,overdraft,w_amount,d_amount,amount;
	int choice,wd_choice;
	string holder,type,yes_no;
	
	BankAccount *bankarr[100];
	int index=0;
	
	do{
		
		cout<<"Press 1 to Create Saving Account"<<endl;
		cout<<"Press 2 to Create Checking Account"<<endl;
		cout<<"Press 3 to Create Fixed Deposit Account"<<endl;
		cout<<"Press 4 to withdraw"<<endl;
		cout<<"Press 5 to Deposite"<<endl;
//		cout<<"Press 6 to Withdraw from Checking Account"<<endl;
		cout<<"Press 6 to Check Overdraft"<<endl;
		cout<<"Press 7 to See Your Account Info "<<endl;
		cout<<"press 8 to Exit"<<endl;
		
		cout<<"Enter Your Choice : ";
		cin>>choice;
		
		switch(choice){
			
			case 1:{
				cout<<"Enter Account Number : ";
				cin>>a_num;
				cout<<"Enter Account Holder Name : ";
				cin>>holder;
				cout<<"Enter Account Balance : ";
				cin>>balance;
				type="SavingAccount";
//				cout<<"If You Want to Withdraw or Deposite Enter Yes : ";
//				cin>>yes_no;
				SavingsAccount *s=new SavingsAccount();
				s->setSavingsAccountinfo(a_num,holder,balance,type);
				bankarr[index]=s;
				
//				if(yes_no=="yes"){
//					cout<<"Enter 1 to withdraw"<<endl;
//					cout<<"Enter 2 to deposit"<<endl;
//					cout<<"Enter Your Choice : ";
//					cin>>wd_choice;
//					
//					if(wd_choice==1){
//						cout<<"Enter Amount to Withdraw : ";
//						cin>>w_amount;
//						s->withdraw(w_amount);
//						cout<<"Withdraw Successfully..."<<endl;
//					}else if(wd_choice==2){
//						cout<<"Enter Amount to Deposit : ";
//						cin>>d_amount;
//						s->deposit(d_amount);
//						cout<<"Deposit Successfully..."<<endl;
//					}else{
//						cout<<"Invalid choice..."<<endl;
//						break;
//					}
//					
//				}else{
//					break;
//				}
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
				
//				cout<<"If You Want to Withdraw from Checking Account Enter Yes : ";
//				cin>>yes_no;
				
				
				CheckingAccount *c=new CheckingAccount();
				c->setCheckingAccountinfo(a_num,holder,balance,type,overdraft);
//				if(yes_no=="yes"){
//					c->checkOverdraft();
//				}else{
//					break;
//				}
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
				
			case 4:{
				
				cout<<"Enter Account Number : ";
				cin>>a_num;
				
				for(int i=0;i<index;i++){
					if(bankarr[i]->acc_num()==a_num){
						if(bankarr[i]->gettype()=="SavingAccount"){
							cout<<"Enter Amount to Withdraw : ";
							cin>>w_amount;
							bankarr[i]->withdraw(w_amount);
						}else{
							cout<<"You Don't Have Saving Account..."<<endl;
							break;
						}
					}else{
						cout<<"Account Number Not Found!"<<endl;

					}
				}
				
				break;
			}
				 	
			case 8:{
				for(int i=0;i<index;i++){
					if(bankarr[i]->gettype()=="SavingAccount"){
						((SavingsAccount*)bankarr[i])->calculateInterest();
						((SavingsAccount*)bankarr[i])->getSavingsAccountinfo();
					}else if(bankarr[i]->gettype()=="checkingAccount"){
						((CheckingAccount*)bankarr[i])->getCheckingAccountinfo();
					}else{
						
						((FixedDepositAccount*)bankarr[i])->calculateInterest();
						((FixedDepositAccount*)bankarr[i])->getFixedDepositAccountinfo();
					}
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

