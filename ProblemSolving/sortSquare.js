function square(arr) {
  const sortSquare = [];

  let firstIndex = 0;
  let lastIndex = arr.length - 1;
  while (firstIndex <= lastIndex) {
    const startItem = Math.abs(arr[firstIndex]);
    const endItem = Math.abs(arr[lastIndex]);
    if (startItem < endItem) {
      sortSquare.unshift(Math.pow(endItem, 2));
      lastIndex--;
    } else {
      sortSquare.unshift(Math.pow(startItem, 2));
      firstIndex++;
    }
  }
  return sortSquare;
}

console.log(square([-2, -1, 1, 2, 3, 4]));
