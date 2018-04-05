"""
Given a sorted list of N numbers, a divide-and-conquer algorithm that can search for a number
x to find out whether x is in this list or not.

This algorithm takes O(logN) time.

:author Ronald Rounsifer
:version 4/5/2018
"""
test = [0,1,2,3,4,5,6,7,8,9]
x = 0

def find(the_list, num):
	left = the_list[ :len(the_list)//2] # items in left half of list (int division)
	right = the_list[len(the_list)//2: ] # items in right half of list (int division)

	if len(left) > 0 and len(right) > 0:
		if num < left[-1:][0]:
			find(left, num)
		elif num > right[0]:
			find(right, num)
		elif num in left or num in right:
			print("True")
			return True
	else:
		print("False")
		return False

find(test, x)
