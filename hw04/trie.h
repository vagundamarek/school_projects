#ifndef TRIE_H
#define TRIE_H
#pragma once

#include <algorithm>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using BitVec = std::vector<bool>;

template <typename Value>
class Trie {
public:
    using ItemList = std::vector<std::pair<BitVec, const Value&>>;

    class Node {
        std::unique_ptr<Value> n_val;
        Node* n_parent;
        std::unique_ptr<Node> n_left;
        std::unique_ptr<Node> n_right;

        bool isLeaf() const { return n_left == nullptr && n_right == nullptr; }
        bool isRoot() const { return n_parent == nullptr; }
        bool hasValue() const { return n_val != nullptr; }

        void mergeTrieRecursive(const Node& other)
        {
            if (!hasValue() && other.hasValue())

                n_val = std::make_unique<Value>(*other.n_val);

            if (other.n_left != nullptr) {
                if (n_left == nullptr)
                    n_left = std::make_unique<Node>();
                n_left->mergeTrieRecursive(*other.n_left.get());
            }
            if (other.n_right != nullptr) {
                if (n_right == nullptr)
                    n_right = std::make_unique<Node>();
                n_right->mergeTrieRecursive(*other.n_right.get());
            }
        }

        /*
         * Gets direction from parent to this node
         *
         */
        bool parentDirection()

        {
            return (this == parent()->n_right.get());
        }

    public:
        const Node* left() const
        {

            return n_left.get();
        }
        const Node* right() const
        {
            return n_right.get();
        }
        const Node* parent() const
        {
            return n_parent;
        }
        const Value* value() const
        {
            return n_val.get();
        }

        friend class Trie;
    };

private:
    std::unique_ptr<Node> t_root;

    void createEmptyNodeForPath(Node** n, Node** previous, bool x, bool* create)
    {
        *create = true;
        if (*previous == nullptr)
            *previous = *n;
        if (x) {
            (*previous)->n_right = std::make_unique<Node>();
            *n = (*previous)->n_right.get();
        } else {
            (*previous)->n_left = std::make_unique<Node>();
            *n = (*previous)->n_left.get();
        }
        (*n)->n_parent = *previous;
    }

    Node* getNodeWithInsertion(const BitVec& key, bool* create)
    {

        Node* previous = nullptr;
        Node* n = t_root.get();

        for (auto x : key) {

            if (x) {
                if (n->n_right != nullptr)
                    n = n->n_right.get();
                else
                    createEmptyNodeForPath(&n, &previous, x, create);
            } else {
                if (n->n_left != nullptr)
                    n = n->n_left.get();
                else
                    createEmptyNodeForPath(&n, &previous, x, create);
            }
            previous = n;
        }

        return n;
    }

    const Node* getNode(const BitVec& key) const
    {

        Node* n = t_root.get();

        for (auto x : key) {
            if (x) {
                if (n != nullptr)
                    n = n->n_right.get();
                else
                    return nullptr;
            } else {
                if (n != nullptr)
                    n = n->n_left.get();
                else
                    return nullptr;
            }
        }
        return n;
    }
    Node* getNode(const BitVec& key)
    {
        return const_cast<Node*>((const_cast<Trie const*>(this))->getNode(key));
    }

    void recursiveRemove(Node* n)
    {
        auto parent = n->n_parent;
        if (n->isRoot()) {
            n->n_val.reset();
            return;
        }
        bool direction = n->parentDirection();
        if (direction) {
            parent->n_right.reset();
            if (!parent->hasValue() && parent->n_left == nullptr)
                recursiveRemove(parent);
        } else {
            parent->n_left.reset();
            if (!parent->hasValue() && parent->n_right == nullptr)
                recursiveRemove(parent);
        }
    }

public:
    Trie()
        : t_root(std::make_unique<Node>())
    {
    }
    Trie(const Trie& other)
        : Trie()
    {
        mergeWith(other);
    }

