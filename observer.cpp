
/************************************************** Description *******************************************************/
/*
    File : observer.cpp
    Programmer : Mohammad Lotfi
    Used : Sample used observer
    Design Pattern : Observer
    Types of memory : Heap & Stack
    Total Tread : Nothing
    Site : https://www.mahsen.ir
    Tel : +989124662703
    Email : info@mahsen.ir
    Last Update : 2023/5/11
*/
/************************************************** Warnings **********************************************************/
/*
    Only for learning
*/
/************************************************** Wizards ***********************************************************/
/*
    Nothing
*/
/************************************************** Includes **********************************************************/
/* Include standard input-output stream head */
#include "iostream"
/* Vector of everything head */
#include "vector"
/************************************************** Defineds **********************************************************/
/*
    Nothing
*/
/************************************************** Names *************************************************************/
/* Using std */
using namespace std;
/************************************************** Variables *********************************************************/
/*
    Nothing
*/
/************************************************** Opjects ***********************************************************/
/* All object to return their status need this object */
class Status {

    public:

        /* All possible messages */
        enum class Message {
            Success,
            Fault,
            Fault_Media
        };

        /* Set current message from outside */
        void SetMessage(Message _Message) {
            this->_Message = _Message;
        }

        /* Set current message */
        Message GetMessage() {
            return _Message;
        }

        /* Show current message on console */
        void ShowMessage() {
            cout << "Message : " << Message2String[(int)this->_Message] << endl;
        }

    private:

        /* All message explanations */
        const string Message2String[3] = {"Success", "Fault", "Fault_Media"};

        /* The variable holding the current message */
        Message _Message;
};
/*--------------------------------------------------------------------------------------------------------------------*/
class Process;
/* Event represents of a job with handle function */
class Event {
    public: virtual Status* Handle(Process *_Process) const = 0;
};
/*--------------------------------------------------------------------------------------------------------------------*/
class Process {
    private:
        vector<Event*> Events;
        string _Command;

    public:
        Status* attach(Event* Event) {
            static Status status;
            status.SetMessage(Status::Message::Fault);

            Events.push_back(Event);
            status.SetMessage(Status::Message::Success);

            return &status;
        }
        Status* Handle() {
            static Status status;
            status.SetMessage(Status::Message::Fault);

            for (Event* Event : Events) {
                Event->Handle(this);
            }

            status.SetMessage(Status::Message::Success);

            return &status;
        }
        Status* Execute(string Command) {
            static Status status;
            status.SetMessage(Status::Message::Fault);

            this->_Command = Command;
            Handle();
            status.SetMessage(Status::Message::Success);

            return &status;
        }
        string getCommand() {
            return _Command;
        }
};

/*--------------------------------------------------------------------------------------------------------------------*/
class Event_1 : public Event {
    public:
        Status* Handle(Process *_Process) const override {
            static Status status;
            status.SetMessage(Status::Message::Fault);

            std::cout << "Event 1 : " << _Process->getCommand() << std::endl;
            status.SetMessage(Status::Message::Success);

            return &status;
        }
};

/*--------------------------------------------------------------------------------------------------------------------*/
class Event_2 : public Event {
    public:
        Status* Handle(Process *_Process) const override {
            static Status status;
            status.SetMessage(Status::Message::Fault);

            std::cout << "Event 2 : " << _Process->getCommand() << std::endl;
            status.SetMessage(Status::Message::Success);

            return &status;            
        }
};

/*--------------------------------------------------------------------------------------------------------------------*/
class Event_3 : public Event {
    public:
        Status* Handle(Process *_Process) const override {
            static Status status;
            status.SetMessage(Status::Message::Fault);

            std::cout << "Event 3 : " << _Process->getCommand() << std::endl;
            status.SetMessage(Status::Message::Success);

            return &status;
        }
};
/************************************************** Functions *********************************************************/
/* The main function start of program in cpp language */
int main() {
    
    /* For translation of return values */
    Status *status;

    Process process;

    Event_1 event_1;
    Event_2 event_2;
    Event_3 event_3;

    status = process.attach(&event_1);
    status = process.attach(&event_2);
    status = process.attach(&event_3);

    status = process.Execute("123456");

    /* Return successful*/
    return 0;
}
/************************************************** Tasks *************************************************************/
/*
    Nothing
*/
/************************************************** Vectors ***********************************************************/
/*
    Nothing
*/
/**********************************************************************************************************************/
