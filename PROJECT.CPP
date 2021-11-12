#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<process.h>

using namespace std;

float rno=0;
float cons=0;
class stud{
    public:
    float rollno;
    char name[26];
    float marks;
    char clas[5];
    void input(){
      cout<<endl<<"Name : "; cin>>name;
      cout<<endl<<"Class : "; cin>>clas;
      cout<<endl<<"Marks : "; cin>>marks;
      cout<<endl<<endl;
    }
    void output(){
      cout<<"\nRoll No. : "<<rollno;
      cout<<"\nName : "<<name;
      cout<<"\nClass : "<<clas;
      cout<<"\nMarks : "<<marks;
    }
    void insertdata(){ 
      void enterdata();
    }
    void modify(){ 
      void search_modify_data();
    }
    void show(){   
      void output_data();
    }
    void del(){    
      void delete_data();
    }
}std,s1,s2,s3,s4,s5,s6,obj;

void enter_data(){
 system("cls");
 if(cons=0){
    fstream fo("original.dat",ios::out|ios::app|ios::binary);
    char ans = 'y';
    here:
    while (ans == 'y'||ans=='Y'){
      rno = rno + 1;
      std.input();
      std.rollno = rno;
      fo.write((char*)&std,sizeof(std));
      cout<<"\nThe roll number of this record is : "<<std.rollno;
      cout<<"\nRecord Added to file."<<"\nWant to enter more records ? (y/n)\n";
      cin>> ans;
      cout<<endl<<endl;
      goto here;
    }
    fo.close();
    cons = 1;
 }
 else if( cons=1){
    system("cls");
    fstream fi("original.dat",ios::in|ios::binary);
    fstream fo("temp.dat",ios::out|ios::binary);
    char last = 'y';
    cout<<"Enter Details of student whose record is to be inserted\n";
    s1.input();
    cout<<"Please enter new roll no : ";
    cin>>s1.rollno;
    while(!fi.eof()){
      fi.read((char*)&s4,sizeof(s4));
      if(s1.rollno<=s4.rollno){
        fo.write((char*)&s1,sizeof(s1));
        last = 'n';
        break;
        }
      else
        fo.write((char*)&s4,sizeof(s4));
    }
    if(last == 'y')
      fo.write((char*)&s1,sizeof(s1));
    else if(!fi.eof()){
      while(!fi.eof()){
        fi.read((char*)&s4,sizeof(s4));
        fo.write((char*)&s4,sizeof(s4));
      }
    }
    fi.close();
    fo.close();
    remove("original.dat");
    rename("temp.dat","original.dat");
    cout<<endl<<endl;
  }
}
void search_modify_data(){
    system("cls");
    int rn = 0;
    int pos = 0;
    char ans = 'z';
    char found = 'n';
    fstream fi("original.dat",ios::in|ios::out|ios::binary);
    cout<<"Enter roll number you want to search and modify : ";
    cin>>rn;
    while(!fi.eof()){
      pos = fi.tellg();
      fi.read((char*)&s2,sizeof(s2));
      if(s2.rollno == rn){
        s2.input();
        found='y';
        cout<<"\nDo you want to modify this record ? (y/n)\n";
        cin>>ans;
        if(ans == 'y'){
        fi.seekg(pos);
        cout<<"\nPlease enter new name : ";cin>>s2.name;
        cout<<"\nPlease enter new class : ";cin>>s2.clas;
        cout<<"\nPlease enter new marks : ";cin>>s2.marks;
        fi.write((char*)&s2,sizeof(s2));
        }
        break;
      }
    }
      if(found == 'n')
        cout<<"Roll Number not found in file "<<endl;
      fi.close();
}
void output_data(){
    system("cls");
    fstream fi("original.dat",ios::in|ios::app|ios::binary);
    fi.seekg(0);
    cout<<"File Now contains : ";
    while(!fi.eof()){
      fi.read((char*)&s3,sizeof(s3));
      if(fi.eof())
        break;
      s3.output();
    }
    fi.close();

}
void delete_data(){
    system("cls");
    fstream fio("original.dat",ios::in|ios::binary);
    fstream file("temp.dat",ios::out|ios::binary);
    int rn = 0;
    char found = 'f';
    char confirm = 'n';
    cout<<"\nEnter roll number of the student whose record is to be deleted : ";
    cin>>rn;
    while(!fio.eof()){      
      fio.read((char*)&s5,sizeof(s5));
      if (s5.rollno == rn){
        s5.output();
        found = 't';
        cout<<"\nAre you sure you want to delete this record ? (y/n) ";
        cin>>confirm;
        if(confirm == 'n')
          file.write((char*)&s5,sizeof(s5));
      }
      else
        file.write((char*)&s5,sizeof(s5));
    }
    if ( found == 'f')
      cout<<"Record not found";
    fio.close();
    file.close();
    remove("original.dat");
    rename("temp.dat","original.dat");
}   
void main(){
    AGAIN:
    system("cls");
    int a = 0;
    cout<<"                     WELCOME TO STUDENT DATABASE"<<endl<<endl;
    cout<<"  To insert records to sorted file. Press 1\n";
    cout<<"  To search and modify. Press 2\n";
    cout<<"  To delete according to roll number. Press 3\n";
    cout<<"  To display contents of file. Press 4\n";
    cout<<"  TO EXIT. PRESS 5\n";
    cin>>a;
    switch(a)
    {
      case 1 : obj.insertdata();
        break;

      case 2 : obj.modify();
        break;

      case 3 : obj.del();
        break;

      case 4 : obj.show();
        break;

      case 5 : system("cls");
        cout<<"thank you for using our database";
        exit(0);
        break;
      default : system("cls");
          cout<<" Wrong input. Please try Again"<<endl<<endl;
          goto AGAIN;
    }
    getch();
}