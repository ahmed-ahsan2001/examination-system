#include<iostream>
#include<fstream>
#include <windows.h>
#include<string>
//#include <stdlib.h>
//#include <cstdlib>
#include<vector>
#include<stdio.h>
#include<conio.h>
using namespace std;
class LoadingBar{
	public:
		void load(){
			char a = 219;
			gotoxy(36, 10);
			cout << "Loading..."<< endl;
			gotoxy(30,12);
			for(int r =1; r<=20; r++)
			{
				for(int q=0; q<=100000000; q++);
				cout << a;
			}
			system("cls");
		}

		void gotoxy(int x, int y){
			COORD d;
			d.X = x;
			d.Y = y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), d);
		}
		void Type(const char*p){
			if(NULL == p){
				return;
			}
			while(*p){
				cout<<*p++<<"\xDB";
				::Sleep(30);
				cout<<"\b \b";
				::Sleep(30);
			}
			::Sleep(300);	
		}
};
int admin();
int parent();
struct questions{
	string question;
	string option_a;
	string option_b;
	string option_c;
	string option_d;
	char right_option;
};
class Panel{ // this is the father class of admin student and examiner 
	public:
		virtual int login()=0;//to prompt the user to make these two function in student and examiner
		virtual int registerr()=0;
};
class Examiner: public Panel{
	private:
		Examiner(const Examiner &obj){
		}
    	struct examiner{
    		string name;
    		int age;
            string qualification;
            string subject;
            double cgpa;
            string university;
            string pass;
            int id=0;
		};
        examiner e;
        int delete_examiner();
        void examiner_register();
        int search_examiner();
    public:
        Examiner(){
        }
        friend int admin();
		int login();
		void prepare_test();
		int registerr();
};
class student:public Panel{
struct Students{
	string name;
	int age,id=0;
	string guardian_name;
	string university;
	string program;
	float gpa;
	int total_marks;
	int total_obtained_marks;
	float percentage;
	int last_test_paper_marks;
	string last_test;
	string pass,high_school;
	int last_5papers_marks[5]={0,0,0,0,0};
	vector<string>v= vector<string>(25);
	//vector<string>v(25);
	int vector_size;
};
	Students s;
	public:
		student(){
		}
		int registerr();
		void show(Students);
		int login();
		int take_test();
	private:
		void student_register();
		friend int admin();
		friend int parent();
		int search_student();
		int delete_student();
		void read(ifstream&,Students&);
		void write(fstream&,Students&);
		
};
int main(){
	LoadingBar lb;
	lb.load();
	cout << endl << endl << endl << endl << endl << endl << endl;
	lb.gotoxy(36,10);
	lb.gotoxy(36,10);
	lb.Type("\n                          Welcome to the Examination System");
	lb.Type("\n\n                                    Prepared By:\n\n                                                     Muhammad Ahmed Ahsan(20K-0343)");
	Sleep(1000);
	char ch;
	Examiner obj;
	student obj1;
	int i,j,k;
	while(1){
		system("cls");
		cout<<endl<<"------------------------------MENU----------------------";
		cout<<"\n1.Admin\n2.Examiner\n3.Student\n4.Parent\n5.Exit";
		cout<<"\nEnter your choice accordingly:";
		cin>>i;
		switch(i){
			case 1:{
				system("cls");
				admin();
				cout<<"\nPress any key to continue . . . ";
				getch();
				break;
			}
			case 2:{
				system("cls");
				cout<<"\n1.Register as an examiner\n2.Login to view your details\n3.Prepare or modify a test paper\n4.Exit from this menu";
				cout<<"\nEnter your choice:";
				cin>>j;
				if(j==1){
					k=obj.registerr();
					if(k==1)
					cout<<"\nRegistration successful";
					else
					cout<<"\nRegistration not successful";
				}
				else if(j==2){
					obj.login();
				}
				else if(j==3){
					k=obj.login();
					if(k==1){
						obj.prepare_test();
					}
				}
				else if(j==4)
				break;
				else{
					cout<<"\nInvalid choice";
				}
				cout<<"\nPress any key to continue . . . ";
				getch();
				break;
			}
			case 3:{
				system("cls");
				cout<<"\n1.Register as a new student\n2.Login to view your numbers and details\n3.Give a test\n4.Exit from this menu";
				cout<<"\nEnter your choice:";
				cin>>j;
				if(j==1){
					k=obj1.registerr();
					if(k==1)
					cout<<"\nRegistration successful";
					else
					cout<<"\nRegistration not successful";
				}
				else if(j==2){
					obj1.login();
				}
				else if(j==3){
					k=obj1.login();
					if(k==1)
					obj1.take_test();
				}
				else if(j==4)
				break;
				else{	
					cout<<"\nInvalid choice";
				}
				cout<<"\nPress any key to continue . . . ";
				getch();
				break;
			}
			case 4:{
				system("cls");
				parent();
				cout<<"\nPress any key to continue . . . ";
				getch();
				break;
			}
			case 5:{
				exit(1);
				break;
			}
			default:{
				cout<<"Invalid choice\nPress any key to continue . . . ";
				getch();
				break;
			}
		}
		
	}
return 0;
}
int student::registerr(){
	
		cout<<endl<<"--------Registering---------";
			cout<<endl<<"Enter your Name: ";
        	getline(cin>>ws,s.name);
        	cout<<endl<<"Enter your Guardian name: ";
        	getline(cin>>ws,s.guardian_name);
			cout<<endl<<"Enter your age:";
			cin>>s.age;
			cout<<endl<<"Enter your high school name:";
			getline(cin>>ws,s.high_school);
			cout<<endl<<"Enter your univeristy name:";
			getline(cin>>ws,s.university);
			cout<<endl<<"Enter your degree program:";
			getline(cin>>ws,s.program);
			cout<<endl<<"Enter your current CGPA :";
			cin>>s.gpa;
			cout<<endl<<"Select a suitable password for login:";
			getline(cin>>ws,s.pass);
			s.total_marks=0;
			s.total_obtained_marks=0;
			s.percentage=0.0;
			s.last_test_paper_marks=0;
			s.last_test="null";
			ifstream my_file;
			my_file.open("Studentlogin.txt");
			Students s1;
			while(!my_file.eof()){
				read(my_file,s1);
				if(s1.name==s.name&&s1.pass==s.pass&&s1.guardian_name==s.guardian_name){
					cout<<"\nYou have already registered please use the login functionality";
					my_file.close();
					return 0;
				}
			}
			my_file.close();
			my_file.open("tempStudent.txt");
			while(!my_file.eof()){
				read(my_file,s1);
				if(s1.name==s.name&&s1.pass==s.pass&&s1.guardian_name==s.guardian_name){
					cout<<"\nYou have already registered please wait for the admin to register you as a student.";
					my_file.close();
					return 0;
				}
			}
			my_file.close();
			s.v[0]="OOP1";
			s.v[1]="OOP2";
			s.v[2]="OOP3";
			s.v[3]="OOP4";
			s.v[4]="OOP5";
			s.v[5]="DE1";
			s.v[6]="DE2";
			s.v[7]="DE3";
			s.v[8]="DE4";
			s.v[9]="DE5";
			s.v[10]="DLD1";
			s.v[11]="DLD2";
			s.v[12]="DLD3";
			s.v[13]="DLD4";
			s.v[14]="DLD5";
			s.v[15]="CPS1";
			s.v[16]="CPS2";
			s.v[17]="CPS3";
			s.v[18]="CPS4";
			s.v[19]="CPS5";
			s.v[20]="PST1";
			s.v[21]="PST2";
			s.v[22]="PST3";
			s.v[23]="PST4";
			s.v[24]="PST5";
			s.vector_size=25;
			fstream ff;
			ff.open("tempStudent.txt",ios::app);
			write(ff,s);
			ff.close();
			return 1;
		}
