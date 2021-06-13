func myPow(x float64, n int) float64 {
	ans := 1.0
	tmp := x
	neg := false
	if n < 0 {
		n = -n
		neg = true
	} else if n == 0 {
		return 1.00
	}
	for n != 0 {
		v := n & 0x1
		n = n >> 1
		if v != 0 {
			ans = ans * tmp
		}
		tmp = tmp * tmp
	}
	if neg {
		return 1 / ans
	}
	return ans
}