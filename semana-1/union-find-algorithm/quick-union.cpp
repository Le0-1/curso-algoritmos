#include <iostream>
#include <cmath>


 class QuickUnionUF {
    private:
        int _number_of_objects = 0;
        int* _id = new int[_number_of_objects];
    
    public:
        QuickUnionUF(int number_of_objects) {
            this->_number_of_objects = number_of_objects;
            this->_id = new int[number_of_objects];

            for (int i = 0; i < number_of_objects; i++) {
                (this->_id[i]) = i;
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
            this->_id[raizDeP] = raizDeQ;
        }

};

int main() {

    return 0;
}