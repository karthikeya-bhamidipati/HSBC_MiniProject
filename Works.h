#include "MainClass.h"


void TransactionShow(Info user)
{
	ifstream iFile;
	History h;
	iFile.open(history, ios::binary);
	if(!iFile)
	{
		cout << "File cannot be opened.....";
		system("PAUSE");
		return;
	}
	cout << "\n\n\tBy whom\t\tReason\t\tAmount" << endl;
	while(iFile.read((char *)&h, sizeof(History)))
	{
		if(!strcmp(user.getuser(),h.getuser()))
			h.ShowHistory();
	}
	system("PAUSE");
}


void TransactionAll()
{
	ifstream iFile;
	History h;
	iFile.open(history, ios::binary);
	if(!iFile)
	{
		cout << "File cannot be opened.....";
		system("PAUSE");
		return;
	}
	cout << "\n\n\tRegd_no\t\tBy whom\t\tReason\t\tAmount" << endl;
	while(iFile.read((char *)&h, sizeof(History)))
		h.ShowAll();
	system("PAUSE");
}


void ShowDues()
{
	ifstream iFile;
	Dues d;
	iFile.open(dues, ios::binary | ios::app);
	while(iFile.read((char *)&d, sizeof(Dues)))
		d.ShowDues();
	system("PAUSE");
}


void AdminPassChange()
{
	ofstream oFile;
	ifstream iFile;
	Info user;
	char us[7], pa[15];
	bool found = false;
	iFile.open(file, ios::binary);
	oFile.open(temp, ios::binary | ios::app);
	if(!iFile)
	{
		cout << "File cannot be opened....";
		iFile.close();
		oFile.close();
		system("PAUSE");
		return;
	}
	cout << "Enter the redg_no to change password:";
	cin >> us;
	while(iFile.read((char *)&user, sizeof(Info)))
	{
		if(!strcmp(user.getuser(),us))
		{
			found = true;
			cout << "Enter the password:";
			cin.ignore();
			cin.getline(pa,15);
			user.AdminPass(pa);
			oFile.write((char *)&user, sizeof(Info));
		}
		else
			oFile.write((char *)&user, sizeof(Info));
	}
	oFile.close();
	iFile.close();
	remove(file);
	rename(temp, file);
	if(!found)
	{
		cout << "The entered redg_no is not in the file.....";
		remove(temp);
		system("PAUSE");
		return;
	}
	cout << "\n\t\tPassword changed successfully...";
	system("PAUSE");
}


void GiveFeedback(Info user)
{
	Feedback F;
	F.getFeedback(user.getuser());
	ofstream oFile;
	oFile.open(feed, ios::binary | ios::app);
	if (!oFile)
	{
		cout<< "File could not be opened.....";
		system("PAUSE");
		return;
	}
	oFile.write((char *)&F, sizeof(F));
	oFile.close();
	cout << "\n\n\t\tYour Feedback is submitted succesfully....";
	system("PAUSE");
}


void DeleteUser()
{
	Info user;
	ifstream iFile;
	ofstream nFile;
	char u[7];
	iFile.open(file, ios::binary);
	nFile.open(temp, ios::binary | ios::app);
	if (!iFile)
	{
		cout<< "File could not be opened.....";
		nFile.close();
		system("PAUSE");
		return;
	}
	bool found = false;
	char choice;
	cout << "Enter the user you want to delete:";
	cin >> u;
	while (iFile.read((char *)&user, sizeof(Info)))
	{
		if(!strcmp(user.getuser(), u))
		{
			found = true;
			cout << user;
			cout << "\n\n\tAre you sure you want to delete this record? (y/n):";
			cin >> choice;
			if (choice == 'n')
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
	if(choice != 'n')
		cout << "\n\n\tDeleted succesfully!!" << endl;
	else 
		cout << "\n\n\tUpdated The Same.........";
	system("PAUSE");
	return;
}



void DeductMoney(Info me)
{
	int amt;
	Info user;
	char re[50],u[7];
	ifstream iFile;
	ofstream nFile;
	iFile.open(file, ios::binary);
	nFile.open(temp, ios::binary);
	if (!iFile)
	{
		cout<< "File could not be opened....";
		nFile.close();
		system("PAUSE");
		return;
	}
	bool found = false;
	cout << "Enter the user you want to deduct money from:";
	cin.ignore();
	cin.getline(u,7);
	while (iFile.read((char *)&user, sizeof(Info)))
	{
		if(!strcmp(user.getuser(), u))
		{
			found = true;
			switch(me.getdepartment())
			{
				case 1: user.DeductReplica(me); break;
				case 3: user.DeductStores(me); break;
				case 4: user.DeductHe(me); break;
				default: break;
			}
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
	cout << "\n\n\tBalcnce has been updated!!" << endl;
	system("PAUSE");
}