#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<conio.h>
#include<ios>
#include<limits>
#include<iomanip>

using namespace std;

struct Date
{
    int dd,mm,yy;
};

void view_booklist();
void add_book();
void delete_book();
void search_book();
void issue_book();
void view_issued_books();
void return_book();

class book
{
    public:

    int bookid;
    char author[50];
    char publication[50];
    char name[50];
    float cost;
    void input();
    void display();
};

inline void book::input()
{
    cin.ignore (numeric_limits<streamsize>::max(), '\n');
    cout << "\t\t\t\t\t\t\t\t\tENTER NAME OF BOOK : ";
    cin.get (name, 50);

    cin.ignore (numeric_limits<streamsize>::max(), '\n');
    cout << "\n\t\t\t\t\t\t\t\t\tENTER AUTHOR : ";
    cin.get (author, 50);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\n\t\t\t\t\t\t\t\t\tENTER PUBLISHER : ";
    cin.get(publication, 50);

    cout << "\n\t\t\t\t\t\t\t\t\tENTER BOOKID : ";
    cin >> bookid;

    cout << "\n\t\t\t\t\t\t\t\t\tENTER COST : ";
    cin >> cost;
}

inline void book::display()
{
    cout << left << setw (25) << bookid << setw (43) << name << setw (35) << author << setw (40) << publication << setw (25) << cost << endl;
}

class student
{
    public:

    char name[20];
    int roll_no;
    unsigned long long int contact;
    char book_name[50];
    int bookid;
    Date d;
    void input();
    void display();
};

inline void student::input()
{
    system("cls");

    char slash = '/';
    cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tEnter Name of Student : ";
    cin.ignore (numeric_limits<streamsize>::max(), '\n');
    cin.get (name, 20);

    cout << "\n\n\t\t\t\t\t\t\t\t\tEnter Roll No. of Student : ";
    cin >> roll_no;

    cout << "\n\n\t\t\t\t\t\t\t\t\tEnter Contact of Student : ";
    cin >> contact;

    cin.ignore (numeric_limits<streamsize>::max(), '\n');
    cout << "\n\n\t\t\t\t\t\t\t\t\tEnter Name of Book to be issued : ";
    cin.get (book_name, 50);

    cout << "\n\n\t\t\t\t\t\t\t\t\tEnter Book ID : ";
    cin >> bookid;

    cout << "\n\n\t\t\t\t\t\t\t\t\tEnter Date (dd/mm/yy) : ";
    cin >> d.dd >> slash >> d.mm >> slash >> d.yy;
}

inline void student::display()
{
    char slash = '/';
    cout << "\t\t\t" << left << setw (25) << name << setw (25) << roll_no << setw (25) << contact << setw (25) << book_name << setw (25) << bookid << d.dd << slash << d.mm << slash << d.yy << endl;
}

int main()
{
    int n;
    system ("cls");

    cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t**LIBRARY MANAGEMENT SYSTEM**\n\n\n";

    cout << "\t\t\t\t\t\t\t\t\t [1]     ADD BOOKS\n";
    cout << "\t\t\t\t\t\t\t\t\t [2]     DELETE BOOKS\n";
    cout << "\t\t\t\t\t\t\t\t\t [3]     ISSUE BOOK\n";
    cout << "\t\t\t\t\t\t\t\t\t [4]     VIEW ISSUED BOOKS\n";
    cout << "\t\t\t\t\t\t\t\t\t [5]     SEARCH BOOK\n";
    cout << "\t\t\t\t\t\t\t\t\t [6]     VIEW BOOKLIST\n";
    cout << "\t\t\t\t\t\t\t\t\t [7]     RETURN BOOK\n";
    cout << "\t\t\t\t\t\t\t\t\t [8]     EXIT\n\n";
    
    cout << "\t\t\t\t\t\t\t\t\t YOUR CHOICE : ";
    cin >> n;

    switch (n)
    {
        case 1:
        {
            add_book();
            break;
        }

        case 2:
        {
            delete_book();
            break;
        }

        case 3:
        {
            issue_book();
            break;
        }

        case 4:
        {
            view_issued_books();
            break;
        }
        
        case 5:
        {
            search_book();
            break;
        }

        case 6:
        {
            view_booklist();
            break;
        }

        case 7:
        {
            return_book();
        }
        
        case 8:
        {
            exit (0);
        }

        default:
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tINVALID CHOICE\n\t\t\t\t\t\t\t\t\t\t";
            getch();
            main();
        }
    }
}

