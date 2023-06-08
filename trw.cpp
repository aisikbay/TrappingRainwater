//ARAM ISIKBAY
#include <iostream>
#include <algorithm>

int trappedWater(int structure[], int size) {
	int i = 0;
	int j = size - 1;

	int leftMax = structure[i];
	int rightMax = structure[j];
	int result = 0;

	while (i < j) {
		if (leftMax <= rightMax) {
			leftMax = std::max(leftMax, structure[++i]);
			result += leftMax - structure[i];
		}
		else {
			rightMax = std::max(rightMax, structure[--j]);
			result += rightMax - structure[j];
		}
	}
	return result;
}

int main() {
	int structure[] = { 0,2,0,1,0,2,1,3,2,1 };
	//int structure[] = {4,0,3,0,2,0,3};
	int size = sizeof(structure) / sizeof(structure[0]);
	std::cout << "Structure ";
	for (auto element : structure) { std::cout << element << " "; }
	std::cout << "will trap " << trappedWater(structure, size) << " sq units of water." << std::endl;
	return 0;
}