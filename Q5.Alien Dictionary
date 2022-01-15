void DFSRec(unordered_set<int> adj[], int u, string &ans, vector<bool> &visited)
    {
        visited[u] = true;
        for(auto v: adj[u])
        {
            if(visited[v] == false)
            {
                DFSRec(adj, v, ans, visited);
            }
        }
        ans.push_back(u+'a');
    }
    
    string topologicalSort(unordered_set<int> adj[], int V)
    {
        string ans;
        vector<bool> visited(V, false);
        
        for(int v=0; v < V; v++)
        {
            if(adj[v].size())
            {
                for(auto u: adj[v])
                {
                    if(visited[u] == false)
                    {
                        DFSRec(adj, u, ans, visited);
                    }
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    string findOrder(string words[], int N, int K) {
    unordered_set<int> adj[K];
    for(int i = 0; i < N-1; i++)
    {
        string word1 = words[i];
        string word2 = words[i+1];
        
        for(int j = 0; j < min(word1.size(), word2.size()); j++)
        {
            if(word1[j] != word2[j])
            {
                int index1 = word1[j] - 'a';
                int index2 = word2[j] - 'a';
                
                adj[index1].insert(index2);
                
                break;
            }
        }
    }
    return topologicalSort(adj,K);
    }
