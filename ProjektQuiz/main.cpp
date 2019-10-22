#include <iostream>
#include <string>
#include <vector>
#include <sqlite3.h>
//#include <gtk/gtk.h>

using namespace std;

char guess; //Answer user inputs for question.
int total;  //Total score.


class Question {
public:
    void setValues(std::string, std::string, std::string, std::string, std::string, char);
    void askQuestion();
    
private:
    string Question_Text;
    string answer_1;
    string answer_2;
    string answer_3;
    string answer_4;
    
    char correct_answer;
};

int main()
{
    string name;
    
    std::vector<Question> questions;
    //db start
    sqlite3 *db;
    int rc;
    
    rc = sqlite3_open("test.db", &db);
    if(rc){
        cout<<"error while opening db :( "<<sqlite3_errmsg(db)<<endl;
    }else{
        cout<<"opened db sucess"<<endl;
    }
    sqlite3_close(db);
    
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
            char newQcorrect_answer;
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
    
    //Ask if user wants to start quiz.
   // cout << "Are you ready to start the quiz, " << name << "? Yes/No.\n";
    //cin >> respond;
  /*
    //If user says yes, the quiz begins.
    if (respond == "Yes" || respond == "yes") {
        cout << "\n";
        cout << "Good luck!\n";
        cout << "\n";
        cout << "Press enter to continue.";
        cin.get();
        cin.ignore();
    }
    else {
        cout << "\n";
        cout << "Goodbye!\n";
        cin.ignore();
        cin.get();
        return 0;
    }
    
    */
    
    
    
    Question q1;
    
    
    
    q1.setValues("1. What command prints something to the screen?",
                 "cin",
                 "cout",
                 "char",
                 "print",
                 'b');
    
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


void Question::setValues(std::string q, std::string a1, std::string a2, std::string a3, std::string a4, char ca)
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
    if (guess == correct_answer) {
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
