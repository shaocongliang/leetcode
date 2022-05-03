func findNDesc(ratings []int, pos, end int) int {
	n := 0
	for ; pos < end-1; pos++ {
		if ratings[pos] > ratings[pos+1] {
			n++
		} else {
			return n
		}
	}
	return n
}

func Max(lhs, rhs int) int {
	if lhs > rhs {
		return lhs
	} else {
		return rhs
	}
}

func candy(ratings []int) int {
	length := len(ratings)
	if length == 1 {
		return 1
	}
	nCandy := 1
	prevCandy := 1
	if ratings[1] < ratings[0] {
		n := findNDesc(ratings, 0, length)
		nCandy = n + 1
		prevCandy = n + 1
	}
	i := 1
	for ; i < length-1; i++ {
		if ratings[i] > ratings[i-1] {
			n2 := 0
			n1 := prevCandy + 1
			if ratings[i] > ratings[i+1] {
				n := findNDesc(ratings, i+1, length)
				n2 = n + 1 + 1
			}
			nCandy += Max(n1, n2)
			prevCandy = Max(n1, n2)
		} else {
			n := 0
			if (i < length-1) && ratings[i] != ratings[i+1] {
				n = findNDesc(ratings, i, length)
			}
			nCandy += 1 + n
			prevCandy = 1 + n
		}
	}
	if ratings[i] > ratings[i-1] {
		return nCandy + prevCandy + 1
	} else {
		return nCandy + 1
	}
}