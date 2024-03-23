
// 3_lab_1_course_2_sem_2024.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Создайте класс, описывающий строку произвольной длины. Не забывайте про принципы абстракции и инкапсуляции.
//В классе реализуйте конструктор копирования, оператор присваивания копированием и деструктор.Продемонстрируйте использование вашего класса.
#include <iostream>
#include <cstring>

class Copira
{
private:
    char* str;
public:
    Copira(const char* s = "") {
        std::cout << strlen(s) << std::endl;
        str = new char[strlen(s) + 1];
        //1-02-13-2
        //3
        //0 1 2 
        //0 1 2 3
        std::copy(s, s + strlen(s) + 1, str);
        std::cout << str << std::endl;

        //str[strlen(s)] = '\0';
        std::cout << strlen(str) << std::endl;
    }
    Copira(const Copira& other) : Copira(other.str) {
        //std::cout << other.str << "!!!" << std::endl;
        //str = new char[strlen(other.str)+1];
        //std::copy(other.str, other.str + strlen(other.str) + 1, str);
        //std::cout << str << "!!!" << std::endl;
    }
    Copira& operator=(const Copira& other) {
        std::cout << str << "normak!!!" << std::endl;
        std::cout << other.str << "otherak!!!" << std::endl;
        delete[] str;
        std::cout << "{}{}{}" << std::endl;
        str = new char[strlen(other.str)+1];
        std::copy(other.str, other.str + strlen(other.str) + 1, str);
        std::cout << str << "normakQWET!!!" << std::endl;
        std::cout << other.str << "otherakQWET!!!" << std::endl;
        return *this;
    }
    ~Copira() {
        delete[] str;
    }
};

int main()
{

    //int x(5); // int x = 5;

    Copira stringOne("123");
    Copira stringTne("666");
    //Copira a = stringOne;
    Copira a(stringTne);
    a = stringOne;
    //stringOne.sayNWord();

}

