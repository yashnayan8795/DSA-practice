#include <unordered_map>
using namespace std;

class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* next;
        Node* prev;
        Node(int k, int v) {
            key = k;
            val = v;
            next = prev = nullptr;
        }
    };

    Node* head;
    Node* tail;
    unordered_map<int, Node*> map;
    int limit;

    LRUCache(int capacity) {
        limit = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (map.find(key) == map.end()) return -1;

        Node* node = map[key];
        deleteNode(node);
        addNode(node);  // Move to front
        return node->val;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            Node* existing = map[key];
            deleteNode(existing);
            map.erase(key);
        }

        if (map.size() == limit) {
            Node* lru = tail->prev;
            deleteNode(lru);
            map.erase(lru->key);
           // delete lru; // Free memory
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        map[key] = newNode;
    }

    void addNode(Node* node) {
        Node* nextNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
    }

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
};
