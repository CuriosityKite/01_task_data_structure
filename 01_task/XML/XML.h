#include <iostream>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>

class XML
{
private:
    boost::property_tree::ptree tree;

public:
    XML(const std::string filename)
    {
        boost::property_tree::read_xml(filename, tree);
    }

    void printIdAndType()
    {
        for (const auto& pr : tree.get_child("videoSource"))
        {
            if (pr.first == "property")
            {
                std::string id = pr.second.get<std::string>("<xmlattr>.id");
                std::string type = pr.second.get<std::string>("<xmlattr>.xsi:type");
                std::cout << "ID: " << id << ", Type: " << type << std::endl;
            }
        }
    }
};