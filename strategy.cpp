
/************************************************** Description *******************************************************/
/*
    File : strategy.cpp
    Programmer : Mohammad Lotfi
    Used : Sample send or receive data to from any media
    Design Pattern : Strategy & Singleton
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
/* Media is interface with virtual functions to use other media for example (UART,LAN,RS485,USB,...) and all things that follows this structure */
class Media {    
    public: 
        /* This function for send data*/
        virtual Status* Send(string Message, uint32_t Length) = 0;
        /* This function for receive data*/
        virtual Status* Receive(string *Message, uint32_t *Length) = 0;
};
/*--------------------------------------------------------------------------------------------------------------------*/
/* Sample of media to useing RS485 (the RS485 is media with specific voltage levels used in industry) */
class RS485 : public Media {    
    private: 

        /* Instance for single use */
        static RS485 *Instance;
        private: RS485() {};

    public: 
        static RS485 *getInstance() {
            if(Instance == nullptr) {
                Instance = new RS485();
            }

            return Instance;
        }

        /* This function rewrite media function for body of send*/
        Status* Send(string Message, uint32_t Length) override {
            static Status status;
            status.SetMessage(Status::Message::Fault);

            /* This line represents everything in this section */
            cout << "RS485 : Send()" << endl;
            status.SetMessage(Status::Message::Success);

            return &status;
        }

        /* This function rewrite media function for body of receive*/
        Status* Receive(string *Message, uint32_t *Length) override {
            static Status status;
            status.SetMessage(Status::Message::Fault);    

            /* This line represents everything in this section */
            cout << "RS485 : Receive()" << endl;
            status.SetMessage(Status::Message::Success);

            return &status;
        }
};
RS485 *RS485::Instance = nullptr;
/*--------------------------------------------------------------------------------------------------------------------*/
/* Sample of media to useing LAN (the LAN is media used ethernet communication) */
class LAN : public Media {    
    private: 

        /* Instance for single use */
        static LAN *Instance;
        private: LAN() {};
        
    public: 
        static LAN *getInstance() {
            if(Instance == nullptr) {
                Instance = new LAN();
            }

            return Instance;
        }

        /* This function rewrite media function for body of send*/
        Status* Send(string Message, uint32_t Length) override {
            static Status status;
            status.SetMessage(Status::Message::Fault);

            /* This line represents everything in this section */
            cout << "LAN : Send()" << endl;
            status.SetMessage(Status::Message::Success);

            return &status;
        }

        /* This function rewrite media function for body of receive*/
        Status* Receive(string *Message, uint32_t *Length) override {
            static Status status;
            status.SetMessage(Status::Message::Fault);    

            /* This line represents everything in this section */
            cout << "LAN : Receive()" << endl;
            status.SetMessage(Status::Message::Success);

            return &status;
        }
};
LAN *LAN::Instance = nullptr;
/*--------------------------------------------------------------------------------------------------------------------*/
/* IEC is a protocol, that used for communication between equipment*/
class IEC {
    public:
        /* Create IEC with empty media */
        IEC() : _Media(nullptr) {};

        /* Set media for use this object */
        Status* setMedia(Media *_Media) {
            static Status status;
            status.SetMessage(Status::Message::Fault); 

            this->_Media = _Media; 
            status.SetMessage(Status::Message::Success);

            return &status;
        }

        /* Handle represents any work to do it around communication */
        Status* Handle(void) {
            static Status status;
            status.SetMessage(Status::Message::Fault);

            if(_Media == nullptr) {
                status.SetMessage(Status::Message::Fault_Media);
                return &status;
            }            

            string Message;
            uint32_t Length;
            
            Message = "Data";
            Length = 4;
            _Media->Send(Message, Length);

            Message = "";
            Length = 0;
            _Media->Receive(&Message, &Length);

            status.SetMessage(Status::Message::Success);

            return &status;
        }
    private:

        /* The variable holding what media added */
        Media *_Media;
};
/************************************************** Functions *********************************************************/
/* The main function start of program in cpp language */
int main() {
    
    /* For translation of return values */
    Status *status;

    /* Making the first and only example of RS485 */
    RS485 *rs485 = RS485::getInstance();
    /* Making the first and only example of LAN */
    LAN *lan = LAN::getInstance();

    /* Making the IEC */
    IEC *iec = new IEC();
    status = iec->Handle();
    status->ShowMessage();

    /* Set RS485 media and use that */
    status = iec->setMedia(rs485);
    status = iec->Handle();

    /* Set LAN media and use that */
    status = iec->setMedia(lan);
    status = iec->Handle();

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
