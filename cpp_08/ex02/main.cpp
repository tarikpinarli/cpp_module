#include "MutantStack.hpp"

static void subSection(const std::string& title) {
    std::cout << BLUE << "------ " << title << " ------" << WHITE << "\n";
}

int main()
{
    {
        subSection("MutantStack Subject Test");
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        int index = 0;
        while (it != ite)
        {
            ++it;
            index++;
        }
        std::stack<int> s(mstack);
    }
    {
        subSection("MutantStack with double and vector type container");
        MutantStack< double, std::vector<double> > vecStack;
        for(int i = 0; i < 10; i++)
        {
            std::cout << "vecStack.push(" << i << ");" << std::endl;
            vecStack.push(i);
        }
        MutantStack<double, std::vector<double> >::iterator it = vecStack.begin();
        MutantStack<double, std::vector<double> >::iterator ite = vecStack.end();
        std::cout << "vecStack = ";
        while (it != ite)
        {
            std::cout << "["<< *it << "]";
            it++;
            if (it != ite)
                std::cout << " ";
            else
                std::cout << std::endl;
        }

        std::cout << "vecStack.size() is: " << vecStack.size() << std::endl;
        std::cout << "vecStack.top() is: " << vecStack.top() << std::endl;
        std::cout << YELLOW << "vecStack.pop()" << WHITE << std::endl;
        vecStack.pop();
        std::cout << "vecStack.top() is: " << vecStack.top() << std::endl;
    }
    return 0;
}
