#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Класс для работы с графом
class Graph
{
	//Структура ребра графа
	struct Edge 
	{
		int from,to;
		int weigh;
	};

	public:
		// Матрица смежности
		int** adjacency_m;
		//Список смежности
		vector <vector<int>> adjacency_l;
		//Список ребер
		Edge* edges;
		//Кол-во вершин в графе
		int count_vertex;
		//Кол-во ребер в графе
		int count_edge;
		Graph(void);
		~Graph(void);
		//Чтение матрицы смежности из файла
		void read_adjancensyM_from_file(string filepath);
		//Запись матрицы смежности в файл
		void write_adjancensyM_in_file(string filepath);
		//Вывод матрицы смежности в консоль
		void write_adjancensyM_in_console();
		//Чтение списка ребер из файла
		void read_edge_list_from_file(string filepath);
		//Запись списка ребер в файл
		void write_edge_list_in_file(string filepath);
		//Вывод списка ребер в консоль
		void write_edge_list_in_console();
		//Чтение списка смежности из файла
		void read_adjancensyL_from_file(string filepath);
		//Запись списка смежности в файл
		void write_adjancensyL_in_file(string filepath);
	private:
		//Инициализация матрицы смежности
		void init_adjacency_matrix(int size);
		//Инициализация списка ребер
		void init_edge_matrix(int size);
};

