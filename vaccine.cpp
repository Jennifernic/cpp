
int vaccine_function();
void writeReciever();
void displayReciever(int);
void changeReciever(int);
void deleteReciever(int);

class reciever
{

	private:

	       char recieverName[40],recieverAddress[100],recieverTaluk[30],recieverPanchayat[30],recieverSymptoms[50],recieverPreCond[20];
	       int recieverNo;
	       char recieverAadhaar[12],recieverMobNo[10];
	       int recieverAge,recieverHeight,recieverWeight;
	       char recieverGender;
	public:
	  void insertReciever();
	  void showReciever();
	  void modifyReciever();
	  int returnRecieverNo() const;

	  reciever()
	  {

		  strcpy(recieverName," ");
		  strcpy(recieverAddress," ");
		  strcpy(recieverPanchayat," ");
		  strcpy(recieverSymptoms," ");
		  strcpy(recieverPreCond," ");
		  strcpy(recieverTaluk," ");
		  strcpy(recieverMobNo," ");
		  strcpy(recieverAadhaar," ");

		  
		  recieverNo = recieverAge = recieverHeight = recieverWeight = 0;
		  recieverGender=' ';
		  

	  }

};

void reciever::insertReciever()
{
	system("cls");
	    cout<<"---------------------------------------"<<endl;
	    cout<<"---------------------------------------"<<endl;
	    cout<<"-----------ADD RECIEVER DETAILS--------"<<endl;
	    cout<<"Reciever number: ";
	    cin>>recieverNo;
	    cout<<"Reciever Name: ";
	    cin>>recieverName;
	    cout<<"Reciever age: ";
	    cin>>recieverAge;
	    cout<<"Height and Weight: ";
	    cin>>recieverHeight>>recieverWeight;
	    cout<<"Gender(M/F): ";
	    cin>>recieverGender;
	    cout<<"ID(adhar number): ";
	    cin>>recieverAadhaar;
	    cout<<"Mobile Number: ";
	    cin>>recieverMobNo;
	    cout<<"Address: ";
	    gets(recieverAddress);
	    cout<<"Thaluk: ";
	    cin>>recieverTaluk;
	    cout<<"Panchayat: ";
	    cin>>recieverPanchayat;
	    cout<<"Symptoms: ";
	    cin>>recieverSymptoms;
	    cout<<"Pre existing medical conditions if any: ";
	    cin>>recieverPreCond;

}

void reciever::showReciever()
{
	system("cls");
	cout<<"----------------- RECIEVER DETAILS----------------"<<endl;
	    cout<<"Reciever Number: "<<recieverNo;
	    cout<<"\nName: "<<recieverName;
	    cout<<"\nAge: "<<recieverAge;
	    cout<<"\nHeight and Weight: "<<recieverHeight<<"\t"<<recieverWeight;
	    cout<<"\nGender(M/F): "<<recieverGender;
	    cout<<"\nID(adhar number): "<<recieverAadhaar;
	    cout<<"\nMobile Number: "<<recieverMobNo;
	    cout<<"\nAddress: "<<recieverAddress;
	    cout<<"\nThaluk: "<<recieverTaluk;
	    cout<<"\nPanchayat: "<<recieverPanchayat;
	    cout<<"\nSymptoms: "<<recieverSymptoms;
	    cout<<"\nPre existing medical conditions if any: "<<recieverPreCond;
}
void reciever::modifyReciever()
{
	    cout<<"-----------------MODIFY RECIEVER DETAILS----------------"<<endl;
	    cout<<"Patient Number: ";
	    cin>>recieverNo;
	    cout<<"Name: ";
	    cin>>recieverName;
	    cout<<"Age: ";
	    cin>>recieverAge;
	    cout<<"Height and Weight: ";
	    cin>>recieverHeight>>recieverWeight;
	    cout<<"Gender(M/F): ";
	    cin>>recieverGender;
	    cout<<"ID(adhar number): ";
	    cin>>recieverAadhaar;
	    cout<<"Mobile Number: ";
	    cin>>recieverMobNo;
	    cout<<"Address: ";
	    gets(recieverAddress);
	    cout<<"Thaluk: ";
	    cin>>recieverTaluk;
	    cout<<"Panchayat: ";
	    cin>>recieverPanchayat;
	    cout<<"Symptoms: ";
	    cin>>recieverSymptoms;
	    cout<<"Pre existing medical conditions if any: ";
	    cin>>recieverPreCond;
}

int reciever::returnRecieverNo() const
{
	return recieverNo;
}

int vaccine_function()
{
  int value,num;
	char response;

do{
	 system("cls");
	 cout<<"1.Add Reciever details"<<endl;
	 cout<<"2.Display Reciever details"<<endl;
	 cout<<"3.Modify Reciever details"<<endl;
	 cout<<"4.Delete Reciever Record"<<endl;
	 cout<<"5.go Back"<<endl;
	 cout<<"Choose an Option : ";

	 cin>>value;

	switch(value)
	{
	  case 1:
			writeReciever();
			break;
	  case 2:
			system("cls");
			cout<<"\n\n\t\t\tEnter The Reciever No. : "; cin>>num;
			displayReciever(num);
			break;
	  case 3:
	  		system("cls");
			cout<<"\n\n\t\t\tEnter The Reciever Identification No. : ";
			cin>>num;
			changeReciever(num);
			break;
	  case 4:
	  		system("cls");
			cout<<"\n\n\t\t\tEnter The Reciever Identification No. : ";
			cin>>num;
			deleteReciever(num);
			break;
			
	  case 5:
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

void writeReciever()
{
	reciever R;
	ofstream intoFile;
	intoFile.open("reciever.dat",ios::binary|ios::app);
	R.insertReciever();
	intoFile.write((char*)&R,sizeof(R));
	intoFile.close();
}

void displayReciever(int n)
{
	reciever R;
	int flag=0;
	ifstream fromFile;
	fromFile.open("reciever.dat",ios::binary);
 	while(fromFile.read((char*)&R,sizeof(R)))
      {
	  if(R.returnRecieverNo()==n)
	{
	  R.showReciever();
	  flag=1;	

	}

      }
fromFile.close();
if(flag==0)
  cout<<"Reciever Record Does Not Exist";
}

void changeReciever(int num)
{
	int found = 0;
	long long int pos;
	reciever R;
	fstream File;
	File.open("reciever.dat",ios::binary|ios::in|ios::out); 
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==0)
	{
		File.read((char*)&R,sizeof(R));
		if(R.returnRecieverNo()==num)
		{
			R.showReciever();
			cout<<"\n\n\t\t\tEnter The New Details of Reciever"<<endl;
			R.modifyReciever();
			pos = (-1)*sizeof(R);
			File.seekp(pos,ios::cur);
			File.write((char*)&R,sizeof(R));
			cout<<"\n\n\t\t\tRecord Updated";
			found=1;
		}
	}
	File.close();
	if(found==0)
	{
		cout<<"\n\n\t\t\tRecord Not Found ";
	}
}

void deleteReciever(int n)
{
	reciever R;
	ifstream inFile;
	ofstream outFile;
	inFile.open("Reciever.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *)&R,sizeof(R)))
	{
		if(R.returnRecieverNo()!=n)
		{
			outFile.write((char *)&R, sizeof(R));
		}
	}
	inFile.close();
	outFile.close();
	remove("Reciever.dat");
	rename("Temp.dat","Reciever.dat");
	cout<<"\n\nRecord Deleted ..";
	
}