#include <iostream>
#include <omp.h>
#include <stdio.h>

int main()
{
    /*
    // lab 2

    int number_threads_1 = 5;

    #pragma omp parallel num_threads(number_threads_1)
    {
        printf("Hello World\n");
    }

    printf("\n");
    
    
    int number_threads_2; // Quantity threads for lab 3
    printf("Write number of threads for lab 3: ");
    scanf_s("%d", &number_threads_2);

    // lab 3_1
    printf("3_1\n");
    #pragma omp parallel num_threads(number_threads_2)
    {
        int id = omp_get_thread_num(); // get num of current thread
        int num_threads = omp_get_num_threads(); // get total number of threads in region
        printf("I am %d thread from %d threads!\n", id, num_threads);
        //std::cout << "I am " << id << " thread from " << num_threads << " threads!\n";
    }

    printf("\n3_2 Print only even threads: \n\n");
    

    // lab 3_2
    #pragma omp parallel num_threads(number_threads_2)
    {
        int id = omp_get_thread_num(); // get num of current thread
        if (id % 2 == 0) { 
            int num_threads = omp_get_num_threads(); // get total number of threads in region
            printf("I am %d thread from %d threads!\n", id, num_threads);
        }
    }*/

    /*
    // lab 4
    int number_threads_3;
    printf("Write number of threads for lab 4: ");
    scanf_s("%d", &number_threads_3);
    

    #pragma omp parallel num_threads(number_threads_3)
    {
        int rank = omp_get_thread_num();
        printf("I am %d thread\n", rank);
    }*/



    return 0;
}



/* lab1 
1) Что такое OpenMP?
 Cтандарт для параллельного программирования. Предоставляет набор директив и функций, которые позволяют 
 программисту контролировать работу с общей памятью и оптимизировать производительность параллельной программы.

2) Какие модели он реализует? Опишите модели и их связь.
 > fork-join - модель, в которой основной поток запускает параллельную область, в которой выполняются 
    несколько нитей. Когда нити заканчивают свою работу, они сливаются обратно в основной поток.
 > Data parallel - модель, в которой данные разделяются между несколькими нитями, и 
    каждая нить работает с своей частью данных.

3) В каких языках реализован этот стандарт?
 C, C++ и Fortran
 
4) Из каких частей состоит реализация в Visual Studio?
 Компилятора и библиотеки OpenMP

*/

/* lab2
1) Какие существуют варианты задания количества нитей в параллельном регионе?
 Задание числа нитей при помощи директивы num_threads().
 Задание числа нитей при помощи переменной окружения OMP_NUM_THREADS.
 Задание числа нитей при помощи вызова функции omp_set_num_threads() в коде программы.

2) Сколько нитей будет создано, если указаны оба варианта с разными значениями?
 Будет использовано число нитей, указанное в omp_set_num_threads(). Это происходит потому, что 
 явное задание числа нитей при помощи функции omp_set_num_threads() имеет более высокий приоритет, 
 чем установка переменной окружения.

3) Что конкретно делает функция omp_set_num_threads()?
 Используется для установки количества нитей, которые будут использоваться в следующем параллельном регионе

*/


/* lab 3
1) Как идентифицируются нити в OpenMP? Для чего это нужно? Приведите содержательный пример.
 Каждая нить (thread) идентифицируется своим номером в рамках параллельной области. 
 Это нужно, чтобы можно было контролировать выполнение конкретных нитей и выполнять 
 различные операции в зависимости от номера нити.
 
2) Совпадают ли эти идентификаторы с идентификаторами потоков в ОС?
 Идентификаторы нитей в OpenMP обычно не совпадают с идентификаторами потоков в операционной системе. 
 Как правило, нити OpenMP создаются внутри процесса операционной системы и используют ресурсы процесса, 
 в том числе и идентификаторы потоков операционной системы.

3) Каков порядок вывода сообщений нитями? Всегда ли он одинаков? Чем определяется этот порядок?
 Порядок вывода сообщений нитями в OpenMP может быть различным в разных запусках программы и зависит 
 от многих факторов, включая процессор, настройки системы, наличие других запущенных процессов и т.д. 
 Он также может зависеть от порядка выполнения инструкций в коде программы. В общем случае порядок 
 выполнения нитей не определен и не гарантирован.

*/

/*
1) Для чего нужны частные переменные? Не противоречит ли их существование реализуемой OpenMP 
модели программирования в общей памяти? Приведите содержательный пример частной переменной.
    Частные переменные необходимы для того, чтобы каждая нить имела свою локальную копию 
    переменной внутри параллельного региона, а не общую. Это позволяет избежать некорректных 
    результатов при одновременном обращении нескольких нитей к одной переменной. 
    Использование частных переменных не противоречит модели программирования в общей памяти, 
    так как каждая нить имеет доступ только к своей локальной копии переменной внутри параллельной области. 
    Примером частной переменной может служить переменная, хранящая сумму значений в некотором массиве, 
    которую каждая нить вычисляет только для своей части массива.

2) Какие новые области видимости появляются в параллельной программе? Как они задаются?
    В параллельной программе появляются две новые области видимости: shared и private. 
    Область видимости shared обозначает переменные, доступные для чтения и записи всеми 
    нитями в параллельном регионе, а область видимости private обозначает переменные, которые 
    должны иметь свою локальную копию для каждой нити в параллельном регионе. Они задаются с помощью 
    директив OpenMP, таких как shared и private.

3) Продемонстрируйте конфликт обращений к переменной rank в написанной программе? Всегда ли он возникает? 
    Как его предотвратить?
    Конфликт обращений к переменной rank возникает, когда несколько нитей пытаются 
    одновременно обратиться к общей переменной rank без использования директивы private.
    В таком случае значение переменной может быть изменено несколькими нитями одновременно,
    что приведет к некорректным результатам. Чтобы предотвратить конфликт обращений к переменной rank, 
    необходимо использовать директиву private для того, чтобы каждая нить имела свою локальную копию 
    переменной внутри параллельной области. Также можно использовать синхронизацию для контроля доступа 
    к общей переменной.
    
    Пример:
    int rank = 0;
    
    #pragma omp parallel num_threads(4)
    {
        rank = omp_get_thread_num();
        printf("I am %d thread.\n", rank);
        rank++; // конфликт обращений к переменной rank
    }

    printf("Final value of rank: %d\n", rank);

    return 0;

    переменная rank общая и каждая нить увеличивает ее значение на 1, что может привести к 
    конфликту обращений и непредсказуемому значению переменной после выполнения параллельной области.
*/