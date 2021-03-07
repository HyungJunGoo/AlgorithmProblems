# Quick sort in Python

# Function to partition the array on the basis of pivot element
def partition(array, low, high):

    # Select the pivot element
    pivot = array[high]
    i = low - 1

    # Put the elements smaller than pivot on the left and greater
    # than pivot on the right of pivot
    for j in range(low, high):
        if array[j] <= pivot:
            i = i + 1
            (array[i], array[j]) = (array[j], array[i])
    
    (array[i+1], array[high]) = (array[high], array[i+1])
    return i+1

def quicksort(array, low, high):
    if low < high:

        pi = partition(array, low, high)

        # Sort the elements on the left of pivot
        quicksort(array, low, pi-1)

        # Sort the elements on the right of pivot
        quicksort(array, pi+1, high)


data = [8,7,2,1,0,9,6]
size = len(data)
quicksort(data, 0, size-1)
print(data)