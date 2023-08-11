func generate(numRows int) [][]int {
    triangle := make([][]int, 0)

	for numRow := 0; numRow < numRows; numRow++ {
		layer := make([]int, 0)
		for numElement := 0; numElement <= numRow; numElement++ {
			value := 1
			if numRow > 1 && numElement > 0 && numElement < numRow {
				value = triangle[numRow-1][numElement-1] + triangle[numRow-1][numElement]
			}
			layer = append(layer, value)
		}
		triangle = append(triangle, [][]int{layer}...)
	}

	return triangle
}