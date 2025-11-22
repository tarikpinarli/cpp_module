#include "MutantStack.hpp"

int main()
{
    std::cout << "=== MutantStack Test Basladi ===" << std::endl;

    std::cout << "\n[1] Bos bir MutantStack<int> olusturuluyor...\n";
    MutantStack<int> mstack;

    std::cout << "\n[2] mstack.push(5) yapiliyor...\n";
    mstack.push(5);

    std::cout << "[3] mstack.push(17) yapiliyor...\n";
    mstack.push(17);

    std::cout << "[4] En ustteki eleman (top): ";
    std::cout << mstack.top() << std::endl;

    std::cout << "\n[5] mstack.pop() ile ustteki eleman cikariliyor...\n";
    mstack.pop();

    std::cout << "[6] stack'in yeni boyutu (size): ";
    std::cout << mstack.size() << std::endl;

    std::cout << "\n[7] mstack.push(3), mstack.push(5), mstack.push(737), mstack.push(0)\n";
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "\n[8] Iterasyon icin iteratorler hazirlaniyor...\n";
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "   - ++it yapiliyor (bir ileri gidiyor)" << std::endl;
    ++it;

    std::cout << "   - --it yapiliyor (tekrar basa donuyor)" << std::endl;
    --it;

    std::cout << "\n[9] Stack'in icerigi iterator kullanarak yazdiriliyor:" << std::endl;
    std::cout << "   (begin()'den end()'e kadar dolasiyoruz)\n\n";

    int index = 0;
    while (it != ite)
    {
        std::cout << "   Eleman [" << index << "] = " << *it << std::endl;
        ++it;
        index++;
    }

    std::cout << "\n[10] MutantStack -> std::stack'e copy construct islemi yapiliyor..." << std::endl;
    std::stack<int> s(mstack);

    std::cout << "=== Test Tamamlandi ===" << std::endl;

    return 0;
}