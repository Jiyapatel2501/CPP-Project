#include<iostream>
using namespace std;

class LibraryItem{
	
	private:
		
		string title;
		string author;
		string dueDate;
		
	public:
		
		void setTitle(string newTitle){
			this->title=newTitle;
		}
		
		void setAuthor(string newAuthor){
			this->author=newAuthor;
		}
		
		void setDueDate(string newDueDate){
			this->dueDate=newDueDate;
		}
		
		string getTitle(){
			return title;
		}
		
		string getAuthor(){
			return author;
		}
		
		string getDueDate(){
			return dueDate;
		}
	
		virtual void setPages(int page){
		}
		virtual void setISBN(string isbn){
		}
		virtual void setDuration(string duration){
		}
		virtual void setIssueNumber(int issueNum){
		}
		
		virtual void checkOut() = 0;
		virtual void returnItem() = 0;
		virtual void displayDetails() = 0;
		
};

class Book : public LibraryItem{
	
	private:
		int pages;
		string isbn;
	public:
		
		void setPages(int page){
			this->pages=page;
		}
		
		void setISBN(string isbn){
			this->isbn=isbn;
		}
		
		int getPages(){
			return pages;
		}
		
		string getISBN(){
			return isbn;
		}
		
		void checkOut(){
			cout<<"Book Issued Successfully...."<<endl;
		}
		
		void returnItem(){
			cout<<"Book Returned Successfully...."<<endl;
		} 
		
		void displayDetails(){
			cout<<"Book Title is : "<<LibraryItem::getTitle()<<endl;
			cout<<"Book Author Name is : "<<LibraryItem::getAuthor()<<endl;
			cout<<"Book Due Date is : "<<LibraryItem::getDueDate()<<endl;	
			cout<<"Book Pages are : "<<getPages()<<endl;
			cout<<"Book ISBN Code is : "<<getISBN()<<endl;
		}
			
	
};

class DVDs : public LibraryItem{
	
	private:
		string duration;
		
	public:
		
		void setDuration(string duration){
			this->duration=duration;
		}
		
		string getDuration(){
			return duration;
		}
		
		void checkOut(){
			cout<<"DVD Issued Successfully...."<<endl;
		}
		
		void returnItem(){
			cout<<"DVD Returned Successfully...."<<endl;
		} 
		
		void displayDetails(){
			cout<<"DVD Title is : "<<LibraryItem::getTitle()<<endl;
			cout<<"DVD Author Name is : "<<LibraryItem::getAuthor()<<endl;
			cout<<"DVD Due Date is : "<<LibraryItem::getDueDate()<<endl;	
			cout<<"DVD Duration is : "<<getDuration()<<endl;
		}
			

	
};

class Magazines : public LibraryItem{
	
	private:
		int issueNumber;
		
	public:
		
		void setIssueNumber(int issueNum){
			this->issueNumber=issueNum;
		}
		
		int getIssueNumber(){
			return issueNumber;
		}
		
		void checkOut(){
			cout<<"Magazines Issued Successfully...."<<endl;
		}
		
		void returnItem(){
			cout<<"Magazines Returned Successfully...."<<endl;
		} 
		
		void displayDetails(){
			cout<<"Magazine Title is : "<<LibraryItem::getTitle()<<endl;
			cout<<"Magazine Author Name is : "<<LibraryItem::getAuthor()<<endl;
			cout<<"Magazine Due Date is : "<<LibraryItem::getDueDate()<<endl;	
			cout<<"Magazine Issue Number is : "<<getIssueNumber()<<endl;
		}
			

};


