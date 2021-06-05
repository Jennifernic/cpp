#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<vector>
#include<sstream>
#include<bits/stdc++.h>

using namespace std;

#include "donation.cpp"
#include "patient.cpp"
#include "vaccine.cpp"

int back = 0;
void patientAnalytics();
void disaplayTable( vector<vector<string> > parsedCsv);
map<string,int> getFrequency(vector<string> vec);
void putFrequency(map<string,int> str2);
int pythonScript();
class MainMenu
{
    private:
        int choice;
    public:
        void printMenu();
        void getMenuChoice(int);
        MainMenu()
        {
            choice=0;
        }

};

void MainMenu::printMenu()
{

    int choice;
    cout<<"1.Covid Patient Management\n";
    cout<<"2.Vaccination Registration\n";
    cout<<"3.Relief Donations\n";
    cout<<"4.Complete Analysis\n";
    cout<<"5.EXIT";
    cout<<"\nEnter your Choice : ";
    cin>>choice;
    getMenuChoice(choice);
}
void MainMenu::getMenuChoice(int choice)
{
	switch(choice)
	{
	    case 1:
		    back = patient_function();
		    break;
	    case 2:
		    back = vaccine_function();
		    break;
        case 3:
            back = donation_function();
            break; 
        case 4:
            //  patientAnalytics();
            back = pythonScript();
            break;
        case 5:
                exit(0);
                break;
        default:
            cout<<"Invalid Choice Entered !!";
            break;               
        }
}
int main()
{
    char filename[] = "initialise.py";
	FILE* fp;

	Py_Initialize();

	fp = _Py_fopen(filename, "r");
	PyRun_SimpleFile(fp, filename);

       do{
        system("cls");
        MainMenu Main;
        Main.printMenu();
       }while(back==1);

    Py_Finalize();
    getch();
    return 0;
}




void patientAnalytics()
{

   
   
    ifstream  data("pAnalysis.csv");
    string line;
    vector<vector<string> > parsedCsv;
    while(getline(data,line))
    {
        stringstream lineStream(line);
        string cell;
        std::vector<std::string> parsedRow;
        while(std::getline(lineStream,cell,','))
        {
            parsedRow.push_back(cell);
        }

        parsedCsv.push_back(parsedRow);
    }

    vector<string> pNo;
    vector<string> pAge;
    vector<string> pGen;
    vector<string> pTal;
    vector<string> pSym;

    map<string,int> pNo_key;
    map<string,int> pAge_key;
    map<string,int> pGen_key;
    map<string,int> pTal_key;
    map<string,int> pSym_key;


    // disaplayTable(parsedCsv);
    for(int i =0 ;i<parsedCsv.size();i++)
    {
        for(int j =0 ;j<parsedCsv[0].size();j++)
        {
            if(j==0)
                pNo.push_back(parsedCsv[i][j]);
            if(j==1)
                pGen.push_back(parsedCsv[i][j]);
            if(j==2)
                pAge.push_back(parsedCsv[i][j]);   
            if(j==3)
                pTal.push_back(parsedCsv[i][j]); 
            if(j==4)
                pSym.push_back(parsedCsv[i][j]);
        }
    }

    // for (int i = 0; i < pNo.size(); i++) {      
    //     std::cout << pNo.at(i) << ' ';
    // }
    // cout<<"\n";
    // for (int i = 0; i < pGen.size(); i++) {
    //     std::cout << pGen.at(i) << ' ';
    // }
    // cout<<"\n";
    // for (int i = 0; i < pAge.size(); i++) {
    //     std::cout << pAge.at(i) << ' ';
    // }
    // cout<<"\n";
    // for (int i = 0; i < pTal.size(); i++) {
    //     std::cout << pTal.at(i) << ' ';
    // }
    // cout<<"\n";
    // for (int i = 0; i < pSym.size(); i++) {
    //     std::cout << pSym.at(i) << ' ';
    // }
   
    pNo_key = getFrequency(pNo);
    pAge_key = getFrequency(pAge);
    pGen_key =  getFrequency(pGen);
    pTal_key = getFrequency(pTal);
    pSym_key = getFrequency(pSym);

    putFrequency(pNo_key);
    putFrequency(pAge_key);
    putFrequency(pGen_key);
    putFrequency(pTal_key);
    putFrequency(pSym_key);


}

void disaplayTable( vector<vector<string> > parsedCsv)
{
    
        for(auto row_obj : parsedCsv)
            {
                for (auto elem: row_obj)
                {
                    cout<<elem<<", ";
                }
                cout<<endl;
            }
        cout<<endl;
}

map<string,int> getFrequency(vector<string> vec)
{
      map<string,int> str;
      vector<string> v = vec;
      
    auto end = v.end();
    for (auto it = v.begin(); it != end; ++it) 
    {
        end = std::remove(it + 1, end, *it);
    }
        v.erase(end, v.end());

    for(int i=0;i<vec.size();i++)
            {
         
              str.insert(pair<string,int>(v[i],count(vec.begin(), vec.end(), v[i])));
            }
    return str;
}

void putFrequency(map<string, int> str2)
{


            map<string, int>::iterator itr;
        for (itr = ++str2.begin(); itr != str2.end(); ++itr) {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';

        
        }
             cout<<"\n";
}

int pythonScript()
{
    char filename[] = "analysis.py";
	FILE* fp;

	// Py_Initialize();

	fp = _Py_fopen(filename, "r");
	PyRun_SimpleFile(fp, filename);

	// Py_Finalize();
    return 1;
}
