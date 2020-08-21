#include <iostream>

using namespace std;

struct Specialization {
    string value;

    explicit Specialization(const string& value) {
        this->value = value;
    }
};

struct Course {
    string value;

    explicit Course(const string& value) {
        this->value = value;
    }
};

struct Week {
    string value;

    explicit Week(const string& value) {
        this->value = value;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle(const Specialization& spec, const Course& course, const Week& week) {
        this->specialization = spec.value;
        this->course = course.value;
        this->week = week.value;
    }
};

int main() {
    //Should work
    LectureTitle title(Specialization("C++"),Course("White belt"),Week("4th"));


    //Shouldn't work

//    LectureTitle title("C++", "White belt", "4th");
//
//    LectureTitle title(string("C++"), string("White belt"), string("4th"));
//
//    LectureTitle title = {"C++", "White belt", "4th"};
//
//    LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};
//
//    LectureTitle title(
//            Course("White belt"),
//            Specialization("C++"),
//            Week("4th")
//    );
//
//    LectureTitle title(
//            Specialization("C++"),
//            Week("4th"),
//            Course("White belt")
//    );

    return 0;
}
