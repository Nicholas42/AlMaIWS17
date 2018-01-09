#ifndef _gph_io_h_
#define _gph_io_h_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

struct graph
{
	//Array mit Pointern auf alle Knoten
	struct edge **nodes;

	int node_count;
	int edge_count;
};

struct edge
{
	int target;
	double weight;

	//Nächste Kante in der Adjazenzliste
	struct edge *next;
};

int index(int v)
{
	return (v - 1);
}

void add_edge(graph *g, int v1, int v2, double w)
{
	//Prüfe Indizes auf Korrektheit
	assert(v1 >= 1 && v2 >= 1);
	assert(v1 <= g->node_count && v2 <= g->node_count);

	//Wir wollen keine Loops
	assert(v1 != v2);

	edge *t;
	t = new struct edge();
	t->target = v2;
	t->next = g->nodes[index(v1)];
	t->weight = w;
	g->nodes[index(v1)] = t;
	g->edge_count += 1;
}

struct graph *init(int size)
{
	struct graph *g = new struct graph();
	g->node_count = size;
	g->edge_count = 0;
	g->nodes = new edge *[size];
	for (int i = 0; i < size; i++)
	{
		g->nodes[i] = nullptr;
	}
	return g;
}

const double default_weight = 0.0;

struct graph *read_edges_file(string filename)
{
	struct graph *g;
	string line;
	int node_count, edge_count;

	//Öffne Datei und prüfe auf Erfolg
	ifstream myfile(filename);
	assert(myfile);

	//Lese Anzahl Knoten
	getline(myfile, line);
	node_count = stoi(line);
	g = init(node_count);

	//Lese Anzahl Kanten
	getline(myfile, line);
	edge_count = stoi(line);

	for (int i = 0; i < edge_count; i++)
	{
		//Lese eine Kante ein
		int a, b;
		double w;
		getline(myfile, line);
		stringstream ss(line);
		ss >> a >> b;
		//Fehler, falls die Zeile falsch formatiert ist
		assert(ss);

		//Versuche noch ein Gewicht zu lesen, falls keins dasteht, nehme 0.0
		ss >> w;
		if(!ss){
		  w = default_weight;
		}
		add_edge(g, a, b, w);
	};
	assert(edge_count == g->edge_count);
	myfile.close();
	return g;
}

void write_edges_file(string filename, graph *g)
{
	//Öffnet Datei und prüfe auf Erfolg
	ofstream out(filename);
	assert(out);

	out << g->node_count << endl;
	out << g->edge_count << endl;

	for (int i = 0; i < g->node_count; i++)
	{
		for (edge *t = g->nodes[i]; t != nullptr; t = t->next)
		{
			out << i + 1 << " " << t->target << " " << t->weight << endl;
			cout << i + 1 << " " << t->target << " " << t->weight << endl;
		}
	}
	out.close();
}

int **init_matrix(int n)
{
	assert(n > 0);

	int** mat = new int *[n];
	for (int i = 0; i < n; i++)
	{
		mat[i] = new int[n]();
	}
	return mat;
}

const char delimiter = ',';
int **read_matrix_file(string filename, int *n)
{
	//Öffne Datei und prüfe auf Erfolg
	ifstream myfile(filename);
	assert(myfile);

	//Lese Knotenzahl/Dimension
	string line;
	getline(myfile, line);
	stringstream ss(line);
	ss >> *n;
	assert(ss);

	int **mat = init_matrix(*n);

	for (int i = 0; i < *n; i++)
	{
		//Lese n-1 mal bis zum Trennzeichen und dann bis zum Ende der Zeile
		for (int j = 0; j < *n - 1; j++)
		{
			//Werfe einen Fehler, falls die Zeile falsch formtatiert ist
			assert(getline(myfile, line, delimiter));
			mat[i][j] = stoi(line);
		}
		assert(getline(myfile, line));
		mat[i][*n - 1] = stoi(line);
	}
	myfile.close();
	return mat;
}

#endif //_gph_io_h_
