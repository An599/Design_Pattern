#pragma once
#include <vector>
struct Neuron
{
	std::vector<Neuron*> in, out;
	unsigned int id;

	Neuron()
	{
		static int id = 1;
		this->id = id++;
	}
    template <typename T>
    void connect_to(T& other)
    {
        if constexpr (std::is_same_v<T, Neuron>)
        {
            out.push_back(&other);
            other.in.push_back(this);
        }
        else
        {
            for (auto& n : other)
            {
                out.push_back(&n);
                n.in.push_back(this);
            }
        }
    }
};

struct NeuronLayer : std::vector<Neuron>
{
	NeuronLayer(int count)
	{
		while (count-- > 0)
			emplace_back(Neuron{});
	}
        template <typename T>
        void connect_to(T & other)
        {
            for (auto& from : *this)
                from.connect_to(other);
        }
};