void student::read(ifstream &fin,Students &s1){
			char ch;
			string str;
		//	s1.v.clear();
			getline(fin>>ws,s1.name);
			fin>>s1.age>>s1.id;
			getline(fin>>ws,s1.guardian_name);
			getline(fin>>ws,s1.university);
			getline(fin>>ws,s1.program);
			fin>>s1.gpa>>s1.total_obtained_marks>>s1.total_marks>>s1.last_test_paper_marks;
			getline(fin>>ws,s1.last_test);
			getline(fin>>ws,s1.pass);
			getline(fin>>ws,s1.high_school);
			for(int i=0;i<5;i++){
//				fin>>ws;
				fin>>s1.last_5papers_marks[i];
			}
//			fin>>ws;
			fin>>s1.vector_size;
			for(int i=0;i<s1.vector_size;i++){
				getline(fin>>ws,s1.v[i]);
			//	=str;
				
			}
		}
void student::write(fstream &fout,Students &s1){
		string str;
			fout<<s1.name<<"\n"<<s1.age<<"\n"<<s1.id<<"\n"<<s1.guardian_name<<"\n"<<s1.university<<"\n"<<s1.program<<"\n"<<s1.gpa<<"\n";
			fout<<s1.total_obtained_marks<<"\n"<<s1.total_marks<<"\n"<<s1.last_test_paper_marks<<"\n"<<s1.last_test<<"\n";
			fout<<s1.pass<<"\n"<<s1.high_school<<"\n";
			for(int i=0;i<5;i++){
				fout<<s1.last_5papers_marks[i]<<"\n";
			}
			int j=0;
    		while(1){
    		if(s1.v[j]==" "||s1.v[j]==""||s1.v[j]=="PST5"){
    			if(s1.v[j]=="PST5")
    			{
				j++;}
    			break;
			}
    		j++;
			}
			s1.vector_size=j;
			fout<<s1.vector_size<<"\n";
			for(int i=0;i<s1.vector_size;i++){
				str=s1.v[i];
				fout<<str<<"\n";
			}
			
		}
void student::show(Students s1){
			
				cout<<"\nName:"<<s1.name<<"\nAge:"<<s1.age<<"\nId:"<<s1.id<<"\nGuardian:"<<s1.guardian_name<<"\nUniversity:"<<s1.university;
			cout<<"\nProgram Enrolled:"<<s1.program<<"\nGPA:"<<s1.gpa<<"\nTotal obtained marks:"<<s1.total_obtained_marks<<"/"<<s1.total_marks;
			if(s1.total_marks>0)
			s1.percentage=((float)s1.total_obtained_marks/(float)s1.total_marks)*100.0;
			cout<<"\nPercentage:"<<s1.percentage<<"\nLast paper marks:"<<s1.last_test_paper_marks<<"\nLast paper you took:";
			cout<<s1.last_test<<"\nHigh school:"<<s1.high_school<<"\nLast 5 paper marks:";
			for(int i=0;i<5;i++){
				cout<<" "<<s1.last_5papers_marks[i];
			}
			//s1.vector_size=s1.v.size();
			for(int i=0;i<s1.vector_size;i++){
				cout<<"\t"<<s1.v[i];
			}
			
		}
