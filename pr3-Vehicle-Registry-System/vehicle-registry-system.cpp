#include<iostream>
using namespace std;


class Vehicle{
	private:
		int vehicleID;
		string manufacturer;
		string model;
		int year;
		
		
	public:
		string type;
		static int totalVehicles;
		
//		default constructor

		Vehicle(){
			
		}
		
//		parameterized constructor

	Vehicle(int id,string manufacturer,string model,int year,string type){
		this->vehicleID=id;
		this->manufacturer=manufacturer;
		this->model=model;
		this->year=year;
		this->type=type;
	}
	
//		setter function

	void setVehicleInfo(int id,string manufacturer,string model,int year,string type){
		this->vehicleID=id;
		this->manufacturer=manufacturer;
		this->model=model;
		this->year=year;
		this->type=type;
		totalVehiclesingo();
	}
	
	
//	getter function

	void getVehicleInfo(){
		cout<<endl;
		cout<<"Vehicle ID : "<<vehicleID<<endl<<"Manufacturer : "<<manufacturer<<endl<<"Model : "<<model<<
		endl<<"Year : "<<year<<endl;
	}
	
	int getId(){
		return vehicleID;
	}
	
	string getType(){
		return type;
	}
	
//	static funtion

	static totalVehiclesingo(){
		totalVehicles++;
	}
	
//	deconstructor

	~Vehicle(){
		
	}	
	
};

int Vehicle::totalVehicles=0;

class Car : public Vehicle{
	private:
		string fuelType;
	
	public:
		
//		default constructor

		Car(){
			
		}

//		parameterized constructor

		Car(int id,string manufacturer,string model,int year,string type,string fuelType):Vehicle(id,manufacturer,model,year,type){
			this->fuelType=fuelType;
		}
		
//		setter function

		void setCarInfo(int id,string manufacturer,string model,int year,string type,string fuelType){
			Vehicle::setVehicleInfo(id,manufacturer,model,year,type);
			this->fuelType=fuelType;
		}
		
//	getter function

		void getCarInfo(){
			Vehicle::getVehicleInfo();
			cout<<"Fuel Type : "<<fuelType<<endl;
		}
		
//	deconstructor

		~Car(){
			
		}
	
	
};

class ElectricCar : public Car{
	private:
		int batteryCapacity;
		
	public:
		
//		default constructor

		ElectricCar(){
			
		}
		
//		parameterized constructor

		ElectricCar(int id,string manufacturer,string model,int year,string type,string fuelType,int batteryCapacity):
		Car(id,manufacturer,model,year,type,fuelType)
		{
			this->batteryCapacity=batteryCapacity;
		}
		
//		setter function

		void setElectricCarInfo(int id,string manufacturer,string model,int year,string type,string fuelType,int batteryCapacity){
			Car::setCarInfo(id,manufacturer,model,year,type,fuelType);
			this->batteryCapacity=batteryCapacity;
		}
		
//	getter function

		void getElectricCarInfo(){
			Car::getCarInfo();
			cout<<"Battery Capacity : "<<batteryCapacity<<endl;
		}
		
//	deconstructor

		~ElectricCar(){
			
		}
		
};

class Aircraft{
	private:
		int flightRange;
		
	public:
		
//		default constructor
		Aircraft(){
			
		}
		
//		parameterized constructor
		Aircraft(int flightRange)
		{
			this->flightRange=flightRange;
		}
		
//		setter function
		void setAircraftInfo(int flightRange){
			this->flightRange=flightRange;
		}
		
//	getter function
		void getAircraftInfo(){
			cout<<"Flight Range : "<<flightRange<<endl;
		}
		
//	deconstructor

		~Aircraft(){
			
		}
};

class FlyingCar : public Car,public Aircraft{
	public:
		
//		default constructor

		FlyingCar(){
				
		}
		
//		parameterized constructor
		
		FlyingCar(int id,string manufacturer,string model,int year,string type,string fuelType,int flightRange)
		:Car(id,manufacturer,model,year,type,fuelType),Aircraft(flightRange)
		{
			
		}
		
//		setter function
		
		void setFlyingCarInfo(int id,string manufacturer,string model,int year,string type,string fuelType,int flightRange){
			Car::setCarInfo(id,manufacturer,model,year,type,fuelType);
			Aircraft::setAircraftInfo(flightRange);
		}
		
//	getter function

		void getFlyingCarInfo(){
			Car::getCarInfo();
			Aircraft::getAircraftInfo();
		}
		
//	deconstructor

		~FlyingCar(){
			
		}
			
			
}; 

class SportsCar : public ElectricCar{
	private:
		int topSpeed;
		
	public:
		
//		default constructor

		SportsCar(){
			
		}
		
//		parameterized constructor

		SportsCar(int id,string manufacturer,string model,int year,string type,string fuelType,int batteryCapacity,int topSpeed)
		:ElectricCar(id,manufacturer,model,year,type,fuelType,batteryCapacity)
		{
			this->topSpeed=topSpeed;
		}
		
//		setter function
		void setSportsCarInfo(int id,string manufacturer,string model,int year,string type,string fuelType,int batteryCapacity,int topSpeed){
			ElectricCar::setElectricCarInfo(id,manufacturer,model,year,type,fuelType,batteryCapacity);
			this->topSpeed=topSpeed;
		}
		
//	getter function

