/*ARAM ISIKBAY
Trapping Rain Water using Dynamic Programming
Time O(n) - three iterations, two to fill leftMax and rightMax arrays and one to compute the result
Space O(n) - additional leftMax and rightMax arrays required*/

#include <iostream>
#include <algorithm>

int trappedWater(int structure[], int size) {
	//Array length defined at runtime
	int *leftMax, *rightMax;
	leftMax = new int[size];
	rightMax = new int[size];
	int result = 0;
	//Fill leftMax array. leftMax[i] stores the max height starting from the left, going right to and including i
	leftMax[0] = structure[0];
	for (int i = 1; i < size; i++) {
		leftMax[i] = std::max(structure[i], leftMax[i - 1]);
	}
	//Fill rightMax array. rightMax[i] stores the max height starting from the right, going left to and including i
	rightMax[size - 1] = structure[size - 1];
	for (int i = size - 2; i >= 0; i--) {
		rightMax[i] = std::max(structure[i], rightMax[i + 1]);
	}
	//Iterate over the structure, comparing the left and right maxes corresponding to that index
	for (int i = 1; i < size - 1; i++) {
		result += std::min(leftMax[i], rightMax[i]) - structure[i];
	}
	return result;
}

int main() {
	int structure[] = { 0,2,0,1,0,2,1,3,2,1 };
	//int structure[] = {4,0,3,0,2,0,3};
	int size = sizeof(structure) / sizeof(structure[0]);
	std::cout << "Structure { ";
	for (auto element : structure) { std::cout << element << " "; }
	std::cout << "} will trap " << trappedWater(structure, size) << " sq units of water." << std::endl;
	return 0;
}