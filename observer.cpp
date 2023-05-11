#include "iostream"
#include "vector"

using namespace std;

class Process;

class Event {
    public: virtual void Handle(Process *_Process) const = 0;
};

class Process {
    private:
        vector<Event*> Events;
        string _Command;

    public:
        void attach(Event* Event) {
            Events.push_back(Event);
        }
        void Handle() {
            for (Event* Event : Events) {
                Event->Handle(this);
            }
        }
        void Execute(string Command) {
            this->_Command = Command;
            Handle();
        }
        string getCommand() {
            return _Command;
        }
};

class Event_1 : public Event {
    public:
        void Handle(Process *_Process) const override {
            std::cout << "Event 1 : " << _Process->getCommand() << std::endl;
        }
};

class Event_2 : public Event {
    public:
        void Handle(Process *_Process) const override {
            std::cout << "Event 2 : " << _Process->getCommand() << std::endl;
        }
};

class Event_3 : public Event {
    public:
        void Handle(Process *_Process) const override {
            std::cout << "Event 3 : " << _Process->getCommand() << std::endl;
        }
};

int main() {

    Process process;

    Event_1 event_1;
    Event_2 event_2;
    Event_3 event_3;

    process.attach(&event_1);
    process.attach(&event_2);
    process.attach(&event_3);

    process.Execute("123456");

    return 0;
}