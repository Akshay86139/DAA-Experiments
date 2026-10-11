// Name: AKSHAY KUMAR
// Roll No: 25/DA/008
// Program: Huffman Coding for Data Compression

#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void generateCodes(Node* root, string code) {
    if (root == NULL)
        return;

    if (!root->left && !root->right) {
        cout << root->ch << " : " << code << endl;
        return;
    }

    generateCodes(root->left, code + "0");
    generateCodes(root->right, code + "1");
}

int main() {
    cout << "Name: AKSHAY KUMAR" << endl;
    cout << "Roll No: 25/DA/008" << endl;
    cout << "\nHuffman Coding for Data Compression\n";

    char characters[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int n = 6;

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < n; i++) {
        pq.push(new Node(characters[i], freq[i]));
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    cout << "\nCharacter : Huffman Code\n";
    generateCodes(pq.top(), "");

    return 0;
}
