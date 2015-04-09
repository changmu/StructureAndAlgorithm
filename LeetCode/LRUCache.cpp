class LRUCache {
private:
    struct Node {
        int key, value;
        Node(int k, int v) : key(k), value(v) {}
    };
    int capacity;
    list<Node> LRU_list;
    unordered_map<int, list<Node>::iterator> hash;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (hash.find(key) == hash.end())
            return -1;

        LRU_list.splice(LRU_list.begin(), LRU_list, hash[key]);
        hash[key] = LRU_list.begin();

        return LRU_list.begin()->value;
    }

    void set(int key, int value) {
        if (hash.find(key) == hash.end()) {
            if (LRU_list.size() == capacity) {
                hash.erase(LRU_list.back().key);
                LRU_list.pop_back();
            }
            LRU_list.push_front(Node(key, value));
        } else {
            hash[key]->value = value;
            LRU_list.splice(LRU_list.begin(), LRU_list, hash[key]);
        }
        hash[key] = LRU_list.begin();
    }
};
