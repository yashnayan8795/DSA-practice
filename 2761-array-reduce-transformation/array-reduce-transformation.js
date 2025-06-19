var reduce= function(nums, fn, init) {
  if (nums.length === 0) {
    return init;
  } else {
    const first = nums[0];
    const last= nums.slice(1);
    const value = fn(init, first);
    return reduce(last, fn, value);
  }
}