
#include <iostream>
using namespace std;

class Date {
    private:
    int dd,mm,yy;
    public:
       //create default Constructor
       Date(int dd,int mm,int yy)
       {
           this->dd=dd;this->mm=mm;this->yy=yy;
       }
       //create a method showDate
       void showDate(){
           cout<<"Date is:"<<dd<<"/"<<mm<<"/"<<yy;
       }
};

class Person{
    private:
       string name;
       Date dob;
    public:
      //create constructor of class Person
       Person(string name,int dd,int mm,int yy):dob(dd,mm,yy)
       {
           this->name=name;
       }
       //create method in person
       void showPerson(){
           cout<<"person name is: "<<name<<"\n";
           dob.showDate();
       }
};
//inherited from person class
class Employee:public Person
{
    private:
    int eid,sal;
    public:
    //constructor
    Employee(int eid,int sal,string name,int dd,int mm,int yy)
    :Person(name,dd,mm,yy){
        this->eid=eid;
        this->sal=sal;
    }
    //method
    void showEmployee(){
        cout<<"\nEmployee id is:"<<eid<<"\n"<<"Employee salary is: "<<sal<<"\n";
        showPerson();
    }

    int getSal(){
        return sal;
    }
};

class SM:public Employee
{
    private:
       int tar,km,cpk;
       double comm;
    public:
       SM(int tar,int km,int cpk,int eid,int sal,string name,int dd,int mm,int yy):Employee(eid,sal,name,dd,mm,yy){
           this->tar=tar;
           this->km=km;
           this->cpk=cpk;
           
       }
       double calSal(){
           this->comm=tar+tar*0.2;
           double tot=comm+getSal()+km*cpk;
           return tot;
       }
       void showSMDetails(){
           cout<<"\ntarget sales :"<<tar<<"\n kilometers travelled: "<<km<<"\n charge per kilometer :"<<cpk<<"\n commision calculated is: "<<comm;
           showEmployee();
       }
       
       
};

class PM:public Employee{
    private:
        int km,cpk;
        string pname;
    public:
        PM(string pname,int km,int cpk,int eid,int sal,string name,int dd,int mm,int yy):Employee(eid,sal,name,dd,mm,yy){
            this->km=km;
            this->cpk=cpk;
            this->pname=pname;
        }
        double calSal(){
           
           double tot=getSal()+km*cpk;
           return tot;
       }
       void showPMDetails(){
           cout<<"\n project name :"<<pname<<"\n kilometers travelled: "<<km<<"\n charge per kilometer :"<<cpk;
           showEmployee();
       }
};

class BU:public Employee{
    private :
        string bu;
        int allowance;
    public:
        BU(string bu,int all,int eid,int sal,string name,int dd,int mm,int yy):Employee(eid,sal,name,dd,mm,yy){
            this->bu=bu;
            this->allowance=all;
        }
        double calSal(){
           
           double tot=getSal()+allowance;
           return tot;
       }
       void showBUDetails(){
           cout<<"\n Business unit name :"<<bu<<"\n allowances : "<<allowance;
           showEmployee();
       }
        
};
int main() {
      


      SM s1(100000,5,100,1001,20000,"Mahesh",31,8,2001);
      double sal=s1.calSal();
      s1.showSMDetails();
      cout<<"\n--------------------------------------------";
      PM p1("C++",5,100,1001,20000,"Mahesh",31,8,2001);
      double sal1=p1.calSal();
      p1.showPMDetails();
      cout<<"\nTotal salary for program Manager:"<<sal1;
      cout<<"\n---------------------------------------";
      BU b1("smartOps",20000,1001,20000,"Mahesh",31,8,2001);
      double sal2=b1.calSal();
      b1.showBUDetails();
      cout<<"\nTotal salary for Admin:"<<sal2;
      return 0;
}