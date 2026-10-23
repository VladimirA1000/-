
// теперь лаба 6
//!!!!!
//!!!
/*#include <stdio.h>
#include <windows.h>

#define NUM_ELEMENTS 100  
#define MAX(a, b) ((a) > (b) ? (a) : (b))  
// Глобальные переменные
int arr[NUM_ELEMENTS];
int n = 0;

//ОБЪЯВЛЕНИЯ ФУНКЦИЙ

// Базовые (ЛР 6.1)
void printElements();
void keyboardInput();
void oddsX10();
int findMin();
int findLastEven();
int findIndexMin();
int findIndexMax();
void countGreaterThan10();
void doubleLastEven();
void countEvensLeftOfMin();
void oddsX10RightOfMin();
void swapMinAndMax();

// (ЛР 6.1)
void multiplyEvensByZero();
void multiplyEvensByMinusOne();
void replaceLessThan4();
void multiplyBetweenMinAndMaxBy10();
void multiplyBetweenFirstAndLastEvenBy100();

// Вспомогательные для ЛР 6.2
void deleteElement(int index);
void insertElement(int index, int value);
int *StartandEndLongestEvenChain();

// ЛР 6.2
void deleteMinElement();
void insertZeroBeforeMin();
void deleteAllEvens();
void duplicateEvens();
void deleteFirstEven();              
void deleteEvensAfterMax();          
void deleteLongestEvenChain();      


// ==================== ГЛАВНАЯ ФУНКЦИЯ ====================

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int k;

    do {
        printf("\n");
        printf("------------------------------\n");
        printf("Содержимое массива:");
        printElements();
        printf("Выберите нужную вам операцию:\n");
        printf("1: Ввести с клавиатуры массив\n");
        printf("2: x10 для всех нечетных элементов\n");
        printf("3: Найти минимальный элемент\n");
        printf("4: Сколько элементов > 10\n");
        printf("5: x2 для последнего четного\n");
        printf("6: Сколько четных левее минимального\n");
        printf("7: x10 для нечетных правее минимального\n");
        printf("8: переставить местами min и max\n");
        printf("-1: Все четные элементы умножить на -1\n");
        printf("9: Все четные элементы умножить на 0\n");
        printf("10: Все элементы < 4 заменить на 4\n");
        printf("11: Элементы между max и min увеличить в 10 раз\n");
        printf("12: Элементы между первым и последним четным увеличить в 100 раз\n");
        printf("13: удалить минимальный элемент\n");
        printf("14: Перед минимальным элементом вставить 0\n");
        printf("15: удалить все четные элементы\n");
        printf("16: Продублировать все четные элементы\n");
        printf("17: Удалить первый четный элемент\n");
        printf("18: Удалить четные после максимального\n");
        printf("19: Удалить самую длинную цепочку четных\n");
        printf("\n");
        printf("0: Выйти из программы\n");
        printf("Выбранная операция >>>>>> ");

        scanf_s("%d", &k);

        switch (k) {
        case 1: keyboardInput(); break;
        case 2: oddsX10(); break;
        case 3: {
            int min = findMin();
            printf("min = %d\n", min);
            break;
        }
        case 4: countGreaterThan10(); break;
        case 5: doubleLastEven(); break;
        case 6: countEvensLeftOfMin(); break;
        case 7: oddsX10RightOfMin(); break;
        case 8: swapMinAndMax(); break;
        case -1: multiplyEvensByMinusOne(); break;
        case 9: multiplyEvensByZero(); break;
        case 10: replaceLessThan4(); break;
        case 11: multiplyBetweenMinAndMaxBy10(); break;
        case 12: multiplyBetweenFirstAndLastEvenBy100(); break;
        case 13: deleteMinElement(); break;
        case 14: insertZeroBeforeMin(); break;
        case 15: deleteAllEvens(); break;
        case 16: duplicateEvens(); break;
        case 17: deleteFirstEven(); break;
        case 18: deleteEvensAfterMax(); break;
        case 19: deleteLongestEvenChain(); break;
        }
    } while (k != 0);

    return 0;
}


// ==================== БАЗОВЫЕ ФУНКЦИИ ====================
// просто отображаем элементы
void printElements() {
    printf(" < ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf(">\n");
}
// вводим их(P.S мы уже выделили место в памяти n лишь показывает скольким мы присвоим значения и сколько выведем)
void keyboardInput() {
    printf("n = ");
    scanf_s("%d", &n);
    if (n > NUM_ELEMENTS) n = NUM_ELEMENTS;
    printf("input %d values: ", n);
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
    }
}
// дальше мы работаеим именно с n а не с макросом
void oddsX10() {
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 1) {
            arr[i] = arr[i] * 10;
        }
    }
}
// просто проходимся и сравниваем
int findMin() {
    if (n == 0) return 0;
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

// последний четный элемент(проходися от конца к началу)
int findLastEven() {
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] % 2 == 0) return i;
    }
    // ничего не нашли
    return 0;
}
// так же как с min значением
int findIndexMin() {
    // нулевой n
    if (n == 0) return 0;
    int indexMin = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[indexMin]) indexMin = i;
    }
    return indexMin;
}


int findIndexMax() {
    // нулевой n
    if (n == 0) return 0;
    int indexMax = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[indexMax]) indexMax = i;
    }
    return indexMax;
}

void countGreaterThan10() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 10) count++;
    }
    printf("Элементов > 10: %d\n", count);
}
// мы уже писали функцию нахождения последнего чет индекса)
void doubleLastEven() {
    int index = findLastEven();
    if (index >= 0) {
        arr[index] *= 2;
        printf("Последний четный (индекс %d) увеличен в 2 раза.\n", index);
    }
    else {
        printf("Четных элементов нет.\n");
    }
}
// уже знаем индекс минимального элемента
void countEvensLeftOfMin() {
    int indexMin = findIndexMin();
    printf("Индекс минимального элемента = %d\n", indexMin);

    int cnt = 0;
    for (int i = 0; i < indexMin; i++) {
        if (arr[i] % 2 == 0) cnt++;
    }
    printf("Левее минимального %d четных элементов\n", cnt);
}
// все что правее
void oddsX10RightOfMin() {
    int indexMin = findIndexMin();
    printf("Индекс минимального элемента = %d\n", indexMin);

    for (int i = indexMin + 1; i < n; i++) {
        if (arr[i] % 2 == 1) {
            arr[i] *= 10;
        }
    }
}
// чтобы не пперемешалось вводим 3 переменную tmp
void swapMinAndMax() {
    int indexMin = findIndexMin();
    int indexMax = findIndexMax();

    printf("Индекс минимального элемента = %d\n", indexMin);
    printf("Индекс максимального элемента = %d\n", indexMax);

    int tmp = arr[indexMin];
    arr[indexMin] = arr[indexMax];
    arr[indexMax] = tmp;
}


// ====================  (ЛР 6.1) ====================

void multiplyEvensByZero() {
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            arr[i] *= 0;
        }
    }
}
void multiplyEvensByMinusOne() {
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            arr[i] *= -1;
        }
    }
}
void replaceLessThan4() {
    for (int i = 0; i < n; i++) {
        if (arr[i] < 4) {
            arr[i] = 4;
        }
    }
}

void multiplyBetweenMinAndMaxBy10() {
    int indexMin = findIndexMin();
    int indexMax = findIndexMax();
    // условие ? истина: ложь
    int left = (indexMin < indexMax) ? indexMin : indexMax;
    int right = (indexMin > indexMax) ? indexMin : indexMax;

    printf("Индексы: min = %d, max = %d\n", indexMin, indexMax);

    for (int i = left; i < right; i++) {
        arr[i] *= 10;
    }
}

void multiplyBetweenFirstAndLastEvenBy100() {
    int firstEven = -1;
    int lastEven = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) { firstEven = i; break; }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] % 2 == 0) { lastEven = i; break; }
    }

    if (firstEven == -1 || lastEven == -1 || firstEven == lastEven) {
        printf("Недостаточно четных элементов для операции.\n");
        return;
    }

    printf("Первый четный: индекс %d, последний четный: индекс %d\n", firstEven, lastEven);

    for (int i = firstEven; i <= lastEven; i++) {
        arr[i] *= 100;
    }
}


// ==================== ВСПОМОГАТЕЛЬНЫЕ ДЛЯ ЛР 6.2 ====================

// Удалить элемент по индексу (сдвигаем всё влево)
void deleteElement(int index) {
    if (index < 0 || index >= n) {
        printf("Неверный индекс!\n");
        return;
    }
    for (int i = index; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

// Вставить значение по индексу (сдвигаем всё вправо)
void insertElement(int index, int value) {
    if (n >= NUM_ELEMENTS) {
        printf("Массив полон! Вставка невозможна.\n");
        return;
    }
    if (index < 0 || index > n) {
        printf("Неверный индекс!\n");
        return;
    }
    for (int i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    n++;
}


// ====================  ЛР 6.2 ====================

// 6.2.3: Удалить минимальный элемент
void deleteMinElement() {
    int indexMin = findIndexMin();
   
    printf("Индекс минимального элемента = %d\n", indexMin);
    deleteElement(indexMin);
}

// 6.2.4: Перед минимальным элементом вставить 0
void insertZeroBeforeMin() {
    int indexMin = findIndexMin();
   
    printf("Индекс минимального элемента = %d\n", indexMin);
    insertElement(indexMin, 0);
}

// 6.2.5*: Удалить все четные элементы
void deleteAllEvens() {
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] % 2 == 0) {
            deleteElement(i);
        }
    }
}

// 6.2.6*: Продублировать все четные элементы
void duplicateEvens() {
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] % 2 == 0) {
            insertElement(i + 1, arr[i]);
        }
    }
}

// 6.2.9 Вариант 1: Удалить первый из четных элементов
void deleteFirstEven() {
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("Удаляем первый четный: индекс %d, значение %d\n", i, arr[i]);
            deleteElement(i);
            return;
        }
    }
    printf("Четных элементов нет.\n");
}

// 6.2.10 Вариант 1: Удалить четные, стоящие после максимального
void deleteEvensAfterMax() {
    int indexMax = findIndexMax();
    if (indexMax < 0) return;
    printf("Индекс максимального элемента = %d\n", indexMax);

    for (int i = n - 1; i > indexMax; i--) {
        if (arr[i] % 2 == 0) {
            deleteElement(i);
        }
    }
}

// 6.2.11 Вариант 1: Удалить самую длинную цепочку четных
int* StartandEndLongestEvenChain() {
    static int rez[2];
    int bestLen = 0;

    
    for (int l = 0; l < n; l++) {
        
        if (arr[l] % 2 != 0) continue;

        int m = 0; 

        
        int r;
        for (r = l; r < n; r++) {
            if (arr[r] % 2 == 0) {
                m++;
            }
            else {
                break; 
            }
        }

        
        if (m > bestLen) {
            bestLen = m;
            rez[0] = l;        
            rez[1] = l + m - 1; 
        }

    
        l = l + m - 1;
    }
    return rez;
}
void deleteLongestEvenChain() {
    int *rez = StartandEndLongestEvenChain();
    int startindex = rez[0];
    int endindex = rez[1];
    for (int i = endindex; i >= startindex; i--) {
        deleteElement(i);
    }
}
*/
// лаба 7
/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <Windows.h>
#include <string.h>

