#include <iostream>
#include <vector>

class WeightQuickUnion {
    public:
        std::vector<int> _ids;
        std::vector<int> _size;
        int _number_of_components;
        int _number_of_ids;
        std::vector<int> _large;

    public:
        WeightQuickUnion(int n) {

            for (int i = 0; i < n; i++) {
                this->_ids.push_back(i);
                this->_size.push_back(1);
                this->_large.push_back(i);
            }
            this->_number_of_components = n;
            this->_number_of_ids = n;
        }

        int findRoot(int n) {
            int ans = n;

            while (ans != this->_ids[ans]) {
                this->_ids[ans] = this->_ids[this->_ids[ans]];
                ans = this->_ids[ans];
            }

            return ans;
        }

        //Coloco o maior na posição da raiz dentro do vector de large
        void connectNodes(int n, int p) {
            int rootN = this->findRoot(n); 
            int rootP = this->findRoot(p);
            int largeN = this->_large[rootN];
            int largeP = this->_large[rootP];

            if (rootN == rootP) return;

            else if (this->_size[rootN] < this->_size[rootP]) {
                this->_ids[rootN] = rootP;
                this->_size[rootP]+= this->_size[rootN];
                if (largeN > largeP)
                    this->_large[rootP] = largeN;
            }

            else {
                this->_ids[rootP] = rootN;
                this->_size[rootN]+=this->_size[rootP];
                if (largeP > largeN)
                    this->_large[rootN] = largeP;
                
            }
            this->_number_of_components--;
        }

        int getComponents() {
            return this->_number_of_components;
        }

        bool isConnected(int n, int p) {
            return findRoot(n) == findRoot(p);
        }

        int findBiggestElementOfComponent(int n) {
            int rootN = findRoot(n);
            return this->_large[rootN];
        }
};

int main() {
    WeightQuickUnion object(10);
    object.connectNodes(9, 5);

    for (int i = 0; i < 10; i++) {
        std::cout << i << " " << object._ids[i] << " " << object._size[i] << "\n";
    }

    std::cout << object._number_of_components << " " << object._number_of_ids << "\n";

    std::cout << object.findBiggestElementOfComponent(5) << "\n";

}