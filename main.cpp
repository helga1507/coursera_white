#include <iostream>
#include <system_error>

using namespace std;

string AskTimeServer() {
    throw system_error(error_code());
    throw exception();
    return "00:20:45";
}

class TimeServer {
public:
    string GetCurrentTime() {
        try {
            this->last_fetched_time = AskTimeServer();
        } catch (system_error& e) {}

        return this->last_fetched_time;
    };
private:
    string last_fetched_time = "00:00:00";
};

int main() {
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