// Собственная реализация isdigit для задачи 7.1.5.2
int isDigitMy(char c) {
    if (c >= '0' && c <= '9') return 1;
    return 0;
}

int main() {
    
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int choice;
    do {
       
        printf("1: Задача 7.1.1 (20 символов после введенного)\n");
        printf("2: Задача 7.1.2 (30 символов до введенного)\n");
        printf("3: Задача 7.1.3 (Подсчитать пробелы)\n");
        printf("4: Задача 7.1.4 (Заменить пробелы на '#')\n");
        printf("5: Задача 7.1.5.1 (Заменить цифры на '$' через isdigit)\n");
        printf("6: Задача 7.1.5.2 (Заменить цифры на '$' через свою isDigitMy)\n");
        printf("7: Задача 7.1.6 (Маленькие латинские в большие)\n");
        printf("8: Задача 7.1.7 (свой вариант с заменой)\n");
        printf("0: Выход\n");
       

        
        if (scanf("%d", &choice) != 1) {
            break; // Защита от бесконечного цикла при вводе букв
        }

        switch (choice) {
           
            // ЗАДАЧА 7.1.1 
           
        case 1: {
            printf("Введите символ =");
            // ВАЖНО: так как scanf оставил \n в буфере, 
            // getchar() съест этот \n, и вам придется ввести символ ЕЩЕ РАЗ.
            int ch = getchar();
            if (ch == '\n') ch = getchar(); // Пропускаем Enter от scanf

            for (int c = ch; c <= ch + 19; c++) {
                printf("'%c' (%d)\n", c, c);
            }
            break;
        }

              
              // ЗАДАЧА 7.1.2 
              
        case 2: {
            printf("Введите символ =");
            int ch = getchar();
            if (ch == '\n') ch = getchar(); // Пропускаем Enter от scanf

            for (int c = ch; c >= ch - 29; c--) {
                printf("'%c' (%d)\n", c, c);
            }
            break;
        }

             
              // ЗАДАЧА 7.1.3 
              
        case 3: {
            char s[80];
            printf("Введите строку:");
            // fgets сразу прочитает оставшийся \n от scanf и выдаст пустую строку,
            // поэтому мы делаем "холостой" вызов, чтобы очистить буфер.
            if (getchar() == '\n') {
                // Буфер очищен, теперь можно читать реальную строку
            }
            fgets(s, 79, stdin);
            printf("\nВы ввели строку s = \"%s\"", s);

            int cnt = 0;
            for (int i = 0; i < strlen(s); i++) {
                if (s[i] == ' ') cnt++;
            }
            printf("\nВ ней %d пробелов\n", cnt);
            break;
        }

             
              // ЗАДАЧА 7.1.4 
             
        case 4: {
            char s[80];
            printf("Введите строку:");
            if (getchar() == '\n') { }
            fgets(s, 79, stdin);
            printf("\nВы ввели строку = \"%s\"\n", s);

            for (int i = 0; s[i] != '\0'; i++) {
                if (s[i] == ' ') s[i] = '#';
            }
            printf("Строка после обработки =\"%s\"\n", s);
            break;
        }

            
              // ЗАДАЧА 7.1.5.1 
             
        case 5: {
            char s[80];
            printf("Введите строку:");
            if (getchar() == '\n') {  }
            fgets(s, 79, stdin);
            printf("\nВы ввели строку = \"%s\"\n", s);

            for (int i = 0; s[i] != '\0'; i++) {
                if (isdigit(s[i])) s[i] = '$';
            }
            printf("Строка после обработки =\"%s\"\n", s);
            break;
        }

              
              // ЗАДАЧА 7.1.5.2 
              
        case 6: {
            char s[80];
            printf("Введите строку:");
            if (getchar() == '\n') { }
            fgets(s, 79, stdin);
            printf("\nВы ввели строку = \"%s\"\n", s);

            for (int i = 0; s[i] != '\0'; i++) {
                if (isDigitMy(s[i])) s[i] = '$';
            }
            printf("Строка после обработки =\"%s\"\n", s);
            break;
        }

            
              // ЗАДАЧА 7.1.6 а
              
        case 7: {
            char s[80];
            printf("Введите строку:");
            if (getchar() == '\n') {  }
            fgets(s, 79, stdin);
            printf("\nВы ввели строку = \"%s\"\n", s);

            for (int i = 0; s[i] != '\0'; i++) {
                s[i] = toupper(s[i]);
            }
            printf("Строка после обработки =\"%s\"\n", s);
            break;
        }
        case 8: {
            char s[90];
            printf("введите строку");
            if (getchar() =='\n'){}
            fgets(s, 80, stdin);
            for (int i = 0; s[i] != '\0'; i++) {
                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') { s[i] = '&'; }
            }
            printf("Строка после обработки =\"%s\"\n", s);
            break;
        }

        case 0:
            printf("Выход...\n");
            break;

        default:
            printf("Неверный выбор!\n");
            break;
        }

    } while (choice != 0);

    return 0;
}
*/
// 2 часть лабы
/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>


