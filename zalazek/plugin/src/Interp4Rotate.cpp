#include <iostream>
#include "Interp4Rotate.hh"
#include "MobileObj.hh"

using std::cout;
using std::endl;


extern "C" {
 Interp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Rotate"; }
}




/*!
 * \brief
 *
 *
 */
Interp4Command* CreateCmd(void)
{
  return Interp4Rotate::CreateCmd();
}


/*!
 *
 */
Interp4Rotate::Interp4Rotate()
{
  std::cout<<"Creating ROTATE"<<std::endl;
}


/*!
 *
 */
void Interp4Rotate::PrintCmd() const
{
  cout << GetCmdName() << " " << _ObjName<< " " << Rot_angle_deg << endl;
}


/*!
 *
 */
const char* Interp4Rotate::GetCmdName() const
{
  return ::GetCmdName();
}


/*!
 *
 */
bool Interp4Rotate::ExecCmd(Scene *wScn) const
{
  MobileObj *obj_on_scene = wScn->FindMobileObj(this->_ObjName.c_str());
  double tmp_yaw = obj_on_scene->GetAng_Yaw_deg();
  double rel_yaw;
  double t = this->Rot_angle_deg / ROTATE_SPEED;
  double steps = (int)(t * 50);

  for(int i = 0; i < steps ; ++i)
  {
    wScn->LockAccess();
    rel_yaw += Rot_angle_deg / steps;
    obj_on_scene->SetAng_Yaw_deg(tmp_yaw + rel_yaw);
    wScn->MarkChange();
    wScn->UnlockAccess();
    usleep(0.02 * 1000000);
  }
return true;
}


/*!
 *
 */
bool Interp4Rotate::ReadParams(std::istream& Strm_CmdsList)
{
  Strm_CmdsList >> _ObjName >> Rot_angle_deg;
  return !Strm_CmdsList.fail();
}


/*!
 *
 */
Interp4Command* Interp4Rotate::CreateCmd()
{
  return new Interp4Rotate();
}


/*!
 *
 */
void Interp4Rotate::PrintSyntax() const
{
  cout << "   Rotate  NazwaObiektu  SzybkoscObrotu[m/s]  KatObrotu[deg]" << endl;
}
