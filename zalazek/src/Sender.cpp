#include "Sender.hh"

Sender::~Sender()
{
    close(_Socket);
}

bool Sender::OpenConnection()
{
  struct sockaddr_in  DaneAdSerw;

  bzero((char *)&DaneAdSerw,sizeof(DaneAdSerw));

  DaneAdSerw.sin_family = AF_INET;
  DaneAdSerw.sin_addr.s_addr = inet_addr("127.0.0.1");
  DaneAdSerw.sin_port = htons(PORT);


  _Socket = socket(AF_INET,SOCK_STREAM,0);

  if (_Socket < 0) {
     cerr << "*** Blad otwarcia gniazda." << endl;
     return false;
  }

  if (connect(_Socket,(struct sockaddr*)&DaneAdSerw,sizeof(DaneAdSerw)) < 0)
   {
     cerr << "*** Brak mozliwosci polaczenia do portu: " << PORT << endl;
     return false;
   }
  return true;
}

int Sender::Send(const char* sMesg)
{
    ssize_t  IlWyslanych;
    ssize_t  IlDoWyslania = (ssize_t) strlen(sMesg);

    while ((IlWyslanych = write(_Socket,sMesg,IlDoWyslania)) > 0) 
    {
        IlDoWyslania -= IlWyslanych;
        sMesg += IlWyslanych;
    }
    if (IlWyslanych < 0) 
    {
    cerr << "*** Blad przeslania napisu." << endl;
    }
    return 0;
}
std::string Sender::AddInstr(MobileObj *obj) const
{
  std::string instr = "AddObj";
  instr += " Name=" + obj->GetName();
  instr += " Shift=(" + std::to_string(obj->GetPositoin_m()[0]) + ", " + std::to_string(obj->GetPositoin_m()[1]) + ", " + std::to_string(obj->GetPositoin_m()[2]) + ")";
  instr += " Scale=(" + std::to_string(obj->getScale()[0]) + ", " + std::to_string(obj->getScale()[1]) + ", " + std::to_string(obj->getScale()[2]) + ")";
  instr += " Trans_m=(" + std::to_string(obj->getTranslation()[0]) + ", " + std::to_string(obj->getTranslation()[1]) + ", " + std::to_string(obj->getTranslation()[2]) + ")";
  instr += " RGB=(" + std::to_string((int)obj->getColor()[0]) + ", " + std::to_string((int)obj->getColor()[1]) + ", " + std::to_string((int)obj->getColor()[2]) + ")";
  instr += " RotXYZ_deg=(" + std::to_string(obj->GetAng_Roll_deg()) + ", " + std::to_string(obj->GetAng_Pitch_deg()) + ", " + std::to_string(obj->GetAng_Yaw_deg()) + ")\n";
  std::cout << instr;
  return instr;
}

std::string Sender::UpdateInstr(MobileObj *obj) const
{
  std::string instr = "UpdateObj";
  instr += " Name=" + obj->GetName();
  instr += " Shift=(" + std::to_string(obj->GetPositoin_m()[0]) + ", " + std::to_string(obj->GetPositoin_m()[1]) + ", " + std::to_string(obj->GetPositoin_m()[2]) + ")";
  instr += " Scale=(" + std::to_string(obj->getScale()[0]) + ", " + std::to_string(obj->getScale()[1]) + ", " + std::to_string(obj->getScale()[2]) + ")";
  instr += " Trans_m=(" + std::to_string(obj->getTranslation()[0]) + ", " + std::to_string(obj->getTranslation()[1]) + ", " + std::to_string(obj->getTranslation()[2]) + ")";
  instr += " RGB=(" + std::to_string((int)obj->getColor()[0]) + ", " + std::to_string((int)obj->getColor()[1]) + ", " + std::to_string((int)obj->getColor()[2]) + ")";
  instr += " RotXYZ_deg=(" + std::to_string(obj->GetAng_Roll_deg()) + ", " + std::to_string(obj->GetAng_Pitch_deg()) + ", " + std::to_string(obj->GetAng_Yaw_deg()) + ")\n";
  
  return instr;
}


