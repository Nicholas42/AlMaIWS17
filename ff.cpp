#include <iostream>
#include "gph_io.h"

struct list{
	list *next;
	edge *e;
};

list *dfs(graph *g, int v, bool *besucht){
	if(v == 1){
		list *l = new list;
		l->next = nullptr;
		l->e = nullptr;
		return l;			
	}
	for(edge *e = g->nodes[v]; e != NULL; e = e->next){
		if(!e->gegen && e->f == e->weight){
			continue;
		}
		if(e->gegen && e->weight == 0){
			continue;
		}
		if(!besucht[index(e->target)]){
			besucht[index(e->target)] = true;
			list *l = dfs(g, index(e->target), besucht);
			if(l != nullptr){
				list *ret = new list;
				ret->next = l; 	
				ret->e = e;
				return ret;
			}
		}
	}	
	return nullptr;
}

void augmentiere(list *l){
	double minimum = -1;
	for(list *i = l; i->e; i = i->next){
		if(i->e->gegen){
			if(minimum == -1 || i->e->weight < minimum){
				minimum = i->e->weight;
			}
		}
		else{
			if(minimum == -1 || i->e->weight - i->e->f < minimum){
				minimum = i->e->weight - i->e->f;
			}	
		}
	}
	for(list *i = l; i->e; i = i->next){
		edge *e = i->e;
		if(!e->gegen){
			e->f += minimum;
			e->gegenkante->weight += minimum;
		}else{
			e->gegenkante->f -= minimum;
			e->weight -= minimum;
		}
	}
}

int main(){
	graph *g = read_edges_file("lameFF.txt");
	for(int i = 0; i < g->node_count; i++){
		for(edge *e = g->nodes[i]; e; e = e->next){
			if(!e->gegen){
				add_gegenedge(g, e->target, i+1, e->f, e);
			}
		}
	}
	list *l;
	bool *besucht = new bool[g->node_count];
	for(int i = 0; i < g->node_count; i++){
		besucht[i] = false;
	}
	l = dfs(g, 0, besucht);
	while(l != nullptr){
		augmentiere(l);
		for(int i = 0; i < g->node_count; i++){
			besucht[i] = false;
		}
		l = dfs(g, 0, besucht);
	}
	for(int i = 0; i < g->node_count; i++){
		for(edge *e = g->nodes[i]; e; e = e->next){
			if(!e->gegen){
				std::cout << i+1 << " " << e->target << " " << e->f << std::endl;
			}
		}
	}
}