int strlen_my_1(char s[]);
int strlen_my_2(char* s);

int strcmp_my_1(char s1[], char s2[]);
int strcmp_my_2(char* s1, char* s2);

void strcpy_my_1(char s1[], char s2[]);
void strcat_my_2(char* s1, char* s2);

int strrchr_my_1(char s[], char c);
int strrchr_my_2(char* s, char c);

char* CreateNewString(char* s1);
char* CreateNewStringP(char* s1);



int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int choice;
    do {
        printf("\n--- Меню ЛР 7.2 ---\n");
        printf("1: 7.2.1.1 strlen (массив)\n");
        printf("2: 7.2.1.2 strlen (указатель)\n");
        printf("3: 7.2.2.1 strcmp (массив)\n");
        printf("4: 7.2.2.2 strcmp (указатель)\n");
        printf("5: 7.2.3 strcpy (массив)\n");
        printf("6: 7.2.4 strcat (указатель)\n");
        printf("7: 7.2.5.1 последнее вхождение (массив)\n");
        printf("8: 7.2.5.2 последнее вхождение (указатель)\n");
        printf("9: 7.2.6.1 ВАРИАНТ 1 (CreateNewString - массив)\n");
        printf("10: 7.2.6.2* ВАРИАНТ 1 (CreateNewStringP - указатель)\n");
        printf("0: Выход\n");
        
        scanf("%d", &choice);

        // Очистка буфера от Enter
        while (getchar() != '\n');

        switch (choice) {
        case 1: {
            char s[100];
            printf("Введите строку: ");
            fgets(s, 99, stdin);

            printf("strlen_my_1 = %d\n", strlen_my_1(s));
            break;
        }
        case 2: {
            char s[100];
            printf("Введите строку: ");
            fgets(s, 99, stdin);
            printf("strlen_my_2 = %d\n", strlen_my_2(s));
            break;
        }
        case 3: {
            char s1[100], s2[100];
            printf("Введите строку 1: "); fgets(s1, 99, stdin);
            printf("Введите строку 2: "); fgets(s2, 99, stdin);
            printf("Результат strcmp_my_1: %d\n", strcmp_my_1(s1, s2));
            break;
        }
        case 4: {
            char s1[100], s2[100];
            printf("Введите строку 1: "); fgets(s1, 99, stdin);
            printf("Введите строку 2: "); fgets(s2, 99, stdin);
            printf("Результат strcmp_my_2: %d\n", strcmp_my_2(s1, s2));
            break;
        }
        case 5: {
            char s1[100], s2[100];
            printf("Введите строку 1: "); fgets(s1, 99, stdin);
            printf("Введите строку 2: "); fgets(s2, 99, stdin);
            strcpy_my_1(s1, s2);
            printf("Результат (s1): %s", s1);
            break;
        }
        case 6: {
            char s1[200], s2[100];
            printf("Введите строку 1: "); fgets(s1, 99, stdin);
            printf("Введите строку 2: "); fgets(s2, 99, stdin);
            // Убираем \n из первой строки
            for (int i = 0; s1[i] != '\0'; i++) {
                if (s1[i] == '\n') {
                    s1[i] = '\0';
                    break;
                }
            }
            strcat_my_2(s1, s2);
            printf("Результат: %s", s1);
            break;
        }
        case 7: {
            char s[100], c;
            printf("Введите строку: "); fgets(s, 99, stdin);
            printf("Введите символ для поиска: "); c = getchar();
            int index = strrchr_my_1(s, c);
            if (index != -1) printf("Последнее вхождение на позиции %d\n", index);
            else printf("Символ не найден.\n");
            break;
        }
        case 8: {
            char s[100], c;
            printf("Введите строку: "); fgets(s, 99, stdin);
            printf("Введите символ для поиска: "); c = getchar();
            int index = strrchr_my_2(s, c);
            if (index != -1) printf("Последнее вхождение на позиции %d\n", index);
            else printf("Символ не найден.\n");
            break;
        }
        case 9: {
            char s1[100];
            printf("Введите строку s1: ");
            fgets(s1, 99, stdin);
            //УДАЛЯЕМ ENTER ИЗ СТРОКИ 
            for (int i = 0; s1[i] != '\0'; i++) {
                if (s1[i] == '\n') {
                    s1[i] = '\0';
                    break;
                }
            }
            char* s2 = CreateNewString(s1);
            printf("s1=%s\n", s1);
            printf("s2=%s\n", s2);
            free(s2);
            break;
        }
        case 10: {
            char s1[100];
            printf("Введите строку s1: ");
            fgets(s1, 99, stdin);
            //УДАЛЯЕМ ENTER ИЗ СТРОКИ 
            for (int i = 0; s1[i] != '\0'; i++) {
                if (s1[i] == '\n') {
                    s1[i] = '\0';
                    break;
                }
            }
            char* s2 = CreateNewStringP(s1);
            printf("s1=%s\n", s1);
            printf("s2=%s\n", s2);
            free(s2);
            break;
        }
        case 0:
            printf("Выход...\n");
            break;
        default:
            printf("Неверный выбор!\n");
            break;
        }
    } while (choice != 0);

    return 0;
}




