//
// Created by carson on 1/15/22.
//

#ifndef DOCUDB_TRIE_H
#define DOCUDB_TRIE_H

#include <atomic>
#include <vector>
#include <stdexcept>

// Simple wrapper around strings to prevent copies
class WordIterator {
public:
    WordIterator(std::string word): _original(word) {}
    ~WordIterator() {
        this->_original = nullptr;
        this->_index = 0;
    }

    bool IsEnd() const {
        return this->_original.length() - 1 >= this->_index;
    }

    void Reset() {
        this->_index = 0;
    }

    char Next() {
        if (this->IsEnd()) {
            return '\0';
        }

        return this->_original[this->_index++];
    }

private:
    std::string _original;
    size_t _index;
};

template <class T>
class TrieNode {
public:
    // TODO: need a better value container
    TrieNode(char character, bool end, T&& value) :
            _nodes(26), _originalCharacter(character), _eok(end), _value(value) {
        this->ValidateCharacter(character);
        this->_character = this->Normalize(character);

        if (value == nullptr) {
            this->_value = nullptr;
        }

        // Clean the original
        value = nullptr;
    }

    ~TrieNode() {
        // TODO: will this be bad??
        delete[] this->_nodes.data();
        this->_nodes.clear();
    }

    [[nodiscard]] char GetOriginalChar() const {
        return this->_originalCharacter;
    }
    [[nodiscard]] char GetChar() const {
        return this->_character;
    }
    [[nodiscard]] bool IsEndOfKey() const {
        return this->_eok;
    }
    [[nodiscard]] const TrieNode* GetAt(int i) const {
        return this->_nodes.at(i);
    }
    [[nodiscard]] const T* GetValue() const {
        return this->_value;
    }
    [[nodiscard]] const TrieNode* Search(char character) const {
        this->ValidateCharacter(character);
        auto normal = this->Normalize(character);
        return this->_nodes.at(normal - 65);
    }
    void SetEndOfKey(bool end) {
        this->_eok = end;
    }

    void Insert(WordIterator &iterator, T&& value) {
        if (iterator.IsEnd()) {
            return;
        }

        char next = iterator.Next();
        TrieNode* node = this->Search(next);
        if (node == nullptr) {
            node = new TrieNode(next, iterator.IsEnd(), value);
            this->_nodes.insert(next - 65, node);
        } else {
            node->SetEndOfKey(iterator.IsEnd());

            if (value != node->GetValue()) {
                // TODO: overwrite value
            }
        }

        this->Insert(iterator, value);
    }

private:

    bool IsValidCharacter(char character) {
        return !(character < 65 || (character > 90 && character < 97) || character > 122);
    }

    void ValidateCharacter(char character) {
        if (!this->IsValidCharacter(character)) {
            throw std::invalid_argument("character must be a valid ascii letter");
        }
    }

    // Everything should be UPPER CASE
    char Normalize(char character) {
        char normal = character;
        // Everything should be upper case
        if (character >= 97) {
            normal -= 32;
        }
        return normal;
    }

    char _character;
    char _originalCharacter;
    bool _eok;
    std::vector<TrieNode*> _nodes;
    T* _value;
};

template <class T>
const T* FindValueByKey(std::string key, TrieNode<T>* root) {

}

#endif //DOCUDB_TRIE_H
