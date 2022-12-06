#include <iostream>
#include "Interp4Set.hh"
#include "MobileObj.hh"

using std::cout;
using std::endl;


extern "C" {
 Interp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Set"; }
}




/*!
 * \brief
 *
 *
 */
Interp4Command* CreateCmd(void)
{
  return Interp4Set::CreateCmd();
}


/*!
 *
 */
Interp4Set::Interp4Set()
{
  std::cout<<"Creating SET"<<std::endl;
}


/*!
 *
 */
void Interp4Set::PrintCmd() const
{
  cout << GetCmdName() << " " << _ObjName << " " <<  X_Coord  <<" "<< Y_Coord << " " << Z_Coord << endl;
}


/*!
 *
 */
const char* Interp4Set::GetCmdName() const
{
  return ::GetCmdName();
}


/*!
 *
 */
bool Interp4Set::ExecCmd(Scene *wScn) const
{
  MobileObj *obj_on_scene = wScn->FindMobileObj(this->_ObjName.c_str());
  Vector3D start_position = obj_on_scene->GetPositoin_m();
  Vector3D rel_position;
  rel_position[0] = this->X_Coord;
  rel_position[1] = this->Y_Coord;
  rel_position[2] = start_position[2];
  wScn->LockAccess();
  obj_on_scene->SetPosition_m(rel_position);
  obj_on_scene->SetAng_Yaw_deg(this->Z_Coord);
  wScn->MarkChange();
  wScn->UnlockAccess();
  return true;
}


/*!
 *
 */
bool Interp4Set::ReadParams(std::istream& Strm_CmdsList)
{
  Strm_CmdsList >> _ObjName  >> X_Coord >> Y_Coord >> Z_Coord;
  return !Strm_CmdsList.fail();
}


/*!
 *
 */
Interp4Command* Interp4Set::CreateCmd()
{
  return new Interp4Set();
}


/*!
 *
 */
void Interp4Set::PrintSyntax() const
{
  cout << "   Set  NazwaObiektu  WspółrzędnaX WspółrzędnaY WspółrzędnaZ" << endl;
}
