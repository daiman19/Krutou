#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//����� ��� ������ � ������
class Graph
{
	//��������� ����� �����
	struct Edge 
	{
		int from,to;
		int weigh;
	};

	public:
		// ������� ���������
		int** adjacency_m;
		//������ ���������
		vector <vector<int>> adjacency_l;
		//������ �����
		Edge* edges;
		//���-�� ������ � �����
		int count_vertex;
		//���-�� ����� � �����
		int count_edge;
		Graph(void);
		~Graph(void);
		//������ ������� ��������� �� �����
		void read_adjancensyM_from_file(string filepath);
		//������ ������� ��������� � ����
		void write_adjancensyM_in_file(string filepath);
		//����� ������� ��������� � �������
		void write_adjancensyM_in_console();
		//������ ������ ����� �� �����
		void read_edge_list_from_file(string filepath);
		//������ ������ ����� � ����
		void write_edge_list_in_file(string filepath);
		//����� ������ ����� � �������
		void write_edge_list_in_console();
		//������ ������ ��������� �� �����
		void read_adjancensyL_from_file(string filepath);
		//������ ������ ��������� � ����
		void write_adjancensyL_in_file(string filepath);
	private:
		//������������� ������� ���������
		void init_adjacency_matrix(int size);
		//������������� ������ �����
		void init_edge_matrix(int size);
};

