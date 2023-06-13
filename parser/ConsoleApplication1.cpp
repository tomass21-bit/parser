// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>
#include <list>
#include <string>
struct Grema {
   
protected:
    char section_in = '[';
    char section_out = ']';
    std::vector <char> empty = {' ','\t','\n'};
    char comment = ';';
    char equally = '=';
    bool flag_equally = false;
    bool flag_section_out = false;
    bool flag_section_in = false;
    std::list<char> ignore = { section_in,section_out, comment , ' ', '\t', '\n' };

};
struct Find_section :public Grema {
    

};
class Ini_parser:public Grema {
public:
    Ini_parser(const std::string& file_name_in) : file_name(file_name_in) {
        std::ifstream in;
        in.open(file_name_in);
    }
    ~Ini_parser() {
        in.close();
    }
template <typename T>
T get_value( std::string question) {
    std::stringstream ss(question);
    std::getline(ss, set_section, '.');
    std::getline(ss, set_value);

    std::map<std::string, T> section;    // контейнер для хранения названий переменных и  их значений
    if (in.is_open()) {
        while (getline(in, temp)) {
            if (flag_section == false) {
                find_section(temp);
            }
            else {
                find_value(temp);
                section[finds_name_value] = finds_value;
                finds_name_value = ' ';
                finds_value = ' ';
            }
        }
        auto iter= section.find(' ');
        auto it = section.find(set_section);
        if (section.empty() == true) {
            //выдать уведомление
            std::cout << "Сделай нормально исключение";
        }
        else if (it->second == "0") {
            std::cout << "Сделай нормльно исключение для отсутвия значения";

        }
        else {
            
            return it->second;
        }

    }
}
private:
    
    void find_section(std::string& temp) {
        if (temp[0] == section_in) {
            for (auto t : temp) {
                for (auto i : ignore) {
                    if (t != i) {
                        finds_section += t;
                    }
                }
            }
            if (compare(set_section, finds_section) == 0) {
                flag_section = true;
            }
            return;
        }
        else
            flag_section = false;
        return;
    }

    void find_value(const std::string& temp) {
        
        if (flag_section == true) {
            if (temp[0] == section_in) { // если следуйщая строка после найденой секции тоже секция бросить исключение (нет переменных в секции)
                flag_section = false;
                

                return;
            }
            else {
                for (auto t : temp) {
                    if (t == equally) {
                        for (auto ig : ignore) {

                            if (t != ig) {
                                finds_value += t;
                            }
                        }
                    }
                    else {
                        for (auto i : ignore) {

                            if (t != i) {
                                finds_name_value += t;
                            }
                        }
                    }
                }

            }
        }
        else
            return;
      
    }

    
    int compare(const std::string& str1, const std::string& str2) {
        int result=str1.compare(str2);
        return result;
    }
    bool flag_section=false;  //Если найдена секция флаг равен true;
    std::string file_name;
    std::ifstream in;
    std::string temp;
    std::string finds_section;
    std::string set_section;
    std::string set_value;
    std::string finds_value;
    std::string finds_name_value;
    
};

int main()
{
    Ini_parser parser("test.ini");
    std::string question = "Section2.var1";
    auto value = parser.get_value<std::string>(question);
    std::cout << value;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
