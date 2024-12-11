/*Задание 4. Счастливый билетик
Что нужно сделать
В старину, когда даже в столице билеты в общественном транспорте выдавали контролёры, существовало поверье: если на билете сумма первых
 трёх цифр в номере билета равна сумме трёх последних, то это к удаче. Напишите программу, которая получала бы на вход шестизначный номер
 билета и выводила, счастливый это билет или нет. К примеру, билеты 666 666 и 252 135 — счастливые, а 123 456 — нет.

Пример выполнения

            Введите номер билета: 123060
            Билет счастливый!
            Введите номер билета: 123040
            Повезёт в следующий раз!

Рекомендации по выполнению
Программу необходимо сделать так, чтобы можно было увеличить количество цифр в билете без особых изменений в коде.
Для получения младшего разряда числа (самой правой цифры) используйте выражение: one_digit = digits % 10.
Используйте циклы для подсчёта суммы цифр в номере билета.
Что оценивается
Программа корректно определяет, является ли билет счастливым.
Для подсчёта суммы цифр в билете используются циклы.*/

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
    if (sum_first == sum_second) {
        std::cout << "Билет счастливый!" << std::endl;
    } else {
        std::cout << "Повезёт в следующий раз!" << std::endl;
    }
    return 0;
}
