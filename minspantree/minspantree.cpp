#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct side 
{
    int node1;
    int node2;
    int weight;
};

bool compareWeight(side left, side right)
{
    return left.weight < right.weight;
}

bool compareNodes(side left, side right)
{
    if(left.node1 == right.node1) {
        return left.node2 < right.node2;
    }
    return left.node1 < right.node1;
}

int find(vector<int>& disjoint, int o)
{
    if(disjoint[o] == -1) {
        return o;
    }

    int temp = find(disjoint, disjoint[o]);
    disjoint[o] = temp;
    return temp;
}

void join(vector<int>& disjoint, int node1, int node2)
{
    node1 = find(disjoint, node1);
    node2 = find(disjoint, node2);

    disjoint[node1] = node2;
}

int main()
{
    int o, p;
    while(cin >> o && cin >> p && o != 0) {
        vector<side> list;
        for(int i=0; i < p; i++) {
            side s;
            cin >> s.node1 >> s.node2 >> s.weight;
            if(s.node1 > s.node2) {
                swap(s.node1, s.node2);
            }
            list.push_back(s);
        }
        sort(list.begin(), list.end(), compareWeight);
        vector<int> disjoint;
        disjoint.resize(o, -1);
        vector<side> keeper;
        int heavy = 0;
        for(auto i : list){
            int point1 = find(disjoint, i.node1);
            int point2 = find(disjoint, i.node2);
            if(point1 == point2) {
                continue;
            }
            join(disjoint, i.node1, i.node2);
            heavy += i.weight;
            keeper.push_back(i);
        }
        int tree = 0;
        for(auto i : disjoint) {
            if(i < 0) {
                tree++;
            }
        }
        if(tree > 1) {
            cout << "Impossible" << endl;
            continue;
        }
        cout << heavy << endl;
        sort(keeper.begin(), keeper.end(), compareNodes);
        for(auto i : keeper) {
            cout << i.node1 << " " << i.node2 << endl;
        }
    }
}