int student::login(){
		string line;
        	string line2;
        	cout<<endl<<"-----LOGGING IN-----";
        	cout<<endl<<"Enter your registered name: ";
			getline(cin>>ws,line);
			cout<<endl<<"Enter your Password: ";
			getline(cin>>ws,line2);
			ifstream file;
			file.open("Studentlogin.txt");
			if(file.peek() == std::ifstream::traits_type::eof()){ 
				cout<<"\nNot registered.";
				return 0;
			}
			file.seekg(0);
			Students temp,s1;
			read(file,temp);
			while(!file.eof()){
			//	show(temp);
				if(temp.name==line&&temp.pass==line2){
					cout<<"\nYou are successfully logined";
					file.close();
					s=temp;
					show(s);
					return 1;
					
				}
				read(file,temp);
			}
			file.close();
			ifstream my_file;
			my_file.open("tempStudent.txt");
			if ( my_file.peek() == std::ifstream::traits_type::eof() ){
			}
			else{
			while(!my_file.eof()){
				read(my_file,s1);
				if(s1.name==line&&s1.pass==line2){
					cout<<"\nPlease wait for the admin to register you as a student.";
					s=s1;
					my_file.close();
					return 0;
				}
			}
			my_file.close();
		}
				cout<<endl<<"login failed! You are not registered as a student ";
				//sleep(1);
				return 0;
			
}		
int student::take_test(){
		int i,j=0,score=0;
			char ch;
			string l1,l2;
			cout<<"\nEnter a suitable id from the below choices to take a test: ";
			for(i=0;i<s.vector_size;i++){
				cout<<" "<<s.v[i];
			}
			cout<<"\nEnter:";
			cin>>l1;
			
			for(i=0;i<s.vector_size;i++){
			if(l1==s.v[i]){
				j=i;
				break;
				}
			}
			if(i==s.vector_size){
				cout<<"\nInvalid choice login again to take a test";
				return 0;
			}
			l2=l1;
			l1=l1+".txt";
			ifstream fin;
			fin.open(l1.c_str());
			if(!fin){
				cout<<"Invalid id from the choices:";
				return 0;
			}			
			s.v.erase(s.v.begin()+j);
			j=0;
			vector<string>::iterator it=s.v.begin();
    		while(it!=s.v.end()){
    		j++;
    		if(s.v[j]==" "||s.v[j]=="")
    		break;
    		it++;
			}
			//j--;
			s.vector_size=j;
	//		s.vector_size=s.v.size();
			struct questions arr[10];
			for(i=0;i<10;i++){
				getline(fin>>ws,arr[i].question);
				getline(fin>>ws,arr[i].option_a);
				getline(fin>>ws,arr[i].option_b);
				getline(fin>>ws,arr[i].option_c);
				getline(fin>>ws,arr[i].option_d);
				fin>>arr[i].right_option;
			}
			fin.close();
			char array[10];
			for(i=0;i<10;i++){
				cout<<"\nQuestion "<<i+1;
				cout<<endl<<arr[i].question<<"\na)"<<arr[i].option_a<<"\nb)"<<arr[i].option_b<<"\nc)"<<arr[i].option_c<<"\nd)"<<arr[i].option_d;
				cout<<"\nEnter corrrect choice enter the alphabet in small:";
				cin>>array[i];
				if(array[i]==arr[i].right_option){
					score++;
				}
				else{
					continue;
				}
			}
			cout<<"\nYour score in this test was:"<<score;
			s.total_marks+=10;
			s.total_obtained_marks+=score;
			s.last_test_paper_marks=score;
			s.last_test=l2;
//		//	int j=0;
//			j=0;
//			vector<string>::iterator it=s.v.begin();
//    		while(it!=s.v.end()){
//    		j++;
//    		it++;
//			}
		//	s.vector_size=s.v.size();
		//	s.vector_size--;
			j=25-s.vector_size-1;
			j=j%5;
			s.last_5papers_marks[j]=score;
			ifstream file;
			fstream fout;
			Students temp;
			file.open("Studentlogin.txt",ios::in);
			file.seekg(0);
			fout.open("temp.txt",ios::app);
			read(file,temp);
			while(!file.eof()){
				if(temp.name==s.name&&temp.pass==s.pass){
					//s1=temp;
				//	cout<<"\nyahabn horaha ha show while k andar"<<s.v.size()<<endl;
					show(s);
					write(fout,s);
					//show(s);
				}
				else{
				write(fout,temp);
				}
				read(file,temp);
			}
			file.close();
			fout.close();
			remove("Studentlogin.txt");
			rename("temp.txt","Studentlogin.txt");	
		}		
int student::search_student(){
			string str,str2;
			cout<<"Enter students registered name to see his details:";
			getline(cin>>ws,str);
			ifstream file;
			file.open("Studentlogin.txt");
			Students temp;
			if(file.peek() == std::ifstream::traits_type::eof()){ 
			cout<<"\nNo record found.";
			return 0;
			}
			read(file,temp);
			while(!file.eof()){
				if(temp.name==str){
					show(temp);
					file.close();
					return 1;
				}
				read(file,temp);
			}
			file.close();
			cout<<"\nRecord not found";
			return 0;
		}
int student::delete_student(){
			string str,str2;
			char ch;
			cout<<"Enter students registered name to delete his details:";
			getline(cin>>ws,str);
			ifstream file;
			file.open("Studentlogin.txt");
			Students temp;
			read(file,temp);
			while(!file.eof()){
				if(temp.name==str){
					show(temp);
					cout<<"\nDo you want delete this student?(y/n)";
					cin>>ch;
					if(ch=='y'||ch=='Y'){
						file.close();
						fstream fout;
						Students temp;
						file.open("Studentlogin.txt",ios::in);
						file.seekg(0);
						fout.open("temp1.txt",ios::app);
						read(file,temp);
						while(!file.eof()){
							if(temp.name==str){
							}
							else{
							write(fout,temp);
							}
							read(file,temp);
						}
						file.close();
						fout.close();
						remove("Studentlogin.txt");
						rename("temp1.txt","Studentlogin.txt");
						return 1;
					}
					else{
						file.close();
						return 1;
					}
					
					
				}
				read(file,temp);
			}
			file.close();
			cout<<"\nRecord not found";
			return 0;
		}
