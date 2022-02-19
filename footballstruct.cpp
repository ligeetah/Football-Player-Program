#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int count=0;
struct first
{
    string name;
    string position;
    int num_of_touch_downs;
    int num_of_catches;
    int num_of_passing_yards;
    int num_of_recieving_yards;
    int num_of_rushing_yards;
};
first array[10];
void add_array(string name,string position,int a1,int a2,int a3,int a4,int a5)
{
    array[count].name=name;
    array[count].position=position;
    array[count].num_of_touch_downs=a1;
    array[count].num_of_catches=a2;
    array[count].num_of_passing_yards=a3;
    array[count].num_of_recieving_yards=a4;
    array[count].num_of_rushing_yards=a5;
    count++;
}
string parse(string row, int column)
{

    int dollarCount = 1;
    string item;
    int index = 0;
    while (true)
    {
        char ch = row[index];
        if (ch == '\0')
            return item;
        if (ch == '$')
        {
            dollarCount++;
        }
        else if (dollarCount == column)
        {
            item = item + ch;
        }
        index++;
    }
    return item;
}
void load_data()
{
    fstream file;
    string name,position,str;
    int a1,a2,a3,a4,a5;
    file.open("file.txt",ios::in);
    while(!file.eof())
    {
        getline(file, str);
        if (str=="")
        {
            break;
        }
        name=parse(str,1);
        position=parse(str,2);
        a1=stoi(parse(str,3));
        a2=stoi(parse(str,4));
        a3=stoi(parse(str,5));
        a4=stoi(parse(str,6));
        a5=stoi(parse(str,7));
        add_array(name,position,a1,a2,a3,a4,a5);
    }
    file.close();
}
void input()
{
    string name,position;
    int a1,a2,a3,a4,a5;
    system("cls");
    cout<<"Main Menu > Input > "<<endl<<endl;
    cin.ignore();
    cout<<"Enter the name : ";
    getline(cin,name);
    cout<<"Enter the position : ";
    getline(cin,position);
    cout<<"Enter the number of touch downs :";
    cin>>a1;
    cout<<"Enter the number of catches :";
    cin>>a2;
    cout<<"Enter the number of passing yards :";
    cin>>a3;
    cout<<"Enter the number of recieving yards :";
    cin>>a4;
    cout<<"Enter the number of rushing yards :";
    cin>>a5;
    add_array(name,position,a1,a2,a3,a4,a5);
}
void display()
{
    system("cls");
    cout<<"Main Menu > Records > "<<endl<<endl;
    for(int x=0;x<count;x++)
    {
        system("cls");
        cout<<"Main Menu > Records > "<<endl<<endl;
        cout<<"Record of Player "<<x+1<<" >"<<endl<<endl;
        cout<<"Name of Player "<<x+1<<" : "<<array[x].name<<endl;
        cout<<"Position "<<x+1<<" : "<<array[x].position<<endl;
        cout<<"Number of touchdowns "<<x+1<<" : "<<array[x].num_of_touch_downs<<endl;
        cout<<"Number of catches "<<x+1<<" : "<<array[x].num_of_catches<<endl;
        cout<<"Number of passing Yards "<<x+1<<" : "<<array[x].num_of_passing_yards<<endl;
        cout<<"Number of recieving Yards "<<x+1<<" : "<<array[x].num_of_recieving_yards<<endl;
        cout<<"Number of rushing Yards "<<x+1<<" : "<<array[x].num_of_rushing_yards<<endl;
        system("pause");
    }
    if(count==0)
    {
        cout<<"There is no record to display ..."<<endl;
        system("pause");
    }
}
void store()
{
    fstream file;
    file.open("file.txt",ios::out);
    for(int x=0;x<count;x++)
    {
        file<<array[x].name<<"$";
        file<<array[x].position<<"$";
        file<<array[x].num_of_touch_downs<<"$";
        file<<array[x].num_of_catches<<"$";
        file<<array[x].num_of_passing_yards<<"$";
        file<<array[x].num_of_recieving_yards<<"$";
        file<<array[x].num_of_rushing_yards<<endl;
    }
    file.close();
}
main()
{
    load_data();
    int op;
    while (1)
    {
        system("cls");
        cout<<"Main Menu > "<<endl<<endl;
        cout << "Press 1 to input" << endl;
        cout << "Press 2 to display" << endl;
        cout << "Press 3 to Search" << endl;
        cout << "Press 4 to Update" << endl;
        cout << "Press 5 to Exit" << endl;
        cin >> op;
        system("cls");
        if (op == 1)
        {
            input();
        }
        else if (op == 2)
        {
            display();
        }
        else if (op == 3)
        {
            cout<<"Main Menu > Search > "<<endl<<endl;
            string pname;
            int index=-1;
            cin.ignore();
            cout<<"Enter the name of Player : ";
            getline(cin,pname);
            for(int x=0;x<count;x++)
            {
                if(pname==array[x].name)
                {
                    index=x;
                }
            }
            if(index != -1 )
            {
                cout<<"Name of Player   : "<<array[index].name<<endl;
                cout<<"Position   : "<<array[index].position<<endl;
                cout<<"Number of touchdowns   : "<<array[index].num_of_touch_downs<<endl;
                cout<<"Number of catches   : "<<array[index].num_of_catches<<endl;
                cout<<"Number of passing Yards   : "<<array[index].num_of_passing_yards<<endl;
                cout<<"Number of recieving Yards   : "<<array[index].num_of_recieving_yards<<endl;
                cout<<"Number of rushing Yards   : "<<array[index].num_of_rushing_yards<<endl;
            }
            else
            {
                cout<<"There is no such PLayer....."<<endl;
            }
            system("pause");
        }
        else if(op == 4)
        {
            cout<<"Main Menu > Update > "<<endl<<endl;
            string pname;
            int index=-1;
            cin.ignore();
            cout<<"Enter the name of Player : ";
            getline(cin,pname);
            for(int x=0;x<count;x++)
            {
                if(pname==array[x].name)
                {
                    index=x;
                }
            }
            if(index != -1 )
            {
                cout<<"Enter the name : ";
                getline(cin,array [index].name);
                cout<<"Enter the position : ";
                getline(cin,array [index].position);
                cout<<"Enter the number of touch downs :";
                cin>>array [index].num_of_touch_downs;
                cout<<"Enter the number of catches :";
                cin>>array [index].num_of_catches;
                cout<<"Enter the number of passing yards :";
                cin>>array [index].num_of_passing_yards;
                cout<<"Enter the number of recieving yards :";
                cin>>array [index].num_of_recieving_yards;
                cout<<"Enter the number of rushing yards :";
                cin>>array [index].num_of_rushing_yards;
            }
            else
            {
                cout<<"There is no such PLayer....."<<endl;
            }
            system("pause");
        }
        else if(op ==5)
        {
            store();
            break;
        }
    }
}