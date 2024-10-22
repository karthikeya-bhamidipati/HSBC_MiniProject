#include "OtherClasses.h"
#include <conio.h>


extern const char file[] = "files/userinfo.dat";
extern const char temp[] = "files/temp.dat";
extern const char history[] = "files/history.dat";
extern const char dues[] = "files/dueslist.dat";


class Info: protected Admin, public SFC, public SaiReplica, protected Stores, protected HostelEsentials
{
	static int TotalUsers;
	char name[20],pass[15],redg_no[7];
	int balance,department;
	public:
	void SetVal()
	{
		cout << "\n\n\t\tEnter the Name of the Student:";
		cin.getline(name,20);
		cout << "\t\tEnter the Regd_no:";
		cin >> redg_no;
		balance = 0;
		department = 0;
		strcpy(pass, "omsrisairam");
	}
	friend ostream &operator << (ostream &dout, Info &user)
	{
		dout << "\n\n\t\tName of the User is " << user.getname() << endl;
		dout << "\n\n\t\tRegd_no of the User is " << user.getuser() << endl;
		dout << "\n\n\t\tBelongs to the Department ";
		switch(user.getdepartment())
		{
			case 0: dout << "None"; break;
			case 1: dout << "SaiReplica"; break;
			case 2: dout << "SFC"; break;
			case 3: dout << "Stores"; break;
			case 4: dout << "HostelEssentials"; break;
			case 5: dout << "Admin"; break;	
		}
		dout << "\n\n";
		return dout;
	}
	void ChangePass();
	void AddUser();
	void AddBal();
	int Users()
	{
		return TotalUsers;
	}
	void Update()
	{
		TotalUsers--;
	}
	void AdminPass(char * pa)
	{
		strcpy(pass,pa);
	}
	void AddBalance(int bal)
	{
		balance = balance + bal;
	}
	void DeductBalance(int bal)
	{
		balance = balance - bal;
	}
	int getbalance()
	{
		return balance;
	}
	int getdepartment()
	{
		return department;
	}
	void SetDepartment();
	void Department(int a)
	{
		department = a;
	}
	char * getname()
	{
		return name;
	}
	char * getuser()
	{
		return redg_no;
	}
	char * getpass()
	{
		return pass;
	}
	void DeductReplica(Info);
	void DeductHe(Info);
	void DeductStores(Info);
};
int Info::TotalUsers = 0;


void Info::DeductReplica(Info me)
{
	int order;
	cout << "Enter the number of pages to be printed:";
	cin >> order;
	if(pages - order < 0)
	{
		cout << "\n\n\t\tYou are short by " << order - pages << endl;
		system("PAUSE");
		return;
	}
	int amt = order * 2;
	if(balance - amt < 0)
	{
		int due = amt - balance;
		char choice = 'n';
		cout << "\n\n\t\tA Due of " << due << "will be added. Do you wish to continue.[y/n]:" << endl;
		cin >> choice;
		if(choice == 'n')
			return;
		pages = pages - order;
		ofstream his;
		his.open(history, ios::binary | ios::app);
		History h;
		char re1[] = "Saireplica print money with due";
		h.IntoHistory(this->redg_no, me.getuser(), re1, 0-balance);
		balance = 0;
		his.write((char *)&h, sizeof(History));
		his.close();
		Dues d;
		char re[] = "Saireplica";
		d.EnterDues(this->redg_no, re, due);
		ofstream oFile;
		oFile.open(dues, ios::binary | ios::app);
		oFile.write((char *)&d, sizeof(Dues));
		oFile.close();
	}
	cout << "\n\n\t\tMoney being deducted is " << amt << endl;
	balance = balance - amt;
	pages = pages - order;
	ofstream his;
	his.open(history, ios::binary | ios::app);
	History h;
	char re[] = "Saireplica print money";
	h.IntoHistory(this->redg_no, me.getuser(), re, 0-amt);
	his.write((char *)&h, sizeof(History));
	his.close();
}