		void getSportsCarInfo(){
			ElectricCar::getElectricCarInfo();
			cout<<"Top Speed : "<<topSpeed<<endl;
		}
		
//	deconstructor

		~SportsCar(){
			
		}
};

class Sedan : public Car{
	public:
		
//		default constructor
		Sedan(){
			
		}	
		
//		parameterized constructor

		Sedan(int id,string manufacturer,string model,int year,string type,string fuelType):Car(id,manufacturer,model,year,type,fuelType){
			
		}
		
//		setter function

		void setSedanInfo(int id,string manufacturer,string model,int year,string type,string fuelType){
			Car::setCarInfo(id,manufacturer,model,year,type,fuelType);
		}
		
//	getter function
		void getSedanInfo(){
			Car::getCarInfo();
		}
		
//	deconstructor

		~Sedan(){
			
		}
		
};

class SUV : public Car{
	public:
	
//		default constructor
	
		SUV(){
			
		}	
		
//		parameterized constructor

		SUV(int id,string manufacturer,string model,int year,string type,string fuelType):Car(id,manufacturer,model,year,type,fuelType){
			
		}

//		setter function		
		void setSUVInfo(int id,string manufacturer,string model,int year,string type,string fuelType){
			Car::setCarInfo(id,manufacturer,model,year,type,fuelType);
		}
		
//	getter function
		void getSUVInfo(){
			Car::getCarInfo();
		}
	
//	deconstructor	
		~SUV(){
			
		}
		
};

class VehicleRegistry:public ElectricCar,public FlyingCar,public SportsCar,public Sedan,public SUV{
	private:
		Vehicle *vehicleArr[100];
		int index=0;
	
	public:
		
		void addElectricCar(int id,string manufacturer,string model,int year,string type,string fuelType,int batteryCapacity){
			ElectricCar *e=new ElectricCar();
			e->setElectricCarInfo(id,manufacturer,model,year,type,fuelType,batteryCapacity);
			vehicleArr[index]=e;
			index++;
		}
		
		void addFlyingCar(int id,string manufacturer,string model,int year,string type,string fuelType,int flightRange){
			FlyingCar *f=new FlyingCar();
			f->setFlyingCarInfo(id,manufacturer,model,year,type,fuelType,flightRange);
			vehicleArr[index]=f;
			index++;
		}
		
		void addSportsCar(int id,string manufacturer,string model,int year,string type,string fuelType,int batteryCapacity,int topSpeed){
			SportsCar *s=new SportsCar();
			s->setSportsCarInfo(id,manufacturer,model,year,type,fuelType,batteryCapacity,topSpeed);
			vehicleArr[index]=s;
			index++;
		}
		
		void addSedan(int id,string manufacturer,string model,int year,string type,string fuelType){
			Sedan *se=new Sedan();
			se->setSedanInfo(id,manufacturer,model,year,type,fuelType);
			vehicleArr[index]=se;
			index++;
		}
		
		void addSUV(int id,string manufacturer,string model,int year,string type,string fuelType){
			SUV *suv=new SUV();
			suv->setSUVInfo(id,manufacturer,model,year,type,fuelType);
			vehicleArr[index]=suv;
			index++;
		}
		
		void displayinfo(){
			for(int i=0;i<index;i++){
				if(vehicleArr[i]->getType()=="ElectricCar"){
					((ElectricCar*)vehicleArr[i])->getElectricCarInfo();
					cout<<"------------------------------------"<<endl;
				}else if(vehicleArr[i]->getType()=="FlyingCar"){
					((FlyingCar*)vehicleArr[i])->getFlyingCarInfo();
					cout<<"------------------------------------"<<endl;
				}else if(vehicleArr[i]->getType()=="SportsCar"){
					((SportsCar*)vehicleArr[i])->getSportsCarInfo();
					cout<<"------------------------------------"<<endl;
				}else if(vehicleArr[i]->getType()=="Sedan"){
					((Sedan*)vehicleArr[i])->getSedanInfo();
					cout<<"------------------------------------"<<endl;
				}else if(vehicleArr[i]->getType()=="SUV"){
					((SUV*)vehicleArr[i])->getSUVInfo();
					cout<<"------------------------------------"<<endl;
				}
			}
		}
		
		void searchId(int id){
			for(int i=0;i<index;i++){
				if(vehicleArr[i]->getId()==id){
					if(vehicleArr[i]->getType()=="ElectricCar"){
						((ElectricCar*)vehicleArr[i])->getElectricCarInfo();
						cout<<"------------------------------------"<<endl;
					}else if(vehicleArr[i]->getType()=="FlyingCar"){
						((FlyingCar*)vehicleArr[i])->getFlyingCarInfo();
						cout<<"------------------------------------"<<endl;
					}else if(vehicleArr[i]->getType()=="SportsCar"){
						((SportsCar*)vehicleArr[i])->getSportsCarInfo();
						cout<<"------------------------------------"<<endl;
					}else if(vehicleArr[i]->getType()=="Sedan"){
						((Sedan*)vehicleArr[i])->getSedanInfo();
						cout<<"------------------------------------"<<endl;
					}else if(vehicleArr[i]->getType()=="SUV"){
						((SUV*)vehicleArr[i])->getSUVInfo();
						cout<<"------------------------------------"<<endl;
					}
				}else{
					cout<<"There is no Vahicle available on this ID..."<<endl;
					cout<<"------------------------------------"<<endl;
					break;
				}
			}
		}
		
