int kaijo(int a, int result) {
  if(a == 0) {
    return result;
  } else {
    return kaijo(a-1, result*a);
  }
}

int kaijo(int a) {
  return kaijo(a,1);
}
