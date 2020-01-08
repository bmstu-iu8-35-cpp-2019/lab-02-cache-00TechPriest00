// Copyright 2019 Fedorov james.sayfer2015@yandex.ru

#include "../include/header.hpp"

double prExp(size_t con_bit, size_t size)
{
    int* t_array = new int[size + 1];
    t_array[size] = '/n';
    size_t i = 0;
    size = size / 4;
    for (i; i < size; i = i + con_bit)
	{
        t_array[i] = i + con_bit;
    }
    i = i - con_bit;
    t_array[i] = 0;
    size_t time_strt = clock();

	int w = 1000;
	double v = 100;

    for (size_t j = 0; j < w; ++j)
	{
        rep1(i = t_array[i];)
    }
    size_t time_fin = clock();
    delete[] t_array;
    return (time_fin - time_strt) / v;
}


int* buildRandArr(size_t con_bit, size_t size)
{
    int* pam = new int[size];
    pam[size] = '\n';
    int n = size / con_bit;
    std::vector<int> pam_num(n);
	int i = 0;

	while (i < n)
	{
		pam_num[i] = i * con_bit;
		i=i+1;
	}

	size_t k = 0;
	while (n>0)
	{
		srand(time(NULL));
		pam[k] = pam_num[rand() % n];
		n = n - 1;
		for (size_t j = pam[k]; j < static_cast<size_t>(n); ++j)
		{
			pam_num[j] = pam_num[j + 1];
		}
		pam_num.resize(n);
		k = k + con_bit;
	}
    return pam;
}

double oddExp(size_t con_bit, size_t size)
{
    int i = 0;
    size = size / 4;
    int* t_array = buildRandArr(con_bit, size);
    size_t time_strt = clock();
	int w = 1000;
	double v = 100;
	size_t j = 0;
	while (j < w)
	{
		rep1(i = t_array[i];);
		j = j + 1;
	}
    size_t time_fin = clock();
    delete[] t_array;
    return (time_fin - time_strt) / v;
}

double revExp(size_t con_bit, size_t size)
{
    int* t_array = new int[size + 1];
    t_array[size] = '/n';
    int i = 0;
    size = size / 4;
    for (i = i - size; i >= 0 ; i = i - con_bit)
	{
        t_array[i] = i - con_bit;
    }
    i = i + con_bit;
    t_array[i] = size - 1;
    size_t time_strt = clock();
	int w = 1000;
	double v = 100;
	size_t j = 0;
	while (j < w)
	{
		rep1(i = t_array[i];);
		j = j + 1;
	}
    size_t time_fin = clock();
    delete[] t_array;
    return (time_fin - time_strt) / v;
}

void outputResult()
{
    size_t exp_n = 1;
	size_t pam = 1048576;
    size_t MByte = 8 * pam;
    size_t bits_architect = 64;

	std::cout << "investigation:\n";
	std::cout << "travel_order: ";
	std::cout << "\"preOrder\"\n";
	std::cout << "experiments:\n";

	for (size_t i = 131072; i <= MByte; i = i * 2)
	{
        i == MByte ? i = 9 * pam : i;
		std::cout << "  - experiment:\n  number: ";
		std::cout << exp_n+1;
		std::cout << "\n  input_data:";
		std::cout << "\n  buffer_size: ";

        if (i < pam)
		{
			std::cout << '\"';
			std::cout << i / 1024;
			std::cout << "kb\"";
        }
		else
		{
			std::cout << '\"';
			std::cout << i / pam;
			std::cout << "mb\"";
        }
		std::cout << "\n   results: ";
		std::cout << "\n   duration: ";
		std::cout << '\"';
		std::cout << prExp(bits_architect, i); 
		std::cout << "ns";
		std::cout << '\"';
		std::cout << "\n";
    }

    exp_n = 1;
	std::cout << "investigation:\n";
	std::cout << "travel_order: ";
	std::cout << "\"PostOrder\"\n";
	std::cout << "experiments:\n";

	for (size_t i = 131072; i <= MByte; i = i * 2)
	{
        i == MByte ? i = 9 * pam : i;
		std::cout << "  - experiment:\n     number: ";
		std::cout << exp_n++;
		std::cout << "\n   input_data:";
		std::cout << "\n   buffer_size: ";

        if (i < pam)
		{
			std::cout << '\"';
			std::cout << i / 1024;
			std::cout << "kb\"";
        } 
		else
		{
			std::cout << '\"';
			std::cout << i / pam;
			std::cout << "mb\"";
        }

		std::cout << "\n   results: ";
		std::cout << "\n   duration: ";
		std::cout << '\"';
		std::cout << prExp(bits_architect, i);
		std::cout << "ns";
		std::cout << '\"';
		std::cout << "\n";
    }

    exp_n = 1;
	std::cout << "investigation:\n";
	std::cout << "travel_order: ";
	std::cout << "\"RandOrder\"\n";
	std::cout << "experiments:\n";

	for (size_t i = 131072; i <= MByte; i = i * 2)
	{
        i == MByte ? i = 9 * pam : i;
		std::cout << "  - experiment:\n   number: ";
		std::cout << exp_n++;
		std::cout << "\n   input_data:";
		std::cout << "\n   buffer_size: ";
        
		if (i < pam)
		{
			std::cout << '\"';
			std::cout << i / 1024;
			std::cout << "kb\"";
        } 
		else
		{
			std::cout << '\"';
			std::cout << i / pam;
			std::cout << "mb\"";
        }
		std::cout << "\n   results: ";
		std::cout << "\n   duration: ";
		std::cout << '\"';
		std::cout << prExp(bits_architect, i);
		std::cout << "ns";
		std::cout << '\"';
		std::cout << "\n";
    }
}
