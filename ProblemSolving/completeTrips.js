var minimumTime = function (time, totalTrips) {
  // loop until total trips complete

  let ho = time[0] * totalTrips;
  let lo = 1;

  while (lo <= ho) {
    let mid = Math.floor((lo + ho) / 2);
    let trips = 0;
    for (let i = 0; i < time.length; i++) {
      trips += Math.floor(mid / time[i]);
    }
    if (trips < totalTrips) {
      lo = mid + 1;
    } else {
      ho = mid - 1;
    }
  }
  return lo;
};

console.log(minimumTime([1, 2, 3, 4], 5));
