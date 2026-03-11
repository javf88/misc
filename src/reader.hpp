#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

struct Parser
{
    Parser(int argc, char **argv)
    {
        for (int i = 1; i < argc; ++i)
        {
            std::string arg(argv[i]);
            this->tokens.push_back(arg);
        }
    }

    const std::string& getOption(const std::string &option) const
    {
        static const std::string help("PROGRAM -f $INPUT_FILE");
        auto it = std::find(this->tokens.cbegin(), this->tokens.cend(), option);

        if (it == this->tokens.cend())
        {
            return help;
        }
        else
        {
            it++;
            return *it;
        }
    }

    std::vector<std::string> tokens;
};
