#include "Works.h"

void AdminMenu(Info user)
{
	int choice;
	while(1)
	{
		system("cls");
		cout << "\n\n\t\t\t\t\t\tWELCOME to HSBC" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tHello, " << user.getname() << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tTotal Users:" << user.Users() << endl;
		cout << "\n\n\t\t\t\tChoose from the options below\n\n" << endl;
		cout << "\t\t1.Add User." << endl;
		cout << "\t\t2.Assigin Self Rerlience Departments." << endl;
		cout << "\t\t3.Change Your Password." << endl;
		cout << "\t\t4.Delete user." << endl;
		cout << "\t\t5.Change other user password." << endl;
		cout << "\t\t6.Logout." << endl;
		cout << "\t\tEnter your choice:";
		cin >> choice;
		system("cls");
		cout << "\n\n\t\t\t\t\t\tWELCOME to HSBC" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tHello, " << user.getname() << endl;
		switch(choice)
		{
			case 1: user.AddUser(); break;
			case 2: user.SetDepartment(); break;
			case 3: user.ChangePass(); break;
			case 4: DeleteUser(); break;
			case 5: AdminPassChange(); break;
			case 6: system("cls"); return;
			default: system("cls"); cout << "Enter a valid option......"; system("PAUSE"); continue;
		}
	}
}

void SaireplicaMenu(Info user)
{
	int choice;
	while(1)
	{
		system("cls");
		cout << "\n\n\t\t\t\t\t\tWELCOME to HSBC" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tHello, " << user.getname() << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tBalance: " << user.getbalance() << endl << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\tPages in the printer " << user.pages << endl << endl;
		cout << "\t\t\t\tChoose from the options below" << endl;
		cout << "\t\t1.Deduct money." << endl;
		cout << "\t\t2.Give feedback to SFC." << endl;
		cout << "\t\t3.Change Your Password." << endl;
		cout << "\t\t4.Show My Transaction history" << endl;
		cout << "\t\t5.Set Pages into printer." << endl;
		cout << "\t\t6.Logout." << endl;
		cout << "\t\tEnter your choice:";
		cin >> choice;
		system("cls");
		cout << "\n\n\t\t\t\t\t\tWELCOME to HSBC" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tHello, " << user.getname() << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tBalance: " << user.getbalance() << endl << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\tPages in the printer " << user.pages << endl << endl;
		switch(choice)
		{
			case 1: DeductMoney(user); break;
			case 2: GiveFeedback(user); break;
			case 3: user.ChangePass(); break;
			case 4: TransactionShow(user); break;
			case 5: user.setpages(); break;
			case 6: system("cls"); return; 
			default: system("cls"); cout << "Enter a valid option......"; system("PAUSE"); continue;
		}
	}
}


void StoresMenu(Info user)
{
	int choice;
	while(1)
	{
		system("cls");
		cout << "\n\n\t\t\t\t\t\tWELCOME to HSBC" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tHello, " << user.getname() << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tBalance: " << user.getbalance() << endl << endl;
		cout << "\t\t\t\tChoose from the options below" << endl;
		cout << "\t\t1.Deduct money." << endl;
		cout << "\t\t2.Change Password." << endl;
		cout << "\t\t3.Give feedback to SFC." << endl;
		cout << "\t\t4.Show Dues list." << endl;
		cout << "\t\t5.Show My Transaction history." << endl;
		cout << "\t\t6.Show All Department Transactions." << endl;
		cout << "\t\t7.Logout." << endl;
		cout << "\t\tEnter your choice:";
		cin >> choice;
		system("cls");
		cout << "\n\n\t\t\t\t\t\tWELCOME to HSBC" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tHello, " << user.getname() << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tBalance: " << user.getbalance() << endl << endl;
		switch(choice)
		{
			case 1: DeductMoney(user); break;
			case 2: user.ChangePass(); break;
			case 3: GiveFeedback(user); break;
			case 4: ShowDues(); break;
			case 5: TransactionShow(user); break;
			case 6: TransactionAll(); break;
			case 7: system("cls"); return;
			default: system("cls"); cout << "Enter a valid option......"; system("PAUSE"); continue;
		}
	}
}


