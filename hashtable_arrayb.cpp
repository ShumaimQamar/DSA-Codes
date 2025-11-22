#include <iostream>
using namespace std;

class HashTable {
private:
    int* keys;     
    bool* used;     
    int size;

public:
    HashTable(int s) {
        size = s;
        keys = new int[size];
        used = new bool[size];

      
        for (int i = 0; i < size; i++) {
            used[i] = false;
            keys[i] = 0;
        }
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int key) {
        int index = hashFunction(key);

     
        while (used[index]) {
            index = (index + 1) % size;
        }

   
        keys[index] = key;
        used[index] = true;
    }

    bool search(int key) {
        int index = hashFunction(key);

       
        while (used[index]) {
            if (keys[index] == key)
                return true;
            index = (index + 1) % size;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            if (used[i])
                cout << i << ": " << keys[i] << endl;
            else
                cout << i << ": " << "EMPTY" << endl;
        }
    }
};


int main() {
    HashTable h(10);

    h.insert(23);
    h.insert(34);
    h.insert(45);
    h.insert(56);

    h.display();

    cout << "Search 45: " << (h.search(45) ? "Found" : "Not Found") << endl;
    cout << "Search 99: " << (h.search(99) ? "Found" : "Not Found") << endl;
}
