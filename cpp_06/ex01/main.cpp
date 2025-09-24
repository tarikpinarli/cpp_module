#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {
    Data d;
    d.id    = 42;
    d.name  = "hello";
    d.value = 3.14;

    Data* p = &d;

    uintptr_t raw = Serializer::serialize(p);
    Data* q = Serializer::deserialize(raw);

    std::cout << "Original ptr : " << p  << "\n";
    std::cout << "Serialized   : " << raw << "\n";
    std::cout << "Deserialized : " << q  << "\n";

    std::cout << (q == p ? "Pointers equal: OK" : "Pointers equal: FAIL") << "\n";
    std::cout << "q->id=" << q->id << ", q->name=" << q->name
              << ", q->value=" << q->value << "\n";

    return 0;
}
