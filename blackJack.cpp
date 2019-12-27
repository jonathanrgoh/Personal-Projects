#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <time.h>
#include <windows.h>
using namespace std;

class Card
{
    private:
        string suit;
        int value;
        string face;

    public:
        Card()
        {
        }
        Card(int v, string s)
        {
            value=v;
            suit=s;
        }

        string getSuit()
        {
            return suit;
        }

        int getValue()
        {
            return value;
        }

        string getFace()
        {
            switch(value)
            {
                case 1: face="A";
                    break;
                case 2: face="2";
                    break;
                case 3: face="3";
                    break;
                case 4: face="4";
                    break;
                case 5: face="5";
                    break;
                case 6: face="6";
                    break;
                case 7: face="7";
                    break;
                case 8: face="8";
                    break;
                case 9: face="9";
                    break;
                case 10: face="10";
                    break;
                case 11: face="J";
                    break;
                case 12: face="Q";
                    break;
                case 13: face="K";
                    break;
            }
            return face;
        }
};

Card box[52];
Card shuffleTemp[52];
int money;

void createDeck()
{
    string suits;
    int cardCounter = 0;

    for(int i=0; i<4; i++)
    {
        switch (i)
        {
            case 0: suits = "Hearts";
                    for(int j=0; j<13; j++)
                    {
                        Card jonsCards = Card(j+1,suits);
                        cardCounter++;
                        box[cardCounter-1]=jonsCards;
                    }
                    break;
            case 1: suits = "Spades";
                    for(int j=0; j<13; j++)
                    {
                        Card jonsCards = Card(j+1,suits);
                        cardCounter++;
                        box[cardCounter-1]=jonsCards;
                    }
                    break;
            case 2: suits = "Diamonds";
                    for(int j=0; j<13; j++)
                    {
                        Card jonsCards = Card(j+1,suits);
                        cardCounter++;
                        box[cardCounter-1]=jonsCards;
                    }
                    break;
            case 3: suits = "Clubs";
                    for(int j=0; j<13; j++)
                    {
                        Card jonsCards = Card(j+1,suits);
                        cardCounter++;
                        box[cardCounter-1]=jonsCards;
                    }
                    break;
        }
    }

    //PRINTS ALL CARDS IN THE DECK
    /*
    for(int k=0; k<52; k++)
    {
        cout<<box[k].getFace()<< " of "<<box[k].getSuit()<<endl;
    }
    */
}

void shuffleDeck()
{
    //int currentCard=0;
    int randNum1, randNum2;
    //cout<<box[1].getSuit();

    for (int k=0; k<52; k++)
    {
        shuffleTemp[k]=box[k];
    }

    for (int i=0; i<52; i++)
    {
        randNum1 = (rand()+time(0))%52;
        swap(shuffleTemp[i],shuffleTemp[randNum1]);
    }

    for (int g=51; g>=0; g--)
    {
        randNum2 = (rand()+time(0))%52;
        swap(shuffleTemp[g],shuffleTemp[randNum2]);
    }
    //PRINTS ALL CARDS IN THE DECK
    /*
    for (int j=0; j<52; j++)
    {
        cout<<shuffleTemp[j].getFace()<< " of
"<<shuffleTemp[j].getSuit()<<endl;
        //cout<<shuffleTemp[j]<<endl;
    }
    */
}

void sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void changeConsoleColor(int x) // use argument 10 for green text
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}

int calcTotals1(int i, int j)
{
    int cookie;
    if(shuffleTemp[i].getValue()==1)
    {
        cookie= 11+j;
        if(cookie>21)
        {
            return 1+j;
        }
        else
        {
            return cookie;
        }
    }

    else if(shuffleTemp[i].getValue()>=10)
    {
        return 10+j;
    }
    else if(shuffleTemp[i].getValue()<10)
    {
        cookie = shuffleTemp[i].getValue()+j;
        return cookie;
    }
    else
        return 0;
}

void welcomeScreen()
{
    changeConsoleColor(14);
    createDeck();
    shuffleDeck();

    cout<< "Welcome to Jon's BlackJack Game"<< endl<<endl;
        cout<< "INSTRUCIONS::"<<endl<<endl<<endl;
}

