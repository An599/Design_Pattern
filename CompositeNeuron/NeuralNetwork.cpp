#include <iostream>
#include "NeuralNetwork.h"
int main()
{
    Neuron n1, n2;
    NeuronLayer layer1(3), layer2(2);
    n1.connect_to(n2);
    n1.connect_to(layer1);
    layer1.connect_to(n1);
    layer1.connect_to(layer2);
;
    std::cout << "Neuron " << n1.id << " out connections: " << n1.out.size() << "\n";
    std::cout << "Neuron " << n2.id << " in connections: " << n2.in.size() << "\n";
}