void HeMenu(Info user)
{
	int choice;
	while(1)
	{
		system("cls");
		cout << "\n\n\t\t\t\t\t\tWELCOME to HSBC" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tHello, " << user.getname() << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tBalance: " << user.getbalance() << endl << endl;
		cout << "\t\t\t\tChoose from the options below" << endl;
		cout << "\t\t1.Add Balance." << endl;
		cout << "\t\t2.Deduct Balance." << endl;
		cout << "\t\t3.Change password." << endl;
		cout << "\t\t4.Give Feedback to SFC." << endl;
		cout << "\t\t5.Show My Transaction history." << endl;
		cout << "\t\t6.Show All Department Transactions." << endl;
		cout << "\t\t7.Logout." << endl;
		cout << "\t\tEnter your choice:";
		cin >> choice;
		system("cls");
		cout << "\n\n\t\t\t\t\t\tWELCOME to HSBC" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tHello, " << user.getname() << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tBalance: " << user.getbalance() << endl << endl;
		switch(choice)
		{
			case 1: user.AddBal(); break;
			case 2: DeductMoney(user); break;
			case 3: user.ChangePass(); break;
			case 4: GiveFeedback(user); break;
			case 5: TransactionShow(user); break; 
			case 6: TransactionAll(); break;
			case 7: system("cls"); return;
			default: system("cls"); cout << "Enter a valid option......"; system("PAUSE"); continue;
		}
	}
}


void SFCMenu(Info user)
{
	int choice;
	while(1)
	{
		system("cls");
		cout << "\n\n\t\t\t\t\t\tWELCOME to HSBC" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tHello, " << user.getname() << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tBalance: " << user.getbalance() << endl << endl;
		cout << "\t\t\t\tChoose from the options below" << endl;
		cout << "\t\t1.Show All Feedbacks." << endl;
		cout << "\t\t2.Change password." << endl;
		cout << "\t\t3.Show My Transaction history." << endl;
		cout << "\t\t4.Logout." << endl;
		cout << "\t\tEnter your choice:";
		cin >> choice;
		system("cls");
		cout << "\n\n\t\t\t\t\t\tWELCOME to HSBC" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tHello, " << user.getname() << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tBalance: " << user.getbalance() << endl << endl;
		switch(choice)
		{
			case 1: user.ShowFeedback(); break;
			case 2: user.ChangePass(); break;
			case 3: TransactionShow(user); break;
			case 4: system("cls"); return;
			default: system("cls"); cout << "Enter a valid option......"; system("PAUSE"); continue;
		}
	}
}


void DefaultMenu(Info user)
{
	int choice;
	while(1)
	{
		system("cls");
		cout << "\n\n\t\t\t\t\t\tWELCOME to HSBC" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tHello, " << user.getname() << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tBalance: " << user.getbalance() << endl << endl;
		cout << "\t\t\t\tChoose from the options below" << endl;
		cout << "\t\t1.Change password." << endl;
		cout << "\t\t2.Give Feedback to SFC." << endl;
		cout << "\t\t3.Show My Transaction history." << endl;
		cout << "\t\t4.Logout." << endl;
		cout << "\t\tEnter your choice:";
		cin >> choice;
		system("cls");
		cout << "\n\n\t\t\t\t\t\tWELCOME to HSBC" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tHello, " << user.getname() << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tBalance: " << user.getbalance() << endl << endl;
		switch(choice)
		{
			case 1: user.ChangePass(); break;
			case 2: GiveFeedback(user); break;
			case 3: TransactionShow(user); break;
			case 4: system("cls"); return;
			default: system("cls"); cout << "Enter a valid option......"; system("PAUSE"); continue;
		}
	}
}