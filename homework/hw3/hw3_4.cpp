#include <iostream>
#include <vector>
#include <iterator>
using namespace std;


struct Node {
    string value;

    string speak() {
        cout << value << endl;
        return receiveFeedback();
    };

    string receiveFeedback() {
        string res = "";
        while (res != "y" && res != "n") {
            cout << "Please enter y or n" << endl;
            getline(cin, res);
        }
        return res;
    };
};


struct Answer : public Node {
    Answer(string str) {value = "Is it a " + str;};
};

struct Question : public Node {
    Question(string str, Answer ans) : answer(ans) {value = str;};
    Answer answer;
};



struct Questioner {
    Questioner(Question initQuestion, Answer defaultAns) : defaultAnswer(defaultAns) {questions = {initQuestion};};
    Answer defaultAnswer;
    vector<Question> questions;

    Answer getCorrectAnswer(){
        string newAnswer;
        cout << "What was the correct answer?" << endl;
        getline(cin, newAnswer);
        return Answer(newAnswer);
    }

    Question getNewQuestion(Answer newAnswer) {
        string newQuestion;
        cout << "What is a question where this animal is the correct answer?" << endl;
        getline(cin, newQuestion);
        return Question(newQuestion, newAnswer);
    }

    void restart() {
        questions.erase(questions.begin()+1, questions.end());
    }

    string askToPlayAgain(string msg) {
        cout << msg << endl;
        string res = "";
        while (res != "y" && res != "n" && res !="r") {
            cout << "Type y, n, or r to restart game" << endl;
            getline(cin, res);
        }

        if (res == "r") {
            restart();
            return "y";
        }

        return res;
    }

    void addNewQuestion() {
        Answer newAns = getCorrectAnswer();
        Question newQuestion = getNewQuestion(newAns);
        questions.push_back(newQuestion);
    }

    void play() {
        string continuePlaying = "y";
        while (continuePlaying == "y") {
            string msg = "Player Wins!\nPlay again?";
            string res = "n";
            for (int i = questions.size() - 1; i >= 0; i--) {
                res = questions[i].speak();
                if (res == "y") {
                    string secondRes = questions[i].answer.speak();
                    if (secondRes == "y") {
                        msg = "Computer Wins \nPlay again?";
                        break;
                    } else {
                        addNewQuestion();
                        break;
                    }
                }
            }

            if (res == "n") {
                string defaultRes = defaultAnswer.speak();
                if (defaultRes == "y") {
                    msg = "Computer Wins \nPlay again?";
                } else {
                    addNewQuestion();
                }
            }


            continuePlaying = askToPlayAgain(msg);
        }

        cout << "Thanks for playing!" << endl;
    };
};


int main() {

    Answer bird("bird");
    Answer dog("dog");

    Question firstQuestion("Does it fly?", bird);

    Questioner questioner(firstQuestion, dog);
    questioner.play();

    return 0;
}
