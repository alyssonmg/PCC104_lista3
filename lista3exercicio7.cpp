#pragma once

#include <iostream>
#include <vector>
#include <chrono>
#include <set>
#include <numeric>
#include <functional>

template <typename T>
void print_vector(std::vector<T>& v)
{
	for (auto i = v.begin(); i != v.end(); ++i)
	{
		std::cout << *i << ' ';
	}

	std::cout << std::endl;
}

int fake_coin_detector2(const std::vector<int>& coins, int begin, int end) {

	int fake_coin = -1;

	if ((end - begin) == 1) {
		return begin;
	}
	else {
		int pile_size = (end - begin) / 2;
		int remainder = (end - begin) % 2;

		int begin_p2 = begin + pile_size;
		
		if (remainder != 0){
			end = end - 1;
		}

		int weight_p1 = std::accumulate(coins.begin() + begin, coins.begin() + begin_p2, 0); //somando o inicio da pilha 1 até o início da pilha 2: de 0 até 4
		int weight_p2 = std::accumulate(coins.begin() + begin_p2, coins.begin() + end, 0); //somando do início da p2 até end, de 5 a 9

		if (weight_p1 < weight_p2) {
			fake_coin = fake_coin_detector2(coins, begin, begin_p2);
		}
		else if (weight_p1 > weight_p2) {
			fake_coin = fake_coin_detector2(coins, begin_p2, end);
		}
		else {
			fake_coin = end;
		}

	}

	return fake_coin;
}

int main()
{
    system("cls");
    std::vector<int> coins(11,3); //definindo 11 moedas com peso 3 para todas
    coins[7] = 1; //definindo a moeda 7 como falsa e peso 1
    print_vector(coins);

    int fake2 = fake_coin_detector2(coins, 0, coins.size());
    std::cout << "Coin Fake: " << fake2 << std::endl;

    return 0;

}