// ЗАДАЧА 7.2.1.1
int strlen_my_1(char s[]) {
    int len = 0;
    while (s[len] != '\0') len++;
    return len-1;
}

// ЗАДАЧА 7.2.1.2
int strlen_my_2(char* s) {
    char* p = s;
    while (*p++);
    return p - s - 1-1;
}

// ЗАДАЧА 7.2.2.1
int strcmp_my_1(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i]) i++;
    return s1[i] - s2[i];
}

// ЗАДАЧА 7.2.2.2
int strcmp_my_2(char* s1, char* s2) {
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

// ЗАДАЧА 7.2.3
void strcpy_my_1(char s1[], char s2[]) {
    int i = 0;
    while (s2[i] != '\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

// ЗАДАЧА 7.2.4
void strcat_my_2(char* s1, char* s2) {
    while (*s1) s1++;
    while (*s1++ = *s2++);
}

// ЗАДАЧА 7.2.5.1
int strrchr_my_1(char s[], char c) {
    int last_index = -1;
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == c) last_index = i;
        i++;
    }
    return last_index;
}

// ЗАДАЧА 7.2.5.2
int strrchr_my_2(char* s, char c) {
    int last_index = -1;
    int current_index = 0;
    while (*s) {
        if (*s == c) last_index = current_index;
        s++;
        current_index++;
    }
    return last_index;
}

// ЗАДАЧА 7.2.6.1 ВАРИАНТ 1 (через МАССИВ)
char* CreateNewString(char* s1) {
    int i;
    int len = 0;
    int has_latin = 0; // Единственный флаг: есть ли латинские буквы

    // 1. Первый проход
    for (i = 0; s1[i] != '\0'; i++) {
        // Проверяем латиницу
        if ((s1[i] >= 'a' && s1[i] <= 'z') || (s1[i] >= 'A' && s1[i] <= 'Z')) {
            has_latin = 1;
        }
    }
    len = i;

    // 2. Вычисляем новую длину
    int new_len = len;
    if (has_latin==1) new_len += 1;       // Под '*'
    if (has_latin==0) new_len += 2;      // Под '##' (если НЕТ латинских букв)

    // 3. Выделяем память
    char* s2 = (char*)malloc((new_len + 1) * sizeof(char));

    // 4. Второй проход
    int out_idx = 0;
    if (has_latin) s2[out_idx++] = '*';

    for (i = 0; s1[i] != '\0'; i++) {
        s2[out_idx++] = s1[i];
    }

    // Если нет ни одной латинской буквы - ставим ##
    if (has_latin==0) {
        s2[out_idx++] = '#';
        s2[out_idx++] = '#';
    }
    s2[out_idx] = '\0';

    return s2;
}

// ЗАДАЧА 7.2.6.2* ВАРИАНТ 1 (через УКАЗАТЕЛИ)
char* CreateNewStringP(char* s1) {
    char* p = s1;
    int len = 0;
    int has_latin = 0;

    // 1. Первый проход
    while (*p) {
        len++;
        // Проверяем ТОЛЬКО латиницу
        if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')) {
            has_latin = 1;
        }
        p++;
    }

    // 2. Вычисляем новую длину
    int new_len = len;
    if (has_latin) new_len += 1;
    if (has_latin==0) new_len += 2;

    // 3. Выделяем память
    char* s2 = (char*)malloc((new_len + 1) * sizeof(char));
    char* ss2 = s2;
    p = s1;

    // 4. Второй проход
    if (has_latin) *ss2++ = '*';

    while (*p) {
        *ss2++ = *p++;
    }

    if (has_latin==0) {
        *ss2++ = '#';
        *ss2++ = '#';
    }
    *ss2 = '\0';

    return s2;
}*/