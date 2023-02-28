#include <iostream>
#include <string>
using namespace std;

class Class {
public:
    Class() {
        this->FirstNum = NULL;
        this->SecondNum = NULL;
    }

    void const replace(string &str, char symbol_replace, char symbol_set) {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == symbol_replace) {
                str[i] = symbol_set;
            }
        }
    }

    void const SelectNum(float& FirstNum, float& SecondNum) {
        string FirstNum_s, SecondNum_s;
        cout << "Select First Number: "; cin >> FirstNum_s;
        cout << "Select Second Number: "; cin >> SecondNum_s;

        replace(FirstNum_s, ',', '.');
        replace(SecondNum_s, ',', '.');

        this->FirstNum = stof(FirstNum_s += '\0'); // '\0' or c_str();
        this->SecondNum = stof(SecondNum_s += '\0'); // '\0' or c_str();
    }

    float const Plus() {
        SelectNum(this->FirstNum, this->SecondNum);

        return this->FirstNum + this->SecondNum;
    }

    float const Minus() {
        SelectNum(this->FirstNum, this->SecondNum);

        return this->FirstNum - this->SecondNum;
    }

    float const Multiply() {
        SelectNum(this->FirstNum, this->SecondNum);

        return this->FirstNum * this->SecondNum;
    }

    float const Divide() {
        SelectNum(this->FirstNum, this->SecondNum);
        if (this->SecondNum == 0) { cout << "Error, Division by 0 \n\n"; return NULL; }

        return this->FirstNum / this->SecondNum;
    }
    
    float const GetFirstNum() {
        return this->FirstNum;
    }

    float const GetSecondNum() {
        return this->SecondNum;
    }

protected:
    float FirstNum;
    float SecondNum;
} Calculator;

int main() {
    char choice = NULL;
    float result = NULL;

    while (true){
        cout << "Simple Calculator v1.2" << "\n";
        cout << "Select operation type (+, -, *, /) \n";
        cout << "-> ";  cin >> choice;

        system("cls");

        switch (choice) {
        case '+':
            cout << Calculator.GetFirstNum() << " + " << Calculator.GetSecondNum() << " = " << Calculator.Plus() << "\n\n";
            break;
        case '-':
            cout << Calculator.GetFirstNum() << " - " << Calculator.GetSecondNum() << " = " << Calculator.Minus() << "\n\n";
            break;
        case '*':
            cout << Calculator.GetFirstNum() << " * " << Calculator.GetSecondNum() << " = " << Calculator.Multiply() << "\n\n";
            break;
        case '/':
            result = Calculator.Divide();
            if (result) { 
                cout << Calculator.GetFirstNum() << " / " << Calculator.GetSecondNum() << " = " << result << "\n\n";
            }

            break;
        default:
            cout << "Wrong Symbol, try again \n";
            break;
        }
    }
    return 0;
}

/*
Напишіть наступну програму. Створіть клас, який би дозволяв використовувати кому для відділення цілої і дробової
частини чисел з плаваючою комою. Тобто, щоб таке число зокрема можна було ввести з клавіатури. Розробіть
методи для виконання основних математичних операцій: додавання, віднімання, множення, ділення; якщо дробова
частина обох операндів рівна нулю, то і остачу від ділення. Для задання операцій використовуйте перелік з
наступних математичних символів: +, -, *, % або /. Головна програма виконує обрану користувачем математичну
операцію з двома числами, а потім виводить результат на екран. Якщо користувач ввів хибний символ, то програма
має про це повідомити. Розгляньте можливість використання ключових слів const і constexpr в даній програмі.
*/
