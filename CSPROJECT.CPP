
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdio.h>
#include<fstream.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>
struct name{
	    int age;
	    char nam[20];
	    int score;
	    }admsn,players[100],x;
int use=0,use1=0,use2=0,use3=0;
class question {
		 int qno;
		 char ques[100];
		 char opt1[50];
		 char opt2[50];
		 char opt3[50];
		 char opt4[50];
		 char ans;
		 char clue[100];
	   public:
		 void read();
		 void display();
		 int retqno(){return qno;}
		 char retans(){return ans;}
		 void correctans();
		 void lifeline();
		 void del1();
		 void del2();
		 void insert1();
		 void insert2();
		 void modify1();
		 void modify2();
		 }q,l,a[20];
fstream q1("qbank1.dat",ios::binary|ios::in|ios::out|ios::app);
fstream q2("qbank2.dat",ios::binary|ios::in|ios::out|ios::app);
fstream s1("swap1.dat",ios::binary|ios::in|ios::out);
fstream s2("swap2.dat",ios::binary|ios::in|ios::out);
ifstream f2("welcome.txt");
ifstream f3("rules.txt");
ifstream f4("end.txt");
void question::read()
{
cout<<"qno :";
cin>>qno;
cout<<"ques :";
gets(ques);
cout<<"opt1 :";
gets(opt1);
cout<<"opt2 :";
gets(opt2);
cout<<"opt3 :";
gets(opt3);
cout<<"opt4 :";
gets(opt4);
cout<<"ans :";
cin>>ans;
cout<<" clue :";
gets(clue);
}
void question::insert1()
{
q.read();
q1.write((char*)&q,sizeof(q));
}

void question::insert2()
{
q.read();
q2.write((char*)&q,sizeof(q));
}

void question ::modify1()
{
 int modify,d=0;
 cout<<"\nenter the qno: ";
 cin>>modify;
 ofstream t1("temp1.dat",ios::binary);
 q1.clear();
 q1.seekg(0);
 while(q1.eof()==0)
 { q1.read((char*)&q,sizeof(q));
 if(q.qno==modify)
 {
 q.display();
 cout<<"enter modified details ";
 q.read();
 d=1;
 }
 t1.write((char*)&q,sizeof(q));
 }
if(d==0)
cout<<"\nitem not found";
q1.close();
t1.close();
if(remove("qbank1.dat")==0)
rename("temp1.dat","qbank1.dat");
}

void question::modify2()
{
 int modify,d=0;
 cout<<"\nenter the qno: ";
 cin>>modify;
 q2.clear();
 q2.seekg(0);
 ofstream t2("temp2.dat",ios::binary);
 while(q2.eof()==0)
 { q2.read((char*)&q,sizeof(q));
 if(q.qno==modify)
 {
 q.display();
 cout<<"enter modified details: ";
 q.read();
 d=1;
 }
 t2.write((char*)&q,sizeof(q));
 }
 if(d==0)
 cout<<"\n item not found";
 q2.close();
 t2.close();
if(remove("qbank2.dat")==0)
rename("temp2.dat","qbank2.dat");
}

void question::del1()
{
int deleting,d=0;
cout<<"\n enter the qno: ";
cin>>deleting;
q1.clear();
 q1.seekg(0);
ofstream t3("temp3.dat",ios::binary);
while(q1.eof()==0)
 {
 q1.read((char*)&q,sizeof(q));
 if(q.qno==deleting)
 {
 q.display();
 cout<<" is deleted ";
 d=1;
 }
else
 t3.write((char*)&q,sizeof(q));
 }
 if(d==0)
 cout<<"\n item not found";
 q1.close();
  t3.close();
if(remove("qbank1.dat")==0)
rename("temp3.dat","qbank1.dat");
}

void question::del2()
{
int deleting,d=0;
cout<<"\nenter the qno :";
cin>>deleting;
ofstream t4("temp4.dat",ios::binary);
q2.clear();
 q2.seekg(0);
while(q2.eof()==0)
 {
 q2.read((char*)&q,sizeof(q));
 if(q.qno==deleting)
 {
 q.display();
 cout<<" is deleted ";
 d=1;
 }
if(d==0)
 t4.write((char*)&q,sizeof(q));
 }
 if(d==0)
 cout<<"\nitem not found";
 t4.close();
 q2.close();
if(remove("qbank2.dat")==0)
rename("temp4.dat","qbank2.dat");
}

