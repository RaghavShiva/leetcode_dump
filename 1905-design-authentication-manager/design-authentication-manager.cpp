#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct Node {
    string key;
    int exp;
    Node* prev;
    Node* next;

    Node(string k, int e) : key(k), exp(e), prev(nullptr), next(nullptr) {}
};

class AuthenticationManager {
    int ttl;
    unordered_map<string, Node*> lookup;
    Node* head;
    Node* tail;

public:
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;

        // Sentinel head and tail
        head = new Node("inf", INT_MAX);
        tail = new Node("inf", INT_MAX);

        head->next = tail;
        tail->prev = head;
    }

    void generate(string tokenId, int currentTime) {
        cleanup(currentTime);

        Node* node = new Node(tokenId, currentTime + ttl);
        lookup[tokenId] = node;
        addNode(node);
    }

    void renew(string tokenId, int currentTime) {
        cleanup(currentTime);

        if (lookup.count(tokenId) && lookup[tokenId]->exp > currentTime) {
            deleteNode(lookup[tokenId]);
            lookup.erase(tokenId);

            Node* node = new Node(tokenId, currentTime + ttl);
            lookup[tokenId] = node;
            addNode(node);
        }
    }

    int countUnexpiredTokens(int currentTime) {
        cleanup(currentTime);
        return lookup.size();
    }

private:
    void cleanup(int currentTime) {
        Node* curr = head->next;

        while (curr != tail && curr->exp <= currentTime) {
            Node* toRemove = curr;
            curr = curr->next;
            lookup.erase(toRemove->key);
            deleteNode(toRemove);
        }
    }

    void addNode(Node* node) {
        Node* prev = tail->prev;

        prev->next = node;
        node->prev = prev;

        node->next = tail;
        tail->prev = node;
    }

    void deleteNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;

        if (prev) prev->next = next;
        if (next) next->prev = prev;

        delete node;
    }
};