    Trie& operator=(const Trie& other)
    {
        auto temp(other);
        std::swap(temp.t_root, t_root);
        return *this;
    }

    const Node& root() const { return *t_root; }
    bool empty() const { return !t_root->hasValue(); }
    const Value* search(const BitVec& key) const
    {
        const Node* n = getNode(key);
        if (n != nullptr && n->n_val.get() != nullptr)
            return n->n_val.get();
        return nullptr;
    }
    Value* search(const BitVec& key)
    {
        return const_cast<Value*>((const_cast<Trie const*>(this))->search(key));
    }

    const Value& at(const BitVec& key) const
    {
        const Value* v = search(key);
        if (v == nullptr)
            throw std::out_of_range("key not found\n");
        return *v;
    }

    Value& at(const BitVec& key)
    {
        return const_cast<Value&>((const_cast<Trie const*>(this))->at(key));
    }

    void remove(const BitVec& key)
    {
        Node* n = getNode(key);
        if (n == nullptr || !n->hasValue())
            return;
        if (n->isLeaf())
            recursiveRemove(n);
        else
            n->n_val.reset();
    }

    bool insert(const BitVec& key, const Value& value)
    {
        bool create = false;
        Node* n = getNodeWithInsertion(key, &create);
        if (!create && n->hasValue())
            return false;
        n->n_val = std::make_unique<Value>(value);
        return true;
    }
    Value& operator[](const BitVec& key)
    {
        bool create = false;
        Node* n = getNodeWithInsertion(key, &create);
        if (create || !n->hasValue())
            n->n_val = std::make_unique<Value>();
        return *n->n_val;
    }
    void clear()
    {
        t_root->n_val.reset();
        t_root->n_left.reset();
        t_root->n_right.reset();
    }

    void mergeWith(const Trie& other)
    {
        t_root.get()->mergeTrieRecursive(*other.t_root.get());
    }
    ItemList items() const
    {

        ItemList container;

        std::stack<Node*> s_nodes;
        std::stack<BitVec> s_keys;
        s_nodes.push(t_root.get());
        s_keys.push({});

        while (!s_nodes.empty()) {

            BitVec key{ (s_keys.top()) };
            Node* n = s_nodes.top();
            s_nodes.pop();
            s_keys.pop();
            if (n->hasValue()) //element has value
            {
                container.emplace_back(key, *(n->n_val));
            }
            if (n->n_right != nullptr) //element has right
            {
                BitVec childKey{ key };
                childKey.push_back(true);
                s_nodes.push(n->n_right.get());
                s_keys.push(childKey);
            }
            if (n->n_left != nullptr) //element has left
            {
                BitVec childKey{ key };
                childKey.push_back(false);
                s_nodes.push(n->n_left.get());
                s_keys.push(childKey);
            }
        }

        return container;
    }
    void draw(std::ostream& output) const
    {
        int i = 0;
        std::queue<std::pair<std::string, Node*>> q;
        q.emplace(std::make_pair("X" + (std::to_string(i)), t_root.get()));
        output << "digraph {" << std::endl;
        while (!q.empty()) {
            std::pair<std::string, Node*> element = q.front();
            q.pop();
            output << '\"' << element.first << "\" [label=\"";
            if (element.second->hasValue())
                output << *element.second->n_val;
            output << "\"]" << std::endl;

            if (element.second->n_left != nullptr) {
                std::string name = element.first + 'L' + std::to_string(i + 1);

                output << '\"' << element.first << "\" -> \"" << name << "\" [label=\"0\"]" << std::endl;
                q.emplace(std::make_pair(name, element.second->n_left.get()));
            }
            if (element.second->n_right != nullptr) {
                std::string name = element.first + 'R' + std::to_string(i + 1);
                output << '\"' << element.first << "\" -> \"" << name << "\" [label=\"1\"]" << std::endl;
                q.emplace(std::make_pair(name, element.second->n_right.get()));
            }
            i++;
        }
        output << "}";
    }
};

#endif
