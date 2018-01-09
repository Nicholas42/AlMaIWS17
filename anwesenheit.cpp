#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "gph_io.h"

void dfs(graph *g, int v, bool *besucht){
	for(edge *e = g->nodes[v]; e != NULL; e = e->next){
		if(!besucht[index(e->target)]){
			besucht[index(e->target)] = true;
			dfs(g, index(e->target), besucht);
		}
	}	
}

void freigeben(graph *g){
	for(int i = 0; i < g->node_count; i++){
		edge *temp;
		for(edge *e = g->nodes[i]; e; e = temp){
			temp = e->next;
			delete e;
		}
	}
	delete g->nodes;
	delete g;
}


int main(){
	graph *g = read_edges_file("erdosgraph.txt");
	bool *besucht = new bool[g->node_count];
	for(int i = 0; i < g->node_count; i++){
		besucht[i] = false;
	}
	besucht[6] = true;
	dfs(g, 6, besucht);
	for(int i = 0; i < g->node_count; i++){
		if(besucht[i]){
			std::cout << i+1 << std::endl;
		}
	}
	ifstream myfile("legende.txt");
	string line;
	string *namen = new string[g->node_count];
	int i = 0;
	while(getline(myfile, line)){
		std::cout << line << std::endl;
		namen[i] = line;
		i++;
	}
	freigeben(g);
}