void issue_book()
{
    system ("cls");

    student s1;
    book b1;

    s1.input();

    int k = 0;

    ofstream fout ("Studentdata.txt", ios::app);
    ifstream fin ("Bookdata.txt");
    ofstream fout1 ("Temporary.txt");

    fin.seekg (0, ios::end);
    int n = fin.tellg() / sizeof(b1);

    fin.seekg (0,ios::beg);
    for (int i = 0; i < n; i++)
    {
        fin.read ((char *)&b1, sizeof(b1));
        if (strcmp (b1.name, s1.book_name))
        {
            fout1.write ((char *)&b1, sizeof(b1));
        }

        else
        {
            k = 1;
            fout1.write ((char *)&b1,sizeof (b1));
        }
    }

    if(k==0)
    {
        cout<<"\n\n\t\t\t\t\t\t\t\t\tBOOK NOT FOUND.\n";
        fout.close();
        fin.close();
        fout1.close();
        cout<<"\n\t\t\t\t\t\t\t\t\t**PRESS ENTER TO GET BACK**";

        getch();
        main();
    }

    else
    {
        fout.write ((char *)&s1, sizeof(s1));
        fout.close();
        fin.close();
        fout1.close();
        ofstream f ("Bookdata.txt");
        ifstream fin1 ("Temporary.txt");
        fin1.seekg (0, ios::end);
        n = fin1.tellg() / sizeof(b1);
        fin1.seekg (0, ios::beg);

        for(int i = 0; i < n; i++)
        {
            fin1.read ((char *)&b1, sizeof(b1));
            f.write ((char *)&b1, sizeof(b1));
        }

        fin1.close();
        f.close();
        cout << "\n\n\t\t\t\t\t\t\t\t\tBOOK ISSUED SUCCESSFULLY.";
        cout << "\n\n\t\t\t\t\t\t\t\t\t**PRESS ENTER TO GET BACK*";

        getch();
        main();
    }
}

void view_issued_books()
{
    system ("cls");

    cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t**ISSUED BOOKS LIST**\n\n";
    cout << "\t\t\t" << left << setw (25) << "NAME" << setw (25) << "ROLL NO." << setw (25) << "CONTACT" << setw (25) << "BOOKNAME" << setw (25) << "BOOKID" << "ISSUE DATE" << endl << endl;
    
    student s1;
    ifstream fin ("Studentdata.txt");

    fin.seekg(0,ios::end);

    int n = fin.tellg() / sizeof (s1);

    fin.seekg(0,ios::beg);

    for (int i = 0; i < n; i++)
    {
        fin.read ((char *)&s1, sizeof (s1));
        s1.display();
    }
    fin.close();
    cout << "\n\n\t\t\t\t\t\t\t\t\tPRESS ENTER TO GET BACK\n";

    getch();
    main();
}



