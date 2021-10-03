def interpolationSearch(arr, low, high, key):
  
  if low <= high and key >= arr[low] and key <= arr[high]:
    pos = low + ((high - low) // (arr[high] - arr[low]) * (key - arr[low]))
    
    if arr[pos] == key:
      return pos
    
    if arr[pos] < key:
      return interpolationSearch(arr, pos + 1, high, key)
    
    if arr[pos] > key:
      return interpolationSearch(arr, low, pos - 1, key)
  
  return -1


if __name__ == '__main__':
  arr = [12,15,18,21,24,27,30,33,37]
  n = len(arr)
  key = 21
  index = interpolationSearch(arr, 0, n - 1, key)
 
  if index != -1:
    print("Element found at index ",index)
  else:
    print("Element not found")
