// 理解のために練習

#include <vector>

class UnionFind {
private:
    std::vector<int> parent;

public:
    UnionFind(int n)
    {
        parent.resize(n, -1);
    }

    int find(int x)
    {
        if (parent[x] < 0) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int x, int y)
    {
        x = find(x); y = find(y);

        if (x == y) return false;

        if (parent[x] > parent[y]) std::swap(x, y);

        parent[x] += parent[y];
        parent[y] = x;

        return true;
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    int size(int x)
    {
        return -parent[find(x)];
    }
};
