struct Node {
    string name;
    map<string, Node*> children;
    string signature;
    Node(string name) : name(name) {}
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = new Node("");
        for (const auto& path : paths) {
            Node* curr = root;
            for (const string& folder : path) {
                if (!curr->children.count(folder)) {
                    curr->children[folder] = new Node(folder);
                }
                curr = curr->children[folder];
            }
        }

        unordered_map<string, int> signatureCount;
        computeSignature(root, signatureCount);

        vector<vector<string>> result;
        vector<string> currentPath;
        collectPaths(root, currentPath, result, signatureCount);

        deleteTree(root);

        return result;
    }

private:
    string computeSignature(Node* node, unordered_map<string, int>& signatureCount) {
        if (node->children.empty()) {
            node->signature = "";
            return node->signature;
        }

        vector<string> signatures;
        for (auto& [name, child] : node->children) {
            string childSig = computeSignature(child, signatureCount);
            signatures.push_back(name + "(" + childSig + ")");
        }
        sort(signatures.begin(), signatures.end());

        node->signature = "";
        for (const string& sig : signatures) {
            node->signature += sig;
        }
        node->signature = "(" + node->signature + ")";  
        signatureCount[node->signature]++;
        return node->signature;
    }
    void collectPaths(Node* node, vector<string>& path, vector<vector<string>>& result,
                      unordered_map<string, int>& signatureCount) {
        if (node->name != "") path.push_back(node->name);
        if (node->signature != "" && signatureCount[node->signature] >= 2) {
            path.pop_back(); 
            return;
        }

        if (!path.empty()) result.push_back(path);

        for (auto& [name, child] : node->children) {
            collectPaths(child, path, result, signatureCount);
        }

        if (!path.empty()) path.pop_back();
    }

    void deleteTree(Node* node) {
        for (auto& [name, child] : node->children) {
            deleteTree(child);
        }
        delete node;
    }
};
