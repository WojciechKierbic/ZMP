#include "../inc/Set4Libinterfaces.hh"

bool Set4Libinterfaces::init(std::vector<std::string> lib_vector)
{
    for (unsigned int i = 0; i < lib_vector.size(); i++)
    {
        auto tmp_lib = make_shared<Libinterface>();
        tmp_lib->init("libs/"+lib_vector[i]);
        std::string cmd_name = lib_vector[i].substr(10, lib_vector[i].length() - 13);
        std::cout<< cmd_name << std::endl;
        Libinterfaces.insert(std::make_pair(cmd_name, tmp_lib));
    }
    return true;
}
bool Set4Libinterfaces::execLib(std::istringstream &strm)
{
    std::string action;
    std::shared_ptr<Libinterface> handler;
    Interp4Command *tmp_cmd;

    while (strm >> action)
    {
        std::map<std::string, std::shared_ptr<Libinterface>>::iterator it = Libinterfaces.find(action);
        if(it == Libinterfaces.end())
        {
            std::cout << "Cannot find plugin for action: " << action << std::endl;
            return 1;
        }
    
    handler = it->second;
    tmp_cmd = handler->CreateCmd();
    tmp_cmd->ReadParams(strm);
    std::cout <<"Polecenie:"<<std::endl;
    tmp_cmd->PrintCmd();
    delete tmp_cmd;
    }
    return 0;
}
