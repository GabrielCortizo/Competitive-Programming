Explique, fale a complexidade e implemente o algoritmo DFS.

Explicação:
O algoritmo de busca em profundidade, atravessa um grafo, a cada braço criado vai até o final do grafo(até achar um nó que foi visitado ou não haver mais nós) e faz o caminho de volta.
Complexidade: O(V+E)

rep(i,0,n){
    if(!visited[n])  DFS(n);
}
void DFS(int node){
 ii u;
 visited[node] = 1;
 
 for(auto u:graph[node]){
 if(!visited[u.x])
 DFS(u.x);
 }
}

