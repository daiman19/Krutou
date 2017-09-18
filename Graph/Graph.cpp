#include <iostream>
#include "Graph.h"
#include <fstream>
#include <ostream>


Graph::Graph(void)
{
	//Обнуляем кол-во вершин и ребер в графе
	count_vertex = 0;
	count_edge = 0;
}

Graph::~Graph(void)
{

}

void Graph::read_adjancensyM_from_file(string filepath)
{
	//Открываем файл по пути filepath на чтение
	ifstream file;
	file.open(filepath, ios::in);
	if (file) {
		//Считываем кол-во вершин
		file>>count_vertex;
		//Создаём матрицу смежности
		init_adjacency_matrix(count_vertex);
		//Считываем матрицу смежности
		for (int i=0; i<count_vertex; i++)
			for (int j=0; j<count_vertex; j++)
				file>>adjacency_m[i][j];
	} else {
		cout<<"Ошибка чтения файла";
	}
	file.close();
}

void Graph::write_adjancensyM_in_file(string filepath)
{
	//Открываем файл по пути filepath на запись
	ofstream file;
	file.open(filepath,ios::out);
	if (file) {
		//Записываем число ребер
		file<<count_vertex<<endl;
		//Записываем матрицу смежности
		for (int i=0; i<count_vertex; i++) {
			for (int j=0; j<count_vertex; j++) {
				file<<adjacency_m[i][j]<<" ";
			}
			file<<endl;
		}
	} else {
		cout<<"Ошибка записи в файл";
	}
	file.close();
}

void Graph::write_adjancensyM_in_console()
{
	for (int i=0; i<count_vertex; i++) {
		for (int j=0; j<count_vertex; j++) {
			cout<<adjacency_m[i][j]<<" ";
		}
		cout<<endl;
	}
}

void Graph::read_edge_list_from_file(string filepath)
{
	//Открываем файл по пути filepath на чтение
	ifstream file;
	file.open(filepath, ios::in);
	if (file) {
		//Считываем кол-во вершин
		file>>count_edge;
		//Создаём список ребер
		init_edge_matrix(count_edge);
		//Считываем список ребер
		//Формат: from to weight
		for (int i=0; i<count_edge; i++)
			file>>edges[i].from>>edges[i].to>>edges[i].weigh;
	} else {
		cout<<"Ошибка чтения файла";
	}
	file.close();
}

void Graph::write_edge_list_in_file(string filepath)
{
	//Открываем файл по пути filepath на запись
	ofstream file;
	file.open(filepath,ios::out);
	if (file) {
		//Записываем кол-во ребер
		file<<count_edge<<endl;
		//Записываем список ребер
		for (int i=0; i<count_edge; i++) {
			file<<edges[i].from<<" ";
			file<<edges[i].to<<" ";
			file<<edges[i].weigh<<" ";
			file<<endl;
		}
	} else {
		cout<<"Ошибка записи в файл";
	}
	file.close();
}

void Graph::read_adjancensyL_from_file(string filepath)
{
	//Открываем файл по пути filepath на чтение
	ifstream file;
	file.open(filepath, ios::in);
	int temp;
	if (file) {
		//Считываем кол-во вершин
		file>>count_vertex;
		//Преобразуем считывание матрицы смежности в список смежности
		adjacency_l.resize(count_vertex);
		for(int i=0; i<count_vertex; i++)
			for(int j=0; j<count_vertex; j++)
			{
				file >> temp;
				if (temp)
					adjacency_l[i].push_back(j+1);
			}
	} else {
		cout<<"Ошибка чтения файла";
	}
	file.close();
}

void Graph::write_adjancensyL_in_file(string filepath)
{
	ofstream file;
	file.open(filepath,ios::out);
	if (file) {
		//Записываем кол-во вершин
		file<<count_vertex<<endl;
		//Выводим в файл список смежности
		for (int i=0; i<adjacency_l.size(); i++) {
			for (int j=0; j<adjacency_l[i].size(); j++)
				file<<adjacency_l[i][j]<<" ";
			file<<endl;
		}
		
	} else {
		cout<<"Ошибка записи в файл";
	}
	file.close();
}

void Graph::write_edge_list_in_console()
{
	for (int i=0; i<count_edge; i++) {
		cout<<edges[i].from<<" ";
		cout<<edges[i].to<<" ";
		cout<<edges[i].weigh<<" ";
		cout<<endl;
	}
}

void Graph::init_edge_matrix(int size)
{
	edges = new Edge [size];
}

void Graph::init_adjacency_matrix(int size)
{
	adjacency_m = new int* [size];
	for (int i=0; i<size;i++)
		adjacency_m[i] = new int [size];
}
