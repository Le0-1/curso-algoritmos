#include <iostream>

class QuickUnionUF {
    private:
        int _number_of_objects = 0;
        int* _id = new int[_number_of_objects];
        int* _size_of_tree = new int[_number_of_objects];

    public:
        QuickUnionUF(int number_of_objects) {
            this->_number_of_objects = number_of_objects;
            this->_id = new int[number_of_objects];
            this->_size_of_tree = new int[number_of_objects];

            for (int i = 0; i < number_of_objects; i++) {
                (this->_id[i]) = i;
                (this->_size_of_tree[i]) = 1;
            }
        }

        int raiz(int number) {
            int id = number;
            while (this->_id[id] != id) {
                id = this->_id[id];
            }
            return id;
        }

        bool is_connected (int p, int q) {
            if (this->raiz(p) == this->raiz(q)) return true;
            else return false;
        }

        void uniao(int p, int q) {
            int raizDeP = this->raiz(p); 
            int raizDeQ = this->raiz(q); 
            
            if (this->_size_of_tree[raizDeP] < this->_size_of_tree[raizDeQ]) {
                this->_id[raizDeP] = raizDeQ;
                this->_size_of_tree[raizDeQ]+= this->_size_of_tree[raizDeP]; 
            } 
            else {
                this->_id[raizDeQ] = raizDeP;
                this->_size_of_tree[raizDeP]+= this->_size_of_tree[raizDeQ];
            }
        }

};

int main() {


}