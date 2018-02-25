
class	 dic_tree_node
{
public:
	char c;
	dic_tree_node * next[27];
	bool is_end;
	dic_tree_node(char cc = ' ')
	{
		c = cc;
		for (int i = 0; i < 27; ++i)
		{
			next[i] = nullptr;
		}
		is_end = false;
	}

};

class WordDictionary {
public:
	/*
	* @param word: Adds a word into the data structure.
	* @return: nothing
	*/
	dic_tree_node *root = new dic_tree_node();
	void addWord(string &word) {
		// write your code here
		int l = word.size();
		dic_tree_node *p = root;
		for (int i = 0; i < l; ++i)
		{
			char t = word[i];
			if (!p->next[(int)(t - 'a')])
			{
				p->next[(int)(t - 'a')] = new dic_tree_node(t);
			}

			p = p->next[(int)(t - 'a')];
		}
		p->is_end = true;
	}

	/*
	* @param word: A word could contain the dot character '.' to represent any one letter.
	* @return: if the word is in the data structure.
	*/
	bool dfs(dic_tree_node *node, string &s, int k)
	{
		if (k == s.size())
		{
			return node->is_end;
		}
		char t = s[k];
		if (t == '.')
		{
			bool temp = false;
			for (auto i = 'a'; i < 'z'; ++i)
			{
				if (node->next[(int)(i - 'a')]) {
					temp = temp || dfs(node->next[(int)(i - 'a')], s, k + 1);
				}
			}
			return temp;
		}
		else
		{
			if (!node->next[(int)(s[k] - 'a')]) return false;
			return dfs(node->next[(int)(s[k] - 'a')], s, k + 1);
		}
	}
	bool search(string &word) {
		// write your code here
		return dfs(root, word, 0);
	}
};
