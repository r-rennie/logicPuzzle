#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Boy {
    string name;
    int age;
    string shirtColor;
    string movieGenre;
    string snack;
};

bool checkConstraints(const vector<Boy> boys);

int main() {
    vector<Boy> boys(4);
    bool complete = false;
    string name;

    cout << "Hello! What's your name?" << endl;
    cin >> name;
    cout << "Hello, " + name << endl;
    // for (int i = 0; i < 4; i++) {
    //     cout << "Name: ";
    //     cin >> boys[i].name;

    //     cout << "Age: ";
    //     cin >> boys[i].age;

    //     cout << "Shirt Color: ";
    //     cin >> boys[i].shirtColor;

    //     cout << "Favorite Movie Genre: ";
    //     cin >> boys[i].movieGenre;

    //     cout << "Favorite Snack: ";
    //     cin >> boys[i].snack;

    //     cout << endl;
    // }
    
    // if (checkConstraints(boys)) {
    //     cout << "Valid solution. Congratulations!" << endl;
    //     complete = true;
    // } else {
    //     cout << "Incorrect. Try again!" << endl;
    // }


    return 0;
}

bool checkConstraints(const vector<Boy> boys) {
    // 1. Joshua is at one of the ends.
    if (boys[0].name != "Joshua" && boys[3].name != "Joshua") {
        cout << "Error in Step 1." << endl;
        return false;
    }

    // 2. The boy wearing the black shirt is somewhere to the left of the youngest boy.
    int youngestPos = 0;
    int blackShirtPos = -1;
    for (int i = 0; i < 4; i++) {
        if (boys[i].age < boys[youngestPos].age) {
            youngestPos = i;
        }
        if (boys[i].shirtColor == "Black") {
            blackShirtPos = i;
        }
    }
    if (!(blackShirtPos < youngestPos)) {
        cout << "Error in Step 2." << endl;
        return false;
    }

    // 3. Joshua likes Horror movies.
    for (int i = 0; i < 4; i++) {
        if (boys[i].name == "Joshua" && boys[i].movieGenre != "Horror") {
            cout << "Error in Step 3." << endl;
            return false;
        }
    }

    // 4. The 14-year-old boy is at the third position.
    if (boys[2].age != 14) {
        cout << "Error in Step 4." << endl;
        return false;
    }

    // 5. The boy wearing the Red shirt is somewhere between the 13-year-old boy and the
    //    one who likes Action movies, in that order
    int redShirtPos = -1;
    int age13Pos = 0;
    int actionFanPos = -1;
    for (int i = 0; i < 4; i++) {
        if (boys[i].shirtColor == "Red") {
            redShirtPos = i;
        }
        if (boys[i].age == 13) {
            age13Pos = i;
        }
        if (boys[i].movieGenre == "Action") {
            actionFanPos = i;
        }
    }
    if (!(redShirtPos > age13Pos) && !(redShirtPos < actionFanPos)) {
        cout << "Error in Step 5." << endl;
        return false;
    }

    // 6. Daniel likes Thriller movies.
    for (int i = 0; i < 4; i++) {
        if (boys[i].name == "Daniel" && boys[i].movieGenre != "Thriller") {
            cout << "Error in Step 6." << endl;
            return false;
        }
    }

    // 7. The boy who is going to eat cookies is at one of the ends.
    if (boys[0].snack != "Cookies" && boys[3].snack != "Cookies") {
        cout << "Error in Step 7." << endl;
        return false;
    }

    // 8. The boy wearing the Black shirt is exactly to the left of the one who likes
    //    Thriller movies
    for (int i = 0; i < 4; i++) {
        if (boys[i].shirtColor == "Black" && boys[i + 1].movieGenre != "Thriller") {
            cout << "Error in Step 8." << endl;
            return false;
        }
    }

    // 9. The boy who is going to eat Crackers is exactly to the right of the boy who
    //    likes Comedy movies
    for (int i = 0; i < 4; i++) {
        if (boys[i].snack == "Crackers" && boys[i - 1].movieGenre != "Comedy") {
            cout << "Error in Step 9." << endl;
            return false;
        }
    }

    // 10. The boy wearing the Red shirt is somewhere between the boy who is going to
    //     eat popcorn and Nicholas, in that order.
    redShirtPos = -1;
    int popcornFanPos = -1;
    int nicholasPos = -1;
    for (int i = 0; i < 4; i++) {
        if (boys[i].shirtColor == "Red") {
            redShirtPos = i;
        }
        if (boys[i].snack == "Popcorn") {
            popcornFanPos = i;
        }
        if (boys[i].name == "Nicholas") {
            nicholasPos = i;
        }
    }
    if (!(redShirtPos > popcornFanPos) && !(redShirtPos < nicholasPos)) {
        cout << "Error in Step 10." << endl;
        return false;
    }

    // 11. At one of the ends is the boy who likes Thriller movies.
    if (boys[0].movieGenre != "Thriller" && boys[3].movieGenre != "Thriller") {
        cout << "Error in Step 11." << endl;
        return false;
    }

    // 12. Nicholas is somewhere between Joshua and Daniel, in that order.
    nicholasPos = -1;
    int joshuaPos = -1;
    int danielPos = -1;
    for (int i = 0; i < 4; i++) {
        if (boys[i].name == "Nicholas") {
            nicholasPos = i;
        }
        if (boys[i].name == "Joshua") {
            joshuaPos = i;
        }
        if (boys[i].name == "Daniel") {
            danielPos = i;
        }
    }
    if (!(nicholasPos > joshuaPos) && !(nicholasPos < danielPos)) {
        cout << "Error in Step 12." << endl;
        return false;
    }

    // 13. At the first position is the boy wearing the green shirt.
    if (boys[0].shirtColor != "Green") {
        cout << "Error in Step 13." << endl;
        return false;
    }

    // TODO: Check that none of the fields are the same


    return true;
}