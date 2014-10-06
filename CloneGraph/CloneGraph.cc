/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode* clone(UndirectedGraphNode* node, map<UndirectedGraphNode*, UndirectedGraphNode*>& graph) {
        if (node == NULL) {
            return NULL;
        }    
        if (graph.find(node) != graph.end()) {
            return graph[node];
        }
        UndirectedGraphNode* newnode = new UndirectedGraphNode(node->label);
        graph[node] = newnode;
        for (int i = 0; i < node->neighbors.size(); i++) {
            UndirectedGraphNode* next = clone(node->neighbors[i], graph);
            newnode->neighbors.push_back(next);
        }
        return newnode;
    }
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        map<UndirectedGraphNode*, UndirectedGraphNode*> graph;
        return clone(node, graph);
    }
};
