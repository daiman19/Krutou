#include <iostream>
#include "Graph.h"

int main()
{
	setlocale (LC_ALL, "RUS");
	Graph test;
	//���������� ������� ���������
	test.read_adjancensyM_from_file("example_adj_m_input.txt");
	//������ ������� ��������� � ����
	test.write_adjancensyM_in_file("example_adj_m_output.txt");
	//���������� ������ �����
	test.read_edge_list_from_file("example_edge_list_input.txt");
	//������ ������ �����
	test.write_edge_list_in_file("example_edge_list_output.txt");
	//���������� ������ ���������
	test.read_adjancensyL_from_file("example_adj_l_input.txt");
	//������ ������ ���������
	test.write_adjancensyL_in_file("example_adj_l_output.txt");
	return 0;
}