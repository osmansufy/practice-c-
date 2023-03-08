const findKthPositive = function (arr, k) {
  let count = 1;
  let empty = 1;

  while (empty < k) {
    let check = arr.includes(count);
    count++;
    if (!check) {
      empty++;
    }
  }

  return count;
};
console.log(findKthPositive([2, 3, 4, 7, 11], 5));
