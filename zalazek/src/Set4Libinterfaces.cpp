#include "Set4Libinterfaces.hh"

Set4Libinterfaces::Set4Libinterfaces()
{
    Libinterface MoveInterface = Libinterface("libInterp4Move.so");
    Libinterface PauseInterface = Libinterface("libInterp4Pause.so");
    Libinterface RotateInterface = Libinterface("libInterp4Rotate.so");
    Libinterface SetInterface = Libinterface("libInterp4Set.so");
    Libinterfaces.insert("Move", MoveInterface);
    Libinterfaces.insert("Pause", PauseInterface);
    Libinterfaces.insert("Rotate", RotateInterface);
    Libinterfaces.insert("Set", SetInterface);
}
Set4Libinterfaces::~Set4Libinterfaces()
{
    for (auto it = Libinterfaces.begin(); it != Libinterfaces.end(); it++)
    {
        it = Libinterfaces.erease(it);
    }
}