void return_book()
{
   system ("cls");

   char name[20];
   char book_name[50];
   int roll_no,bookid;

   student s1;
   book b1;

   cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tENTER NAME OF STUDENT : ";

   cin.ignore (numeric_limits<streamsize>::max(), '\n');
   cin.get (name,20);
   cout << "\n\n\t\t\t\t\t\t\t\t\tENTER STUDENT ROLL NO. : ";

   cin >> roll_no;
   cout << "\n\n\t\t\t\t\t\t\t\t\tENTER BOOK NAME : ";

   cin.ignore (numeric_limits<streamsize>::max(), '\n');
   cin.get (book_name, 50);
   cout << "\n\n\t\t\t\t\t\t\t\t\tENTER BOOKID : ";

   cin >> bookid;
   ifstream fin ("Studentdata.txt");
   ofstream fout ("Temporarystudent.txt");
   fin.seekg (0, ios::end);
   int n = fin.tellg() / sizeof(s1), k = 0;
   fin.seekg (0, ios::beg);
   for(int i = 0; i < n; i++)
   {
       fin.read ((char *)&s1, sizeof(s1));
       if (!strcmp (name, s1.name) && (roll_no == s1.roll_no) && (bookid == s1.bookid) && !strcmp (book_name,s1.book_name))
       {
           k = 1;
           cout << "\n\n\t\t\t\t\t\t\t\t\t**PRESS ENTER TO RETURN BOOK.**\n";
           getch();
           cout << "\n\t\t\t\t\t\t\t\t\t**RETURNED SUCCESSFULLY.**\n";
       }

       else
       {
           fout.write ((char *)&s1, sizeof(s1));
       }
    }

   fin.close();
   fout.close();

   if (k == 0)
    {
       cout << "\n\n\t\t\t\t\t\t\t\t\t**INVALID ISSUE DETAILS.**\n";
       cout << "\n\t\t\t\t\t\t\t\t\t**PRESS ENTER TO GET BACK.**\n";
       getch();
       main();
    }

   ifstream fin2 ("Temporarystudent.txt");
   ofstream fout2 ("Studentdata.txt");
   fin2.seekg (0, ios::end);
   n = fin2.tellg() / sizeof(s1);
   fin2.seekg (0, ios::beg);
   for (int i = 0; i < n; i++)
   {
       fin2.read ((char *)&s1, sizeof(s1));
       fout2.write ((char *)&s1, sizeof(s1));
   }

   fin2.close();
   fout2.close();
   ifstream fin1 ("Bookdata.txt");
   ofstream fout1 ("Temporary.txt");
   fin1.seekg (0, ios::end);
   n = fin1.tellg() / sizeof(b1);
   fin1.seekg (0, ios::beg);
   for(int i = 0; i < n; i++)
   {
       fin1.read ((char *)&b1, sizeof(b1));
       if (!(strcmp(b1.name,book_name)) && bookid == b1.bookid)
       {
           fout1.write ((char *)&b1, sizeof(b1));
       }

       else
       {
           fout1.write ((char *)&b1, sizeof(b1));
       }
   }
   fin1.close();
   fout1.close();

   ofstream fout3 ("Bookdata.txt");
   ifstream fin3 ("Temporary.txt");
   fin3.seekg (0, ios::end);
   n = fin3.tellg() / sizeof(b1);
   fin3.seekg (0, ios::beg);
   for (int i = 0; i < n; i++)
   {
       fin3.read ((char *)&b1, sizeof(b1));
       fout3.write ((char *)&b1, sizeof(b1));
   }

   fin3.close();
   fout3.close();
   cout << "\n\n\t\t\t\t\t\t\t\t\t   **PRESS ENTER TO GET BACK.**\n";

   getch();
   main();
}

void view_booklist()
{
    system ("cls");

    ios_base::fmtflags flags = cout.flags();
    cout << "\n\n\t\t\t\t\t\t\t\t\t**BOOKLIST**\n\n\n";
    cout << left << setw (25) << "BOOKID" << setw (42) << "BOOKNAME" << setw (35) << "AUTHOR" << setw (40) << "PUBLISHER" << setw (24) << "COST" << endl << endl;
    
    book b1;
    ifstream fin;
    fin.open ("Bookdata.txt");
    fin.seekg (0, ios::end);

    int n;
    n = fin.tellg() / sizeof(b1);
    fin.seekg (0, ios::beg);

    for (int i = 0; i < n; i++)
    {
        fin.read ((char *)&b1, sizeof(b1));
        b1.display();
    }

    fin.close();
    cout << "\n\n\t\t\t\t\t\t\t\t\t**PRESS ENTER TO GET BACK**";
    getch();
    main();
}