void student::student_register(){
	
	string pass;
	cout<<"Enter your pass word again:";
	getline(cin>>ws,pass);
	string line,line2;
	ifstream fin;
	fin.open("adminlogin.txt");
	getline(fin>>ws,line);
	getline(fin>>ws,line2);
	int i,j,k=0;
	char ch;
	fin>>i>>j;
	fin.close();
//	cout<<"done";
	Students arr[10];
	ifstream my_file;
	my_file.open("tempStudent.txt");
	my_file.seekg(0);
	if(my_file.peek() == std::ifstream::traits_type::eof()){ 
		cout<<"\nNo new registrations.";
		return ;
	}
	my_file.seekg(0);
	read(my_file,arr[k]);
	while (!my_file.eof()){
	//	cout<<"done in while";
		k++;
		read(my_file,arr[k]);
		if(my_file.get()==EOF){
			k++;
		break;}
		else{
			my_file.seekg(-1,ios_base::cur);
		}
	}
	my_file.close();
	ofstream to_clear;
	to_clear.open("tempStudent.txt");
	to_clear.close();
	if(pass==line2){
		while(k){
			k--;
			cout<<"\nName:"<<arr[k].name<<"\nAge:"<<arr[k].age<<"\nGuardian name:"<<arr[k].guardian_name<<"\nProgram:"<<arr[k].program<<"\nGPA:"<<arr[k].gpa;
			cout<<"\nUniversity:"<<arr[k].university<<"\nPassword:"<<arr[k].pass;
			cout<<"\nDo you want to accept this person as a student in your institution(y/n):";
			cin>>ch;
			if(ch=='y'||ch=='Y'){
				arr[k].id=j+100;
				j=j+100;
				ofstream fout;
				fout.open("adminlogin.txt");
				fout.seekp(0);
				fout<<line<<endl<<line2<<endl<<i<<endl<<j<<endl;
				fout.close();
				fstream file;
				file.open("Studentlogin.txt",ios::app);
				write(file,arr[k]);
				file.close();
			}
			else{
				continue;
			}
		}
		
	}
	else
	cout<<"Wrong pass word";
}


