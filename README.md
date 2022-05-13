
### Задача:
реализовать следующие функции для работы с графами:
 
1. поиск в глубину; 
2. поиск в ширину; 
3. алгоритм Дейкстры; 
4. алгоритм Крускала; 
5. алгоритм Прима; 
6. алгоритм Флойда-Уоршалла; 
7. алгоритм Тарьяна для топологической сортировки; 
8. алгоритм Флёри; 
9. алгоритм поиска эйлерова цикла на основе объединения циклов; 
10. алгоритм Косарайю.



### реализуемый класс графа:
[`graph`](function_graph/graph.h) находится в
<pre>$PROJECT_DIR$/function_graph/graph.</pre>

### тестирование класса:
тестирование данного класса : [`graph_fun_TEST`](test/graph_fun_TEST.cpp) находится в
<pre> $PROJECT_DIR$/test/graph_fun_TEST.cpp </pre>

Для запуска тестирования данного класса неоходимо выполнить следующее:

#### собрать проект
```bash
$ mkdir build
$ cd build/
$ cmake ..
$ make 
```
#### запустить тестирование
```bash
./test/lab_5_6_TEST
```

banchmark : [`graph_fun_BENCHMARK`](Benchmark/graph_fun_benchmark.cpp) находится в
<pre> $PROJECT_DIR$/Benchmark/graph_fun_benchmark.cpp </pre>

Для запуска banchmark метода данного класса неоходимо выполнить следующее:

#### собрать проект
```bash
$...
```
####запустить banchmark
```bash
./Benchmark/lab_5_6_BENCHMARK
```