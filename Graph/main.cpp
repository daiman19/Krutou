#include <iostream>
#include "Graph.h"

int main()
{
	setlocale (LC_ALL, "RUS");
	Graph test;
	//Считывание матрицы смежности
	test.read_adjancensyM_from_file("example_adj_m_input.txt");
	//Запись матрицы смежности в файл
	test.write_adjancensyM_in_file("example_adj_m_output.txt");
	//Считывание списка ребер
	test.read_edge_list_from_file("example_edge_list_input.txt");
	//Запись списка ребер
	test.write_edge_list_in_file("example_edge_list_output.txt");
	//Считывание списка смежности
	test.read_adjancensyL_from_file("example_adj_l_input.txt");
	//Запись списка смежности
	test.write_adjancensyL_in_file("example_adj_l_output.txt");
	return 0;
}