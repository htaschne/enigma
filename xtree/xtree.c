#include <stdio.h>

void explora(int gen, int *final_gen, int *total_val, int *qtd_nodes) {
	int nfilhos, nvalores, val;
  scanf("%d %d", &nfilhos, &nvalores);

	while (nfilhos--)
		explora(gen + 1, final_gen, total_val, qtd_nodes);

	while (nvalores--) {
    scanf("%d", &val);
		(*total_val) += val;
	}
	if (gen > *final_gen)
		*final_gen = gen;

	(*qtd_nodes)++;
}

int main() {
  int final_gen = 0; int total_val = 0; int qtd_nodes = 0;
	explora(0, &final_gen, &total_val, &qtd_nodes);
	printf("Quantidade de nodos: %d\n", qtd_nodes);
	printf("Altura da arvore: %d\n", final_gen);
	printf("Soma total dos nodos: %d\n", total_val);
}