void Examiner::examiner_register(){
	string pass;
	cout<<"Enter your pass word again:";
	getline(cin>>ws,pass);
	string line,line2;
	ifstream fin;
	fin.open("adminlogin.txt");
	getline(fin,line);
	getline(fin,line2);
	int i,j,k=0;
	char ch;
	fin>>i>>j;
	fin.close();
	examiner arr[10];
	ifstream my_file;
	my_file.open("tempExaminer.txt");
	my_file.seekg(0);
	if(my_file.peek() == std::ifstream::traits_type::eof()){ 
		cout<<"\nNo new registrations.";
		return ;
	}
	while (!my_file.eof()){
	getline(my_file>>ws,arr[k].name);
	my_file>>arr[k].age;
	getline(my_file>>ws,arr[k].qualification);
	getline(my_file>>ws,arr[k].subject);
	my_file>>arr[k].cgpa;
	getline(my_file>>ws,arr[k].university);
	getline(my_file>>ws,arr[k].pass);
	my_file>>arr[k].id;
	k++;
	}
	my_file.close();
	ofstream to_clear;
	to_clear.open("tempExaminer.txt");
	to_clear.close();
	k--;
	if(pass==line2){
		while(k){
			k--;
			
			cout<<"\nName:"<<arr[k].name<<"\nAge:"<<arr[k].age<<"\nQualification:"<<arr[k].qualification<<"\nSubject:"<<arr[k].subject<<"\nCGPA:"<<arr[k].cgpa;
			cout<<"\nUniversity:"<<arr[k].university<<"\nPassword:"<<arr[k].pass;
			cout<<"\nDo you want to accept this person as an examiner to your institution(y/n):";
			cin>>ch;
			if(ch=='y'||ch=='Y'){
				arr[k].id=i+1000;
				i=i+1000;
				ofstream fout;
				fout.open("adminlogin.txt");
				fout.seekp(0);
				fout<<line<<endl<<line2<<endl<<i<<endl<<j<<endl;
				fout.close();
				fstream file;
				file.open("Examinerlogin.txt",ios::app);
				file<<arr[k].name<<"\n"<<arr[k].age<<"\n"<<arr[k].qualification<<"\n"<<arr[k].subject<<"\n"<<arr[k].cgpa<<"\n"<<arr[k].university<<"\n";
				file<<arr[k].pass<<"\n"<<arr[k].id<<"\n";
				file.close();
			}
			else{
				continue;
			}
		}
		
	}
	else 
	cout<<"Wrong pass word";
}
int Examiner::delete_examiner(){
			string str,str1;
			cout<<"\nEnter examiner registered name to delete his details:";
			getline(cin>>ws,str);
			ifstream file;
			file.open("Examinerlogin.txt");
			file.seekg(0);
			examiner temp;
			char ch;
			while (!file.eof()){
				getline(file>>ws,temp.name);
				file>>temp.age;
				getline(file>>ws,temp.qualification);
				getline(file>>ws,temp.subject);
				file>>temp.cgpa;
				getline(file>>ws,temp.university);
				getline(file>>ws,temp.pass);
				file>>temp.id;
				if(str==temp.name){
					file.close();
					cout<<"\nName:"<<temp.name<<"\nAge:"<<temp.age<<"\nQualification:"<<temp.qualification<<"\nSubject:"<<temp.subject<<"\nCGPA:"<<temp.cgpa;
					cout<<"\nUniversity:"<<temp.university<<"\nPassword:"<<temp.pass<<"\nID:"<<temp.id ;
					cout<<"\nDo you want to delete this examiner details?(y/n)";
					cin>>ch;
					if(ch=='y'||ch=='Y'){
						fstream ff;
						file.open("Examinerlogin.txt");
						ff.open("tempExaminer1.txt",ios::app);
						file.seekg(0);
						while(!file.eof()){
							getline(file>>ws,temp.name);
							file>>temp.age;
							getline(file>>ws,temp.qualification);
							getline(file>>ws,temp.subject);
							file>>temp.cgpa;
							getline(file>>ws,temp.university);
							getline(file>>ws,temp.pass);
							file>>temp.id;
							if(temp.name==str){
							}
							else{
							ff<<temp.name<<"\n"<<temp.age<<"\n"<<temp.qualification<<"\n"<<temp.subject<<"\n"<<temp.cgpa<<"\n"<<temp.university<<"\n";
							ff<<temp.pass<<"\n"<<temp.id<<"\n";
							}
						}
						file.close();
						ff.close();
						remove("Examinerlogin.txt");
						rename("tempExaminer1.txt","Examinerlogin.txt");
						return 1;
					}
					else{
					file.close();
					return 1;}
				}
				else{
					continue;
					}	
			}
			file.close();
			cout<<"\nRecord not found";
			return 0;	
}
int Examiner::search_examiner(){
			string str,str1;
			cout<<"\nEnter examiner registered name to see his details:";
			getline(cin>>ws,str);
			ifstream file;
			file.open("Examinerlogin.txt");
			file.seekg(0);
			examiner temp;
			char ch;
			while (!file.eof()){
				getline(file>>ws,temp.name);
				file>>temp.age;
				getline(file>>ws,temp.qualification);
				getline(file>>ws,temp.subject);
				file>>temp.cgpa;
				getline(file>>ws,temp.university);
				getline(file>>ws,temp.pass);
				file>>temp.id;
				if(str==temp.name){
					file.close();
					cout<<"\nName:"<<temp.name<<"\nAge:"<<temp.age<<"\nQualification:"<<temp.qualification<<"\nSubject:"<<temp.subject<<"\nCGPA:"<<temp.cgpa;
					cout<<"\nUniversity:"<<temp.university<<"\nPassword:"<<temp.pass<<"\nID:"<<temp.id ;
					return 1;
				}
				else{
					continue;
					}	
			}
			file.close();
			cout<<"\nRecord not found";
			return 0;
}
void Examiner::prepare_test(){
        	string q_filename;
        	cout<<endl<<"\t\tWelcome "<<e.name;
        	cout<<endl<<"------You are now preparing test papers-----";
        	cout<<endl<<"To update questions related to your subject please enter your subject and test paper id";
            int n;
            string test_id;
            cout<<endl<<"Test paper (1/2/3/4/5): ";
            cin>>test_id;
            while((test_id!="1")&&(test_id!="2")&&(test_id!="3")&&(test_id!="4")&&(test_id!="5")){
				cout<<"Invalid id entered enter again:";
				cin>>test_id;
			}
            q_filename= e.subject + test_id +".txt";
			fstream fin;
			fin.open(q_filename.c_str(),ios::in);
			if(!fin.is_open()){
				fin.open(q_filename.c_str(),ios::out);
				cout<<endl<<"Enter 10 questions along with their 4 choices (1 must be the right choice) and the right choice.";
				for(int i=0;i<10;i++){
					struct questions temp1;
					cout<<endl<<"Enter question "<<i+1<<":\n";
					getline(cin>>ws,temp1.question);
					cout<<"Enter option a:";
					getline(cin>>ws,temp1.option_a);
					cout<<"Enter option b:";
					getline(cin>>ws,temp1.option_b);
					cout<<"Enter option c:";
					getline(cin>>ws,temp1.option_c);
					cout<<"Enter option d:";
					getline(cin>>ws,temp1.option_d);
					cout<<"Which is the right option a/b/c/d? enter the character:";
					cin>>temp1.right_option;
					while((temp1.right_option!='a')&&(temp1.right_option!='b')&&(temp1.right_option!='c')&&(temp1.right_option!='d')){
						cout<<"Invalid option entered enter again:";
						cin>>temp1.right_option;
					}
					fin<<temp1.question<<endl<<temp1.option_a<<endl<<temp1.option_b<<endl<<temp1.option_c<<endl<<temp1.option_d<<endl<<temp1.right_option<<endl;
				}
				fin.close();
			}
			else {
				struct questions arr[10];
				int i;
				char ch;
				for(i=0;i<10;i++){
					getline(fin>>ws, arr[i].question);
					getline(fin>>ws, arr[i].option_a);
					getline(fin>>ws, arr[i].option_b);
					getline(fin>>ws, arr[i].option_c);
					getline(fin>>ws, arr[i].option_d);
					fin>> arr[i].right_option;
				}
				fin.close();
				ch='y';
				cout<<endl<<"These questions are already present in the file.";
				for(i=0;i<10;i++){
					cout<<endl<<"Question "<<i+1;
					cout<<endl<<arr[i].question<<endl<<"a)"<<arr[i].option_a<<endl<<"b)"<<arr[i].option_b<<endl<<"c)"<<arr[i].option_c;
					cout<<endl<<"d)"<<arr[i].option_d<<endl<<"Right option is:"<<arr[i].right_option;
				}
				while(ch=='y'||ch=='Y'){
					cout<<endl<<"Enter question number you want to change:";
					cin>>i;
					if(i>10)
					break;
					cout<<endl<<"Enter question "<<i<<":\n";
					i=i-1;
					getline(cin>>ws,arr[i].question);
					cout<<"Enter option a:";
					getline(cin>>ws,arr[i].option_a);
					cout<<"Enter option b:";
					getline(cin>>ws,arr[i].option_b);
					cout<<"Enter option c:";
					getline(cin>>ws,arr[i].option_c);
					cout<<"Enter option d:";
					getline(cin>>ws,arr[i].option_d);
					cout<<"Which is the right option a/b/c/d? enter the character:";
					cin>>arr[i].right_option;
					while((arr[i].right_option!='a')&&(arr[i].right_option!='b')&&(arr[i].right_option!='c')&&(arr[i].right_option!='d')){
						cout<<"Invalid option entered enter again:";
						cin>>arr[i].right_option;
					}
					cout<<endl<<"Do you want to modify any other questions(y/n)?:";
					cin>>ch;
					
				}
				fin.open(q_filename.c_str(),ios::out);
				for(i=0;i<10;i++){
					fin<<arr[i].question<<endl<<arr[i].option_a<<endl<<arr[i].option_b<<endl<<arr[i].option_c<<endl<<arr[i].option_d<<endl<<arr[i].right_option<<endl;
				}
				fin.close();
			}
		}
