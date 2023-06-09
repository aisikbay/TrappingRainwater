/*ARAM ISIKBAY
Trapping Rain Water using two pointers
Time O(n) - single iteration over structure[]
Space O(1) - constant memory required for leftMax and rightMax ints
*/

#include <iostream>
#include <algorithm>

int trappedWater(int structure[], int size) {
	//Iterators for left and right
	int i = 0;
	int j = size - 1;
	//Left and right max variables
	int leftMax = structure[i];
	int rightMax = structure[j];
	int result = 0;
	//Single iteration over structure[]
	while (i < j) {
		//Comparison of left and right maxes is done first
		if (leftMax <= rightMax) {
			//Update leftMax and compute result
			leftMax = std::max(leftMax, structure[++i]);
			result += leftMax - structure[i];
		}
		else {
			//Update rightMax and compute result
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