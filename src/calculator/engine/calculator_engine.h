#include <string>


class CalculatorEngine
{
	public:
		double evaluate(const std::string &expr);

	private:
		std::string normalize(const std::string &expr, size_t len);
		double compute(const std::string &expr, size_t len);
};

