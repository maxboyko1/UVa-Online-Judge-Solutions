#include <iostream>
#include <queue>
#include <string>
#include <vector>

enum class Color { 
    unassigned = 0, 
    white = 1, 
    black = 2 
};


Color color_complement (Color color)
{
    if (color == Color::white) 
        return Color::black;
    else if (color == Color::black) 
        return Color::white;
    return Color::unassigned;
}

std::string is_bicolorable (std::vector<int> adj[], int n)
{
    int a, b, i;
    Color vertex_color[n];
    std::queue<int> q;
        
    vertex_color[0] = Color::white;
    for (i = 1; i < n; ++i)
        vertex_color[i] = Color::unassigned;
    
    q.push(0);

    while (!q.empty()) {
        a = q.front();
        q.pop();

        for (i = 0; i < adj[a].size(); ++i) {
            b = adj[a][i];

            if (vertex_color[b] == Color::unassigned) {
                vertex_color[b] = color_complement(vertex_color[a]);
                q.push(b);
            } else if (vertex_color[b] != color_complement(vertex_color[a])) {
                return "NOT BICOLORABLE.";
            }
        }
    }

    return "BICOLORABLE.";
}

int main ()
{
    int n, l; 
    int a, b; 

    std::cin >> n;

    while (n) {
        std::vector<int> adj[n];
        std::cin >> l;
        
        while (l--) {
            std::cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        std::cout << is_bicolorable(adj, n) << std::endl;
        std::cin >> n;
    }

    return 0;
}