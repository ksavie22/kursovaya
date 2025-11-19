#include <stdio.h>
#include <math.h>
#include <float.h>
#include <locale.h>

// Функция для вычисления f(x)
double f(double x) {
    if (x < -2) {
        return 1.0 / log(fabs(x));
    }
    else if (x < 1) {
        return cos(x * x) * exp(-x);
    }
    else {
       
        double sum = 0;
        for (int n = 0; n <= 5; n++) {
            int exponent = 2 * n + 1;
            int denominator = 2 * n + 1;
            double term = pow(x, exponent) / denominator;
            sum += term;
        }
        return sum;
    }
}

// область опред
int is_defined(double x) {
    return !(x < -2 && fabs(x) <= 1);
}

//  Значение в точке
void calculate_value() {
    double x;
    printf("Введите x: ");
    scanf("%lf", &x);

    if (!is_defined(x)) {
        printf("Ошибка: функция не определена при x = %.2f\n", x);
        return;
    }

    printf("f(%.4f) = %.6f\n", x, f(x));
}



// меню
int main() {
    setlocale(LC_ALL, "RUS");
    int choice;


   

    printf("Программа для работы с кусочно-заданной функцией:\n");
    printf("f(x) = 1/ln|x|, x < -2\n");
    printf("f(x) = cos(x^2)·e^(-x), -2 <= x < 1\n");
    printf("f(x) = E x^(2n+1)/(2n+1), x >= 1\n\n");

    do {
        printf("\n=== МЕНЮ ===\n");
        printf("1. Значение функции в точке\n");
        printf("2. Таблица значений на интервале\n");
        printf("3. Поиск минимума/максимума на отрезке\n");
        printf("4. Поиск x: f(x) ≈ Y\n");
        printf("5. Производная в точке\n");
        printf("0. Выход\n");
        printf("Выберите операцию: ");

        scanf("%d", &choice);

        switch (choice) {
        case 1: calculate_value(); break;
        case 2: create_table(); break;
        case 3: find_extremum(); break;
        case 4: find_x_by_y(); break;
        case 5: calculate_derivative(); break;
        case 0: printf("Выход из программы\n"); break;
        default: printf("Неверный выбор. Попробуйте снова.\n");
        }

    } while (choice != 0);

    return 0;
}