int donation_function();
void writeDonor();
void displayDonor(int);

class donation
{
	private:

	      int donorNo;
	      char donorBranch[50],donorBank[50];
	      char donorName[25],donorAddress[100],donorDate[50];
	      char donorMobileNo[10],donorChequeNo[10];
	      double donorAmount;
	public:
	  void insertDonor();
	  void showDonor();
	  void modifyDonor();
	  int returnDonorNo() const;

	  donation()
	  {
		  strcpy(donorBranch," ");
		  strcpy(donorBank," ");
		  strcpy(donorName," ");
		  strcpy(donorAddress," ");
		  strcpy(donorDate," ");
		  strcpy(donorMobileNo," ");
		  strcpy(donorChequeNo," ");
		  donorAmount =0.0;
	  }

};
void donation::insertDonor()
{
	system("cls");
	    cout<<"---------------------------------------"<<endl;
	    cout<<"---------------------------------------"<<endl;
	    cout<<"-----------ADD CONTRIBUTION DETAILS--------"<<endl;
	    cout<<"Contribution No: ";
	    cin>>donorNo;
	    cout<<"Date: ";
	    gets(donorDate);
	    cout<<"Contributor Bank Name:";
	    gets(donorBank);
	    cout<<"Contributor Branch name: ";
	    gets(donorBranch);
	
	    cout<<"\t\tContribution to the\t\t\n";
	    cout<<"\tChief Minister's Pandemic Relief Fund\t\n ";
	    cout<<"Recieved with thanks from: \n";
	    cout<<"\tName of Contributor: ";
	    gets(donorName);
	    cout<<"\tAddress: ";
	    gets(donorAddress);
	    cout<<"\tTelephon No: ";
	    gets(donorMobileNo);
	    cout<<"\tThe sum of Rs.: ";
	    cin>>donorAmount;
	    cout<<"\tBy Cash/Cheque/DD No.: ";
	    gets(donorChequeNo);
}

void donation::showDonor()
{
	system("cls");
	cout<<"----------------- CONTRIBUTION RECIEPT----------------"<<endl;
	    cout<<"Contribution No: "<<donorNo<<endl;
	    cout<<"Date: "<<donorDate<<endl;
	    cout<<"Contributor Bank Name:"<<donorBank<<endl;
	    cout<<"Contributor Branch name: "<<donorBranch<<endl;
	  
	    cout<<"\t---------------Contribution to the---------------\t\n"<<endl;
	    cout<<"---------Chief Minister's Pandemic Relief Fund------------\n "<<endl;
	    cout<<"Recieved with thanks from: \n"<<endl;
	    cout<<"\tName of Contributor: "<<donorName<<endl;
	    cout<<"\tAddress: "<<donorAddress<<endl;
	    cout<<"\tTelephon No: "<<donorMobileNo<<endl;
	    cout<<"\tThe sum of Rs.: "<<donorAmount<<endl;
	    cout<<"\tBy Cash/Cheque/DD No.: "<<donorChequeNo<<endl;
	    cout<<"\n\nPayment Done Successfully!\n";
}

int donation::returnDonorNo() const
{
	return donorNo;
}
int donation_function()
{

  int value,num;
	char response;

do{
	 system("cls");
	 cout<<"1.Contribute to Chief Minister's Pandemic Relief Fund"<<endl;
	 cout<<"2.Display Contribution Reciept"<<endl;
	 cout<<"3.GO BACK"<<endl;
	 cout<<"Choose an Option : ";
	 cin>>value;

	switch(value)
	{
	  case 1:
				writeDonor();
				break;
	  case 2:
				system("cls");
				cout<<"\n\n\t\t\tEnter The Contributor No. : "; 
				cin>>num;
				displayDonor(num);
				break;
	   case 3:
				return 1;

	   default:
				cout<<"Invalid Option";
				break;

	}

cout<<"\nDo you want to Continue : ";
	cin>>response;
}while(response=='Y' || response=='y');

getch();
return 0;
}

void writeDonor()
{
	donation d;
	ofstream totheFile;
	totheFile.open("contribution.dat",ios::binary|ios::app);
	d.insertDonor();
	totheFile.write((char*)&d,sizeof(d));
	totheFile.close();
}
void displayDonor(int n)
{
	donation d;
	int flag=0;
	ifstream fromtheFile;
	fromtheFile.open("contribution.dat",ios::binary);
 	while(fromtheFile.read((char*)&d,sizeof(d)))
      {
	  if(d.returnDonorNo()==n)
	{
	  d.showDonor();
	  flag=1;	

	}

      }
fromtheFile.close();
if(flag==0)
  cout<<"Contributor Record Does Not Exist";
}