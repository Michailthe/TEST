///////////////////////////////////////////////

#include <iostream>
using namespace std;
int main() {
    cout << "Этот тест проверит везучий у вас билет или нет!" << endl;
    cout<<"Проверка на число цифр"<<endl;
    long long number;
    cin>>number;
    if(number>1000000 || number<0)
    {
        cout<<"Число должно быть шестизначным"<<endl;
    }
    long long temp = number;
    int num_digits = 0;
    while (temp > 0) {
        temp /= 10;
        ++num_digits;
    }
    if (num_digits % 2 != 0) {
        std::cout << "Номер билета должен содержать чётное количество цифр." << std::endl;
        return 0;
    }
    int half = num_digits / 2;
    int sum_first = 0;
    int sum_second = 0;
    temp = number;
    for (int i = 0; i < num_digits; ++i) {
        int digit = temp % 10; // Извлекаем младший разряд
        temp = temp / 10;            // Удаляем младший разряд

        if (i < half) {
            sum_second = sum_second+digit; // Вторую половину цифр добавляем к sum_second
        } else {
            sum_first =sum_first+ digit;  // Первую половину цифр добавляем к sum_first
        }
    }

    return 0;
}
