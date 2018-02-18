class Solution {
public:
	/*
	* @param node: A undirected graph node
	* @return: A undirected graph node
	*/
	UndirectedGraphNode* cloneGraph(UndirectedGraphNode* graph) {

		if (!graph) return NULL;
		unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> fx;
		queue<UndirectedGraphNode *> q;
		q.push(graph);
		UndirectedGraphNode *graphcopy = new UndirectedGraphNode(graph->label);
		fx[graph] = graphcopy;
		while (!q.empty()) {
			UndirectedGraphNode *node = q.front();
			q.pop();
			int n = node->neighbors.size();
			for (int i = 0; i < n; i++) {
				UndirectedGraphNode *t = node->neighbors[i];
				if (fx.find(t) == fx.end()) {
					q.push(t);
					UndirectedGraphNode *p = new UndirectedGraphNode(t->label);
					fx[t] = p;
					fx[node]->neighbors.push_back(p);
				}
				else {
					fx[node]->neighbors.push_back(fx[t]);
				}
			}
		}
		return graphcopy;
	}
};
