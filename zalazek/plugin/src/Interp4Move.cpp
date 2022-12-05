#include <iostream>
#include "Interp4Move.hh"

using std::cout;
using std::endl;


extern "C" {
 Interp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Move"; }
}




/*!
 * \brief
 *
 *
 */
Interp4Command* CreateCmd(void)
{
  return Interp4Move::CreateCmd();
}


/*!
 *
 */
Interp4Move::Interp4Move()
{
  std::cout<<"Creating MOVE"<<std::endl;
}


/*!
 *
 */
void Interp4Move::PrintCmd() const
{
  cout << GetCmdName() << " " << _ObjName << " " << _Speed_mmS  <<" "<< _distance_m << endl;
}


/*!
 *
 */
const char* Interp4Move::GetCmdName() const
{
  return ::GetCmdName();
}


/*!
 *
 */
bool Interp4Move::ExecCmd(Scene *wScn) const
{
  MobileObj *obj_on_scene = wScn->FindMobileObj(this->_ObjName.c_str());
  Vector3D start_position;
  Vector3D orientation;
  Vector3D tmp_move;
  Vector3D rel_move;
  start_position = obj_on_scene->GetPositoin_m();
  orientation[0] = obj_on_scene->GetAng_Roll_deg();
  orientation[1] = obj_on_scene->GetAng_Pitch_deg();
  orientation[2] = obj_on_scene->GetAng_Yaw_deg();
  double t = this->_distance_m / this->_Speed_mmS;
  double steps = (int)(t * 50);
  for(int i = 0; i < steps; ++i)
  {
    tmp_move[0] += (this->_distance_m/steps) * cos(orientation[1]*M_PI / 180) * cos(orientation[3] * M_PI / 180);
    tmp_move[1] += (this->_distance_m/steps) * (cos(orientation[0] * M_PI / 180) * sin(orientation[2]* M_PI / 180) + cos(orientation[2] * M_PI / 180)*sin(orientation[1] * M_PI / 180) * sin (orientation[0] * M_PI / 180));
    tmp_move[2] += (this->_distance_m/steps) * (sin(orientation[0] * M_PI / 180) * sin(orientation[2]* M_PI / 180) - cos(orientation[0] * M_PI / 180)*cos(orientation[2] * M_PI / 180) * sin (orientation[1] * M_PI / 180));
    for (int j = 0; j < 3; j++)
    {
      rel_move[j] = tmp_move[j] + start_position[j];
    }
    wScn->LockAccess();
    obj_on_scene->SetPosition_m(rel_move);
    wScn->MarkChange();
    wScn->UnlockAccess();
    usleep(0.02 * 1000000);
  }

  return true;
}


/*!
 *
 */
bool Interp4Move::ReadParams(std::istream& Strm_CmdsList)
{
  Strm_CmdsList >> _ObjName >> _Speed_mmS >> _distance_m;
  return !Strm_CmdsList.fail();
}


/*!
 *
 */
Interp4Command* Interp4Move::CreateCmd()
{
  return new Interp4Move();
}


/*!
 *
 */
void Interp4Move::PrintSyntax() const
{
  cout << "   Move  NazwaObiektu  Szybkosc[m/s]  DlugoscDrogi[m]" << endl;
}