int Examiner::login(){
        	string line;
        	string line2;
        	cout<<endl<<"-----LOGGING IN-----";
        	cout<<endl<<"Enter your registered name: ";
			getline(cin>>ws,line);
			cout<<endl<<"Enter your Password: ";
			getline(cin>>ws,line2);
			ifstream file;
			file.open("Examinerlogin.txt");
			file.seekg(0);
			examiner temp;
			char ch;
			while (!file.eof()){
				getline(file>>ws,temp.name);
				file>>temp.age;
				getline(file>>ws,temp.qualification);
				getline(file>>ws,temp.subject);
				file>>temp.cgpa;
				getline(file>>ws,temp.university);
				getline(file>>ws,temp.pass);
				file>>temp.id;
				if(line==temp.name){
					if(line2==temp.pass){
						cout<<endl<<"You are logged in successfully!";
						e=temp;
						file.close();
						cout<<"\nName:"<<temp.name<<"\nAge:"<<temp.age<<"\nQualification:"<<temp.qualification<<"\nSubject:"<<temp.subject<<"\nCGPA:"<<temp.cgpa;
						cout<<"\nUniversity:"<<temp.university<<"\nPassword:"<<temp.pass<<"\nID:"<<temp.id ;
						return 1;
					}
					else{
						continue;
					}
				}
				else{
						continue;
					}	
			}
			file.close();
			ifstream my_file;
			my_file.open("tempExaminer.txt");
			my_file.seekg(0);
			while (!my_file.eof()){
				getline(my_file>>ws,temp.name);
				my_file>>temp.age;
				getline(my_file>>ws,temp.qualification);
				getline(my_file>>ws,temp.subject);
				my_file>>temp.cgpa;
				getline(my_file>>ws,temp.university);
				getline(my_file>>ws,temp.pass);
				my_file>>temp.id;
				if(temp.name==e.name&&temp.pass==e.pass&&temp.cgpa==e.cgpa){
					cout<<endl<<"Please wait for the admin to accept you as an examiner.";
						my_file.close();
					return 0;
				}
				else{
					continue;
				}
			}
			my_file.close();
			if(line == temp.name && line2 == temp.pass){
				return 1;
			}
			else{
				cout<<endl<<"login failed!";
				//sleep(1);
				return 0;
			}	
        }
int Examiner::registerr(){	
        	cout<<endl<<"--------Registering---------";
			cout<<endl<<"Enter your Name: ";
        	getline(cin>>ws,e.name);
        	cout<<endl<<"Enter your latest Qualification with degree name: ";
        	getline(cin>>ws,e.qualification);
			cout<<endl<<"Enter your age:";
			cin>>e.age;
			// while(e.age != int){
			// 	cout<<endl<<"Enter your age again: "
			// 	cin>>e.age;
			// }
			
			cout<<endl<<"Enter your univeristy name:";
			getline(cin>>ws,e.university);
			cout<<endl<<"Enter the CGPA you graduated with:";
			cin>>e.cgpa;
			cout<<endl<<"Enter the subject name you are interested in from the following list:";
			cout<<endl<<"1.Object oriented programming(OOP)";
			cout<<"\n2.Differential Calculus(DE)";
			cout<<"\n3.Digital Logic Design(DLD)";
			cout<<"\n4.Communication and Presentation Skills(CPS)";
			cout<<"\n5.Pakistan Studies(PST)\nPlease Enter the code only in :";
			getline(cin>>ws,e.subject);
			while((e.subject!="OOP")&&(e.subject!="DE")&&(e.subject!="DLD")&&(e.subject!="CPS")&&(e.subject!="PST")){
				cout<<"Invalid code entered enter again:";
				getline(cin>>ws,e.subject);
			}
			cout<<endl<<"Please enter a suitable Password: ";
			getline(cin>>ws,e.pass);
			ifstream my_file;
			my_file.open("Examinerlogin.txt");
			my_file.seekg(0);
			examiner temp;
			char ch;
			while (!my_file.eof()){
				getline(my_file>>ws,temp.name);
				my_file>>temp.age;
				getline(my_file>>ws,temp.qualification);
				getline(my_file>>ws,temp.subject);
				my_file>>temp.cgpa;
				getline(my_file>>ws,temp.university);
				getline(my_file>>ws,temp.pass);
				my_file>>temp.id;
				if(temp.name==e.name&&temp.pass==e.pass){
					cout<<endl<<"You have already registered please use the login functionality";
					return 0;
				}
				else{
					continue;
				}
			}
			my_file.close();
			//total_register++;
			my_file.open("tempExaminer.txt");
			my_file.seekg(0);
			while (!my_file.eof()){
				getline(my_file>>ws,temp.name);
				my_file>>temp.age;
				getline(my_file>>ws,temp.qualification);
				getline(my_file>>ws,temp.subject);
				my_file>>temp.cgpa;
				getline(my_file>>ws,temp.university);
				getline(my_file>>ws,temp.pass);
				my_file>>temp.id;
				if(temp.name==e.name&&temp.pass==e.pass&&temp.cgpa==e.cgpa){
					cout<<endl<<"You have already registered please wait for the admin to accept you as an examiner.";
					return 0;
				}
				else{
					continue;
				}
			}
			my_file.close();
			fstream file;
			file.open("tempExaminer.txt",ios::app);
			file<<e.name<<"\n"<<e.age<<"\n"<<e.qualification<<"\n"<<e.subject<<"\n"<<e.cgpa<<"\n"<<e.university<<"\n";
			file<<e.pass<<"\n"<<e.id<<"\n";
			file.close();
			return 1;
		}

