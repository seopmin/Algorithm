/*
  [9655 - 돌던지기]
  문제가 추상적이어서 애매~~~하지만 짝수는 CY, 홀수는 SK 승!
*/

#include <iostream>

int main() {
	int n;
	std::cin >> n;
	if (n % 2 == 1)
		std::cout << "SK";
	else
		std::cout << "CY";
}
