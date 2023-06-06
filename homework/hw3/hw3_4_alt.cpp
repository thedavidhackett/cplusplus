#include <iostream>
#include <vector>
#include <iterator>
using namespace std;



struct Node {
    virtual string speak() =0;
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
    Answer(string str) {value = str;};
    string value;
    string getCorrectAnswer(){
        string newAnswer;
        cout << "What was the correct answer?" << endl;
        getline(cin, newAnswer);
        return newAnswer;
    }

    string speak() {
        cout << "Is it a " + value << endl;
        string res = receiveFeedback();
        if (res == "n") {
            return getCorrectAnswer();
        } else {
            return res;
        }
    }

};

struct Question : public Node {
    Question(string str) {value = str;};
    Node * yes;
    Node * no;
    string value;
    string getNewQuestion() {
        string newQuestion;
        cout << "What is a question where this animal is the correct answer?" << endl;
        getline(cin, newQuestion);
        return newQuestion;
    }

    string speak(){
        cout << value << endl;
        string res = receiveFeedback();
        string next;
        if (res == "y") {
            next = yes.speak();
        } else {
            next = no.speak();
        };

        if (next.length() > 1) {
            string newText = getNewQuestion();
            Answer newAnswer = Answer(next);
            Node &newAnswerNode = newAnswer;
            if (res == "y") {
                // Question );
                // Node &newQuestionNode = newQuestion;
                yes &Question(newText, newAnswerNode, yes);
            } else {
                Question newQuestion(newText, newAnswerNode, no);
                Node &newQuestionNode = newQuestion;
                no = newQuestionNode;
            }

            return "n";
        }

        return next;
    }
};



struct Questioner {
    Questioner(Question initQuestion) : startingQuestion(initQuestion){};
    Question startingQuestion;
    void play() {
        string continuePlaying = "y";
        while (continuePlaying == "y") {
            string res = startingQuestion.speak();
            if (res == "y") {
                cout << "Computer Wins \n Play again?" << endl;
            } else {
                cout << "Player Wins \n Play again?" << endl;
            }

            continuePlaying = startingQuestion.receiveFeedback();
        }

        cout << "Thanks for playing!" << endl;
    };
};


struct BaseTest {
    string msg;
    void testFunc() {
        cout << msg << endl;
    };
};

struct Test : public BaseTest {
    Test(string initmsg) {msg = initmsg;};
};

int main() {

    Answer yes("bird");
    Answer no("dog");

    Node &yesNode = yes;
    Node &noNode = no;
    Question firstQuestion("Does it fly?", yesNode, noNode);

    Questioner questioner(firstQuestion);
    questioner.play();

    return 0;
}
