#cible de compilation avec les matrice d'adjacence
Matrix: Node_Matrix.o graph_matrix.o main_matrix.o generic_matrix.o edge_matrix.o
	gcc Node_Matrix.o graph_matrix.o main_matrix.o edge_matrix.o generic_matrix.o -o Matrix
	@echo '----Done----'

Node_Matrix.o: Node_Matrix.c Node_Matrix.h
	gcc -g -DGMATRICE -c Node_Matrix.c

graph_matrix.o: graph_matrix.c graph_matrix.h edge_matrix.o Node_Matrix.o
	gcc -g -DGMATRICE -c graph_matrix.c

main_matrix.o: graph_matrix.o Node_Matrix.o generic_matrix.o main.c
	gcc -g -DGMATRICE -c main.c -o main_matrix.o

generic_matrix.o: graph_matrix.o
	gcc -g -DGMATRICE -c generic.c -o generic_matrix.o

edge_matrix.o: Edge.c Node_Matrix.o
	gcc -g -DGMATRICE -c Edge.c -o edge_matrix.o



#cible de compilation avec les liste d'adjacence
List: Node_list.o graph_list.o main_list.o generic_list.o edge_list.o
	gcc Node_list.o graph_list.o main_list.o generic_list.o edge_list.o -o List
	@echo '----Done----'

Node_list.o: Node_list.c Node_list.h
	gcc -g -DGMATRICE -c Node_list.c

graph_list.o: graph_list.c graph_list.h Node_list.o edge_list.o
	gcc -g -DGLISTE -c graph_list.c

main_list.o: graph_list.o Node_list.o generic_list.o main.c
	gcc -g -DGLISTE -c main.c -o main_list.o

generic_list.o: graph_list.o Node_list.o
	gcc -g -DGLISTE -c generic.c -o generic_list.o

edge_list.o: Edge.c Node_list.o
	gcc -g -DGMATRICE -c Edge.c -o edge_list.o

clean:
	rm *.o
	@echo '-- project cleaned --'