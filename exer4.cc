#include <boost/algorithm/string/trim.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
using namespace std;
class Assembly
{
public:
    string label;
    string opcode;
    string oprend;
    int obj;
    int location;
    Assembly() : label(""), opcode(""), oprend(""), location(0), obj(0) {}
    Assembly(string l, string opc, string opr)
        : label(l), opcode(opc), oprend(opr), location(0), obj(0) {}
    Assembly(int loc, string l, string opc, string opr)
        : location(loc), label(l), opcode(opc), oprend(opr), obj(0) {}
};

void Read_SYMTAB(map<string, int> &symtab, int &length)
{
    ifstream file("SYNTAB");
    string program_name, loc_s, length_s, label;
    int loc, label_loc;
    file >> program_name >> loc_s >> length_s;
    loc = stoi(loc_s, nullptr, 16);
    length = stoi(length_s, nullptr, 16);
    symtab[program_name] = loc;
    while (file >> label >> loc_s)
    {
        label_loc = stoi(loc_s, nullptr, 16);
        symtab[label] = label_loc;
    }
}
void Read_INTFILE(vector<Assembly> &res)
{
    ifstream file("INTFILE");
    string loc_s, label, opcode, oprend, line;
    size_t line_len;
    while (file >> loc_s)
    {
        file.ignore();
        getline(file, line);
        line_len = line.length();
        label = line.substr(0, 8);
        opcode = line.substr(9, min(size_t(6), line_len - 9));
        if (line_len >= 18)
            oprend = line.substr(17, min(size_t(18), line_len - 17));
        else
            oprend = "";
        boost::trim(label);
        boost::trim(opcode);
        boost::trim(oprend);
        res.emplace_back(
            stoi(loc_s, nullptr, 16),
            label, opcode, oprend);
    }
}

int main()
{
    map<string, int> symtab;
    vector<Assembly> intfile;
    int length;
    Read_SYMTAB(symtab, length);
    Read_INTFILE(intfile);
    return 0;
}