void question::display()
{
cout<<ques;
cout<<"\n a. "<<opt1<<"\n b. "<<opt2<<"\n c. "<<opt3 <<"\n d. "<<opt4;
}

void question::correctans()
{
cout<<"\n the correct answer is :";
switch(ans)
{
case 'a':cout<<"\n "<<opt1;
	 break;
case 'b':cout<<"\n"<<opt2;
	 break;
case 'c':cout<<"\n "<<opt3;
	  break;
case 'd':cout<<"\n "<<opt4;
	  break;
}
}

void question::lifeline()
{
int lln=0,ch1;
use++;
if(use<=3)
{
if(use==1)
{
cout<<"there are three lifelines available "<<"\n";
cout<<"1. 50:50"<<"\n"<<"2. swap"<<"\n";
cout<<"3. ask a clue"<<"\n";
cout<<"enter which lifeline do u want ?";
cin>>lln;
}
else if(use==2)
{
if(use1==1)
{
cout<<"there are 2 lifelines available "<<"\n";
cout<<"2. swap "<<"\n"<<"3. ask a clue "<<"\n";
cout<<"enter which lifeline do u want ?";
cin>>lln;
}
else if(use2==1)
{
cout<<"there are 2 lifelines left"<<"\n";
cout<<"1. 50:50"<<"\n"<<"3. ask a clue"<<"\n";
cout<<"enter which lifeline do u want ?";
cin>>lln;
}
else if(use3==1)
{
cout<<"there are 2 lifelines available "<<"\n ";
cout<<"1. 50:50 "<<"\n"<<"2. swap "<<"\n";
cout<<"enter which lifeline do u want ?";
cin>>lln;
}
}
else if(use==3)
{
cout<<"there is one lifeline available \n ";
if(use1==1&&use2==1)
{
cout<<"3. ask a clue";
lln=3;
}
else if(use2==1&&use3==1)
{
cout<<"1. 50:50 ";
lln=1;
}
else if(use3==1&&use1==1)
{
cout<<"2. swap ";
lln=2;
}
}
}
else
cout<<"all 3 lifelines are used ";
switch(lln)
{
case 1:use1++;
	  cout<<"50:50 is used"<<"\n";
	  int a,b,flag=0;
	  char op[4]={'a','b','c','d'};
	  do{
	 do{
	 a=rand()%4;
	 b=rand()%4;
	   }while(a==b);
	  if(ans==op[a]||ans==op[b])
	  flag=1;
	  }while(flag==0);
    switch(a){
		 case 0:cout<<op[a]<<"."<<opt1<<"\n";
		 break;
		 case 1:cout<<op[a]<<"."<<opt2<<"\n";
		 break;
		 case 2:cout<<op[a]<<"."<<opt3<<"\n";
		 break;
		 case 3:cout<<op[a]<<"."<<opt4<<"\n";
		 break;
		 }
	 switch(b){
		 case 0:cout<<op[b]<<"."<<opt1<<"\n";
		 break;
		 case 1:cout<<op[b]<<"."<<opt2<<"\n";
		 break;
		 case 2:cout<<op[b]<<"."<<opt3<<"\n";
		 break;
		 case 3:cout<<op[b]<<"."<<opt4<<"\n";
		 break;
		 }
		 break;
	  case 2:
		use2++;
		cout<<"enter the category(1/2):";
		cin>>ch1;
		if(ch1==1)
		{
		cout<<"swap question"<<"\n";
		s1.read((char*)&q,sizeof(q));
		q.display();
		}
		else if(ch1==2)
		{
		cout<<"swap question"<<"\n";
		s2.read((char*)&q,sizeof(q));
		q.display();
		}
		break;
	 case 3:
		use3++;
		cout<<"ask a clue lifeline is used "<<"\n";
		cout<<clue;
		break;
	 default:cout<<"\n no lifeline can be used";

	 }
	 }

void top()
{
char top[100];
cout<<"\n";
ifstream f1("top.txt");
while(f1.eof()==0)
{
f1.getline(top,100,'$');
cout<<top;
}
cout<<"\n";
getch();
}

