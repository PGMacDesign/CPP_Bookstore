#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <cstring>


//This program allows users to add books/ cds/ dvds to a virtual bookstore and then displays them

using namespace std;

//This is the base class of which all others are derrived. All derrived classes are types of publications
class Publication
{
    protected:
        char title[100]; //Title, array of characters
        float price; //Price of item

    public:
        Publication();
        void getData(); //Reads title and price from keyboard
        void DisplayData(); //Displays the title and price
};

//Constructor
Publication::Publication()
{
}

//Obtains the Title and Price from the keyboard and inputs them into the member values
void Publication::getData()
{
    string str1;
    cout<<"\nPlease enter the title: "<<endl;
    getline(cin, str1);
    //char tempArray[100];
    //tempArray[] = str1.c_str();
    strcpy (title, str1.c_str());

    cout<<"\nPlease enter the price: "<<endl;
    cin>>price;
}

//Displays the Title and the price obtained in the getData() function
void Publication::DisplayData()
{
    cout<<"Title: "<<title<<endl;
    cout<<"Price: $"<<price<<endl;
}

//--End Class Publication-------------------------------------------------------------

//This is a derrived class, Book, which is derrived from type Publication
class Book: public Publication
{
    private:
        int pageNumber; //Page number in book

    public:
        void getData(); //Reads the page number from the keyboard
        void DisplayData(); //Displays the page number

};

//Obtains the pagenumber from the keyboard and inputs them into the member values
void Book::getData()
{
    Publication::getData();
    cout<<"\nHow many pages are in this book? (Whole Numbers Please) " <<endl;
    cin >> pageNumber;
}

//Displays the number of pages obtained in the getData() function
void Book::DisplayData()
{
    Publication::DisplayData();
    cout<<"Number of Pages: " << pageNumber << endl;
}


//--End Class Book--------------------------------------------------------------------

//
class CDMusic: public Publication
{
    private:
        float playingTime; //Length of time of CD in minutes

    public:
        void getData(); //Reads the length of playing time, in minutes, from the keyboard
        void DisplayData(); //Displays the length of playing time in minutes
};

//Obtains the playing time from the keyboard and inputs them into the member values
void CDMusic::getData()
{
    Publication::getData();
    cout<<"\nWhat is the length (in minutes) of the Music? " <<endl;
    cin>>playingTime;
}

//Displays the Length of CD obtained in the getData() function
void CDMusic::DisplayData()
{
    Publication::DisplayData();
    cout<<"Length of CD in Minutes: " << playingTime << endl;
}

//--End Class CDMusic------------------------------------------------------------------

//This is a derrived class, DVDMovie, which is derrived from type Publication
class DVDMovie: public Publication
{
    private:
        char rating[5]; //Standard US rating system, G, PG, PG13, R

    public:
        void getData(); //Reads the page number from the keyboard
        void DisplayData(); //Displays the page number
};

//Obtains the DVD Rating from the keyboard and inputs them into the member values
void DVDMovie::getData()
{
    Publication::getData();
    string str2;
    cout<<"\nWhat is the Rating of this Movie? (G, PG, PG13, R) " <<endl;
    cin>>str2;
    strcpy (rating, str2.c_str());
}

//Displays the Rating of the DVD obtained in the getData() function
void DVDMovie::DisplayData()
{
    Publication::DisplayData();
    cout<<"Rating of the DVD: " << rating;
}

//--End Class DVDMovie-----------------------------------------------------------------

//This is the inputloop function which runs a do while loop to allow the user to
//enter in as many new Books, DVDMovies, and CDMusic objects as they want.
//It returns a vector, pubs, which is a vector OF vectors. Those inner vectors are
//Groups of Publication Objects that will be used to hold data entered from the keyboard.
class inputLoop
{
    public:
        //Publication* inputLoopChoice();
        vector< vector<Publication*> > inputLoopChoice();
};

//Creates a simple do while loop for input into the console. Gives choice for starting
vector< vector<Publication*> > inputLoop::inputLoopChoice()
{
    int answer = 0;
    vector< vector<Publication*> > pubs;
    vector< Publication* > books;
    vector< Publication* > cds;
    vector< Publication* > dvds;
    do
    {
        cout<<"\nData Entry Screen\n"<<endl;
        cout<<"1: Book"<<endl;
        cout<<"2: CD"<<endl;
        cout<<"3: DVD"<<endl;
        cout<<"0: Exit"<<endl;
        cout<<"\nPlease enter your choice: "<<endl;
        cin>>answer;
        cin.ignore();

        if (answer == 1)
        {
            Book* b = new Book;
            b->getData();
            books.push_back(b);

        } else if (answer == 2)
        {
            CDMusic* c = new CDMusic;
            c->getData();
            cds.push_back(c);
        } else if (answer == 3)
        {
            DVDMovie* d = new DVDMovie;
            d->getData();
            dvds.push_back(d);
        } else if (answer < 0 || answer > 3)
        {
            cout<<"\nPlease enter one of the choices I gave you"<<endl;
        }
    } while (answer != 0);

    pubs.push_back(books);
    pubs.push_back(cds);
    pubs.push_back(dvds);
    return pubs;
}

//--End Class InputLoop----------------------------------------------------------------

//Main Function
int main()
{

    vector< vector<Publication*> > pubs;

    inputLoop loop;
    pubs = loop.inputLoopChoice();

    cout << endl;

    cout << "\nBOOKS" << endl;
    cout << "=====" << endl;
    for (int i = 0; i < pubs[0].size(); i++) {
        Book* b = (Book*) pubs[0][i];
        b->DisplayData();
        cout << "\n" << endl;
    }
    cout << "----- END BOOKS -----" << endl;

    cout << "\nCDs" << endl;
    cout << "===" << endl;
    for (int i = 0; i < pubs[1].size(); i++) {
        CDMusic* c = (CDMusic*) pubs[1][i];
        c->DisplayData();
        cout << "\n" << endl;
    }
    cout << "----- END CDs -----" << endl;

    cout << "\nDVDs" << endl;
    cout << "====" << endl;
    for (int i = 0; i < pubs[2].size(); i++) {
        DVDMovie* d = (DVDMovie*) pubs[2][i];
        d->DisplayData();
        cout << "\n" << endl;
    }
    cout << "----- END DVDs -----" << endl;

    return 0;
}
