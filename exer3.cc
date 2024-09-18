#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    string input, input_U, label, opcode, oprend, comment, pattern = " ";
    vector<string> ret;
    while (getline(cin, input))
    {
        bool flag = false;
        if (input[0] == '.')
        {
            continue;
        }
        label = input.substr(0, 9);
        string label_out;
        for (int i = 0; i < label.size(); i++)
        {
            if (label[i] != ' ')
            {
                label_out.push_back(toupper(label[i]));
            }
        }
        cout << left << setw(8) << label_out << " ";
        opcode = input.substr(9, 6);
        string opcode_out;
        for (int i = 0; i < opcode.size(); i++)
        {
            if (opcode[i] != ' ')
            {
                opcode_out.push_back(toupper(opcode[i]));
            }
        }
        if (opcode_out == "RSUB")
        {
            cout << "RSUB" << endl;
            continue;
        }
        cout << left << setw(6) << opcode_out << " ";
        cout << " ";
        oprend = input.substr(17, 18);
        string oprend_out;
        for (int i = 0; i < oprend.size(); i++)
        {
            if (oprend[i] != ' ' && flag == false)
            {
                oprend_out.push_back(toupper(oprend[i]));
            }
            else if (flag == true)
            {
                oprend_out.push_back(oprend[i]);
            }
            if (oprend[i + 1] == '\'' && (oprend[i] == 'c' || oprend[i] == 'C'))
            {
                flag = true;
            }
        }
        if (oprend_out[oprend_out.size() - 1] == ' ')
        {
            oprend_out.pop_back();
        }
        cout << left << oprend_out << endl;
    }
    return 0;
}