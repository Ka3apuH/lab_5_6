
###Задача:
реализовать контейнер-адаптер `priority_queue`. Принцип работы очереди:
первым извлекается наибольший элемент. Контейнер должен
обеспечивать логарифмическое время работы для добавления и удаления элемента.

###реализуемый класс очереди:
[`priority_queue`](priority_queue/priority_queue.h) находится в
<pre>$PROJECT_DIR$/priority_queue/priority_queue.h</pre>

###тестирование класса:
тестирование данного класса : [`lab1_priority_queue_TEST`](test/priority_queue_TEST.cpp) находится в
<pre> $PROJECT_DIR$/test/priority_queue_TEST.cpp </pre>

Для запуска тестирования данного класса неоходимо выполнить следующее:

####собрать проект
```bash
$ mkdir build
$ cd build/
$ cmake ..
$ make 
```
####запустить тестирование
```bash
./test/lab1_priority_queue_TEST
```
![alt text](images/Снимок%20экрана%20от%202022-02-24%2005-40-34.png "Описание будет тут")
###banchmark метода класса `add_element`:

banchmark : [`lab1_priority_queue_BENCHMARK`](Benchmark/benchmark_priority_queue.cpp) находится в
<pre> $PROJECT_DIR$/Benchmark/benchmark_priority_queue.cpp </pre>

Для запуска banchmark метода данного класса неоходимо выполнить следующее:

####собрать проект
```bash
$...
```
####запустить banchmark
```bash
./Benchmark/lab1_priority_queue_BENCHMARK
```

![alt text](images/Снимок%20экрана%20от%202022-02-24%2005-47-46.png "Описание будет тут")
Как можно заметить на данном скрине добавление элемента очень сильно приближенно к сложности 

`O(ln N)`

 причем это добавление сразу `N` элементов (пока не придумал как проверить добавление сразу к заполненной очереди добавить 1 элемент)
и при этом логприфмическая сложность на 93%