void initialize (int n){}
int q[5000];
int hasEdge(int u, int v){return ++q[u > v ? u : v] == (u > v ? u : v);}
