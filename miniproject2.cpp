#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
static int p = 0;
class a
{
  char busn[10], driver[10], arrival[5], depart[5], from[10], to[10], seat[9][5][10];
public:
  void install( );
  void allotment( );
  void empty( );
  void show( );
  void avail( );
  void position(int i);
}
bus[10];
void vline(char ch)
{
  for (int i=80;i>0;i--)
  cout<<ch;
}
void a::install()
{
  cout<<endl<<"Enter bus no: ";
  cin>>bus[p].busn;
  cout<<"Enter Driver's name: ";
  cin>>bus[p].driver;
  cout<<"Arrival time: ";
  cin>>bus[p].arrival;
  cout<<"Departure: ";
  cin>>bus[p].depart;
  cout<<"From: ";
  cin>>bus[p].from;
  cout<<"To: ";
  cin>>bus[p].to;
  bus[p].empty();
  p++;
  
cout<<endl<<"Bus added Sucessfully "<<endl;
}
void a::allotment()
{
  int seat;
  char number[5];
  top:
  cout<<endl<<"Bus no: ";
  cin>>number;
  int n;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
  while(n<=p)
  {
    cout<<"Seat Number: ";
    cin>>seat;
    if(seat>45)
    {
      cout<<endl<<"There are only 45 seats available in this bus."<<endl;
    }
    else
    {
    if (strcmp(bus[n].seat[seat/5][(seat%5)-1], "Empty")==0)
      {
        cout<<"\tEnter passanger's name: ";
        cin>>bus[n].seat[seat/5][(seat%5)-1];
        
        cout<<"\tSeat Reserved Sucessfully ";
        break;
      }
    else
      cout<<"\tThe seat no. is already reserved."<<endl;
      }
      }
    if(n>p)
    {
      cout<<"\tEnter correct bus no."<<endl;
      goto top;
    }
  }

void a::empty()
{
  for(int i=0; i<9;i++)
  {
    for(int j=0;j<5;j++)
    {
      strcpy(bus[p].seat[i][j], "Empty");
    }
  }
}
void a::show()
{
  int n;
  char number[5];
  cout<<"\tEnter bus no: ";
  cin>>number;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
while(n<=p)
{
  vline('*');
  cout<<endl<<"\t\t\tBus no: \t"<<bus[n].busn
  <<"\n\t\t\tDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"
  <<bus[n].arrival<<"\t\t\tDeparture time:"<<bus[n].depart
  <<"\n\t\t\tFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<
  bus[n].to<<"\n";
  vline('*');
  bus[0].position(n);
  int a=1;
  for (int i=0; i<9; i++)
  {
    for(int j=0;j<5;j++)
    {
      a++;
      if(strcmp(bus[n].seat[i][j],"Empty")!=0)
      cout<<"\n\t\t\tThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
    }
  }
  break;
  }
  if(n>p)
    cout<<"\t\t\tEnter correct bus no: ";
}
void a::position(int l)
{
  int s=0;p=0;
  for (int i =0; i<9;i++)
  {
    cout<<"\n";
    for (int j = 0;j<5; j++)
    {
      s++;
      if(strcmp(bus[l].seat[i][j], "Empty")==0)
        {
          cout.width(5);
          cout.fill(' ');
          cout<<s<<".";
          cout.width(10);
          cout.fill(' ');
          cout<<bus[l].seat[i][j];
          p++;
        }
        else
        {
        cout.width(5);
        cout.fill(' ');
        cout<<s<<".";
        cout.width(10);
        cout.fill(' ');
        cout<<bus[l].seat[i][j];
        }
      }
    }
  cout<<"\n\n\t\t\tThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn;
  }
void a::avail()
{

  for(int n=0;n<p;n++)
  {
    vline('*');
    cout<<endl<<"\t\t\tBus no: \t"<<bus[n].busn<<"\n\t\t\tDriver: \t"<<bus[n].driver
    <<"\t\t\tArrival time: \t"<<bus[n].arrival<<"\t\t\tDeparture Time: \t"
    <<bus[n].depart<<"\n\t\t\tFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"
    <<bus[n].to<<"\n";
    vline('*');
    vline('_');
  }
}
int main()
{
system("cls");
int w;
while(1)
{

  cout<<endl;
  
  cout<<"\tBus Reservation System Project in C++"<<endl<<endl;
  
cout<<"1.Add Bus"<<endl;
cout <<"2.Bus Reservation"<<endl;
cout  <<"3.Show"<<endl;
cout<<"4.Buses Available."<<endl;
cout <<"5.Exit"<<endl;
cout<<"Enter your choice:-> ";
cin>>w;
  switch(w)
  {
    case 1:  bus[p].install();
      break;
    case 2:  bus[p].allotment();
      break;
    case 3:  bus[0].show();
      break;
    case 4:  bus[0].avail();
      break;
    case 5:  exit(0);
  }
}
return 0;
}