void Info::DeductHe(Info me)
{
	int amt;
	cout << "\n\n\t\tEnter the amount you want to deduct:";
	cin >> amt;
	if(balance - amt < 0)
	{
		int due = amt - balance;
		char choice = 'n';
		cout << "\n\n\t\tA Due of " << due << "will be added. Do you wish to continue.[y/n]:" << endl;
		cin >> choice;
		if(choice == 'n')
			return;
		ofstream his;
		his.open(history, ios::binary | ios::app);
		History h;
		char re1[50];
		cout << "\n\n\t\tEnter the reason deduction:";
		cin.ignore();
		cin.getline(re1,50);
		h.IntoHistory(this->redg_no, me.getuser(), re1, 0-balance);
		balance = 0;
		his.write((char *)&h, sizeof(History));
		his.close();
		Dues d;
		char re[] = "Saireplica";
		d.EnterDues(this->redg_no, re, due);
		ofstream oFile;
		oFile.open(dues, ios::binary | ios::app);
		oFile.write((char *)&d, sizeof(Dues));
		oFile.close();
	}
	cout << "\n\n\t\tMoney being deducted is " << amt << endl;
	balance = balance - amt;
	pages = pages;
	ofstream his;
	his.open(history, ios::binary | ios::app);
	History h;
	char re[50];
	cout << "\n\n\t\tEnter the reason deduction:";
	cin.ignore();
	cin.getline(re,50);
	h.IntoHistory(this->redg_no, me.getuser(), re, 0-amt);
	his.write((char *)&h, sizeof(History));
	his.close();
}



void Info::DeductStores(Info me)
{
	int amt;
	cout << "\n\n\t\tEnter the amount you want to deduct:";
	cin >> amt;
	if(balance - amt < 0)
	{
		int due = amt - balance;
		char choice = 'n';
		cout << "\n\n\t\tA Due of " << due << "will be added. Do you wish to continue.[y/n]:" << endl;
		cin >> choice;
		if(choice == 'n')
			return;
		ofstream his;
		his.open(history, ios::binary | ios::app);
		History h;
		char re1[50];
		cout << "\n\n\t\tEnter the reason deduction:";
		cin.ignore();
		cin.getline(re1,50);
		h.IntoHistory(this->redg_no, me.getuser(), re1, 0-balance);
		balance = 0;
		his.write((char *)&h, sizeof(History));
		his.close();
		Dues d;
		char re[] = "Saireplica";
		d.EnterDues(this->redg_no, re, due);
		ofstream oFile;
		oFile.open(dues, ios::binary | ios::app);
		oFile.write((char *)&d, sizeof(Dues));
		oFile.close();
	}
	cout << "\n\n\t\tMoney being deducted is " << amt << endl;
	balance = balance - amt;
	pages = pages;
	ofstream his;
	his.open(history, ios::binary | ios::app);
	History h;
	char re[50];
	cout << "\n\n\t\tEnter the reason deduction:";
	cin.ignore();
	cin.getline(re,50);
	h.IntoHistory(this->redg_no, me.getuser(), re, 0-amt);
	his.write((char *)&h, sizeof(History));
	his.close();
}


void Info::AddBal()
{
	Info user;
	ifstream iFile;
	ofstream nFile;
	char u[7];
	iFile.open(file, ios::binary);
	nFile.open(temp, ios::binary);
	if (!iFile)
	{
		cout<< "File could not be opened.....";
		nFile.close();
		system("PAUSE");
		return;
	}
	bool found = false;
	cout << "Enter the user name you want to add money into:";
	cin.ignore();
	cin.getline(u,7);
	while (iFile.read((char *)&user, sizeof(Info)))
	{
		if(!strcmp(user.getuser(), u))
		{
			found = true;
			int amt = 0;
			cout << "\n\n\t\tEnter the amount you want to Add:";
			cin >> amt;
			ofstream his;
			his.open(history, ios::binary | ios::app);
			History h;
			char reason[] = "Into Account";
			h.IntoHistory(user.getuser(), this->redg_no, reason , amt);
			his.write((char *)&h, sizeof(History));
			his.close();
			user.AddBalance(amt);
			nFile.write((char*)&user, sizeof(Info));
		}
		else
			nFile.write((char *)&user, sizeof(Info));
	}
	nFile.close();
	iFile.close();
	remove(file);
	rename(temp, file);
	if(!found)
	{
		cout << "\n\n\tUser Not Found";
		system("PAUSE");
		return;
	}	
	cout << "\n\n\tBalance has been updated!!" << endl;
	system("PAUSE");
}


