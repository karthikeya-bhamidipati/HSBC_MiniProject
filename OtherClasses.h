#include <iostream>
#include <string.h>
#include <fstream>


extern const char feed[] = "files/feedback.dat";


using namespace std;

class Info;

class HostelEsentials
{
	virtual void AddBal() = 0;
	virtual void DeductHe(Info) = 0;
};


class SaiReplica
{
	public:
	static int pages;
	void setpages()
	{
		int k;
		cout << "\n\n\t\tEnter the pages you want to put into the printer:";
		cin >> k;
		pages = k;
	}
	virtual void DeductReplica(Info) = 0;
};
int SaiReplica::pages = 0;


class Stores
{
	virtual void DeductStores(Info) = 0;
};


class Feedback
{
	char redg_no[7], reply[50];
	public:
	void getFeedback(char * reg)
	{
		strcpy(redg_no, reg);
		cout << "\n\n\t\tPlease give your feedback in max 50 charecters:";
		cin.ignore();
		cin.getline(reply,50);
	}
	void ShowFeedback()
	{
		cout << redg_no << "\t\t" << reply << endl;
	}
};


class SFC
{
	public:
	void ShowFeedback()
	{
		Feedback F;
		ifstream iFile;
		iFile.open(feed, ios::binary);
		cout << "\t\tRedg_no" << "\t\t\t\tFeedback" << endl;
		while(iFile.read((char *)&F, sizeof(F)))
			F.ShowFeedback();
		iFile.close();
		system("PAUSE");
	}
};


class Admin
{
	public:
	virtual void AdminPass(char *) = 0;
	virtual void AddUser() = 0;
};



class History
{
	char redg_no[7], reason[50], by_who[7];
	int amt;
	public:
	void ShowHistory()
	{
		cout << "\t" << by_who << "\t\t" << reason <<"\t\t" << amt << endl;
	}
	void ShowAll()
	{
		cout << "\t" << redg_no << "\t\t" << by_who << "\t\t" << reason << "\t\t" << amt << endl;
	}
	void IntoHistory(char * rn , char * who , char * rea , int am)
	{
		strcpy(redg_no, rn);
		strcpy(by_who, who);
		strcpy(reason, rea);
		amt = am;
	}
	char * getuser()
	{
		return redg_no;
	}
};

class Dues
{
	char regd_no[7], reason[20];
	int amt;
	public:
	void ShowDues()
	{
		cout << "\n\n\t" << regd_no << "\t" << reason << "\t" << amt << endl;
	}
	void EnterDues(char * r, char * re, int am)
	{
		strcpy(regd_no, r);
		strcpy(reason, re);
		amt = am;
	}
};