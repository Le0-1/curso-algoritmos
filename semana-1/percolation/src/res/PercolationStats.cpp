#include <PercolationStats.hpp>
#include <WeightedQuickUnion.hpp>
#include <Percolation.hpp>

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

PercolationStats::PercolationStats(unsigned grid_size, unsigned trials) {
    this->_grid_size = grid_size;
    this->_trials = trials;

    //seed para escolher um número aleatório, se não a funnção "rand()", sem o 's',
    //vai gerar apenas o mesmo número.
    srand(time(0));

    //Essa variável vai pegar a proporção de cada experimento e guardar em um vector,
    //expressão para determinar ela na linha 46
    double openSitesProportion = 0.0;

    //O tamanho do grid total é constante para cada experimento.
    double gridFullSize = (static_cast<double>(grid_size)) * (static_cast<double>(grid_size));

    //Preciso criar um objeto da classe Percolation e retirar os dados necessários,
    //e, enquanto o objeto não está percolado, preciso is abrindo locais
    for (unsigned i = 0; i < trials; i++) {
        Percolation _percolation_object(grid_size);

        //Enquant o grid não tem um caminho de cima para baixo
        while (!(_percolation_object.percolates())) {

            //Não preciso colocar +1 no grid_size pois para pegar linha e coluna 
            //vai de 0 até grid_size - 1, oque o modulo já faz para mim.
            unsigned row = rand() % (grid_size); 
            unsigned col = rand() % (grid_size);
            _percolation_object.open(row, col);
        }
        //Chama a função para determinar o número de "sites" abertos.
        double numOfOpenSites = static_cast<double>(_percolation_object.numberOfOpenSites());

        openSitesProportion = numOfOpenSites/gridFullSize;
        this->_open_sites_proportion.push_back(openSitesProportion);
    }
    this->calculateMean();
    this->calculateStandardDeviation();
    this->calculateConfidenceHigh();
    this->calculateConfidenceLow();
}

//Metódo que calcula a média entre a relação de proporção de sites abertos com o número de trials
//e.g: (0.51 + 0.56)/2, foram 2 trials que o primeiro a proporção foi 0.51 e o segundo 0.56. agora eu pego a média deles
void PercolationStats::calculateMean() {
    double sumOfProportion = 0;

    for (unsigned i = 0; i < this->_open_sites_proportion.size(); i++) {
        sumOfProportion+= this->_open_sites_proportion[i];
    }

    this->_mean = sumOfProportion/static_cast<double>(this->_trials);
}

double PercolationStats::getMean() {
    return this->_mean;
}

//Método que calcula o desvio padrão usando a fórmula.
void PercolationStats::calculateStandardDeviation() {
    //Variável responsável por fazer a soma do numerador do desvio padrão
    double standardDeviationSum = 0.0;

    //Criar uma variável só para fazer o cast de trials(unsigned) para um double
    double dTrials = static_cast<double>(this->_trials);

    for (unsigned i = 0; i < this->_open_sites_proportion.size(); i++) {

        //Subtraction é a variável para armazenar a subtração do desvio padrão
        double subtraction = (this->_open_sites_proportion[i] - this->_mean); 
        standardDeviationSum+= pow(subtraction, 2);
    }
    //Fórmula proporcionada pelo exercício
    double standardDeviation = standardDeviationSum/(dTrials - 1);
    this->_stardand_deviation = sqrt(standardDeviation);
}

double PercolationStats::getStandardDeviation() {
    return this->_stardand_deviation;
}

//Os dois próximos métodos calcular o intervalo de confiança e os armazenam no membro _confidence da classe
//A constante 1.96 foi dada no exercício.
void PercolationStats::calculateConfidenceLow() {
    double trialsSqrt = sqrt(static_cast<double>(this->_trials));
    this->_confidence_interval.first = (this->_mean) - ((1.96 * this->_stardand_deviation)/trialsSqrt);
}


void PercolationStats::calculateConfidenceHigh() {
    double trialsSqrt = sqrt(static_cast<double>(this->_trials));
    this->_confidence_interval.second = (this->_mean) + ((1.96 * this->_stardand_deviation)/trialsSqrt);
}

double PercolationStats::getConfidenceHigh() {
    return this->_confidence_interval.second;
}

double PercolationStats::getConfidenceLow() {
    return this->_confidence_interval.first;
}

void PercolationStats::printStats() {
    std::cout << "Média: " << "\t" << this->_mean << "\n";
    std::cout << "Desvio Padrão: " << this->_stardand_deviation << "\n";
    std::cout << "Intervalo de confiança: " << "\t" << "[" << this->_confidence_interval.first << ", "  << this->_confidence_interval.second << "] \n";
}