int parent(){
	student temp;
	temp.search_student();
}

int admin(){
	string str,str1,line,line2;
	student obj;
	Examiner obj2;
	int i,j,k;
	char ch;
	cout<<"\nWelcome,Please login with your credentials to continue";
	cout<<"\nEnter Id/name:";
	getline(cin>>ws,str);
	cout<<"\nEnter Password:";
	getline(cin>>ws,str1);
	ifstream fin;
	fin.open("adminlogin.txt");
	getline(fin,line);
	getline(fin,line2);
	if(line==str){
		if(line2==str1){
			while(1){
			system("cls");
			cout<<"\n1.See new students registration and register them\n2.See new examiners registration and register them\n3.See registered examiner details\n4.See registered students details";
			cout<<"\n5.Delete any examiner\n6.Delete any student\n7.See test papers\n8.Delete or modify a test paper\n9.Logout and Exit\nEnter your choice:";
			cin>>i;
			switch(i){
				case 1:{
					system("cls");
					obj.student_register();
					cout<<"\nPress any key to continue . . . ";
					getch();
					break;
				}
				case 2:{
					system("cls");
					obj2.examiner_register();
					cout<<"\nPress any key to continue . . . ";
					getch();
					break;
				}
				case 3:{
					system("cls");
					obj2.search_examiner();
					cout<<"\nPress any key to continue . . . ";
					getch();
					break;
				}
				case 4:{
					system("cls");
					obj.search_student();
					cout<<"\nPress any key to continue . . . ";
					getch();
					break;
				}
				case 5:{
					system("cls");
					obj2.delete_examiner();
					cout<<"\nPress any key to continue . . . ";
					getch();
					break;
				}
				case 6:{
					system("cls");
					obj.delete_student();
					cout<<"\nPress any key to continue . . . ";
					getch();
					break;
				}
				case 7:{
					system("cls");
					cout<<"\nEnter the test paper id from the given list to see its questions:";
					string str,str1;
					obj.s.v[0]="OOP1";
					obj.s.v[1]="OOP2";
					obj.s.v[2]="OOP3";
					obj.s.v[3]="OOP4";
					obj.s.v[4]="OOP5";
					obj.s.v[5]="DE1";
					obj.s.v[6]="DE2";
					obj.s.v[7]="DE3";
					obj.s.v[8]="DE4";
					obj.s.v[9]="DE5";
					obj.s.v[10]="DLD1";
					obj.s.v[11]="DLD2";
					obj.s.v[12]="DLD3";
					obj.s.v[13]="DLD4";
					obj.s.v[14]="DLD5";
					obj.s.v[15]="CPS1";
					obj.s.v[16]="CPS2";
					obj.s.v[17]="CPS3";
					obj.s.v[18]="CPS4";
					obj.s.v[19]="CPS5";
					obj.s.v[20]="PST1";
					obj.s.v[21]="PST2";
					obj.s.v[22]="PST3";
					obj.s.v[23]="PST4";
					obj.s.v[24]="PST5";
					obj.s.vector_size=25;
					for(int i=0;i<obj.s.vector_size;i++){
						cout<<" "<<obj.s.v[i];
					}
					cout<<"\n\nEnter your choice:";
					getline(cin>>ws,str);
					int i;
					for(i=0;i<obj.s.vector_size;i++){
						if(str==obj.s.v[i]){
							ifstream fin;
							str=str+".txt";
							fin.open(str.c_str());
							if(!fin)
							cout<<"Test file has not been created yet";
							else{
								char ch1;
								ch1=fin.get();
								while(!fin.eof()){
									cout<<ch1;
									ch1=fin.get();
								}
								fin.close();
							}
							break;
						}
						
					}
					if(i==obj.s.vector_size)
					cout<<"\nInvalid choice";
					cout<<"\nPress any key to continue . . . ";
					getch();
					break;
				}
				case 8:{
					system("cls");
					cout<<"\nEnter the test paper id from the given list to modify its questions:";
						obj.s.v[0]="OOP1";
					obj.s.v[1]="OOP2";
					obj.s.v[2]="OOP3";
					obj.s.v[3]="OOP4";
					obj.s.v[4]="OOP5";
					obj.s.v[5]="DE1";
					obj.s.v[6]="DE2";
					obj.s.v[7]="DE3";
					obj.s.v[8]="DE4";
					obj.s.v[9]="DE5";
					obj.s.v[10]="DLD1";
					obj.s.v[11]="DLD2";
					obj.s.v[12]="DLD3";
					obj.s.v[13]="DLD4";
					obj.s.v[14]="DLD5";
					obj.s.v[15]="CPS1";
					obj.s.v[16]="CPS2";
					obj.s.v[17]="CPS3";
					obj.s.v[18]="CPS4";
					obj.s.v[19]="CPS5";
					obj.s.v[20]="PST1";
					obj.s.v[21]="PST2";
					obj.s.v[22]="PST3";
					obj.s.v[23]="PST4";
					obj.s.v[24]="PST5";
					obj.s.vector_size=25;
					string str,str1;
					for(int i=0;i<obj.s.vector_size;i++){
						cout<<" "<<obj.s.v[i];
					}
					cout<<"\nEnter your choice:";
					getline(cin>>ws,str);
					int i;
					for(i=0;i<obj.s.vector_size;i++){
						if(str==obj.s.v[i]){
							ifstream fin;
							str=str+".txt";
							fin.open(str.c_str());
							if(!fin){
								char choice;
								cout<<"Test file has not been created yet.Do you want to create it?(y/n)";
								cin>>choice;
								if(choice=='y'||choice=='Y'){
										fstream fin1;
										fin1.open(str.c_str(),ios::out);
										cout<<endl<<"Enter 10 questions along with their 4 choices (1 must be the right choice) and the right choice.";
										for(int i=0;i<1;i++){
											struct questions temp1;
											cout<<endl<<"Enter question "<<i+1<<":\n";
											getline(cin>>ws,temp1.question);
											cout<<"Enter option a:";
											getline(cin>>ws,temp1.option_a);
											cout<<"Enter option b:";
											getline(cin>>ws,temp1.option_b);
											cout<<"Enter option c:";
											getline(cin>>ws,temp1.option_c);
											cout<<"Enter option d:";
											getline(cin>>ws,temp1.option_d);
											cout<<"Which is the right option a/b/c/d? enter the character:";
											cin>>temp1.right_option;
											while((temp1.right_option!='a')&&(temp1.right_option!='b')&&(temp1.right_option!='c')&&(temp1.right_option!='d')){
											cout<<"Invalid option entered enter again:";
											cin>>temp1.right_option;
										}
										fin1<<temp1.question<<endl<<temp1.option_a<<endl<<temp1.option_b<<endl<<temp1.option_c<<endl<<temp1.option_d<<endl<<temp1.right_option<<endl;
										}
										fin1.close();
								}
							}
							else{
								struct questions arr[10];
								int i;
								char ch;
								for(i=0;i<10;i++){
									getline(fin>>ws, arr[i].question);
									getline(fin>>ws, arr[i].option_a);
									getline(fin>>ws, arr[i].option_b);
									getline(fin>>ws, arr[i].option_c);
									getline(fin>>ws, arr[i].option_d);
									fin>>arr[i].right_option;
								}
								fin.close();
								ch='y';
								cout<<endl<<"These questions are already present in the file.";
								for(i=0;i<10;i++){
									cout<<endl<<"\nQuestion "<<i+1;
									cout<<endl<<arr[i].question<<endl<<"a)"<<arr[i].option_a<<endl<<"b)"<<arr[i].option_b<<endl<<"c)"<<arr[i].option_c;
									cout<<endl<<"d)"<<arr[i].option_d<<endl<<"Right option is:"<<arr[i].right_option;
								}
								while(ch=='y'||ch=='Y'){
									cout<<endl<<"Enter question number you want to change:";
									cin>>i;
									if(i>10)
									break;
									cout<<endl<<"Enter question "<<i<<":\n";
									i=i-1;
									getline(cin>>ws,arr[i].question);
									cout<<"Enter option a:";
									getline(cin>>ws,arr[i].option_a);
									cout<<"Enter option b:";
									getline(cin>>ws,arr[i].option_b);
									cout<<"Enter option c:";
									getline(cin>>ws,arr[i].option_c);
									cout<<"Enter option d:";
									getline(cin>>ws,arr[i].option_d);
									cout<<"Which is the right option a/b/c/d? enter the character:";
									cin>>arr[i].right_option;
									while((arr[i].right_option!='a')&&(arr[i].right_option!='b')&&(arr[i].right_option!='c')&&(arr[i].right_option!='d')){
										cout<<"Invalid option entered enter again:";
										cin>>arr[i].right_option;
									}
								cout<<endl<<"Do you want to modify any other questions(y/n)?:";
								cin>>ch;
					
								}
								ofstream fout;
								fout.open(str.c_str(),ios::out);
								for(i=0;i<10;i++){
									fout<<arr[i].question<<endl<<arr[i].option_a<<endl<<arr[i].option_b<<endl<<arr[i].option_c<<endl<<arr[i].option_d<<endl<<arr[i].right_option<<endl;
								}
								fout.close();
							}
							break;
						}
						
					}
					if(i==obj.s.vector_size)
					cout<<"\nInvalid choice";
					cout<<"\nPress any key to continue . . . ";
					getch();
					break;
				}
				case 9:{
					return 0;
				}
				default:{
					cout<<"\nInvalid choice\nPress any key to continue . . . ";
					getch();
					break;
				}
			
			}
			
			}
			
			
		}
		else{
			cout<<"Wrong Password";
			cout<<"\nPress any key to continue . . . ";
			getch();
			return 0;
		}
	}
	else{
		cout<<"\nInvalid id";
		cout<<"\nPress any key to continue . . . ";
		getch();
		return 0;
	}
	
	
}


