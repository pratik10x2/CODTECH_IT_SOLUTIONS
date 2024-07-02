#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Question {
    string questionText;
    vector<string> options;
    int correctOption;
};

void askQuestion(const Question& question, int& score) {
    cout << question.questionText << endl;
    for (int i = 0; i < question.options.size(); ++i) {
        cout << i + 1 << ". " << question.options[i] << endl;
    }

    int userAnswer;
    cout << "Your answer: ";
    cin >> userAnswer;

    if (userAnswer - 1 == question.correctOption) {
        cout << "Correct!" << endl;
        ++score;
    } else {
        cout << "Wrong! The correct answer was: " << question.options[question.correctOption] << endl;
    }
    cout << endl;
}

int main() {
    vector<Question> questions = {
        {
            "What is the capital of France?",
            {"Berlin", "Madrid", "Paris", "Rome"},
            2
        },
        {
            "Which planet is known as the Red Planet?",
            {"Earth", "Mars", "Jupiter", "Venus"},
            1
        },
        {
            "Who wrote 'To Kill a Mockingbird'?",
            {"Harper Lee", "Mark Twain", "Ernest Hemingway", "F. Scott Fitzgerald"},
            0
        }
    };

    int score = 0;

    cout << "Welcome to the Quiz Game!" << endl << endl;

    for (const auto& question : questions) {
        askQuestion(question, score);
    }

    cout << "Your final score is: " << score << " out of " << questions.size() << endl;

    return 0;
}
