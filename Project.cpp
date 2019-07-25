#include <iostream>
#include <cstdlib>
#include <fstream> //reading from /txt files
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
//#include "linkedlist.h"
using namespace std;


// creating structure for the linked list, it can be imprted from a .h file later
struct Apartment
{
	int id;
	int rent;
	string location;
	int bedrooms;
	string laundry;
	Apartment* prev;
	Apartment* next;
	bool chosen;
	string resident;
	int student_id;

};

struct Student
{
	int id;
	string name ;
	int rent;
	int bedrooms;
	string location;
	string laundry;
	bool chosen;
};

struct ApartmentList
{
	ApartmentList();
	~ApartmentList();

	Apartment* header;
	Apartment* trailer;

	void insert(const Apartment& newapartment);
	void add(Apartment* v, int id, int rent, string location, int br, string lau);
	void remove(Apartment* v);
	void removeFront();
	bool isEmpty();

};

void insertlist() {
}

ApartmentList::ApartmentList() {
	header = new Apartment;
	trailer = new Apartment;
	header->next = trailer;
	trailer->prev = header;
}


bool ApartmentList::isEmpty() 
{ return (header->next == trailer); }


ApartmentList::~ApartmentList() {
	while (!isEmpty()){
		delete header;
		delete trailer;
	}
}

void ApartmentList::add(Apartment* v, const int id, const int rent, const string location, const int br, const string lau) {
	Apartment* u = new Apartment; 
	u->id = id;
	u->rent = rent;
	u->location = location;
	u->bedrooms = br;
	u->laundry = lau;
	u->next = v;
	u->prev = v->prev;
	v->prev->next = v->prev = u;
}

void ApartmentList::remove(Apartment* v) {
	Apartment* u = v->prev;
	Apartment* w = v->next;
	u->next = w;
	w->prev = u;
	delete v;
}


class WaitingStudentQueue {
	public:
		WaitingStudentQueue();
		bool isEmpty() const;
		const Student& front();
		void enqueue(const Student& s);
		void dequeue();
};


int main(int argc, char *argv[])
{
	ifstream ifs;
	ifs.open(argv[1]);
	string line;

	ApartmentList alist;

	if (argc!=3)
	{
		cerr << "Usage: "<< argv[0] << " Input apartment file followed by the student file" <<endl;
		exit(-1);
	}


	if (ifs.fail())
	{
		cerr<< "Unable to open the file :("<<endl;
		exit(-1);
	}



	while (getline( ifs, line))
	{
		istringstream ss(line);

		int id, rent, bedrooms;
		string location, laundry;

		ss >> id >> name >>location >> bedrooms >> laundry >> rent;

		alist.add(alist.header->next, id, rent, location, bedrooms, laundry);

		cout << alist.trailer->prev << "\n";

		cout << alist.trailer->prev->id << "\n";

	}


	ifs.close();

	cout << alist.trailer;

	ifs.open(argv[2]);


	if (ifs.fail())
	{
		cerr<< "Unable to open the file :("<<endl;
		exit(-1);
	}

	while (getline(ifs,line))
	{
		line;	
	}

	Apartment * P = new Apartment;
	Student * q = new Student;
	for ( Apartment* p = Apartmentlist->header; p != NULL; p= p->next){
		for (Student* q = Studentlist->header; q != NULL; q = q->next){

			if((p->location == q->location || q-> location == "Any")&&(p->bedrooms == q -> bedrooms || q-> bedrooms =="Any") && p->rent <= q->rent &&(q->laundry == p->laundry || p->laundry == "Any")&&p->chosen == false && q-> chosen == false)
			{
				p->chosen = true;
				p->resident = q->name;
				q->chosen = true;
				//dequeu the student from the waiting student queue
				p->student_id = q->id;			

			}

		}
	}
	Apartment * a = new Apartment;
	//a better method would just be iterate through waiting list queue, but its not made yet
	/*if(q->chosen = false)
	  {

	  }
	  */
	for ( Apartment* a = Apartmentlist->header; a != NULL; a= a->next){
		if (a->Chosen=true)
		{
			cout<<"The apartment "<<a->id<< " is assigned to "<< a->resident<<"("<<a->student_id<<")."<<endl;


		}
		else
		{
			cout<<"The apartment "<< a->id<< " is unassigned."<<endl;
		}
	}
	return 0;
}

