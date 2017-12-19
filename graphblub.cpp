#include <iostream>
#include "gph_io.h"

int main(){
  graph *g = read_edges_file("nikolaus.txt");
  int **mat = init_matrix(g->node_count);
  for(int i = 0; i < g->node_count; i++){
    std::cout << "Knoten " << i+1 << " hat Nachbarn:" << std::endl;
    int deg = 0;
    for(edge *e = g->nodes[i]; e; e = e->next){
      mat[i][index(e->target)] = 1;
      std::cout << "\t" << e->target << std::endl;
      deg++;
    }
    std::cout << "\tInsgesamt " << deg << " ausgehende Kanten." << std::endl;
  }

  for(int i = 0; i < g->node_count; i++){
    for(int j = 0; j < g->node_count; j++){
      std::cout << mat[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

