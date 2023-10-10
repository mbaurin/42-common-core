#include <iostream>
#include <string>
#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

int main()
{
    Data *data = new Data();
    uintptr_t serializedValue;
    Data *deserializedValue;

    data->value = 42;
    std::cout << "data address: " << &data->value << std::endl;
    serializedValue = serialize(data);
    std::cout << "data serialized: " << serializedValue << std::endl;
    deserializedValue = deserialize(serializedValue);
    std::cout << "data deserialized: " << deserializedValue << std::endl;

    delete data;

    return 0;
}