		~VehicleRegistry(){
			for(int i=0;i<index;i++){
				delete vehicleArr[i];
			}
		}
		
};

int main(){
	
	int choice,v_choice,id,year,battery,speed,range;
	string model,manufacturer,fuelType,type; 
	VehicleRegistry r1;
	
	do{
		cout<<endl;
		cout<<"Press 1 to Add a vehicle"<<endl;
		cout<<"Press 2 to View all vehicles"<<endl;
		cout<<"Press 3 to Search by Id"<<endl;
		cout<<"Press 4 to Exit"<<endl;
		cout<<"------------------------------------"<<endl;
		cout<<"Enter Your Choice :";
		cin>>choice;
		
		switch(choice){
			case 1:
				cout<<"Press 1 to Add ElectricCar"<<endl;
				cout<<"Press 2 to Add FlyingCar"<<endl;
				cout<<"Press 3 to Add SportsCar"<<endl;
				cout<<"Press 4 to Add Sedan"<<endl;
				cout<<"Press 5 to Add SUV"<<endl;
				cout<<"Enter Your Choice :";
				cin>>v_choice;
				cout<<endl<<"------------------------------------"<<endl;
				
				switch(v_choice){
					case 1:
						cout<<"Enter Vehicle ID : ";
						cin>>id;
						cout<<"Enter Vehicle manufacturer : ";
						cin>>manufacturer;
						cout<<"Enter Vehicle model : ";
						cin>>model;
						cout<<"Enter Vehicle Year : ";
						cin>>year;
						type="ElectricCar";
						cout<<"Enter Vehicle Fuel Type : ";
						cin>>fuelType;
						cout<<"Enter Vehicle Battery Capacity : ";
						cin>>battery;
						
						r1.addElectricCar(id,manufacturer,model,year,type,fuelType,battery);
						break;
						
					case 2:
						
						cout<<"Enter Vehicle ID : ";
						cin>>id;
						cout<<"Enter Vehicle manufacturer : ";
						cin>>manufacturer;
						cout<<"Enter Vehicle model : ";
						cin>>model;
						cout<<"Enter Vehicle Year : ";
						cin>>year;				
						type="FlyingCar";
						cout<<"Enter Vehicle Fuel Type : ";
						cin>>fuelType;
						cout<<"Enter Vehicle Flight Range : ";
						cin>>range;
						r1.addFlyingCar(id,manufacturer,model,year,type,fuelType,range);
						break;
						
					case 3:
						
						cout<<"Enter Vehicle ID : ";
						cin>>id;
						cout<<"Enter Vehicle manufacturer : ";
						cin>>manufacturer;
						cout<<"Enter Vehicle model : ";
						cin>>model;
						cout<<"Enter Vehicle Year : ";
						cin>>year;
						type="SportsCar";
						cout<<"Enter Vehicle Fuel Type : ";
						cin>>fuelType;
						cout<<"Enter Vehicle Battery Capacity : ";
						cin>>battery;
						cout<<"Enter Vehicle Top Speed : ";
						cin>>speed;
						r1.addSportsCar(id,manufacturer,model,year,type,fuelType,battery,speed);
						break;
						
					case 4:
						
						cout<<"Enter Vehicle ID : ";
						cin>>id;
						cout<<"Enter Vehicle manufacturer : ";
						cin>>manufacturer;
						cout<<"Enter Vehicle model : ";
						cin>>model;
						cout<<"Enter Vehicle Year : ";
						cin>>year;
						type="Sedan";
						cout<<"Enter Vehicle Fuel Type : ";
						cin>>fuelType;
						
						r1.addSedan(id,manufacturer,model,year,type,fuelType);
						break;
						
					case 5:
						cout<<"Enter Vehicle ID : ";
						cin>>id;
						cout<<"Enter Vehicle manufacturer : ";
						cin>>manufacturer;
						cout<<"Enter Vehicle model : ";
						cin>>model;
						cout<<"Enter Vehicle Year : ";
						cin>>year;
						type="SUV";
						cout<<"Enter Vehicle Fuel Type : ";
						cin>>fuelType;
						
						r1.addSUV(id,manufacturer,model,year,type,fuelType);
						break;
						
						
					default:
						cout<<"Invalid Choice..."<<endl;
						break;
				}
				
				break;
			
			case 2:
				r1.displayinfo();
				break;
				
			case 3:
				int s_id;
				cout<<"Enter Vehicle ID to Search : ";
				cin>>s_id;
				r1.searchId(s_id);
				break;
				
			default:
				cout<<"Exited From System..."<<endl;
				break;
		}
		
	}while(choice!=4);	
	
	return 0;
}









