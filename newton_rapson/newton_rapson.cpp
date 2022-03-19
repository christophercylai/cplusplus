#include <iostream>
#include <vector>
#include <math.h>

// this type represents a Term in a function, such as 2x^2 in f(x)=2x^2+5x+2 
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


class Function
{
    public:
        Function() {
            int degree;
            std::cout << "Enter the highest degree of f(x)" << std::endl;
            std::cin >> degree;

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

        double newton_raphson(double xn) {
            return (xn - (calcFunc(function, xn)/calcFunc(diff_func, xn)));
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
            for (int ts=0; ts < func.size()-1; ts++) {
                if (func[ts].multiplier != 0) {
                    std::cout << func[ts].multiplier << "x^" << func[ts].degree << " + ";
                }
            }
            std::cout << func[func.size()-1].multiplier << std::endl;
        }

        void differentiate() {
            for (auto& t : function) {
                diff_func.push_back(t.getPrime());
            }
        }

        double calcFunc(std::vector<Term>& func, double xn) {
            double xn_1 = 0;
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
    func.printFunction();

    // applying newton-raphson method
    double xn;
    std::cout << "Enter a number close to the root" << std::endl;
    std::cin >> xn;

    for (int i=0; i <= 8; i++) {
        xn = func.newton_raphson(xn);
    }
    std::cout << xn << std::endl;
}
