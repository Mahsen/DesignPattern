
//*********************************************************** Explanation ***************************************************************//
/*
File : strategy.cpp
Used : Sample send or receive data to from any media
Last Update : 2023/5/11
Programmer : Mohammad Lotfi
Site : https://www.mahsen.ir
Tel : +989124662703
Email : info@mahsen.ir
Design Pattern : Strategy & Singleton
*/
//************************************************************* Warning *****************************************************************//
/*
none
*/
//************************************************************* Wizard ******************************************************************//
/*
none
*/
//************************************************************ includes ******************************************************************//
/* Include standard input-output stream head */
#include "iostream"
//************************************************************ defineds ******************************************************************//
/*
none
*/
//************************************************************ variables *****************************************************************//
/* Using std */
using namespace std;
//************************************************************* opjects ******************************************************************//
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
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
/* Media is interface with virtual functions to use other media for example (UART,LAN,RS485,USB,...) and all things that follows this structure */
class Media {    
    public: 
        /* This function for send data*/
        virtual Status* Send(string Message, uint32_t Length) = 0;
        /* This function for receive data*/
        virtual Status* Receive(string *Message, uint32_t *Length) = 0;
};
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
class RS485 : public Media {    
    private: 
        static RS485 *Instance;
        private: RS485() {};

    public: 
        static RS485 *getInstance() {
            if(Instance == nullptr) {
                Instance = new RS485();
            }

            return Instance;
        }

        Status* Send(string Message, uint32_t Length) override {
            static Status status;
            status.SetMessage(Status::Message::Fault);

            cout << "RS485 : Send()" << endl;
            status.SetMessage(Status::Message::Success);

            return &status;
        }

        Status* Receive(string *Message, uint32_t *Length) override {
            static Status status;
            status.SetMessage(Status::Message::Fault);    

            cout << "RS485 : Receive()" << endl;
            status.SetMessage(Status::Message::Success);

            return &status;
        }
};
RS485 *RS485::Instance = nullptr;
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
class LAN : public Media {    
    private: 
        static LAN *Instance;
        private: LAN() {};
        
    public: 
        static LAN *getInstance() {
            if(Instance == nullptr) {
                Instance = new LAN();
            }

            return Instance;
        }

        Status* Send(string Message, uint32_t Length) override {
            static Status status;
            status.SetMessage(Status::Message::Fault);

            cout << "LAN : Send()" << endl;
            status.SetMessage(Status::Message::Success);

            return &status;
        }

        Status* Receive(string *Message, uint32_t *Length) override {
            static Status status;
            status.SetMessage(Status::Message::Fault);    

            cout << "LAN : Receive()" << endl;
            status.SetMessage(Status::Message::Success);

            return &status;
        }
};
LAN *LAN::Instance = nullptr;
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
class IEC {
    public:
        IEC() : _Media(nullptr) {};
        Status* setMedia(Media *_Media) {
            static Status status;
            status.SetMessage(Status::Message::Fault); 

            this->_Media = _Media; 
            status.SetMessage(Status::Message::Success);

            return &status;
        }
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
        Media *_Media;
};
//************************************************************ functions *****************************************************************//
int main() {
    
    Status *status;

    RS485 *rs485 = RS485::getInstance();
    LAN *lan = LAN::getInstance();

    IEC *iec = new IEC();
    status = iec->Handle();
    status->ShowMessage();

    status = iec->setMedia(rs485);
    status = iec->Handle();

    status = iec->setMedia(lan);
    status = iec->Handle();

    return 0;
}
//*************************************************************** tasks *******************************************************************//
/*
none
*/
//************************************************************** vectors ******************************************************************//
/*
none
*/
//****************************************************************************************************************************************//