void Info::AddUser()
{
	ofstream oFile;
	Info user,temp;
	cin.ignore();
	user.SetVal();
	ifstream iFile;
	iFile.open(file, ios::binary);
	if(!iFile)
	{
		oFile.open(file, ios::binary | ios::app);
		oFile.write((char *)&user, sizeof(user));
		oFile.close();
		cout << "\n\n\t\tUser added successfully...";
		system("PAUSE");
		return;
	}
	bool check = false;
	try
	{
		while(iFile.read((char *)&temp, sizeof(Info)))
			if(!strcmp(temp.getuser(), user.getuser()))
				check = true;
		iFile.close();
		if(check)
		{
			cout << "\n\n\t\tEntered user is already exists....";
			system("PAUSE");
			return;
		}
		else
			throw user;
	}
	catch(Info user)
	{
		TotalUsers++;
		oFile.open(file, ios::binary | ios::app);
		oFile.write((char *)&user, sizeof(user));
		oFile.close();
		cout << "\n\n\t\tUser added successfully...";
		system("PAUSE");
		return;
	}
}


void Info::SetDepartment()
{
	Info user;
	ifstream iFile;
	ofstream nFile;
	iFile.open(file, ios::binary);
	nFile.open(temp, ios::binary | ios::app);
	if (!iFile)
	{
		cout<< "File could not be opened....";
		system("PAUSE");
		return;
	}
	bool found = false;
	int choice = 0;
	char us[7];
	cout << "Enter the user you want to assign department to:";
	cin.ignore();
	cin.getline(us,7);
	system("cls");
	while (iFile.read((char *)&user, sizeof(Info)))
	{
		if(!strcmp(user.getuser(),us))
		{
			found = true;
			cout << "\n\n\t\t\t\tChoose from below:" << endl;
			cout << "\t\t1. Saireplica." << endl;
			cout << "\t\t2. SFC." << endl;
			cout << "\t\t3. Stores." << endl;
			cout << "\t\t4. Hostel Essentials." << endl;
			cout << "\t\tEnter the Deparment you want to assign:";
			cin >> choice;
			user.Department(choice);
			nFile.write((char *)&user, sizeof(Info));
		}
		else
			nFile.write((char *)&user, sizeof(Info));
	}
	nFile.close();
	iFile.close();
	if(!found)
	{
		cout << "\n\n\tUser Not Found.";
		system("PAUSE");
		return;
	}
	remove(file);
	rename(temp, file);
	cout << "\n\n\tUser updated successfully." << endl;
	system("PAUSE");
}


void Info::ChangePass()
{
	Info user;
	ifstream iFile;
	ofstream nFile;
	iFile.open(file, ios::binary);
	nFile.open(temp, ios::binary | ios::app);
	if (!iFile)
	{
		cout<< "File could not be opened....";
		system("PAUSE");
		return;
	}
	bool found = false;
	while (iFile.read((char *)&user, sizeof(Info)))
	{
		if(!strcmp(user.getuser(),this->redg_no))
		{
			found = true;
			char p[15], ch;
			int i=0;
			cout << "\n\n\t\tEnter the old password:";
			while(1)
			{
				ch = getch();
				if(ch == '\r')
				{
					p[i] = '\0';
					cout << endl;
					break;
				}
				if(ch == '\b')
				{
					if(i <= 0)
						continue;
					cout << '\b';
					i--;
					continue;
				}
				p[i] = ch;
				i++;
				cout << '*';
			}
			if(!strcmp(pass, p))
			{
				cout << "\t\tEnter the new password:";
				int i=0;
				while(1)
				{
					ch = getch();
					if(ch == '\r')
					{
						p[i] = '\0';
						cout << endl;
						break;
					}
					if(ch == '\b')
					{
						if(i <= 0)
							continue;
						cout << '\b';
						i--;
						continue;
					}
					p[i] = ch;
					i++;
					cout << '*';
				}
				strcpy(pass, p);
			}
			else
			{
				cout << "Invalid Password......" << endl;
				nFile.close();
				iFile.close();
				system("PAUSE");
				ChangePass();
			}
			nFile.write((char *)this, sizeof(Info));
		}
		else
			nFile.write((char *)&user, sizeof(Info));
	}
	nFile.close();
	iFile.close();
	remove(file);
	rename(temp, file);
	if(!found)
	{
		cout << "\n\n\tUser Not Found";
		system("PAUSE");
		return;
	}	
	cout << "\n\n\tYour password has been updated!!" << endl;
	system("PAUSE");
}