void search_book()
{
    system ("cls");

    char name[50];
    int bookid;
    int k = 0;
    book b1;
    cin.ignore (numeric_limits<streamsize>::max(), '\n');
    cout << "\n\n\t\t\t\t\t\t\t\t\tENTER NAME OF BOOK : ";

    cin.get (name, 50);
    cout << "\t\t\t\t\t\t\t\t\tENTER BOOKID : ";

    cin >> bookid;
    cin.clear();
    ifstream fin ("Bookdata.txt");
    fin.seekg (0, ios::end);
    int n = fin.tellg() / sizeof(b1);
    fin.seekg (0, ios::beg);
    for (int i = 0; i < n; i++)
    {
        fin.read ((char *)&b1, sizeof(b1));
        if (!(strcmp(b1.name, name)) && bookid == b1.bookid)
        {
            k = 1;
            ios_base::fmtflags flags = cout.flags();
            cout << endl << left << setw (25) << "BOOKID" << setw (42) << "BOOKNAME" << setw (35) << "AUTHOR" << setw (40) << "PUBLISHER" << setw (24) << "COST" << setw (25) << "COPIES" << endl << endl;
            b1.display();
        }
    }

    if (k == 0)
    {
        cout << "\n\n\t\t\t\t\t\t\t\t\tBOOK NOT FOUND.";
    }
    fin.close();

    cout << "\n\n\t\t\t\t\t\t\t\t\t**PRESS ENTER TO GET BACK**";

    getch();
    main();
}


void add_book()
{
    system ("cls");
    cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\t**ADD NEW BOOK**\n\n\n";

    book b1;
    b1.input();
    ofstream fout;
    fout.open ("Bookdata.txt", ios::app);
    fout.write ((char *)&b1, sizeof(b1));
    fout.close();
    cout << "\n\n\t\t\t\t\t\t\t\t\t**BOOK ADDED SUCCESSFULLY**";
    cout << "\n\n\t\t\t\t\t\t\t\t\t**PRESS ENTER TO GET BACK**";
    getch();
    main();
}

void delete_book()
{
    system ("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t**DELETE BOOKS**\n\n\n";

    char name[50];
    int k = 0;
    book b1;
    cout << "\t\t\t\t\t\t\t\tENTER NAME OF BOOK YOU WANT TO DELETE : ";
    cin.ignore (numeric_limits<streamsize>::max(), '\n');
    cin.get (name, 50);
    ifstream fin ("Bookdata.txt");
    ofstream fout ("Temporary.txt");
    fin.seekg (0, ios::end);
    int n = fin.tellg() / sizeof(b1);
    fin.seekg (0, ios::beg);

    for (int i = 0; i < n; i++)
    {
        fin.read ((char *)&b1, sizeof(b1));
        if (strcmp(b1.name, name))
        {
            fout.write ((char *)&b1, sizeof(b1));
        }

        else
        {
            k = 1;
        }
    }

    fin.close();
    fout.close();
    if (k == 0)
    {
        cout << "\n\n\t\t\t\t\t\t\t\t\t**BOOK NOT FOUND.**\n";
        cout << "\t\t\t\t\t\t\t\t\t**PRESS ENTER TO GET BACK**";

        getch();
        main();
    }

    ifstream fin1 ("Temporary.txt");
    ofstream fout1 ("Bookdata.txt");
    fin1.seekg (0, ios::end);
    n = fin1.tellg() / sizeof(b1);
    fin1.seekg (0, ios::beg);
    for (int i = 0; i < n; i++)
    {
        fin1.read ((char *)&b1, sizeof(b1));
        fout1.write ((char *)&b1, sizeof(b1));
    }

    fin1.close();
    fout1.close();
    cout << "\n\n\t\t\t\t\t\t\t\t\t**DELETION SUCCESSFUL.**\n";
    cout << "\t\t\t\t\t\t\t\t\t**PRESS ENTER TO GET BACK**";

    getch();
    main();
}