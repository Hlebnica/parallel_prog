#include <iostream>
#include <omp.h>
#include <stdio.h>
#include <windows.h>

int main()
{
    /* 
    // lab 2

    int number_threads_1 = 4;
    omp_set_num_threads(10);

    #pragma omp parallel num_threads(number_threads_1)
    {
        printf("Hello World\n");
    }

    printf("\n");
    */
    
    
    /* 
    // LAB 3
    int number_threads_lab3; // Quantity threads for lab 3
    printf("Write number of threads for lab 3: ");
    scanf_s("%d", &number_threads_lab3);
    
    // lab 3_1
    printf("3_1\n");
    #pragma omp parallel num_threads(number_threads_lab3)
    {
        int id = omp_get_thread_num(); // get num of current thread
        int num_threads = omp_get_num_threads(); // get total number of threads in region
        printf("I am %d thread from %d threads!\n", id, num_threads);
    }

    printf("\n3_2 Print only even threads: \n\n");
    

    // lab 3_2
    #pragma omp parallel num_threads(number_threads_lab3)
    {
        int id = omp_get_thread_num(); // get num of current thread
        if (id % 2 == 0) { 
            int num_threads = omp_get_num_threads(); // get total number of threads in region
            printf("I am %d thread from %d threads!\n", id, num_threads);
        }
    }


    //  pragma omp parallel for, автоматически распределяет итерации цикла между потоками.
    
    #pragma omp parallel for num_threads(100)
    for (int i = 0; i < 100; i++) {
        int id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();
        printf("TEST -- I am %d thread from %d threads!\n", id, num_threads);
    }


    // с помощью условий
    #pragma omp parallel num_threads(10)
    {
        int id = omp_get_thread_num();
        if (id == 0) {
            // Задача для первого потока
        }
        else if (id == 1) {
            // Задача для второго потока
        }
        else if (id == 2) {
            // Задача для третьего потока
        }
        else {
            // Задача для остальных потоков
        }
    }
    */

    /*
    Контроль выполнения каждого потока
    Распределение работы между потоками
    Избежание конфликтов доступа к общим ресурсам 
    Диагностика и отладка проблем
    */
    
    /*
    Какую роль играют количество подзадач и номер подзадачи в параллельных задачах

    Количество подзадач - на сколько разделится задача
    Для отдельной подзадачи - масштаб/размер отдельной задачи
    id - какую часть задачи решать

    */

    

    // LAB 4

    /*
    // Какие области видимости в последовательных программах
    /*
        Глобальная область видимости (global scope) - это область кода, которая доступна из любого места программы. 
        Переменные, объявленные в глобальной области видимости, хранятся в сегменте данных (Data) программы, который 
        является общим для всех потоков и процессов.

        Локальная область видимости (local scope) - это область кода, которая доступна только внутри функции или блока кода. 
        Переменные, объявленные в локальной области видимости, хранятся в стеке (Stack) текущего потока и не доступны 
        из других потоков или процессов.
    */
   
    
    // Какие области видимости в параллельных программах
    /*
        Общая область видимости (global scope) - это область кода, которая выполняется последовательно в каждом потоке. 
        Переменные, объявленные в общей области видимости, хранятся в сегменте данных (Data) программы, который является 
        общим для всех потоков и процессов. (shared)

        Локальная область видимости (local scope) - это область кода, которая выполняется параллельно в каждом потоке. 
        Переменные, объявленные в локальной области видимости, хранятся в стеке (Stack) текущего потока и не доступны из 
        других потоков или процессов. (private)

    */
    
    // Показать какая из областей видимости где находится на слайде 6 в 3 презентации
    /*
    
    */
    
    /*
    int k; // threads
    printf("Write number of threads for lab 4: ");
    scanf_s("%d", &k);
    
    int rank;
    
    printf("\npublic without SLEEP:\n");
    #pragma omp parallel num_threads(k) 
    {
        rank = omp_get_thread_num();
        printf("I am %d thread\n", rank);
    }
    
    printf("\npublic SLEEP:\n");
    #pragma omp parallel num_threads(k) 
    {
        rank = omp_get_thread_num();
        Sleep(100);
        printf("I am %d thread\n", rank);
    }*/


    /*
    При объявлении переменной как private в блоке parallel, 
    для каждой нити выделяется своя локальная память на стеке 
    для хранения локальной копии этой переменной. Каждая нить имеет доступ только к 
    своей локальной копии переменной, и при изменении значения переменной в одной нити, 
    эти изменения не будут видны в других нитях.
    */




    // Как в функции вывода компилятор определяет какую переменную использовать для вывода

    /*
    - Компилятор может выбрать ту переменную, которая объявлена ближе к месту использования. 
    Это называется "правилом наименьшей видимости".
    */

    /*
    printf("\nprivate:\n");
    #pragma omp parallel num_threads(k) private(rank)
    {
        rank = omp_get_thread_num();
        Sleep(100);
        printf("I am %d thread\n", rank);
    }*/
    
    
    // LAB 5
    // 5_1
    int n;
    std::cin >> n;

    int k;
    std::cin >> k;

    int sum = 0;
    #pragma omp parallel for reduction(+ : sum) num_threads(k)
    for (int i = 0; i < n; i++)
    {
        sum += i;
        printf("[%d]: Sum = %d\n", omp_get_thread_num(), sum);
    }

    std::cout << sum;

    return 0;
}


