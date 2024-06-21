Hey! 
Myself Vaibhav Goyal 

Approch:

Q1:
1.First, set a counter to track valid subarrays.
2.Utilize a sliding window of length m to go through the array. It assists in efficiently finding the segment sum without redoing it for every new segment.
3.Find the sum of the initial window of size m.
4.Move the window along the array. At each new position, subtract the element left behind and add the new element entering the window.
5.For each window position, check if the sum meets the condition.
