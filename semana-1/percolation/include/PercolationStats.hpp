#ifndef PERCOLATION_STATS_H
#define PERCOLATION_STATS_H

#include <iostream>
#include <vector>

class PercolationStats {
    private:
    unsigned _grid_size;
    unsigned _trials;
    double _mean, _stardand_deviation;
    std::vector<double> _open_sites_proportion;
    std::pair<double, double> _confidence_interval;

    public:
        // realizar tentativas independentes em um grid n-por-n
        PercolationStats(unsigned grid_size, unsigned trials);

        // média amostral do limiar de percolação
        void calculateMean();

        // retorna a média
        double getMean();

        // amostra do desvio padrão do limiar de percolação
        void calculateStandardDeviation();

        // retorna o desvio padrão
        double getStandardDeviation();

        // low endpoint do intervalo de 95% de confiança
        void calculateConfidenceLow();

        double getConfidenceLow();

        // high endpoint do intervalo de 95% de confiança
        void calculateConfidenceHigh();

        double getConfidenceHigh();

        void printStats();




};

#endif