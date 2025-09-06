#include <iostream>
#include <string>
using namespace std;

class Person 
{
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    void display()
	{
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};

class Staff : public Person 
{
protected:
    string staffID;
public:
    Staff(string n, int a, string id) : Person(n, a), staffID(id) {}
    void display()
	{
        Person::display();
        cout<<"Staff ID: "<<staffID<<endl;
    }
};

class Doctor : public Staff 
{
protected:
    string specialization;
public:
    Doctor(string n, int a, string id, string spec)
        : Staff(n, a, id), specialization(spec) {}
    void display()
	{
        Staff::display();
        cout<<"Specialization: "<<specialization<<endl;
    }
};

class Nurse : public Staff 
{
protected:
    int yearsOfExperience;
public:
    Nurse(string n, int a, string id, int exp)
        : Staff(n, a, id), yearsOfExperience(exp) {}
    void display()
	{
        Staff::display();
        cout<<"Years of Experience: "<<yearsOfExperience<<endl;
    }
};

class Surgeon : public Doctor 
{
private:
    int surgicalHours;
public:
    Surgeon(string n, int a, string id, string spec, int hours, string personName, int personAge)
        : Doctor(n, a, id, spec), surgicalHours(hours) {}
    void display()
	{
        cout<<"=== Surgeon Details ==="<<endl;
        cout<<"Person Details (Additional Profile):"<<endl;
        Person::display();
        cout<<"Doctor Details:"<<endl;
        Doctor::display();
        cout<<"Surgical Hours: "<<surgicalHours<<endl;
    }
};

int main() 
{
    Person person("John Smith", 45);
    Staff staff("Mary Johnson", 30, "S123");
    Doctor doctor("Alice Brown", 40, "D456", "Cardiology");
    Nurse nurse("Bob Wilson", 35, "N789", 8);
    Surgeon surgeon("Sarah Davis", 50, "D901", "Neurosurgery", 120, "Dr. Sarah", 50);

    int choice;
    do {
        cout<<"\n=== Hospital Management System ==="<<endl;
        cout<<"1. View Person Details"<<endl;
        cout<<"2. View Staff Details"<<endl;
        cout<<"3. View Doctor Details"<<endl;
        cout<<"4. View Nurse Details"<<endl;
        cout<<"5. View Surgeon Details"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter your choice (1-6): ";
        cin>>choice;

        // Handle user choice
        switch (choice) {
            case 1:
                cout<<"\n=== Person Details ==="<<endl;
                person.display();
                break;
            case 2:
                cout<<"\n=== Staff Details ==="<<endl;
                staff.display();
                break;
            case 3:
                cout<<"\n=== Doctor Details ==="<<endl;
                doctor.display();
                break;
            case 4:
                cout<<"\n=== Nurse Details ==="<<endl;
                nurse.display();
                break;
            case 5:
                cout<<"\n=== Surgeon Details ==="<<endl;
                surgeon.display();
                break;
            case 6:
                cout<<"Thank you for using the Hospital Management System!"<<endl;
                break;
            default:
                cout<<"Invalid choice! Please enter a number between 1 and 6."<<endl;
        }
    } while (choice != 6);
}
