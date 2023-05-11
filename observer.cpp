
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
        /* vector of all event that can happend */
        vector<Event*> Events;
        /* Commad is what to doing */
        string _Command;

    public:
        /* This function add event to vector */
        Status* attach(Event* Event) {
            static Status status;
            status.SetMessage(Status::Message::Fault);

            Events.push_back(Event);
            status.SetMessage(Status::Message::Success);

            return &status;
        }

        /* This function rub all events from vectors */
        Status* Handle() {
            static Status status;
            status.SetMessage(Status::Message::Fault);

            for (Event* Event : Events) {
                Event->Handle(this);
            }

            status.SetMessage(Status::Message::Success);

            return &status;
        }

        /* This function set commad and the run handle function */
        Status* Execute(string Command) {
            static Status status;
            status.SetMessage(Status::Message::Fault);

            this->_Command = Command;
            Handle();
            status.SetMessage(Status::Message::Success);

            return &status;
        }

        /* This function use events */
        string getCommand() {
            return _Command;
        }
};

/*--------------------------------------------------------------------------------------------------------------------*/
/* This class for analize one */
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
/* This class for analize two */
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
/* This class for analize three */
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

    /* This for handle all event process  */
    Process process;

    /* First event */
    Event_1 event_1;
    /* Second event */
    Event_2 event_2;
    /* Third event */
    Event_3 event_3;

    /* Add first event */
    status = process.attach(&event_1);
    /* Add second event */
    status = process.attach(&event_2);
    /* Add third event */
    status = process.attach(&event_3);

    /* Now execute all event with command '123456' */
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
