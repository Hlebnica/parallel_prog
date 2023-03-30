#include <iostream>
#include <omp.h>
#include <stdio.h>

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
    Номер подзадачи, чтобы каждый поток или процесс обрабатывал определенную часть массива. 
    Например, если мы разбиваем массив на 10 подзадач, то каждый поток или 
    процесс может обрабатывать десятую часть массива, используя номер подзадачи 
    для идентификации этой части.

    Идентификатор может использоваться для идентификации конкретного 
    потока или процесса и его соответствующей подзадачи. Например, если у 
    нас есть 10 потоков, то мы можем использовать идентификаторы 0-9 для каждого потока, 
    чтобы каждый поток обрабатывал соответствующую подзадачу.

    Какую роль играют количество подзадач и номер подзадачи в параллельной задаче
    */

    /**/
    // LAB 4
    int number_threads_3;
    printf("Write number of threads for lab 4: ");
    scanf_s("%d", &number_threads_3);
    

    #pragma omp parallel num_threads(number_threads_3)
    {
        int rank = omp_get_thread_num();
        printf("I am %d thread\n", rank);
    }
    

    /*
    // LAB 5
    // 5_1
    int N = 10;
    int sum = 0;

    #pragma omp parallel num_threads(2) reduction(+:sum)
    {
        int rank = omp_get_thread_num();
        int start = rank * N / 2 + 1;
        int end = (rank + 1) * N / 2;
        int local_sum = 0;

        for (int i = start; i <= end; i++) {
            local_sum += i;
        }

        sum += local_sum;
        printf("[%d]: Sum = %d\n", rank, local_sum);
    }

    printf("Sum = %d\n", sum);
    */

    return 0;
}


