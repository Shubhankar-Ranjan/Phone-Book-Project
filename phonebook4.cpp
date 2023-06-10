#include<iostream>
#include<windows.h>
using namespace std;
void start();
int menu();
int k=0;




int main()
{
	start();
	string name[100];
	string no[100];
	string address[100];
	int check=0;
	int Total_contacts=0;
    check=menu();
    do
    {
    	// Add contacts 
    	if(check==1)
    	{
    		cout<<"\t\t\t\t\t\t Name :";
    		cin>>name[k];
    		cout<<"\t\t\t\t\t\t Phone no :";
    		cin>>no[k];
			cout<<"\t\t\t\t\t\t Address :";
			cin>>address[k];
    		k++;
    		Total_contacts++;
		}
		
		//Diplay contacts
		else if (check==2)
		{
			int check2=0;
			for(int i=0; i<100;i++)
			{
				if(name[i]!="\0")
				cout<<"\t\t\t\t\t Name :"<<name[i]<< "      Phone :"<<no[i]<<"    Address : "<<address[i]<<endl;
				check2++;
			}
			if(check2==0)
			{
				cout<<"\t\t\t\t\t";
			}
		}
		//Search by Number
		else if(check==3)
		{
			string temp;
			cout<<"\t\t\t\t\tNumber : ";
			cin>>temp;
			int check2=0;
			for(int i=0;i<100;i++)
			{
				if(temp==no[i])
				{
					cout<<"\t\t\t\t\tNumber is Found\n";
					cout<<"\t\t\t\t\tName : "<<name[i]<<"        Phone :"<<no[i]<<"    Address : "<<address[i]<<endl;
					check2++;
				}
			}
			if(check2==0)
			{
				cout<<"\t\t\t\t\t This Number is Not found in your contact list\n";
			}
		}
		//Search By Name
		else if(check==4)
		{
				string temp;
			cout<<"\t\t\t\t\tName : ";
			cin>>temp;
			int check2=0;
			for(int i=0;i<100;i++)
			{
				if(temp==name[i])
				{
					cout<<"\t\t\t\t\tName is Found\n";
					cout<<"\t\t\t\t\tName : "<<name[i]<<"       Phone :"<<no[i]<<"    Address : "<<address[i]<<endl;
					check2++;
				}
				
			}
			if(check2==0)
			{
				cout<<"\t\t\t\t\t This name is Not found in your contact list\n";
			}
		}
		// Update
		else if(check==5)
		{
			string temp,temp2,temp3,temp4;
			cout<<"\t\t\t\t\tName : ";
			cin>>temp;
			int check2=0;
			for(int i=0;i<100;i++)
			{
				if(temp==name[i])
				{
					cout<<"\t\t\t\t\tName : "<<name[i]<<"       Phone :"<<no[i]<<"    Address : "<<address[i]<<endl;
					cout<<"\t\t\t\t\tNew Name : ";
					cin>>temp2;
					cout<<"\t\t\t\t\tNew Number : ";
					cin>>temp3;
					cout<<"\t\t\t\t\tNew Address: ";
					cin>>temp4;
					name[i]=temp2;
					no[i]=temp3;
					address[i]=temp4;
					check2++;
					cout<<"\t\t\t\t\tUpdated Successfully ";
				}
			
			}
				if(check2==0)
			{
				cout<<"\t\t\t\t\t This name is Not found in your contact list\n";
			}
		}
		// delete
		else if(check==6)
		{
				string temp;
			cout<<"\t\t\t\t\tFor Delete Enter Name : ";
			cin>>temp;
			int check2=0;
			for(int i=0;i<100;i++)
			{
				if(temp==name[i])
				{
					cout<<"\t\t\t\t\tDeleted Successfully\n";
					cout<<"\t\t\t\t\tName : "<<name[i]<<"       Phone :"<<no[i]<<"    Address : "<<address[i]<<endl;
					name[i]="\0";
					no[i]="\0";
					address[i]="\0";
					check2++;
					Total_contacts--;
				}
			}
			if(check2==0)
			{
				cout<<"\t\t\t\t\t This name is Not found in your contact list\n";
			}
		}
		// delete All
		else if(check==7)
		{	
		
					cout<<"\t\t\t\t\t All Deleted Successfully\n";
					for(int i=0;i<k;i++)
					{
						name[i]="\0";
						no[i]="\0";
						address[i]="\0";
					}
					k=0;
					Total_contacts=0;
		}
		// Diplay numbers of contacts
		else if(check==8)
		{
			cout<<"\t\t\t\t\tTotal Number of contact list are : "<<Total_contacts<<endl;
			
		}
		
		check=menu();
		
	}while(check!=9);
	
}
int menu()
{
	cout<<"\n\n\n\n\n";
	cout<<"\t\t\t\t\t--------------------------------------------\n";
	cout<<"\t\t\t\t\t--------------------------------------------\n";
	cout<<"\t\t\t\t\t|          PHONE BOOK APPLICATION          |\n";
	cout<<"\t\t\t\t\t--------------------------------------------\n";
	cout<<"\t\t\t\t\t|                                          |\n";
	cout<<"\t\t\t\t\t|       [1]  Add Contacts                  |\n";
	cout<<"\t\t\t\t\t|       [2]  Diplay All Contacts           |\n";
	cout<<"\t\t\t\t\t|       [3]  Search by Number              |\n";
	cout<<"\t\t\t\t\t|       [4]  Search by Name                |\n";
	cout<<"\t\t\t\t\t|       [5]  Update                        |\n";
	cout<<"\t\t\t\t\t|       [6]  Delete                        |\n";
	cout<<"\t\t\t\t\t|       [7]  Delete All                    |\n";
	cout<<"\t\t\t\t\t|       [8]  Number of contacts            |\n";
	cout<<"\t\t\t\t\t|                                          |\n";
	cout<<"\t\t\t\t\t--------------------------------------------\n";
	cout<<"\t\t\t\t\t|            [9]    Exit                  |\n";
	cout<<"\t\t\t\t\t--------------------------------------------\n";
	
	int a;
	cin>>a;
	system("cls");
	return a;
}


void start()
{
	system("Color 0B");
	cout<<"\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t----------------------------\n";
	cout<<"\t\t\t\t\t\t---------Phonebook Project by----------\n";
	cout<<"\t\t\t\t\t\t-------Shubhankar Ranjan and Sivam Pratik----------\n";
	cout<<"\t\t\t\t\t\t----------------------------\n";
	cout<<"\t\t\t\t\t\t----------------------------\n";
	cout<<"\t\t\t\t\t\tPHONE BOOK APPLICATION\n";
	cout<<"\t\t\t\t\t\t----------------------------\n\n";
	cout<<"\t\t\t\t\tLoading ";
	char x = 219;
	for(int i=0; i<35; i++)
	{
		cout<<x;
		if(i<10)
		Sleep(300);
		if(i>=10 && i<20)
		Sleep(150);
		if(i>=10)
		Sleep(25);
	}
	system("cls");
	
}
