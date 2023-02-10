#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <typeinfo>

void openFile(std::ifstream& myFile, std::string fileName) {
    myFile.open(fileName);

    if (myFile.is_open()) {
        std::cout << "Sucessefuly Opened the File" << std::endl;
    }
    else {
        std::cout << "Failure" << std::endl;
        exit(-1);
    }
}

class QuickUnionUF {
    private:
        int _number_of_objects = 0;
        int* _id = new int[_number_of_objects];
        int* _size_of_tree = new int[_number_of_objects];

        //Criar a variável para me dar o número de componentes
        int number_of_components = 0;

    public:
        QuickUnionUF(int number_of_objects) {
            this->_number_of_objects = number_of_objects;
            this->_id = new int[number_of_objects];
            this->_size_of_tree = new int[number_of_objects];

            //Inicilizar a variável para mostrar o número de componentes
            this->number_of_components = number_of_objects;

            //Inicialização
            for (int i = 0; i < number_of_objects; i++) {
                (this->_id[i]) = i;
                (this->_size_of_tree[i]) = 1;
            }
        }
        
        int getComponents() {
            return this->number_of_components;
        }

        int root(int number) {
            int id = number;
            while (this->_id[id] != id) {
                id = this->_id[id];
            }
            return id;
        }

        bool is_connected(int p, int q) {
            if (this->root(p) == this->root(q)) return true;
            else return false;
        }

        void node_union(int p, int q) {
            int raizDeP = this->root(p); 
            int raizDeQ = this->root(q);

            if (raizDeP == raizDeQ) return;
            
            else if (this->_size_of_tree[raizDeP] < this->_size_of_tree[raizDeQ]) {
                this->_id[raizDeP] = raizDeQ;
                this->_size_of_tree[raizDeQ]+= this->_size_of_tree[raizDeP];

                //Diminuindo o número de componenetes com base no número de nós que a árvore adicionada tinha
                this->number_of_components-= 1;
            } 
            else {
                this->_id[raizDeQ] = raizDeP;
                this->_size_of_tree[raizDeP]+= this->_size_of_tree[raizDeQ];

                //Diminuindo o número de componenetes com base no número de nós que a árvore adicionada tinha
                this->number_of_components-= 1;
            }
        }

};

int main() {
    //Para resolver o exercício vou manter um array de tamanho N (Número de conexões que foram feitas);
    //Para cada conexão eu verifico se as raízes dos dois números são iguais e se não, conecto eles e reduzo o tamanho de N em 1;

    int numeroDeUsuarios;

    std::ifstream myFile;
    openFile(myFile, "social-network.txt");
    myFile >> numeroDeUsuarios;
    QuickUnionUF socialNetwork(numeroDeUsuarios);


    while (!(myFile.eof())) {
        std::string firstNumber, secondNumber;
        std::string date, hour;
        myFile >> firstNumber >> secondNumber >> date >> hour;
        int p = stoi(firstNumber);
        int q = stoi(secondNumber);

        if (socialNetwork.root(p) != socialNetwork.root(q)) {
            socialNetwork.node_union(p, q);
        }

        if (socialNetwork.getComponents() == 1) {
            std::cout << "Todos foram conectados" << "\n";
            std::cout << "Última conexão foi entre: [" << p << "," << q << "]" << "\n";
            std::cout << "Data: " << date << "\n";
            std::cout << "Hora: " << hour << std::endl;
            break;
        }
    }

    myFile.close();
}

