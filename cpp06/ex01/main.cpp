#include "Serializer.hpp"

int main()
{
	Data data = {0, 1.5, "test"};
	uintptr_t rawPtr = Serializer::serialize(&data);
	Data* dataPtr = Serializer::deserialize(rawPtr);

	std::cout << "Original data address:     " << &data << "\n";
	std::cout << "Serialized raw pointer:    0x" << std::hex << rawPtr << "\n";
	std::cout << "Deserialized data pointer: " << dataPtr << "\n";

	std::cout << "\nContent of initial data structure:\n";
	std::cout << "intValue: " << data.intValue << "\n";
	std::cout << "dblValue: " << data.dblValue << "	\n";
	std::cout << "strValue: " << data.strValue << "	\n";

	if (dataPtr)
	{
		std::cout << "\nContent of deserialized version:\n";
		std::cout << "intValue: " << dataPtr->intValue << "\n";
		std::cout << "dblValue: " << dataPtr->dblValue << "	\n";
		std::cout << "strValue: " << dataPtr->strValue << "	\n";
	}

	return 0;
}