int main(){
	
	int choice,itemChoice,issueNum,page;
	string title,author,dueDate,isbn,duration;
	int index=0;
	
	LibraryItem *libraryArr[100]; 
	
	do{
		cout<<"===== Library Management System ====="<<endl;
		cout<<"Press 1 to Add Library Item"<<endl;
		cout<<"Press 2 to Search"<<endl;
		cout<<"Press 3 to Checkout"<<endl;
		cout<<"Press 4 to Return"<<endl;
		cout<<"Press 5 to Display"<<endl;
		cout<<"Press 6 to Exit"<<endl<<endl;
		
		cout<<"Enter your Choice : ";
		cin>>choice;
		
		cout<<"-----------------------------"<<endl;
		
		switch(choice){
			
			case 1:
				
				cout<<endl<<"Press 1 to Add Book"<<endl;
				cout<<"Press 2 to Add DVD"<<endl;
				cout<<"Press 3 to Add Magazine"<<endl;
				cout<<"Press 4 to Exit"<<endl<<endl;
				
				cout<<"Enter Your Choice : ";
				cin>>itemChoice;
				cout<<"-----------------------------"<<endl;
				
				switch(itemChoice){
					
					case 1:{
						
						cin.ignore();
						
						cout<<endl<<"Enter Book Title : ";
						getline(cin,title);
						
						cout<<"Enter Book Author Name : ";
						getline(cin,author);
						
						cout<<"Enter Book Due Date (dd/mm/yyyy) : ";
						getline(cin,dueDate);
						
						cout<<"Enter Book Pages : ";
						cin>>page;
						
						try{
							cout<<"Enter Book ISBN Code : ";
							cin>>isbn;
							if(isbn.length()!=13){
								throw 123;
							}							
							
						}catch(int a){
							cout<<"ISBN Code is not 13 Digits so Rewrite it...";
							cout<<endl<<"Enter Book ISBN Code : ";
							cin>>isbn;
						}
						
						
						libraryArr[index]=new Book();
						
						libraryArr[index]->setTitle(title);
						libraryArr[index]->setAuthor(author);
						libraryArr[index]->setDueDate(dueDate);
						libraryArr[index]->setPages(page);
						libraryArr[index]->setISBN(isbn);
						cout<<endl<<"-----------------------------"<<endl<<endl;
						
						index++;
						
						
						break;
					}
						
					case 2:{
						
						cin.ignore();
						
						cout<<endl<<"Enter DVD Title : ";
						getline(cin,title);
						
						cout<<"Enter DVD Author Name : ";
						getline(cin,author);
						
						cout<<"Enter DVD Due Date (dd/mm/yyyy) : ";
						getline(cin,dueDate);
						
						cout<<"Enter DVD Duration : ";
						getline(cin,duration);
						
						
						libraryArr[index]=new DVDs();
						
						libraryArr[index]->setTitle(title);
						libraryArr[index]->setAuthor(author);
						libraryArr[index]->setDueDate(dueDate);
						libraryArr[index]->setDuration(duration);
						cout<<"-----------------------------"<<endl<<endl;
						
						index++;
						
						break;
						
					}
					case 3:{
						
						cin.ignore();
						
						cout<<endl<<"Enter Magazines Title : ";
						getline(cin,title);
						
						cout<<"Enter Magazines Author Name : ";
						getline(cin,author);
						
						cout<<"Enter Magazines Due Date (dd/mm/yyyy) : ";
						getline(cin,dueDate);
						
						cout<<"Enter Magazines Issue Number : ";
						cin>>issueNum;
						
						
						libraryArr[index]=new Magazines();
						
						libraryArr[index]->setTitle(title);
						libraryArr[index]->setAuthor(author);
						libraryArr[index]->setDueDate(dueDate);
						libraryArr[index]->setIssueNumber(issueNum);
						cout<<"-----------------------------"<<endl<<endl;
						
						index++;
						
						break;
					}
						
					case 4:
						
						cout<<"Exited..."<<endl;
						break;
						
					default:
						
						cout<<"Invalid Choice...."<<endl;
						break;
				}
				
				break;
				
			case 2:{
				
				string s_title;
				cout<<"Enter Title to Search (Book / DVD / Magazine) : ";
				cin>>s_title;
				cout<<endl;
				bool flag=false;
				
				for(int i=0;i<index;i++){
					if(libraryArr[i]->getTitle()==s_title){
						flag=true;
						libraryArr[i]->displayDetails();
						cout<<endl<<"-----------------------------"<<endl;
					}
				}
				
				if(flag==false){
					cout<<"Library Item Not Found..."<<endl;
				}
				break;
			}
				
			case 3:{
				
				cout<<"Enter Title to Search (Book / DVD / Magazine) : ";
				cin>>title;
				
				bool flag=false;
				
				for(int i=0;i<index;i++){
					if(libraryArr[i]->getTitle()==title){
						flag=true;
						libraryArr[i]->checkOut();
						cout<<"-----------------------------"<<endl;
					}
				}
				
				if(flag==false){
					cout<<"Library Item Not Issued Successfully..."<<endl;
				}
				
				break;
			}
				
				
				
			case 4:{
				
				cout<<"Enter Title to Search (Book / DVD / Magazine) : ";
				cin>>title;
				
				bool flag=false;
				
				for(int i=0;i<index;i++){
					if(libraryArr[i]->getTitle()==title){
						flag=true;
						libraryArr[i]->returnItem();
						cout<<"-----------------------------"<<endl;
					}
				}
				
				if(flag==false){
					cout<<"Library Item Not Returned Successfully..."<<endl;
				}
				
				break;
			}
					
			case 5:{
			
				if(index==0){
					cout<<endl<<"Library Item Not Found..."<<endl<<endl;
				}else{
					for(int i=0;i<index;i++){
						libraryArr[i]->displayDetails();
						cout<<"-----------------------------"<<endl;
					}
				}
				
				break;
			}
				
			case 6:{
				
				cout<<"Exinting From System..."<<endl;
				break;
			}
				
				
				
			default:{
				
				cout<<"Invalid Choice..."<<endl;
				break;
			}
			
		}
			
		
		
		
	}while(choice!=6);
	
	for(int i=0;i<index;i++){
		delete libraryArr[i];
	}
	
	
	return 0;
}