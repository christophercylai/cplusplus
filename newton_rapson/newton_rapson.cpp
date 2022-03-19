#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <stdexcept>

// this class represents a Term in a function, such as 2x^2 in f(x)=2x^2+5x+2 
class Term
{
    public:
        Term(int d, int m) {
            degree = d;
            multiplier = m;
        }
        int degree;
        int multiplier;

        Term getPrime() {
            // differentiate Term
            if (degree <= 0) {
                return Term(0, multiplier*0);
            }
            return Term(degree-1, multiplier*degree);
        }
};


// this class represents the function, which is in the form of:
//   std::vector<Terms>
class Function
{
    public:
        Function() {
            int degree;
            std::cout << "Enter the highest degree of f(x)" << std::endl;
            std::cin >> degree;
            std::cout << std::endl;

            for (int& d = degree; d >= 0; d--) {
                int m;
                std::cout << "Enter the multiplier of " << d << " degree" << std::endl;
                std::cin >> m;

                auto term = Term(d, m);
                function.push_back(term);
            }
            std::cout << std::endl;
            differentiate();
        }

        float newton_raphson(float xn) {
            return (xn - (calcFunc(function, xn)/calcFunc(diff_func, xn)));
        }

        bool zeroed(const float& xn) {
            // check if f(xn) results in 0
            const float y = calcFunc(function, xn);
            if (y < 0.0000001) {
                return true;
            }
            return false;
        }

        void printFunction() {
            print_func(function);
        }

        void printDiff() {
            print_func(diff_func);
        }


    private:
        static void print_func(std::vector<Term>& func) {
            std::cout << "Your function is:" << std::endl;
            std::cout << func[0].multiplier << "x^" << func[0].degree;
            for (int ts=1; ts < func.size(); ts++) {
                if (func[ts].multiplier != 0) {
                    std::cout << " + " << func[ts].multiplier << "x^" << func[ts].degree;
                }
            }
            std::cout << std::endl;
        }

        void differentiate() {
            // differentiate the function
            for (auto& t : function) {
                diff_func.push_back(t.getPrime());
            }
        }

        static float calcFunc(std::vector<Term>& func, float xn) {
            float xn_1 = 0;
            for (auto& f : func) {
                xn_1 += f.multiplier * std::pow(xn, f.degree);
            }
            return xn_1;
        }

        std::vector<Term> function;
        std::vector<Term> diff_func;
};


int main() {
    // get the function from user input
    Function func = Function();

    float xn;
    std::cout << "Enter a number close to the root" << std::endl;
    std::cin >> xn;
    std::cout << std::endl;
    const std::string x_init = std::to_string(xn);

    // applying newton-raphson method
    bool zeroed = false;
    int count = 10;
    while (! zeroed) {
        xn = func.newton_raphson(xn);
        zeroed = func.zeroed(xn);
        count = count - 1;
        if (count < 0) {
            throw std::runtime_error("No solution - there is no root near " + x_init);
        }
    }

    // printing results
    func.printFunction();
    std::cout << "The root of the function is: " << xn << std::endl;
}
