

int patient_function();
void writePatient();
void displayPatient(int);
void changePatient(int);
void deletePatient(int);

class patient
{
	private:
	       char patientName[40],patientAddress[100],patientTaluk[30],patientPanchayat[30],patientSymptoms[50],patientPreCond[20];
	       int patientNo;
	       char patientAadhaar[12],patientMobNo[10];
	       int patientAge,patientHeight,patientWeight;
	       char patientGender;
	public:
	  void insertPatient();
	  void showPatient();
	  void modifyPatient();
	  int returnPatientNo() const;
	  patient()
	  {
		  strcpy(patientName," ");
		  strcpy(patientAddress," ");
		  strcpy(patientPanchayat," ");
		  strcpy(patientSymptoms," ");
		  strcpy(patientPreCond," ");
		  strcpy(patientTaluk," ");
		  strcpy(patientMobNo," ");
		  
		  patientNo = patientAge = patientHeight = patientWeight = 0;
		  patientGender=' ';
		  

	  }
};

void patient::insertPatient()
{
	
	system("cls");
	
	fstream fout;
	fout.open("pAnalysis.csv", ios::out | ios::app);
	cout<<"-----------------ADD PATIENT DETAILS----------------"<<endl;
	    cout<<"Patient Number: ";
	    cin>>patientNo;
	    cout<<"Name: ";
	    cin>>patientName;
	    cout<<"Age: ";
	    cin>>patientAge;	
	    cout<<"Height and Weight: ";
	    cin>>patientHeight>>patientWeight;
	    cout<<"Gender(M/F): ";
	    cin>>patientGender;
	    cout<<"ID(adhar number): ";
	    cin>>patientAadhaar;
	    cout<<"Mobile Number: ";
	    cin>>patientMobNo;
	    cout<<"Address: ";
	    cin>>patientAddress;
	    cout<<"Thaluk: ";
	    cin>>patientTaluk;
	    cout<<"Panchayat: ";
	    cin>>patientPanchayat;
	    cout<<"Major Symptom: ";
	    cin>>patientSymptoms;
	    cout<<"Pre existing medical conditions if any: ";
	    cin>>patientPreCond;

		fout<<patientNo<<","
			<<patientGender<<","
			<<patientAge<<","
			<<patientTaluk<<","
			<<patientSymptoms<<"\n";
}
void patient::showPatient()
{
	system("cls");
	cout<<"----------------- PATIENT DETAILS----------------"<<endl;
	    cout<<"Patient Number: "<<patientNo;
	    cout<<"\nName: "<<patientName;
	    cout<<"\nAge: "<<patientAge;
	    cout<<"\nHeight and Weight: "<<patientHeight<<"\t"<<patientWeight;
	    cout<<"\nGender(M/F): "<<patientGender;
	    cout<<"\nID(adhar number): "<<patientAadhaar;
	    cout<<"\nMobile Number: "<<patientMobNo;
	    cout<<"\nAddress: "<<patientAddress;
	    cout<<"\nThaluk: "<<patientTaluk;
	    cout<<"\nPanchayat: "<<patientPanchayat;
	    cout<<"\nMajor Symptom: "<<patientSymptoms;
	    cout<<"\nPre existing medical conditions if any: "<<patientPreCond;
}

void patient::modifyPatient()
{
	    cout<<"-----------------MODIFY PATIENT DETAILS----------------"<<endl;
	    cout<<"Patient Number: ";
	    cin>>patientNo;
	    cout<<"Name: ";
	    cin>>patientName;
	    cout<<"Age: ";
	    cin>>patientAge;
	    cout<<"Height and Weight: ";
	    cin>>patientHeight>>patientWeight;
	    cout<<"Gender(M/F): ";
	    cin>>patientGender;
	    cout<<"ID(adhar number): ";
	    cin>>patientAadhaar;
	    cout<<"Mobile Number: ";
	    cin>>patientMobNo;
	    cout<<"Address: ";
	    cin>>patientAddress;
	    cout<<"Thaluk: ";
	    cin>>patientTaluk;
	    cout<<"Panchayat: ";
	    cin>>patientPanchayat;
	    cout<<"Symptoms: ";
	    cin>>patientSymptoms;
	    cout<<"Pre existing medical conditions if any: ";
	    cin>>patientPreCond;
}

int patient::returnPatientNo() const
{

	return patientNo;
}
int patient_function()
{

	int value,num;
	char response;

do{
	 system("cls");
	 cout<<"1.Add patient details"<<endl;
	 cout<<"2.Display patient details"<<endl;
	 cout<<"3.Modify patient details"<<endl;
	 cout<<"4.Delete patient details"<<endl;
	 cout<<"5.GO BACK"<<endl;
	 cout<<"Choose an Option : ";
	 cin>>value;

	 switch(value)
	 {
		case 1 : writePatient();
			 break;
		case 2 :

			system("cls");
			cout<<"\n\n\t\t\tEnter The Patient No. : "; cin>>num;
			displayPatient(num);
			break;
		case 3 :
			system("cls");
			cout<<"\n\n\t\t\tEnter The Patient No. : ";
			cin>>num;
			changePatient(num);
			break;
		case 4 :
			system("cls");
			cout<<"\n\n\t\t\tEnter The Patient No. : ";
			cin>>num;
			deletePatient(num);
			break;
	    case 5:
			return 1;

		default:cout<<"\nInvalid Option";
			break;

	}
	cout<<"\nDo you want to Continue : ";
	cin>>response;

}while(response=='Y' || response=='y');
getch();
return 0;
}


void writePatient()
{
	patient P;
	ofstream toFile;
	toFile.open("patient.dat",ios::binary|ios::app);
	P.insertPatient();
	toFile.write((char*)&P,sizeof(P));
	toFile.close();
}
void displayPatient(int n)
{
	patient P;
	int flag=0;
	ifstream inFile;
	inFile.open("patient.dat",ios::binary);
	while(inFile.read((char*)&P,sizeof(P)))
	{
		if(P.returnPatientNo()==n)
		{
			P.showPatient();
			flag=1;
		}

	}
	inFile.close();
	if(flag==0)
	cout<<"\t\t\nPatient Record Does not exists!";
}

void changePatient(int n)
{
	int found=0;
	patient p;
	fstream File;
	File.open("patient.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found == 0)
	{
		File.read((char *)&p, sizeof(p));
		if(p.returnPatientNo()==n)
		{
			p.showPatient();
			cout<<"\n\n\t\t\tEnter The New Details of Patient"<<endl;
			p.modifyPatient();
			long long int pos=(-1)*(sizeof(p));
			File.seekp(pos,ios::cur);
			File.write((char *)&p,sizeof(p));
			cout<<"\n\n\t\t\tRecord Updated";
			found=1;
		  }
	}
	File.close();
	if(found==0)
		cout<<"\n\n\t\t\tRecord Not Found ";
}
void deletePatient(int n)
{
	patient p;
	ifstream inFile;
	ofstream outFile;
	inFile.open("patient.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *)&p,sizeof(p)))
	{
		if(p.returnPatientNo()!=n)
		{
			outFile.write((char *)&p, sizeof(p));
		}
	}
	inFile.close();
	outFile.close();
	remove("patient.dat");
	rename("Temp.dat","patient.dat");
	cout<<"\n\nRecord Deleted ..";
}
