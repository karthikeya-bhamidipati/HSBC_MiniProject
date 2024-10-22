#include "Menus.h"


int main()
{
	system("cls");
	Info user;
	// user.AddUser();
	// return 0;
	ifstream iFile;
	char un[7], pa[15];
	bool check = false;
	iFile.open(file, ios::binary);
	if(!iFile)
	{
		cout << "File does not exist.....";
		system("PAUSE");
		return 0;
	}
	try
	{
		cout << "\n\n\t\tRedg_no:";
		cin >> un;
		while(iFile.read((char *)&user, sizeof(user)))
		{
			if(!strcmp(user.getuser(),un))
			{
				check = true;
				break;
			}
		}
		if(!check)
			throw un;
	}
	catch(char * user)
	{
		iFile.close();
		cout << "\n\n\t\t" << user << " is not a valid user name....";
		system("PAUSE");
		main();
	}
	iFile.close();
	char ch;
	int i=0;
	try
	{
		cout << "\t\tPassword:";
		while(1)
		{
			ch = getch();
			if(ch == '\r')
			{
				pa[i] = '\0';
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
			pa[i] = ch;
			i++;
			cout << '*';
		}
		if(strcmp(user.getpass(), pa))
			throw 0;
	}
	catch(int pass)
	{
		cout << "\n\n\t\tPlease check your password and try again....";
		system("PAUSE");
		main();
	}
	switch(user.getdepartment())
	{
		case 0: DefaultMenu(user); return 0;
		case 1: SaireplicaMenu(user); return 0;
		case 2: SFCMenu(user); return 0;
		case 3: StoresMenu(user); return 0;
		case 4: HeMenu(user); return 0;
		case 5: AdminMenu(user); return 0;
	}
}