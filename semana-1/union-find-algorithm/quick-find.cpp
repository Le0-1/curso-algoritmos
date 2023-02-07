#include <iostream>

class QuickFindUF {
    private:
        int _number_of_objects = 0;
        int* _id = new int[_number_of_objects];
    
    public:
        QuickFindUF(int number_of_objects) {
            this->_number_of_objects = number_of_objects;
            this->_id = new int[number_of_objects];

            for (int i = 0; i < number_of_objects; i++) {
                (this->_id[i]) = i;
            }
        }

        bool is_connected(int p, int q) {
            if (this->_id[p] == this->_id[q]) return true;
            else return false;
        }

        void uniao(int p, int q) {
            if (this->is_connected(p, q)) {
                    std::cout << "Já estão conectados" << std::endl;
                    return;
                }

            int id_do_p = this->_id[p]; 
            int id_do_q = this->_id[q]; 

            for (int i = 0; i < this->_number_of_objects; i++) {

                if (this->_id[i] == id_do_p) { 
                    this->_id[i] = id_do_q;  
                }
            }
        }

};


int main() {

    return 0;
}