void quiz()
{
int i,pts=20,j=0,d=0,c=0;
char ca,ans1,ch;
clrscr();
for(i=0;i<10;i++)
{
clrscr();
top();
j++;
cout<<j<<" .";
a[i].display();
if(use<3)
{
cout<<"\n do u want to use lifeline ? ";
cin>>ch;
if(tolower(ch)=='y')
a[i].lifeline();
}
cout<<"\n "<<"enter ur answer";
cin>>ans1;

if(use2==0||d==1)
ca=a[i].retans();
else if(use2==1)
{
d=1;
c=1;
ca=q.retans();
}
if(ca==ans1)
cout<<"your answer is correct";
else
{
pts=pts-2;
cout<<"ooppppss... u r wrong :(";
if(c==1)
{
 c=0;
q.correctans();
}
else
a[i].correctans();
}
c=0;
getch();
}
clrscr();
top();
cout<<"\n \n \n ";
cout<<"the points you have scored is ";
cout<<pts;
admsn.score=pts;
cout<<"\n \n \n ";
top();
getch();
clrscr();
}

void user()
{
int i=0,t1=0,t2=0;
int choice,category;
char choiceuser,o4;
do
{ clrscr();
cout<<"\n \ncategory 1 =12 to 15";
cout<<"\n"<<"category 2= 15 to 17";
cout<<"\n enter your choice: ";
cout<<"\n1.add";
cout<<"\n2.delete";
cout<<"\n3.modify";
cout<<"\n4.display";
cout<<"\n5.exit";
cin>>choice;

switch(choice)
{
case 1:
{
	  cout<<"\nwhich category do you want?";
	  cin>>category;
	  clrscr();
	    switch(category)
	    {
	    case 1:
	    cout<<"do u want"<<"\n"<<"\n 1 append ";
	    cout<<"2. add all the questions ?";
	    cin>>t1;
	    if(t1==2)
	    {
	    clrscr();
	    cout<<"enter the question details ";
	    cout<<"of the age group (12-15)"<<"\n";
	    do{
		 i++;
		 q.read();
		 q1.write((char*)&q,sizeof(q));
		 clrscr();
		 }while(i<10);
	    clrscr();
	    cout<<"do u want to chage the records in swap file ";
	    cin>>o4;
	    if(tolower(o4)=='y')
		{         clrscr();
				 cout<<"enter the swap question "<<"\n";
		q.read();
		s1.write((char*)&q,sizeof(q));

		}
		}
		if(t1==1)
		q.insert1();
		break;
		case 2:
		clrscr();
		cout<<"do u want"<<"\n"<<"\n 1 append ";
		cout<<"2. add all the questions ?";
		cin>>t2;
		clrscr();
		if(t2==1)
		q.insert2();
		else
		{  clrscr();
		cout<<"enter the question details ";
		cout<<"of the age group (15-17)"<<"\n";
		   do{
			 i++;
			 q.read();
			 q2.write((char*)&q,sizeof(q));
			 clrscr();
			}while(i<10);

		clrscr();
		cout<<"do u want to chage the records in swap file ";
		cin>>o4;
		clrscr();
		if(tolower(o4)=='y')
		 {       clrscr();
		 cout<<"enter the swap question "<<"\n";
		 q.read();
		 s2.write((char*)&q,sizeof(q));

		  }
}
}
}
break;

case 2:
	  cout<<"which category do you want to delete?";
	  cin>>category;
	  clrscr();
	  switch(category)
	  {
	  case 1:
		q.del1();
		q1.open("qbank1.dat",ios::binary|ios::in|ios::out|ios::app);
		   break;
	  case 2:
	   q.del2();
	   q2.open("qbank2.dat",ios::binary|ios::in|ios::out|ios::app);
		  break;
	    }
	break;//for case 2 choice switch
case 3:
cout<<"which category do you want?";
cin>>category;
switch(category)
 {
	  case 1:
	    q.modify1();
	    q1.open("qbank1.dat",ios::binary|ios::in|ios::out|ios::app);
		  break;
	  case 2:
	  q.modify2();
		   q2.open("qbank2.dat",ios::binary|ios::in|ios::out|ios::app);
		break;
	    }
	break;
case 4:
cout<<"which category do you want?";
cin>>category;
switch(category)
 {
	  case 1:i=0;
	    while(q1.eof()==0)
	  {i++;
	  q1.read((char*)&q,sizeof(q));
	  cout<<i<<" .";
		q.display();
	  delay(5000);
	  clrscr();
	  cout<<"\n ";
	  }
	  break;
	 case 2:
i=0;
	 while(q2.eof()==0)
	  {i++;
	  q2.read((char*)&q,sizeof(q));
	  cout<<i<<" .";
			  q.display();
	  delay(2000);
	  clrscr();
	  }
		break;
	    }
	break;

 case 5:
 exit(0);
 break;
}
cout<<"\ndo you want to continue?";
cin>>choiceuser;
clrscr();
}while(toupper(choiceuser)=='Y');
}
void main()
{
char welcome[100],o1,o2[100],rule[100],end[100];
int k,i=0;
clrscr();
while(f2.eof()==0)
{
f2.getline(welcome,100,'$');
cout<<welcome;
}
getch();
clrscr();
cout<<"are u the owner of quiz ?";
cin>>o1;
if(tolower(o1)=='y')
{
cout<<"enter the password ";
for( k=0;k<9;k++)
{
o2[k]=getch();
cout<<"*";
}
delay(2000);
if(strcmpi(o2,"csproject")==0)
user();
}
else
 clrscr();
 cout<<"enter your name ";
 gets(admsn.nam);
 cout<<"enter your age ";
 cin>>admsn.age;
 if(admsn.age<12||admsn.age>17)
 {
 cout<<"                        the quiz is conducted only for 8 th -12th "<<"\n";
 cout<<"                       soooorrryyyy ........:( :(";
 cout<<"\n press any key to exit ";
 getch();
 exit(0);
 }
 else
 {
 clrscr();
 while(f3.eof()==0)
 {
 f3.getline(rule,100,'$');
 cout<<rule;
 }
 getch();
 clrscr();
 if(admsn.age>=12&&admsn.age<15)
  {
   if(q1)
  {
  i=0;
  while(q1.eof()==0)
  {
  q1.read((char*)&q,sizeof(q));
    a[i]=q;
    i++;
    }
    }
  quiz();
  fstream p1("player1.dat",ios::binary|ios::in|ios::out|ios::app);
  p1.write((char*)&admsn,sizeof(admsn));
 int max=0,pos=0,n;
 i=0;
 p1.clear();
 p1.seekg(0);
 while(p1.read((char*)&x,sizeof(x)))
 {
 players[i]=x;
 i++;
 }
 max=players[0].score;
 for(n=0;n<=i;n++)
  if(players[n].score>max)
  {
  max=players[n].score;
  pos=n;
  }
 if(strcmpi(admsn.nam,players[pos].nam)==0)
 {   clrscr();
 cout<<" \n \n \n \n \t\t\t CONGRAGULATIONS   ";
 cout<<" \n\t\t YOU ARE THE BEST SCORER ";
 getch();
 }
 else
{             clrscr();
 cout<<" \n\n \n\n\n\n\n\n\n\n\n\n\t\t   the best scorer"<<players[pos].nam <<"\n  score : "  <<players[pos].score;
 getch();
}
}
 else  if(admsn.age>=15&&admsn.age<=17 )
{
  if(q2)
  {
  i=0;
  while(q2.eof()==0)
  {
  q2.read((char*)&q,sizeof(q));
    a[i]=q;
    i++;
    }
    }
    quiz();
    clrscr();
    fstream p2("player.dat",ios::binary|ios::in|ios::out|ios::app);
    p2.write((char*)&admsn,sizeof(admsn));
    i=0;
    int max=0,pos=0,n;
   while(p2.read((char*)&x,sizeof(x)))
   {
   players[i]=x;
   i++;
   }
  max=players[0].score;
  for(n=0;n<=i;n++)
  if(players[n].score>max)
  {
  max=players[n].score;
  pos=n;
  }
 if(strcmpi(admsn.nam,players[n].nam)==0)
 {            clrscr();
 cout<<"               \n\n\n\n\n\n\n\n\n              \n\n\n CONGURAGULATIONS  ";
 cout<<"\n                                  YOU ARE THE BEST SCORER ";
 getch();
 }
 else
{ clrscr();
 cout<<"the best scorer of thr game is "<<players[pos].nam<<"\n  the score is "<<players[pos].score;
    getch();
    }
    }

clrscr();
 while (f4.eof()==0)
 {
 f4.getline(end,100,'$');
 cout<<end;
 }
 getch();
 }
 }

