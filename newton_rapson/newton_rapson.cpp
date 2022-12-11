#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <stdexcept>

// this class represents a Term in a function, such as 2x^2 in f(x)=2x^2+5x+2 
class Term
{
    public:
        explicit Term(int d, int m) {
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
        explicit Function() {
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

        double newtonRaphson(const double& xn) {
            double ret = xn - (calcFunc(function, xn)/calcFunc(diff_func, xn));
            if (std::isnan(ret)) {
                throw std::runtime_error("The supplied starting point has a slope of 0");
            }
            return ret;
        }

        bool zeroed(const double& xn) {
            // check if f(xn) results in 0
            const double y = calcFunc(function, xn);
            if (std::abs(y) < 0.000000000001) {
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
            std::cout << "(" << func[0].multiplier << "x^" << func[0].degree << ")";
            for (int ts=1; ts < func.size(); ts++) {
                if (func[ts].multiplier != 0) {
                    std::cout << " + " << "(" << func[ts].multiplier << "x^" << func[ts].degree << ")";
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

        static double calcFunc(std::vector<Term>& func, double xn) {
            double xn_1 = 0;
            for (auto& f : func) {
                xn_1 += f.multiplier * std::pow(xn, f.degree);
            }
            return xn_1;
        }

        std::vector<Term> function;
        std::vector<Term> diff_func;
};


int main()
{
    // get the function from user input
    Function func = Function();

    double xn;
    std::cout << "Enter a number close to the root" << std::endl;
    std::cin >> xn;
    std::cout << std::endl;

    // applying newton-raphson method
    bool zeroed = false;

    for (int count=0; count <= 100; count++) {
        if (count == 100) {
            std::cerr << "Root does not exist" << std::endl;
            func.printFunction();
            return 1;
        }
        xn = func.newtonRaphson(xn);
        if (func.zeroed(xn)) {
            break;
        }
    }

    // printing results
    func.printFunction();
    std::cout << "The root of the function is: " << xn << std::endl;
}
