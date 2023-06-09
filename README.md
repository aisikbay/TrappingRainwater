# Trapping Rainwater
Problem: Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

## Example 1
<img width = "55%" align = "left" src="https://github.com/aisikbay/TrappingRainwater/assets/94331548/58d81e6f-de9f-4dff-add4-c66553d78672"></img><br>
`H = {0, 2, 0, 1, 0, 2, 1, 3, 2, 1}`<br>
In the first example, the structure can hold 6 sq. units of water after rain. <br clear = "left">


## Example 2
<img width = "55%" align = "left" src="https://github.com/aisikbay/TrappingRainwater/assets/94331548/ab198f28-326a-4b87-a885-64eb730494d6"></img><br>
`H = {4, 0, 3, 0, 2, 0, 3}`<br>
In the second example, the structure can hold 10 sq. units of water after rain.<br clear = "left">

## Approach
We can determine how much water a particular index of the structure can hold based on the max height to the left and right of the index:<br>
$min(leftMax[i], rightMax[i]) - height[i]$<br>
* leftMax[i] is the max height starting from the left up to index i
* rightMax[i] is the max height starting fromt he right down to index i
* height[i] is the height of the structure at index i<br>

The end points of the graph cannot contain water, so index 0 and 9 of example 1 will not contain any.<br>
Consider index 2 of example 1: 
`min(2,3)-0 = 2-0 = 2`<br>
Or index 1 of example 2: 
`min(4,3)-0 = 3-0 = 3`<br>
Summing these values for each index results in the correct answer.

## Implementation
* **Dynamic Programming** <br>
In `trwDP.cpp`, dynamic programming is used to compute the trapped water capacity. Two arrays, `leftMax[]` and `rightMax[]` are used to track the leftMax starting from the left up to and including index i, and the rightMax starting from the right down to and including index i
Two iterations are done to fill these array values, and a third to compute the amount of water that will be trapped. <br>

    * _Time complexity_: _O(n)_<br>
    * _Space complexity_: _O(n)_<br>
  
* **Double pointer** <br> 
In `trw.cpp`, two pointers are used to simplify keeping track of the left and right maxes, and less storage is used as the previous values do not need to be stored. During the single iteration over the height structure, the comparison of `leftMax` and `rightMax` is done first to determine which pointer to increment. The effect of that index is then added before considering the next.<br>

    * _Time complexity_: _O(n)_ <br>
    * _Space complexity_: _O(n)_ <br>
