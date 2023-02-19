#include "span.hpp"
#include <exception>
#include <random>

int main()
{
	try {
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

//	try {
//
//
//		// size over
//		{
//			Span sp = Span(1);
//			sp.addNumber(1);
//			sp.addNumber(2);
//		}
//
//
//		// no range
//		{
//			Span sp = Span(10);
//			sp.addNumber(1);
//
//			std::cout << sp.shortestSpan() << std::endl;
//			std::cout << sp.longestSpan() << std::endl;
//		}
//	}
//	catch (std::exception & e)
//	{
//		std::cerr << e.what() << std::endl;
//	}


//	{
//		// 시드값을 얻기 위한 random_device 생성.
//		std::random_device rd;
//		// random_device 를 통해 난수 생성 엔진을 초기화 한다.
//		std::mt19937 gen(rd());
//		// 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
//		std::uniform_int_distribution<int> dis(0, 10000);
//
//
//		Span sp = Span(100000);
//		try {
//			for (int i = 0; i < 10000; i++) {
//				int randomNumber = dis(gen);
//				std::cout << "number add : " << randomNumber << std::endl;
//				sp.addNumber(randomNumber);
//			}
//		}
//		catch (std::exception &e) {
//			std::cerr << e.what() << std::endl;
//		}
//		std::cout << sp.shortestSpan() << std::endl;
//		std::cout << sp.longestSpan() << std::endl;
//	}
}