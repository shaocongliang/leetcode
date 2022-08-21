func accmulateTrap(lhs, rhs int, trap *int, height []int) {
	min := lhs
	if height[lhs] > height[rhs] {
		min = rhs
	}
	for lhs += 1; lhs < rhs; lhs++ {
		if height[min]-height[lhs] < 0 {
			continue
		} else {
			*trap += height[min] - height[lhs]
		}
	}
}

func reset(index, i *int) {
	*index = -1
	*i = *i - 1
}

func trap(height []int) int {
	startIndex := -1
	endIndex := -1
	length := len(height)
	ans := 0

	for i := 0; i < length; i++ {
		if startIndex == -1 {
			if height[i] == 0 {
				continue
			} else {
				if i+1 < length && height[i+1] >= height[i] {
					continue
				} else {
					startIndex = i
					i = i + 1
				}
			}
		} else {
			if height[i] == 0 {
				continue
			} else {
				// last element
				if i > length-2 {
					if height[i] > height[startIndex+1] || i-startIndex > 2 {
						accmulateTrap(startIndex, i, &ans, height)
					}
					return ans
				} else {
					max := 0
					for j := i; j < length; j++ {
						if height[j] >= height[startIndex] {
							endIndex = j
							break
						} else {
							if height[j] > max {
								max = height[j]
								endIndex = j
							}
						}
					}
					if endIndex-startIndex == 2 && height[endIndex] <= height[startIndex+1] {
						startIndex = -1
						i = endIndex - 1
					} else {
						accmulateTrap(startIndex, endIndex, &ans, height)
						startIndex = -1
						i = endIndex - 1
					}
				}
			}
		}
	}
	return ans
}