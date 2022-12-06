#include "Set4Libinterfaces.hh"

bool Set4Libinterfaces::init(std::vector<std::string> lib_vector)
{
    for (int i = 0; i < lib_vector.size(); i++)
    {
        auto tmp_lib = std::make_shared<Libinterface>();
        tmp_lib->init("libs/"+lib_vector[i]);
        std::string cmd_name = lib_vector[i].substr(10, lib_vector[i].length() - 13);
        std::cout << cmd_name + " utworzono!!!!" << std::endl;
        Libinterfaces.insert(std::make_pair(cmd_name, tmp_lib)); 
    }
}
Interp4Command* Set4Libinterfaces::execCmd(std::string key)
{
    std::shared_ptr<Libinterface> handler;
    Interp4Command *tmp_cmd = nullptr;
    std::cout<<"Tutaj "<<key<<endl;
    if (key == "BEGIN_PARALLEL_ACTIONS")
    {
        this->parallel = true;
    }
    else if (key == "END_PARALLEL_ACTIONS")
    {
        this->parallel = false;
    }
    else
    {
        auto it = Libinterfaces.find(key);
        if(it == Libinterfaces.end())
        {
            std::cerr<< " Cannot find plug for " << key << std::endl;
            return nullptr;
        }
        handler = it->second;
        tmp_cmd = handler->CreateCmd();
    }
    
    return tmp_cmd;
}
