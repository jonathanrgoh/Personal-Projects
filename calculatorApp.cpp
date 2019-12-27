#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

// Driver code
void sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void changeConsoleColor(int x) // use argument 10 for green text
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}

int main()
{
    //string str1 = "1: 2 3 4 prakhar";
    string str2;
    int splitter;
    string number1, number2;
    double num1,num2;
    char operators;
    bool on = true;
    bool correctSyntax = true;
    int counter=0;
    int operatorsCount;

    changeConsoleColor(224);
    cout<< "TURNING ON ";
        for (int i=3; i>0; --i)
        {
            sleep(500);
            cout<<".";
        }

    cout<< endl << endl;

    changeConsoleColor(14);
    cout<<"Welcome to the CALCULATOR!\n" << "       Made by Jon\n       7/28/19\n\n";


    cout<<"INSTRUCTIONS::\n    1. Do not add spaces\n    2. Do not add an equals sign\n    3. The expression should be on one line\n    4. Press ENTER to calculate\n    5. Type \'exit\' to end the program\n\n";
    cout<<"EXAMPLE::\n    Acceptable Expression: 170*23\n    Acceptable Operators: + - * /\n    Acceptable Comparisons: = < >\n\n\n";

    do
    {
        changeConsoleColor(15);
        counter++;
        cout<<"#" <<counter;

        operatorsCount=0;
        correctSyntax=true;
        str2="";
        splitter=-15;

        cout<<" ENTER THE CALCULATION => ";

        changeConsoleColor(11);
        cin>>str2;

        if(str2=="exit")
        {
            changeConsoleColor(207);
            cout<<"\n\n\nGOODBYE ";
            for (int i=3; i>0; --i)
            {
                sleep(1000);
                cout<<i<<" ";
            }

            cout<<"!POOF!";
            sleep(1000);
            return 0;
        }
        for(int i=0; i<str2.length(); i++)
        {
            if(str2[i]=='+'||str2[i]=='-'||str2[i]=='*'||str2[i]=='/'||str2[i]=='='||str2[i]=='<'||str2[i]=='>')
            {
                splitter=i;
                operators=str2[i];
                operatorsCount++;

            }
            else if(!isdigit(str2[i]))
            {
                if(str2[i]!='.')
                {
                    correctSyntax =false;
                }
            }
        }

        if(correctSyntax==false||splitter==-15||operatorsCount>1)
        {
            changeConsoleColor(12);
            cout<< "\n?????????????????????????????\n? SYNTAX ERROR... TRY AGAIN ?\n?????????????????????????????\n\n";
        }

        if(correctSyntax==true&&splitter!=-15&&operatorsCount<=1)
        {
            changeConsoleColor(15);
            number1=str2.substr(0,splitter);
            number2=str2.substr(splitter+1,str2.length());
            //cout<<number1<<endl<<number2;

            char *err1, *err2;
            num1=strtod(number1.c_str(), &err1);
            num2=strtod(number2.c_str(), &err2);

            switch (operators)
            {
                case '*': cout<<"   ="<<num1*num2<<endl<<endl;
                    break;
                case '/': cout<<"   ="<<num1/num2<<endl<<endl;
                    break;
                case '+': cout<<"   ="<<num1+num2<<endl<<endl;
                    break;
                case '-': cout<<"   ="<<num1-num2<<endl<<endl;
                    break;
                case '=': cout<<"   =";
                    if(num1==num2)
                        cout<<"True"<<endl<<endl;
                    else
                        cout<<"False"<<endl<<endl;
                    break;
                case '<': cout<<"   =";
                    if(num1<num2)
                        cout<<"True"<<endl<<endl;
                    else
                        cout<<"False"<<endl<<endl;
                    break;
                case '>': cout<<"   =";
                    if(num1>num2)
                        cout<<"True"<<endl<<endl;
                    else
                        cout<<"False"<<endl<<endl;
                    break;
            }
        }
    }
    while(on==true);

    return 0;
}