void blackJackGame()
{
    changeConsoleColor(15);
    money=100;
    int startingBet;
    string hitStand;
    bool play = true;
    char playAgain;
    bool bust = false;
    int yourTotals, dealerTotals, tempTotals;

    do
    {
        changeConsoleColor(15);

        startingBet=0;
        bust = false;
        yourTotals=0;
        dealerTotals=0;
        playAgain='y';

        cout<< "You have $"<<money;

        while(startingBet<10)
        {
            cout<<"\nWhat is your starting BET? => $";
            cin>>startingBet;
            if(startingBet<10)
            {
                changeConsoleColor(192);
                cout<<"MINIMUM BET = $10\n";
                changeConsoleColor(15);
            }
        }

        changeConsoleColor(240);
        cout<< "\n\nDEALING CARDS NOW";
            for (int i=4; i>0; --i)
            {
                sleep(1000);
                cout<<".";
            }
            cout<< endl << endl;
        changeConsoleColor(15);

        cout<< "DEALER Has =>\n   "<<shuffleTemp[1].getFace()<<" of
"<<shuffleTemp[1].getSuit()<<" , (?)"<<endl;

        for (int i=3; i>0; --i)
        {
            sleep(1000);
            cout<<".";
        }

        cout<< "\n\nYOU Have =>\n   "<<
        shuffleTemp[2].getFace()<<" of "<<shuffleTemp[2].getSuit()<<
        " , "<<shuffleTemp[4].getFace()<<" of
"<<shuffleTemp[4].getSuit()<<endl<<endl;

        for (int i=3; i>0; --i)
        {
            sleep(1000);
            cout<<".";
        }
        cout<<endl<<endl;

            changeConsoleColor(240);
            cout<< "YOUR TURN           \n====================\n   hit or
stand? => ";
            changeConsoleColor(15);
            cin>> hitStand;
            if(hitStand=="hit")
            {
                cout<<"\nYOU NOW HAVE =>\n   "<<
                shuffleTemp[5].getFace()<<" of "<<shuffleTemp[5].getSuit()<<
                " , "<<shuffleTemp[2].getFace()<<" of
"<<shuffleTemp[2].getSuit()<<
                " , "<<shuffleTemp[4].getFace()<<" of
"<<shuffleTemp[4].getSuit()<<endl<<endl;

                cout<< "   hit or stand? => ";
                    cin>> hitStand;
                    if(hitStand=="hit")
                    {
                        cout<<"\nYOU NOW HAVE =>\n   "<<
                        shuffleTemp[6].getFace()<<" of
"<<shuffleTemp[6].getSuit()<<
                        " , "<<shuffleTemp[5].getFace()<<" of
"<<shuffleTemp[5].getSuit()<<
                        " , "<<shuffleTemp[2].getFace()<<" of
"<<shuffleTemp[2].getSuit()<<
                        " , "<<shuffleTemp[4].getFace()<<" of
"<<shuffleTemp[4].getSuit()<<endl<<endl;

                        cout<< "   hit or stand? => ";
                            cin>> hitStand;
                            if(hitStand=="hit")
                            {
                                cout<<"\nYOU NOW HAVE =>\n   "<<
                                shuffleTemp[7].getFace()<<" of
"<<shuffleTemp[7].getSuit()<<
                                " , "<<shuffleTemp[6].getFace()<<" of
"<<shuffleTemp[6].getSuit()<<
                                " , "<<shuffleTemp[5].getFace()<<" of
"<<shuffleTemp[5].getSuit()<<
                                " , "<<shuffleTemp[2].getFace()<<" of
"<<shuffleTemp[2].getSuit()<<
                                " , "<<shuffleTemp[4].getFace()<<" of
"<<shuffleTemp[4].getSuit()<<endl<<endl;
                            }
                            else
                            {
                                tempTotals=calcTotals1(2,0);
                                yourTotals=tempTotals;
                                yourTotals=calcTotals1(4,tempTotals);
                                tempTotals=yourTotals;
                                yourTotals=calcTotals1(5,tempTotals);
                                tempTotals=yourTotals;
                                yourTotals=calcTotals1(6,tempTotals);

                                cout<<"\nYOUR TOTALS WERE: " << yourTotals
<< endl<<endl;
                            }
                    }
                    else
                    {
                        tempTotals=calcTotals1(2,0);
                        yourTotals=tempTotals;
                        yourTotals=calcTotals1(4,tempTotals);
                        tempTotals=yourTotals;
                        yourTotals=calcTotals1(5,tempTotals);

                        cout<<"\nYOUR TOTALS WERE: " << yourTotals <<
endl<<endl;
                    }
            }
            else
            {
                tempTotals=calcTotals1(2,0);
                yourTotals=tempTotals;
                yourTotals=calcTotals1(4,tempTotals);

                cout<<"\nYOUR TOTALS WERE: " << yourTotals << endl<<endl;
            }
            //calc totals and see whose hand is better

        for (int i=3; i>0; --i)
        {
            sleep(1000);
            cout<<".";
        }

        changeConsoleColor(240);
        cout<< "\n\nDEALER'S TURN\n=============\n";
        changeConsoleColor(15);
        cout<<"DEALER HAS =>\n   "<<
        shuffleTemp[1].getFace()<<" of "<<shuffleTemp[1].getSuit()<<
        " , "<<shuffleTemp[3].getFace()<<" of
"<<shuffleTemp[3].getSuit()<<endl<<endl;

        tempTotals=calcTotals1(1,0);
        dealerTotals=tempTotals;
        dealerTotals=calcTotals1(3,tempTotals);

        for (int i=3; i>0; --i)
        {
            sleep(1000);
            cout<<".";
        }
        cout<<endl<<endl;

        if(dealerTotals<17)
        {
            cout<< "   Dealer decided to hit\n";

            cout<<"DEALER NOW HAS =>\n   "<<
            shuffleTemp[7].getFace()<<" of "<<shuffleTemp[7].getSuit()<<
            " , "<<shuffleTemp[1].getFace()<<" of
"<<shuffleTemp[1].getSuit()<<
            " , "<<shuffleTemp[3].getFace()<<" of
"<<shuffleTemp[3].getSuit()<<endl<<endl;

            tempTotals=dealerTotals;
            dealerTotals=calcTotals1(7,tempTotals);

            for (int i=3; i>0; --i)
            {
                sleep(1000);
                cout<<".";
            }
            cout<<endl<<endl;

            if(dealerTotals<17)
            {
                cout<< "   Dealer decided to hit\n";

                cout<<"DEALER NOW HAS =>\n   "<<
                shuffleTemp[8].getFace()<<" of "<<shuffleTemp[8].getSuit()<<
                " , "<<shuffleTemp[7].getFace()<<" of
"<<shuffleTemp[7].getSuit()<<
                " , "<<shuffleTemp[1].getFace()<<" of
"<<shuffleTemp[1].getSuit()<<
                " , "<<shuffleTemp[3].getFace()<<" of
"<<shuffleTemp[3].getSuit()<<endl<<endl;

                tempTotals=dealerTotals;
                dealerTotals=calcTotals1(8,tempTotals);
            }
            else
            {
                cout<<endl<<endl;
                cout<< "   Dealer decided to stand\n";
            }

        }
        else
        {
            cout<< "   Dealer decided to stand\n";
        }

        cout<<"DEALER'S TOTALS WERE: " << dealerTotals << endl<<endl;

        cout<<"Working out the numbers right now";
        for (int i=3; i>0; --i)
        {
            sleep(1000);
            cout<<".";
        }
        cout<<endl<<endl;

        changeConsoleColor(240);
        if(dealerTotals==yourTotals)
        {
            cout<<"DRAW...No money lost. $0";
        }
        else if((dealerTotals>yourTotals)&&(dealerTotals<=21))
        {
            cout<<"DEALER WINS. You lose $"<< startingBet<<endl;
            money-=startingBet;
            cout<<"You have $"<<money<<" remaining.\n\n";
        }
        else if((dealerTotals<yourTotals)&&(yourTotals<=21))
        {
            cout<<"YOU WIN! You get $"<<startingBet<<endl;
            money+=startingBet;
            cout<<"You have $"<<money<<" remaining.\n\n";
        }

        if(money<=0)
        {
            cout<<"You're out of funds... Better luck next time.";
            exit;
        }

        cout<< "\n\nDo you want to PLAY AGAIN (y/n)? => ";
        cin>>playAgain;

        if(playAgain=='n')
        {
            play=false;
        }
        cout<<endl<<endl<<endl;
    }
    while(play==true);

}

int main()
{
    welcomeScreen();
    blackJackGame();
    return 0;
}
