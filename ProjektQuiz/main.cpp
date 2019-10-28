#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
//#include <gtk/gtk.h>

using namespace std;

string upper(string s);

bool sameString(string s1, string s2);

string upper(string s){
    string conv;
    for(short i = 0; i<s.length();i++)
        conv += toupper(s[i]);
    
    return conv;
    
}

bool sameString(string s1, string s2){
    bool same = true;
    if(s1.length() == s2.length()){
        for(int i = 0; i < s1.length(); i++){
            if(s1[i] != s2[i]){
                same = false;
            }
        }
    }else{
        same = false;
    }
    
    return same;
}

string guess; //Answer user inputs for question.
int total;  //Total score.


class Question {
public:
    void setValues(std::string, std::string, std::string, std::string, std::string, std::string);
    void askQuestion();
    
private:
    string Question_Text;
    string answer_1;
    string answer_2;
    string answer_3;
    string answer_4;
    
    string correct_answer;
}; //endQuestion

std::vector<std::string> split(std::string strToSplit, char delimeter)
{
    std::stringstream ss(strToSplit);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (std::getline(ss, item, delimeter))
    {
        splittedStrings.push_back(item);
    }
    return splittedStrings;
}


int main()
{
    
    fstream newfile;
    /*
    newfile.open("/Users/marcinrosol/documents/c++/projektquiz/questions.txt",ios::out);  // open a file to perform write operation using file object
    
    if(newfile.is_open())     //checking whether the file is open
    {
        newfile<<"Tutorials point \n"; //inserting text
        newfile.close(); //close the file object
    }
     */
    
    newfile.open("/Users/marcinrosol/documents/c++/projektquiz/questions.txt",ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){   //checking whether the file is open
        string line;
        while(getline(newfile, line)){  //read data from file object and put it into string.
            string text = "Let;me;split;this;into;words;elo;dwa;";
            
            // 7 bo mamy 7 pol w obiekcie
            // mapujemy na obiekt i dodajemy do naszej super elo bazy x  D  d  D
            // a
            std::vector<std::string> splittedStrings = split(text, ';');
            
            if(splittedStrings.size() == 7){
                cout<<splittedStrings[0]<<endl;
                cout<<splittedStrings[1]<<endl;
                cout<<splittedStrings[2]<<endl;
                cout<<splittedStrings[3]<<endl;
                cout<<splittedStrings[4]<<endl;
                cout<<splittedStrings[5]<<endl;
                cout<<splittedStrings[6]<<endl;
                cout<<7<<endl;
            }else{
                cout<<"Longer";
            }
            
            //for(int i = 0; i < splittedStrings.size() ; i++){
               // std::cout<<splittedStrings[i]<<std::endl;
           // }
            splittedStrings.clear();

            cout << line << "\n";   //print the data of the string
        }
        newfile.close();   //close the file object.
    }
    
    string name;
    
    std::vector<Question> questions;
    
    
    // db end
    
    cout << "Press enter to start...\n";
    cin.get();
    
    //imie
    
    cout << "What's your name?\n";
    cin >> name;
    cout << "\n";
    
    
    
    //Ask if user want to add some question to database
    string respond;
    
    while (respond == "") {
        cout<<"\nPick one option:\n a: start game \n b:quit game \n c: create new questions ";
        cin>>respond;
        if(respond == "A" || (respond == "a")){
            cout << "\n";
            cout << "Good luck!\n";
            cout << "\n";
            cout << "Press enter to continue.";
            cin.get();
            cin.ignore();
        }else
            if(respond == "B" || (respond == "b")){
                cout << "\n";
                cout << "Goodbye!\n";
                cin.ignore();
                cin.get();
                return 0;
            }else
                if(respond == "C" || (respond == "c")){
                    string newQText;
                    string newQanswer_1;
                    string newQanswer_2;
                    string newQanswer_3;
                    string newQanswer_4;
                    string newQcorrect_answer;
                    cout<<"Question text: ";
                    cin>>newQText;
                    cout<<"First answer: ";
                    cin>>newQanswer_1;
                    cout<<"Second answer: ";
                    cin>>newQanswer_2;
                    cout<<"Third answer: ";
                    cin>>newQanswer_3;
                    cout<<"Fourth answer: ";
                    cin>>newQanswer_4;
                    cout<<"Correct answer, pick a, b, c or d: ";
                    cin>>newQcorrect_answer;
                    Question newQ;
                    
                    newQ.setValues(newQText,
                                   newQanswer_1,
                                   newQanswer_2,
                                   newQanswer_3,
                                   newQanswer_4,
                                   newQcorrect_answer);
                    
                    questions.push_back(newQ);
                    // dodac do bazy danych i nastepnie pobrac do vektora questions od nowa baze danych, ale to po rozpoczaciu gry
                    
                    respond = "";
                }else{
                    respond = "";
                    cout<<"Wrong type\n";
                }
    }
   
    Question q1;
    
    
    
    q1.setValues("1. What command prints something to the screen?",
                 "cin",
                 "cout",
                 "char",
                 "print",
                 "b");
    
    questions.push_back(q1);
    
    
    
    
    for (auto& q : questions) {
        q.askQuestion();
    }
    
    
    cout << "Your Total Score is ";
    cout << "\n";
    
    
    if (total > 1) {
        cout <<"test1"<< "\n";
        // tutaj dodac fajny cos ze woow wygrales tu masz punkty, i tabelka jakies inne rzeczy takie o
        cin.get();
        cin.ignore();
        return 0;
    }
    else
    {
        cout << "You failed... Sorry, better luck next time.\n";
        // dodac tabelke wynikow i takie rzeczy o
        cout << "\n";
    }
    cin.get();
    cin.ignore();
    return 0;
}


void Question::setValues(std::string q, std::string a1, std::string a2, std::string a3, std::string a4, std::string ca)
{
    Question_Text = q;
    answer_1 = a1;
    answer_2 = a2;
    answer_3 = a3;
    answer_4 = a4;
    correct_answer = ca;
}

void Question::askQuestion()
{
    cout << "\n";
    cout << Question_Text << "\n";
    cout << "a. " << answer_1 << "\n";
    cout << "b. " << answer_2 << "\n";
    cout << "c. " << answer_3 << "\n";
    cout << "d. " << answer_4 << "\n";
    cout << "\n";
    
    
    cout << "What is your answer?" << "\n";
    cin >> guess;
    //jezeli poprawnie odpowiedzial dostaje punkciki
    if(sameString(guess, correct_answer) == true) {
        cout << "\n";
        cout << "Correct!" << "\n";
        total += 1; //dodaje 1 do wyniku
        cout << "\n";
        cout << "Press enter to continue." << "\n";
        cin.get();
        cin.ignore();
    }
    else {
        //jezeli sie pomyli nie dodaje nic, odejmuje mu zycia
        //wyswietlanie poprawnej odpowiedzi
        
        //zycia -= 1;
        
        cout << "\n";
        cout << "Sorry, you're wrong..." << "\n";
        cout << "The correct answer is " << correct_answer << "." << "\n";
        cout << "\n";
        cout << "Press enter to continue." << "\n";
        cin.get();
        cin.ignore();
    }
}


